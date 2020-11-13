%{
#include "lexer.h"
#include <stdio.h>

void yyerror(const char* str);

%}

// vul aan met tokendeclaraties
// vul aan met voorrangdeclaraties

%token
  SEMICOLON LPAREN RPAREN COMMA
  IF THEN ELSIF ELSE UNLESS WHILE DO UNTIL CASE WHEN END RETURN
  ASSIGN PLUSASSIGN MINUSASSIGN MULASSIGN DIVASSIGN ANDASSIGN ORASSIGN
  PLUS MINUS MUL DIV GT GE LT LE EQ NE
  AND OR NOT
  BOOLEAN INTEGER IDENTIFIER
  UNDEF DEF
  NEWLINE

%defines

%right ASSIGN PLUSASSIGN MINUSASSIGN MULASSIGN DIVASSIGN ANDASSIGN ORASSIGN
%right GT GE LT LE EQ NE
%left AND OR
%left PLUS MINUS
%left MUL DIV
%right UMINUS NOT

%%

program : compstmt
;

compstmt : stmt
  | stmt t
  | stmt t compstmt
;

stmt : UNDEF IDENTIFIER
  | DEF IDENTIFIER LPAREN arglist RPAREN compstmt END
  | RETURN expr
  | IF expr then compstmt elsif else END
  | UNLESS expr then compstmt else END
  | WHILE expr do compstmt END
  | UNTIL expr do compstmt END
  | CASE expr WHEN expr then compstmt when else END
  | expr
;

elsif : /* empty */
  | elsif ELSIF expr then compstmt
;

when : /* empty */
  | when WHEN expr then compstmt
;

else : /* empty */
  | ELSE compstmt
;

expr : IDENTIFIER ASSIGN expr
  | IDENTIFIER PLUSASSIGN expr
  | IDENTIFIER MINUSASSIGN expr
  | IDENTIFIER MULASSIGN expr
  | IDENTIFIER DIVASSIGN expr
  | IDENTIFIER ANDASSIGN expr
  | IDENTIFIER ORASSIGN expr
  | expr PLUS expr
  | expr MINUS expr
  | expr MUL expr
  | expr DIV expr
  | expr GT expr
  | expr GE expr
  | expr LT expr
  | expr LE expr
  | expr EQ expr
  | expr NE expr
  | expr AND expr
  | expr OR expr
  | NOT expr
  | literal
  | IDENTIFIER
  | MINUS expr  %prec UMINUS
  | IDENTIFIER LPAREN exprs RPAREN
  | LPAREN expr RPAREN
  | error
;

literal : BOOLEAN
  | INTEGER
;

exprs : /* empty */
  | expr
  | exprs COMMA expr
;

arglist : /* empty */
  | IDENTIFIER
  | arglist COMMA IDENTIFIER
;

then : t
  | THEN
  | t THEN
;

do : t
  | DO
  | t DO
;

t : SEMICOLON
  | NEWLINE
;


%%

void yyerror (const char *s)
{
  puts(s); 
}
