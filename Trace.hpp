#ifndef TRACE_H
#define TRACE_H
#include <vector>
#include <stack>
#include <iostream>
#include <iomanip>
#include "Bytecode.hpp"
namespace Trace {

  void trace_opcodes(std::vector<int> code, unsigned int ip, int opcode) {
    using namespace Bytecode;
    std::cerr << std::setfill('0') << std::setw(4) << ip << ": " << opcodes[opcode] << " ";
    if (instructions[opcodes[opcode]] == 1) {
      std::cerr << code[ip + 1];
    }
  }

  void trace_stack(std::vector<int> stack, int sp) { 
    std::cout << std::setfill(' ') << std::right << std::setw(10) << " [";
    if (sp >= 0) {
      for (int i = 0; i <= sp; i++) {
        std::cerr << " [" << stack[i] << "] ";
      }
    }
    std::cerr << "]" << std::endl;


  }
}
#endif
