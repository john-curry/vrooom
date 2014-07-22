#include <iomanip>
#include <iostream>
#include <vector>
#include "Bytecode.hpp"
#include "Trace.hpp"
using namespace std;
using namespace Bytecode;
using namespace Trace;

int line_number_to_absolute_index(int line_number, std::vector<int> code) {
  int final_position = 0;
  while (line_number != 0) {                                // use line_number as an index, decrementing whenever an opcode has been found
    if (instructions[opcodes[code[final_position]]] == 0) { // if instruction has no arguements
      final_position += 1;                                  // icrement the final position
    }
    if (instructions[opcodes[code[final_position]]] == 1) { // if the opcode has one arguement
      final_position += 2;                                  // move final position up 2 to make up for the arguement
    }
    line_number -= 1;                                       // acknoledge that we have gone down a line
  }
  return final_position;
}

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
      switch (opcode) { //decode
        case BR: {
          ip = code[ip + 1];
        }
        case BRT: {
          if (stack[sp--] == TRUE) {
            ip = line_number_to_absolute_index(code[ip], code);
          } else {
            ip++;
          }
          stack.pop_back();
          break;
        }
        case BRF: {
          if (stack[sp--] == FALSE) {
            ip = line_number_to_absolute_index(code[ip], code);
          } else {
            ip++;
          }
          stack.pop_back();
          break;
        }
        case ICONST: {
          int var = code[ip++];
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
        default: {
          std::cerr << std::endl << " WARNING: " << "Unimplemented opcode " << opcode << ". Quitting program..." << std::endl;
          return;
        }
      }
      print_stack();
    }
  }
};

int main() {
  using namespace Bytecode;
  vector<int> code {
 /*0 */   ICONST, 3,
 /*1 */   ICONST, 0,
 /*2 */   BRF, 5,
 /*3 */   ICONST, 99, 
 /*4 */   ICONST, 98,
 /*5 */   ICONST, 97,
 /*6 */   PRINT,
 /*7 */   HALT    
 /*8 */ 
 /*9 */ };             
 /*10*/ 
 /*11*/
 /*12*/
 /*13*/
 /*14*/
 /*15*/
 /*16*/
 /*17*/











  
  
  
  
  

  vm<true, 100> mvm(code, 0, 0);
  mvm.cpu();
  return 0;
}








