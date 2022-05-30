set(BINARY ${CMAKE_PROJECT_NAME})


include_directories(../include)
# file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES
../include/ast/ast.hpp
../include/lexer/lexer.hpp
../include/token/token.hpp
./ast/ast.cpp
./token/token.cpp
./lexer/lexer.cpp)

add_executable(${BINARY}_run main.cpp
    ${SOURCE})

add_library(${BINARY}_lib STATIC ${SOURCES})