#ifndef MONKEY_PARSER_H_
#define MONKEY_PARSER_H_

#include <string>
#include<unordered_map>
#include <vector>
#include "../lexer/lexer.hpp"
#include "../ast/ast.hpp"

namespace monkey {
    class Parser;

    typedef Expression* (Parser::*PrefixParseFn)();
    typedef Expression* (Parser::*InfixParseFn)(Expression* );
    
    enum Precedence {
        LOWEST,
        EQUALS,      // ==
        LESSGREATER, // > or <
        SUM,         // +
        PRODUCT,     // *
        PREFIX,      // -X or !X
        CALL,        // myFunction(X)
        INDEX,       // []
    };
    
    class Parser {
    public:
        void New(Lexer& l);
        Program* ParseProgram();
    private:
        void nextToken();
        bool expectPeek(const TokenType& t);

        Statement* parseStatement();
        LetStatement* parseLetStatement();
        ExpressionStatement* parseExpresssionStatement();


        Expression* parseExpression(Precedence Precedence);
        //prefix parser functions
        Expression* parseIdentifier();
        Expression* parseIntegerLiteral();


        Lexer l;
        Token curToken;
        Token peekToken;

        std::unordered_map<TokenType, PrefixParseFn> prefixParseFns;
        std::unordered_map<TokenType, InfixParseFn> infixParseFns;

        std::vector<std::string> errors;
    };


}

#endif