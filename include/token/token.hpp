#ifndef MONKEY_TOKEN_H_
#define MONKEY_TOKEN_H_
#include <string>

namespace monkey {
    typedef std::string TokenType;

    class Token {
    };

    const TokenType IELLEGAL = "IELLEGAL";
    const TokenType END = "END";

    const TokenType IDENT = "IDENT";
    const TokenType INT = "INT";
    const TokenType STRING = "STRING";

    const TokenType ASSIGN = "=";
}

#endif