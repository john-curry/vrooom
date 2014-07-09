#include <iomanip>
#include <iostream>
#include <vector>
#include "Bytecode.hpp"
#include "Trace.hpp"
using namespace std;
using namespace Bytecode;
using namespace Trace;
template<bool trace, int stack_size>
class vm {
public:
  vector<int> code;
  vector<int> stack;
  vector<int> data;
  vector<int> globals;
  unsigned int ip;
  int sp = -1;
  unsigned int fp;

  vm(vector<int> code_, int entry_, int datasize) : code(code_), ip(entry_) { 
    stack.reserve(stack_size);
    globals.reserve(stack_size);
  }
  void print_stack() { if (trace) trace_stack(stack, sp); }

  void cpu() {
    while (ip <= code.size()) {
      int opcode = code[ip]; // fetch
      if (trace) trace_opcodes(code, ip, opcode);
      ip++;
      switch (opcode) {
        case ICONST: {
          int var = code[ip];
          ip++;
          sp++;
          stack.push_back(var);
          break;
        }
        case PRINT: {
          int toprint = stack[sp];
          stack.pop_back();
          sp--;
          std::cout << toprint << std::endl;
          break;
        }
        case IADD: {
          int a = stack[sp];
          stack.pop_back();
          sp--;
          int b = stack[sp];
          stack.pop_back();
          stack.push_back(a + b);
          break;
        }
        case IMUL: {
          int a = stack[sp];
          sp--;
          int b = stack[sp];
          stack[sp] = a * b;
          break;
        }
        case GLOAD: {
          int addr = code[ip];
          ip++;
          stack.push_back(globals[addr]);
          sp++;
          break;
        }
        case GSTORE: {
          int var = stack[sp];
          sp--;
          int addr = code[ip];
          ip++;
          globals[addr] = var;
          break;
        }
        case HALT: {
          std::cout << std::endl;
          return;
          break;
        }
      }
      print_stack();
    }
  }
};

int main() {
  using namespace Bytecode;
  vector<int> code {
    ICONST, 99,
    GSTORE, 0,
    ICONST, 33,
    GLOAD, 0,
    PRINT,
    HALT    
    
  };


  vm<true, 100> mvm(code, 0, 0);
  mvm.cpu();
  return 0;
}








