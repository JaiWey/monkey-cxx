#ifndef MONKEY_TOKEN_H_
#define MONKEY_TOKEN_H_
#include <string>
#include <unordered_map>

namespace monkey {
    typedef std::string TokenType;

    class Token {
        public:
        Token() {}
        Token(TokenType type, std::string literal) : type(type), literal(literal) {}
        Token(TokenType type, char ch) : type(type), literal(std::string(1, ch)) {}
        
        TokenType type;
        std::string literal;
    };

    const TokenType IELLEGAL = "IELLEGAL";
    const TokenType END = "END";

    const TokenType IDENT = "IDENT";
    const TokenType INT = "INT";
    const TokenType STRING = "STRING";

    const TokenType ASSIGN   = "=";
    const TokenType PLUS     = "+";
    const TokenType MINUS    = "-";
    const TokenType BANG     = "!";
    const TokenType ASTERISK = "*";
    const TokenType SLASH    = "/";
    const TokenType PERCENT  = "%";

    const TokenType LT     = "<";
    const TokenType GT     = ">";
    const TokenType LE     = "<=";
    const TokenType GE     = ">=";

    const TokenType EQ     = "==";
    const TokenType NE     = "!=";

    const TokenType COMMA     = ",";
    const TokenType SEMICOLON = ";";
    const TokenType COLON = ":";

    const TokenType LPAREN   = "(";
    const TokenType RPAREN   = ")";
    const TokenType LBRACE   = "{";
    const TokenType RBRACE   = "}";
    const TokenType LBRACKET = "[";
    const TokenType RBRACKET = "]";

    const TokenType REF    = "&";

    // keywords
    const TokenType FUNCTION = "FUNCTION";
    const TokenType LET      = "LET";
    const TokenType TRUE     = "TRUE";
    const TokenType FALSE    = "FALSE";
    const TokenType IF       = "IF";
    const TokenType ELSE     = "ELSE";
    const TokenType RETURN   = "RETURN";
    const TokenType WHILE    = "WHILE";

    extern std::unordered_map<std::string, TokenType> keywords;

    TokenType LookupIdent(std::string ident);
}

#endif