#include "ast/ast.hpp"

namespace monkey {
    std::string Program::TokenLiteral() {
        if (statements.size()) {
            return statements[0]->TokenLiteral();
        } else {
            return "";
        }
    }
    std::string Program::String() {
        std::string res;
        for (auto stmt: statements) {
            res += stmt->String() + "\n";
        }
        return res;
    }

    std::string LetStatement::String() {
        std::string res = TokenLiteral() + " " +
            name.String() + " = ";
        if (value != nullptr) {
            res += value->String();
        }
        res += ";"
        return res;
    }
}