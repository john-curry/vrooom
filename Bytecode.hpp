#ifndef BYTECODE_H
#define BYTECODE_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
namespace Bytecode {
  const int IADD     = 1;
  const int ISUB     = 2;
  const int IMUL     = 3;
  const int ILT      = 4;
  const int IEQ      = 5;
  const int BR       = 6;
  const int BRT      = 7;
  const int BRF      = 8;
  const int ICONST   = 9;
  const int LOAD     = 10;
  const int GLOAD    = 11;
  const int STORE    = 12;
  const int GSTORE   = 13;
  const int PRINT    = 14;
  const int POP      = 15;
  const int HALT     = 16;

  // this is a convention for the sake of convenience
  const int FALSE    = 0;
  const int TRUE     = 1;

  std::map<std::string, int> instructions {
    { "IADD",    0  },
    { "ISUB",    0  },
    { "IMUL",    0  },
    { "ILT",     0  },
    { "IEQ",     0  },
    { "BR",      1  },
    { "BRT",     1  },
    { "BRF",     1  },
    { "ICONST",  1  },
    { "LOAD",    1  },
    { "GLOAD",   1  },
    { "STORE",   1  },
    { "GSTORE",  1  },
    { "PRINT",   0  },
    { "POP",     0  },
    { "HALT",    0  }
  };

  std::vector<std::string> opcodes {
    "",
    "IADD",
    "ISUB",
    "IMUL",
    "ILT",
    "IEQ",
    "BR",
    "BRT",
    "BRF",
    "ICONST",
    "LOAD",
    "GLOAD",
    "STORE",
    "GSTORE",
    "PRINT",
    "POP",
    "HALT"
  };
}
#endif
