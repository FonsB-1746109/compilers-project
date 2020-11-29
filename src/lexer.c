#include <stdio.h>
#include "lexer.h"
#include "lex.yy.c"
#include "ruby.tab.h"
#include "ruby.tab.c"

/* Array with tokens such that index = tokenid - 250*/
char *tokens[] = {
"SEMICOLON", "UNDEF", "DEF", "LPAREN", "RPAREN", "END", "RETURN",
"PRINT", "INTEGER", "IDENTIFIER", "IF", "THEN", "ELSIF", "ELSE", "UNLESS",
"WHILE", "DO", "UNTIL", "CASE", "WHEN", "COMMA", "ASSIGN",
"PLUSASSIGN", "MINUSASSIGN", "MULASSIGN", "DIVASSIGN",
"ANDASSIGN", "ORASSIGN", "PLUS", "MINUS", "MUL", "DIV", "GT",
"GE", "LT", "LE", "EQ", "NE", "AND", "OR", "NOT", "BOOLEAN"
}; 

int main(int argc, char* argv[])
{
  int tokenid;
  
  yyparse();

  /* If we de not explicitly bind yyin to a file, stdin is assumed. */
  // while (tokenid=yylex())
  //   {
  //     /* Token codes start from 250 */ 
  //     printf(" %s\n", tokens[tokenid-250]);

  //     /* Append value */
  //     if ( (tokenid == IDENTIFIER) || (tokenid == INTEGER) || (tokenid == BOOLEAN) ) 
	//       printf("=\"%s\"\n", yytext);
  //   }
  //   printf("\n");


  return 0;
}
