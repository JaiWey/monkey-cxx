#ifndef MONKEY_AST_H_
#define MONKEY_AST_H_
#include <string>

namespace monkey {
class Node
{
private:
    /* data */
public:
    virtual ~Node() {};
    virtual std::string TokenLiteral() = 0;
    virtual std::string String() = 0;
    virtual std::string Type() = 0;
};
}
#endif  // MONKEY_AST_H_