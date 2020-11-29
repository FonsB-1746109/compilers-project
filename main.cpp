#include <stdio.h>
#include <iostream>
#include "src/lex.yy.c"
#include "src/ruby.tab.h"
#include "src/ruby.tab.c"


int main(int argc, char* argv[])
{
  // Open a file handle to a particular file:
  FILE *myfile = fopen(argv[1], "r");
  // Make sure it is valid:
  if (!myfile) {
    std::cout << "I can't open file!" << std::endl;
    return -1;
  }
  // Set Flex to read from it instead of defaulting to STDIN:
  yyin = myfile;
  // Parse through the input:
  yyparse();

  return 0;
}