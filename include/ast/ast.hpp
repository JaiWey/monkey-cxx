#ifndef MONKEY_AST_H_
#define MONKEY_AST_H_
#include "../token/token.hpp"
#include <string>
#include <vector>

namespace monkey
{
    class Node
    {
    private:
        /* data */
    public:
        virtual ~Node(){};
        virtual std::string TokenLiteral() = 0;
        virtual std::string String() = 0;
        virtual std::string Type() = 0;
    };

    class Statement: public Node {
    public:
        virtual std::string TokenLiteral() = 0;
        virtual std::string String() = 0;
        virtual std::string Type() = 0;
    };

    class Expression: public Node {
    public:
        virtual std::string TokenLiteral() = 0;
        virtual std::string String() = 0;
        virtual std::string Type() = 0;
    };

    class Program: public Node {
    public:
        ~Program() {
            for (auto stmt : statements) {
                delete stmt;
            }
        }
        std::string TokenLiteral();
        std::string String();
        std::string Type() { return "Program";}

        std::vector<Statement*> statements;
    };

    class Identifier : public Expression {
    public:
        std::string TokenLiteral() { return token.literal;}
        std::string String() { return value;}
        std::string Type() { return "Identifier";}

        Token token;
        std::string value;
    };

    class IntegerLiteral : public Expression {
    public:
        std::string TokenLiteral() { return token.literal; }
        std::string String() { return value; }
        std::string Type() { return "IntegerLiteral";}

        Token token;
        std::string value;
    };

    class CallExpression : public Expression {
    public:
        ~CallExpression() {
            for (auto arg: arguments) {
                delete arg;
            }
            delete function;
        }
        std::string TokenLiteral() { return token.literal; };
        std::string String();
        std::string Type() { return "IntegerLiteral";}

        Token token;
        Expression* function;
        std::vector<Expression*> arguments;
    };




//Statements
    class LetStatement : public Statement {
    public:
        ~LetStatement() {
            delete value;
        };
        std::string TokenLiteral() { return token.literal; }
        std::string String();
        std::string Type() { return "LetStatement"; }

        Token token;
        Identifier name;
        Expression* value;
    };

    class ExpressionStatement: public Statement {
    public:
        std::string TokenLiteral() { return token.literal; }
        std::string String();
        std::string Type() { return "ExpressionStatement"; }
        
        Token token;
        Expression* expression;
    };
}
#endif // MONKEY_AST_H_