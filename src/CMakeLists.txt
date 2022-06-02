set(BINARY ${CMAKE_PROJECT_NAME})


include_directories(../include)
# file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES
../include/ast/ast.hpp
../include/lexer/lexer.hpp
../include/token/token.hpp
../include/parser/parser.hpp
./ast/ast.cpp
./token/token.cpp
./lexer/lexer.cpp
./parser/parser.cpp)

add_executable(${BINARY}_run
    ${SOURCE} ./main.cpp)

add_library(${BINARY}_lib STATIC ${SOURCES})