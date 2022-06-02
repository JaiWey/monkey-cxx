#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "../include/lexer/lexer.hpp"
#include "../include/parser/parser.hpp"

std::string readFile2(std::string &fileName) {
  std::ifstream ifs(fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

  std::ifstream::pos_type fileSize = ifs.tellg();
  ifs.seekg(0, std::ios::beg);

  std::vector<char> bytes(fileSize);
  ifs.read(bytes.data(), fileSize);

  return std::string(bytes.data(), fileSize);
}

int main(int argc, char** argv) {
    // monkey::print();
    std::string filename{argv[1]};
    std::string input = readFile2(filename);

    monkey::Lexer l;
    monkey::Parser p;

    // l.New(input);
    // p.New(l);
    // monkey::Program* program = p.ParseProgram();
    return 0;
}