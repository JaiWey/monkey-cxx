#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../include/lexer/lexer.hpp"

TEST(LexerTest, test1) {
    const char* inputRaw = R""""(
        let five = 5;
        let ten = 10;

        let add = fn(x, y) {
        x + y;
        };

        let result = add(five, ten);
        !-/*5;
        5 < 10 > 5;

        if (5 < 10) {
            return true;
        } else {
            return false;
        }

        10 == 10;
        10 != 9;
        "foobar"
        "foo bar"
        [1, 2];
        {"foo": "bar"}"
        )"""";
    std::string input(inputRaw);

    std::vector<monkey::Token> resultEXP{
        monkey::Token(monkey::LET, "let"),
        monkey::Token(monkey::IDENT, "five"),
        monkey::Token(monkey::ASSIGN, "="),
        monkey::Token(monkey::INT, "5"),
        monkey::Token(monkey::SEMICOLON, ";"),
        monkey::Token(monkey::LET, "let"),
        monkey::Token(monkey::IDENT, "ten"),
        monkey::Token(monkey::ASSIGN, "="),
        monkey::Token(monkey::INT, "10"),
        monkey::Token(monkey::SEMICOLON, ";"),
        monkey::Token(monkey::LET, "let"),
        monkey::Token(monkey::IDENT, "add"),
        monkey::Token(monkey::ASSIGN, "="),
        monkey::Token(monkey::FUNCTION, "fn"),
        monkey::Token(monkey::LPAREN, "("),
        monkey::Token(monkey::IDENT, "x"),
        monkey::Token(monkey::COMMA, ","),
        monkey::Token(monkey::IDENT, "y"),
        monkey::Token(monkey::RPAREN, ")"),
        monkey::Token(monkey::LBRACE, "{"),
        monkey::Token(monkey::IDENT, "x"),
        monkey::Token(monkey::PLUS, "+"),
        monkey::Token(monkey::IDENT, "y"),
        monkey::Token(monkey::SEMICOLON, ";"),
        monkey::Token(monkey::RBRACE, "}"),
        monkey::Token(monkey::SEMICOLON, ";"),
        monkey::Token(monkey::LET, "let"),
        monkey::Token(monkey::IDENT, "result"),
        monkey::Token(monkey::ASSIGN, "="),
        monkey::Token(monkey::IDENT, "add"),
        monkey::Token(monkey::LPAREN, "("),
        monkey::Token(monkey::IDENT, "five"),
        monkey::Token(monkey::COMMA, ","),
        monkey::Token(monkey::IDENT, "ten"),
        monkey::Token(monkey::RPAREN, ")"),
        monkey::Token(monkey::SEMICOLON, ";"),
        monkey::Token(monkey::BANG, "!"),
        monkey::Token(monkey::MINUS, "-"),
        monkey::Token(monkey::SLASH, "/"),
        monkey::Token(monkey::ASTERISK, "*"),
        monkey::Token(monkey::INT, "5"),
        monkey::Token(monkey::SEMICOLON, ";"),
        monkey::Token(monkey::INT, "5"),
        monkey::Token(monkey::LT, "<"),
        monkey::Token(monkey::INT, "10"),
        monkey::Token(monkey::GT, ">"),
        monkey::Token(monkey::INT, "5"),
        monkey::Token(monkey::SEMICOLON, ";"),
        monkey::Token(monkey::IF, "if"),
        monkey::Token(monkey::LPAREN, "("),
        monkey::Token(monkey::INT, "5"),
        monkey::Token(monkey::LT, "<"),
        monkey::Token(monkey::INT, "10"),
        monkey::Token(monkey::RPAREN, ")"),
        monkey::Token(monkey::LBRACE, "{"),
        monkey::Token(monkey::RETURN, "return"),
        monkey::Token(monkey::TRUE, "true"),
        monkey::Token(monkey::SEMICOLON, ";"),
        monkey::Token(monkey::RBRACE, "}"),
        monkey::Token(monkey::ELSE, "else"),
        monkey::Token(monkey::LBRACE, "{"),
        monkey::Token(monkey::RETURN, "return"),
        monkey::Token(monkey::FALSE, "false"),
        monkey::Token(monkey::SEMICOLON, ";"),
        monkey::Token(monkey::RBRACE, "}"),
        monkey::Token(monkey::INT, "10"),
        monkey::Token(monkey::EQ, "=="),
        monkey::Token(monkey::INT, "10"),
        monkey::Token(monkey::SEMICOLON, ";"),
        monkey::Token(monkey::INT, "10"),
        monkey::Token(monkey::NE, "!="),
        monkey::Token(monkey::INT, "9"),
        monkey::Token(monkey::SEMICOLON, ";"),
        monkey::Token(monkey::STRING, "foobar"),
        monkey::Token(monkey::STRING, "foo bar"),
        monkey::Token(monkey::LBRACKET, "["),
        monkey::Token(monkey::INT, "1"),
        monkey::Token(monkey::COMMA, ","),
        monkey::Token(monkey::INT, "2"),
        monkey::Token(monkey::RBRACKET, "]"),
        monkey::Token(monkey::SEMICOLON, ";"),
        monkey::Token(monkey::LBRACE, "{"),
        monkey::Token(monkey::STRING, "foo"),
        monkey::Token(monkey::COLON, ":"),
        monkey::Token(monkey::STRING, "bar"),
        monkey::Token(monkey::RBRACE, "}"),
        monkey::Token(monkey::END, "")
    };
    monkey::Lexer l;
    l.New(input);
    for (monkey::Token& it : resultEXP) { 
        monkey::Token tok = l.NextToken();
        EXPECT_EQ (tok.type,  it.type);
        EXPECT_EQ (tok.literal,  it.literal);
    }
}