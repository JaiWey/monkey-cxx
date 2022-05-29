#include "lexer/lexer.hpp"
#include <iostream>
#include <ctype.h>

namespace monkey
{
    bool isLetter(char ch) {
        return isalpha(ch);
    }
    bool isDigit(char ch) {
        return isdigit(ch);
    }

    void Lexer::readChar()
    {
        if (readPosition >= input.size())
        {
            ch = 0;
        }
        else
        {
            ch = input[readPosition];
        }
        position = readPosition;
        readPosition++;
    }

    char Lexer::peekChar() {
        if (readPosition >= input.size()) {
            return 0;
        } else {
            return input[readPosition];
        }
    }








    void Lexer::New(std::string& input) {
        this->input = input;
        readPosition = 0;
    }

    Token Lexer::NextToken() {
        Token tok;
        
    }
}