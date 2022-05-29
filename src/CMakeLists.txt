set(BINARY ${CMAKE_PROJECT_NAME})


include_directories(../include)
# file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES main.cpp
../include/ast/ast.hpp
../include/lexer/lexer.hpp)

add_executable(${BINARY}_run main.cpp
    ../include/token/token.hpp
    ../include/ast/ast.hpp
    ../include/lexer/lexer.hpp)

add_library(${BINARY}_lib STATIC ${SOURCES})