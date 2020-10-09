%{
/* 
ruby.lex: lex-file for ruby
C definitions
*/

#include "tokens.h"

  /* Keep track of current position of lex for error messages, i.e. 
     the position just *after* the last token read */
  int line_nr = 1;
  int col_nr = 1; 
  void ADJUST() { col_nr += yyleng; }
%}

%%

/* Regular Expressions */

identifier      [a-z]([a-z]|[0-9])*
real            ("-"|"+")?(([0-9]+"."[0-9]*)|([0-9]*"."[0-9]+))
comment         "--".*
whitespace      (" "|"\t")+

;                       { return SEMICOLON}
undef                   { return UNDEF}
def                     { return DEF}
"("                     { return LPAREN}
")"                     { return RPAREN}
end                     { return END}
return                  { return RETURN}
if                      { return IF; }
then                    { return THEN; }
elsis                   { return ELSIF; }
else                    { return ELSE; }
unless                  { return UNLESS; }
while                   { return WHILE; }
do                      { return DO; }
unless                  { return UNLESS; }
unless                  { return UNLESS; } //int te vullen
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
unless                  { return UNLESS; }
\n                      { line_nr++; col_nr=0; }

{identifier}            { return ID; }
{real}                  { return REAL; }
{comment}|{whitespace}  {/* doe niets */}


/* Errors */
.      {
  if (yytext[0] < ' '){ /* non-printable char */
    /*yyerror*/ fprintf(stderr,"illegal character: ^%c",yytext[0] + '@'); 
  }
  else {
    if (yytext[0] > '~') {
      /* non-printable char printed as octal int padded with zeros, eg \012*/
      /*yyerror(*/fprintf(stderr,"illegal character: \\%03o", (int) yytext[0]);
    }
    else {
      /*yyerror(*/fprintf(stderr,"illegal character: %s",yytext);
    }
  }
  /* lex read exactly one char; the illegal one */
  fprintf(stderr," at line %d column %d\n", line_nr, (col_nr-1));
			       }
%%

/* Function called by (f)lex when EOF is read. If yywrap returns a
   true (non-zero) (f)lex will terminate and continue otherwise.*/
int yywrap(){
  return (1);
}

