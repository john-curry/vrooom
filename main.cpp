#include <iomanip>
#include <iostream>
#include <vector>
#include "Bytecode.hpp"
#include "Trace.hpp"
#include "VirtualMachine.h"
using namespace std;
using namespace Bytecode;
using namespace Trace;

int main() {
  using namespace Bytecode;
  vector<int> code {
    ICONST, 2,
    ICONST, 4,
    ILT,
    BRT, 5,
    ICONST, 99,
    ICONST, 97,
    ICONST, 96,
    ICONST, 95,
    ICONST, 94,
    ICONST, 94,
    IEQ, 
    BRT, 14,
    ICONST, 93,
    ICONST, 92,
    ICONST, 91,
    ICONST, 90,
    PRINT,
    HALT
  };
    
  vm<true, 100> mvm(code, 0, 0);
  mvm.cpu();
  return 0;
}








