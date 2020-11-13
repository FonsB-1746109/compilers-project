%{
/* 
ruby.lex: lex-file for ruby
C definitions
*/

#include "ruby.tab.h"

  /* Keep track of current position of lex for error messages, i.e. 
     the position just *after* the last token read */
  int line_nr = 1;
  int col_nr = 1; 
  void ADJUST() { col_nr += yyleng; }
%}

 /* Regular Expressions */

identifier  [a-z]([a-z]|[0-9])*
real        ("-"|"+")?(([0-9]+"."[0-9]*)|([0-9]*"."[0-9]+))
integer     [0-9]+
boolean     ("true"|"false")
comment     "--".*
whitespace  (" "|"\t")+

%%

;                       { return SEMICOLON; }
,                       { return COMMA; }
undef                   { return UNDEF; }
def                     { return DEF; }
"("                     { return LPAREN; }
")"                     { return RPAREN; }
end                     { return END; }
return                  { return RETURN; }
if                      { return IF; }
then                    { return THEN; }
elsif                   { return ELSIF; }
else                    { return ELSE; }
unless                  { return UNLESS; }
while                   { return WHILE; }
do                      { return DO; }
until                   { return UNTIL; }
case                    { return CASE; }
when                    { return WHEN; }
"="                     { return ASSIGN; }
"+="                    { return PLUSASSIGN; }
"-="                    { return MINUSASSIGN; }
"*="                    { return MULASSIGN; }
"/="                    { return DIVASSIGN; }
"&&="                   { return ANDASSIGN; }
"||="                   { return ORASSIGN; }
"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return MUL; }
"/"                     { return DIV; }
">"                     { return GT; }
">="                    { return GE; }
"<"                     { return LT; }
"<="                    { return LE; }
"=="                    { return EQ; }
"!="                    { return NE; }
"&&"                    { return AND; }
"||"                    { return OR; }
"!"                     { return NOT; }
\n                      { line_nr++; col_nr=0; return NEWLINE; }

{boolean}               { return BOOLEAN; }
{identifier}            { return IDENTIFIER; }
 /* {real}                  { return REAL; } */
{integer}               { return INTEGER; }
{comment}|{whitespace}  { }



.      { /* Errors */
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

