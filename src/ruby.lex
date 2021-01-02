%{
/* 
ruby.lex: lex-file for ruby
C definitions
*/
#include "absyn.h"
#include "ruby.tab.h"

#include <stdlib.h>

  /* Keep track of current position of lex for error messages, i.e. 
     the position just *after* the last token read */
  int line_nr = 1;
  int col_nr = 1; 
  void ADJUST() { col_nr += yyleng; }
%}

 /* Regular Expressions */

identifier  [a-z]([a-z]|[0-9])*
integer     [0-9]+
boolean     (true|false)
comment     ("--"|"#").*
whitespace  (" "|"\t")+

%%
;                       { ADJUST(); return SEMICOLON; }
,                       { ADJUST(); return COMMA; }
undef                   { ADJUST(); return UNDEF; }
def                     { ADJUST(); return DEF; }
"("                     { ADJUST(); return LPAREN; }
")"                     { ADJUST(); return RPAREN; }
end                     { ADJUST(); return END; }
return                  { ADJUST(); return RETURN; }
if                      { ADJUST(); return IF; }
then                    { ADJUST(); return THEN; }
elsif                   { ADJUST(); return ELSIF; }
else                    { ADJUST(); return ELSE; }
unless                  { ADJUST(); return UNLESS; }
while                   { ADJUST(); return WHILE; }
do                      { ADJUST(); return DO; }
until                   { ADJUST(); return UNTIL; }
case                    { ADJUST(); return CASE; }
when                    { ADJUST(); return WHEN; }
print                   { ADJUST(); return PRINT; }
"="                     { ADJUST(); return ASSIGN; }
"+="                    { ADJUST(); return PLUSASSIGN; }
"-="                    { ADJUST(); return MINUSASSIGN; }
"*="                    { ADJUST(); return MULASSIGN; }
"/="                    { ADJUST(); return DIVASSIGN; }
"&&="                   { ADJUST(); return ANDASSIGN; }
"||="                   { ADJUST(); return ORASSIGN; }
"+"                     { ADJUST(); return PLUS; }
"-"                     { ADJUST(); return MINUS; }
"*"                     { ADJUST(); return MUL; }
"/"                     { ADJUST(); return DIV; }
">"                     { ADJUST(); return GT; }
">="                    { ADJUST(); return GE; }
"<"                     { ADJUST(); return LT; }
"<="                    { ADJUST(); return LE; }
"=="                    { ADJUST(); return EQ; }
"!="                    { ADJUST(); return NE; }
"&&"                    { ADJUST(); return AND; }
"||"                    { ADJUST(); return OR; }
"!"                     { ADJUST(); return NOT; }
\n                      { line_nr++; col_nr=1; return NEWLINE; }

{boolean}               { 
                          if (strcmp(yytext, "true") == 0)
                            yylval.boolean = 1;
                          else
                            yylval.boolean = 0;
                          
                          ADJUST();
                          return BOOLEAN; 
                        }
{identifier}            {
                          char* s = (char*) malloc(yyleng+1);
                          strcpy(s, yytext);
                          yylval.id = s;
                          ADJUST();
                          return IDENTIFIER; 
                        }
{integer}               {
                          yylval.integer = atoi(yytext);
                          ADJUST();
                          return INTEGER; 
                        }
{comment}|{whitespace}  { ADJUST(); }



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

