%{
#include "absyn.h"

#include "lexer.h"
#include <stdio.h>



void yyerror(const char* str);

Program tree;
%}

%union {
  char* id;
  int integer;
  bool boolean;

  Program program;
  Compstmt compstmt;
  Stmt stmt;
  Elsif elsif;
  When when;
  Else else;
  Expr expr;
  Exprs exprs;
  Literal literal;
  Arglist arglist;
}

%token <id> IDENTIFIER
%token <integer> INTEGER
%token <boolean> BOOLEAN

%token
  SEMICOLON LPAREN RPAREN COMMA
  IF THEN ELSIF ELSE UNLESS WHILE DO UNTIL CASE WHEN END RETURN
  ASSIGN PLUSASSIGN MINUSASSIGN MULASSIGN DIVASSIGN ANDASSIGN ORASSIGN
  PLUS MINUS MUL DIV GT GE LT LE EQ NE
  AND OR NOT
  UNDEF DEF
  NEWLINE PRINT

%defines

%right ASSIGN PLUSASSIGN MINUSASSIGN MULASSIGN DIVASSIGN ANDASSIGN ORASSIGN
%right GT GE LT LE EQ NE
%left AND OR
%left PLUS MINUS
%left MUL DIV
%right UMINUS NOT

%type <program> program
%type <compstmt> compstmt
%type <stmt> stmt
%type <elsif> elsif
%type <when> when
%type <else> else
%type <expr> expr
%type <exprs> exprs
%type <literal> literal
%type <arglist> arglist

%%

program : compstmt
        { $$ = new Program($1); tree = $$; }
;

compstmt : stmt
        { $$ = new Compstmt($1); }
  | stmt t
        { $$ = new Compstmt($1); }
  | stmt t compstmt 
        { $$ = new Compstmt($1, $3); }
;

stmt : PRINT LPAREN expr RPAREN
        { $$ = new PrintStmt($3); }
  | UNDEF IDENTIFIER
        { $$ = new UndefStmt($2); }
  | DEF IDENTIFIER LPAREN arglist RPAREN compstmt END
        { $$ = new DefStmt($2, $4, $6); }
  | RETURN expr
        { $$ = new ReturnStmt($2); }
  | IF expr then compstmt elsif else END
        { $$ = new IfStmt($2, $4, $5, $6); }
  | UNLESS expr then compstmt else END
        { $$ = new UnlessStmt($2, $4, $5); }
  | WHILE expr do compstmt END
        { $$ = new WhileStmt($2, $4); }
  | UNTIL expr do compstmt END
        { $$ = new UntilStmt($2, $4); }
  | CASE expr WHEN expr then compstmt when else END
        { $$ = new CaseStmt($2, $4, $6, $7, $8); }
  | expr
        { $$ = new ExprStmt($1); }
;

elsif : /* empty */
        { $$ = new Elsif(); }
  | ELSIF expr then compstmt elsif 
        { $$ = new Elsif($2, $4, $5); }
;

when : /* empty */
        { $$ = new When(); }
  | WHEN expr then compstmt when 
        { $$ = new When($2, $4, $5); }

;

else : /* empty */
        { $$ = new Else(); }
  | ELSE compstmt
        { $$ = new Else($2); }
;

expr : IDENTIFIER ASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::Assign, $3); }
  | IDENTIFIER PLUSASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::PlusAssign, $3); }
  | IDENTIFIER MINUSASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::MinAssign, $3); }
  | IDENTIFIER MULASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::MulAssign, $3); }
  | IDENTIFIER DIVASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::DivAssign, $3); }
  | IDENTIFIER ANDASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::AndAssign, $3); }
  | IDENTIFIER ORASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::OrAssign, $3); }
  | expr PLUS expr
        { $$ = new BinOpExpr($1, Binop::Plus, $3); }
  | expr MINUS expr
        { $$ = new BinOpExpr($1, Binop::Minus, $3); }
  | expr MUL expr
        { $$ = new BinOpExpr($1, Binop::Times, $3); }
  | expr DIV expr
        { $$ = new BinOpExpr($1, Binop::Div, $3); }
  | expr GT expr
        { $$ = new BinOpExpr($1, Binop::Gt, $3); }
  | expr GE expr
        { $$ = new BinOpExpr($1, Binop::Ge, $3); }
  | expr LT expr 
        { $$ = new BinOpExpr($1, Binop::Lt, $3); }
  | expr LE expr
        { $$ = new BinOpExpr($1, Binop::Le, $3); }
  | expr EQ expr
        { $$ = new BinOpExpr($1, Binop::Eq, $3); }
  | expr NE expr
        { $$ = new BinOpExpr($1, Binop::Ne, $3); }
  | expr AND expr
        { $$ = new BinOpExpr($1, Binop::And, $3); }
  | expr OR expr
        { $$ = new BinOpExpr($1, Binop::Or, $3); }
  | NOT expr
        { $$ = new NotExpr($2); }
  | literal
        { $$ = new LitExpr($1); }
  | IDENTIFIER
        { $$ = new IdExpr($1); }
  | MINUS expr  %prec UMINUS
        { $$ = new MinExpr($2); }
  | IDENTIFIER LPAREN exprs RPAREN
        { $$ = new FunctionExpr($1, $3); }
  | LPAREN expr RPAREN
        { $$ = $2; }
  | error
        { $$ = ErrorExpr(); }
;

literal : BOOLEAN
        { $$ = new Literal($1)}
  | INTEGER
        { $$ = new Literal($1)}
;

exprs : /* empty */
        { $$ = new LastExprs(); }
  | expr
        { $$ = new LastExprs($1); }
  | exprs COMMA expr
        { $$ = new PairExprs($1, $3)}
;

arglist : /* empty */
        { $$ = new LastArgList(); }
  | IDENTIFIER
        { $$ = new LastArgList($1); }
  | arglist COMMA IDENTIFIER
        { $$ = new PairArgList($1, $3); }
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
