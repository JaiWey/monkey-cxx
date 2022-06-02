#include "parser/parser.hpp"

namespace monkey
{
    void Parser::nextToken() {
        curToken = peekToken;
        peekToken = l.NextToken();
    }

    bool Parser::expectPeek(const TokenType& t) {
        if (peekToken.type == t) {
            nextToken();
            return true;
        } else {
            return false;
        }
    }

    Statement* Parser::parseStatement() {
        if (curToken.type == LET) {
            return parseLetStatement();
        } else {
            return parseExpresssionStatement();
        }
    }

    LetStatement* Parser::parseLetStatement() {
        LetStatement* stmt = new LetStatement();
        stmt->token = curToken;

        if (!expectPeek(IDENT)) {
            delete stmt;
            return nullptr;
        }

        stmt->name.token = curToken;
        stmt->name.value = curToken.literal;
        if (!expectPeek(ASSIGN)) {
            delete stmt;
            return nullptr;
        }
        nextToken();

        stmt->value = parseExpression(LOWEST);

        if (peekToken.type == SEMICOLON)
            nextToken();
        return stmt;
    }

    Expression* Parser::parseExpression(Precedence Precedence) {
        if (prefixParseFns.find(curToken.type) == prefixParseFns.end()) {

        }

        PrefixParseFn prefix = prefixParseFns[curToken.type];

        Expression* leftExp = (this->*prefix)();

        return leftExp;
    }

    void Parser::New(Lexer& l) {
        this->l = l;

        prefixParseFns[IDENT] = &Parser::parseIdentifier;
    }


    Program* ParseProgram() {
        Program* program = new Program();

        return program;
    }
} // namespace monkey
