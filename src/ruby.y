%{
#include "absyn.h"

#include "lexer.h"
#include <stdio.h>
#include <stdbool.h> 

void yyerror(const char* str);

Program *tree;

%}

%union {
  char* id;
  int integer;
  bool boolean;

  Program *program;
  CompStmt *compstmt;
  Stmt stmt;
  Elsif *elsif;
  When *when;
  Else *els;
  Expr expr;
  Exprs exprs;
  Literal *literal;
  ArgList arglist;
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
%type <els> els
%type <expr> expr
%type <exprs> exprs
%type <literal> literal
%type <arglist> arglist

%%

program : compstmt
        { $$ = new Program($1); tree = $$; puts("Program(compstmt)"); }
;

compstmt : stmt
        { $$ = new CompStmt($1); puts("CompStmt(stmt)"); }
  | stmt t
        { $$ = new CompStmt($1); puts("CompStmt(stmt) t"); }
  | stmt t compstmt 
        { $$ = new CompStmt($1, $3); puts("CompStmt(stmt,compstmt)"); }
;

stmt : PRINT LPAREN expr RPAREN
        { $$ = new PrintStmt($3); puts("PrintStmt(expr)"); }
  | UNDEF IDENTIFIER
        { $$ = new UndefStmt($2); puts("UndefStmt(expr)"); }
  | DEF IDENTIFIER LPAREN arglist RPAREN optnewline compstmt END
        { $$ = new DefStmt($2, $4, $7); puts("DefStmt(id,arglist,compstmt)"); }
  | RETURN expr
        { $$ = new ReturnStmt($2); puts("ReturnStmt(expr)"); }
  | IF expr then compstmt elsif els END
        { $$ = new IfStmt($2, $4, $5, $6); puts("IfStmt(expr,comptstmt,elsif,else)"); }
  | UNLESS expr then compstmt els END
        { $$ = new UnlessStmt($2, $4, $5); puts("UnlessStmt(expr,compstmt,else)"); }
  | WHILE expr do compstmt END
        { $$ = new WhileStmt($2, $4); puts("WhileStmt(expr,compstmt)"); }
  | UNTIL expr do compstmt END
        { $$ = new UntilStmt($2, $4); puts("UntilStmt(expr,compstmt)"); }
  | CASE expr optnewline WHEN expr then compstmt when els END
        { $$ = new CaseStmt($2, $5, $7, $8, $9); puts("CaseStmt(expr,expr,compstmt,when,else)"); }
  | expr
        { $$ = new ExprStmt($1); puts("ExprStmt(expr)"); } 
;

elsif : /* empty */
        { $$ = new Elsif(); puts("Elsif()"); }
  | ELSIF expr then compstmt elsif 
        { $$ = new Elsif($2, $4, $5); puts("Elsif(expr,compstmt,elsif)"); }
;

when : /* empty */
        { $$ = new When(); puts("When()"); }
  | WHEN expr then compstmt when 
        { $$ = new When($2, $4, $5); puts("When(expr,compstmt,when)"); }
;

els : /* empty */
        { $$ = new Else(); puts("Else()"); }
  | ELSE optnewline compstmt
        { $$ = new Else($3); puts("Else(comstmt)"); }
;

expr : IDENTIFIER ASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::Assign, $3); puts("AssignOpExpr(id,=,expr)"); }
  | IDENTIFIER PLUSASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::PlusAssign, $3); puts("AssignOpExpr(id,+=,expr)"); }
  | IDENTIFIER MINUSASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::MinAssign, $3); puts("AssignOpExpr(id,-=,expr)"); }
  | IDENTIFIER MULASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::MulAssign, $3); puts("AssignOpExpr(id,*=,expr)"); }
  | IDENTIFIER DIVASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::DivAssign, $3); puts("AssignOpExpr(id,/=,expr)"); }
  | IDENTIFIER ANDASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::AndAssign, $3); puts("AssignOpExpr(id,&&=,expr)"); }
  | IDENTIFIER ORASSIGN expr
        { $$ = new AssignOpExpr($1, Assignop::OrAssign, $3); puts("AssignOpExpr(id,||=,expr)"); }
  | expr PLUS expr
        { $$ = new BinOpExpr($1, Binop::Plus, $3); puts("BinOpExpr(expr,+,expr)"); }
  | expr MINUS expr
        { $$ = new BinOpExpr($1, Binop::Minus, $3); puts("BinOpExpr(expr,-,expr)"); }
  | expr MUL expr
        { $$ = new BinOpExpr($1, Binop::Times, $3); puts("BinOpExpr(expr,*,expr)"); }
  | expr DIV expr
        { $$ = new BinOpExpr($1, Binop::Div, $3); puts("BinOpExpr(expr,/,expr)"); }
  | expr GT expr
        { $$ = new BinOpExpr($1, Binop::Gt, $3); puts("BinOpExpr(expr,>,expr)"); }
  | expr GE expr
        { $$ = new BinOpExpr($1, Binop::Ge, $3); puts("BinOpExpr(expr,>=,expr)"); }
  | expr LT expr 
        { $$ = new BinOpExpr($1, Binop::Lt, $3); puts("BinOpExpr(expr,<,expr)"); }
  | expr LE expr
        { $$ = new BinOpExpr($1, Binop::Le, $3); puts("BinOpExpr(expr,<=,expr)"); }
  | expr EQ expr
        { $$ = new BinOpExpr($1, Binop::Eq, $3); puts("BinOpExpr(expr,==,expr)"); }
  | expr NE expr
        { $$ = new BinOpExpr($1, Binop::Ne, $3); puts("BinOpExpr(expr,!,expr)"); }
  | expr AND expr
        { $$ = new BinOpExpr($1, Binop::And, $3); puts("BinOpExpr(expr,&&,expr)"); }
  | expr OR expr
        { $$ = new BinOpExpr($1, Binop::Or, $3); puts("BinOpExpr(expr,||,expr)"); }
  | NOT expr
        { $$ = new NotExpr($2); puts("NotExpr(expr)"); }
  | literal
        { $$ = new LitExpr($1); puts("LitExpr(literal)"); }
  | IDENTIFIER
        { $$ = new IdExpr($1); puts("IdExpr(id)"); }
  | MINUS expr  %prec UMINUS
        { $$ = new MinExpr($2); puts("MinExpr(expr)"); }
  | IDENTIFIER LPAREN exprs RPAREN
        { $$ = new FunctionExpr($1, $3); puts("FunctionExpr(id,exprs)"); }
  | LPAREN expr RPAREN
        { $$ = $2; }
  | error
        { $$ = new ErrorExpr(); puts("ErrorExpr()"); }
;

literal : BOOLEAN
        { $$ = new Literal($1); puts("Literal(bool)"); }
  | INTEGER
        { $$ = new Literal($1); puts("Literal(int)"); }
;

exprs : /* empty */
        { $$ = new LastExprs(); puts("LastExpr()"); }
  | expr
        { $$ = new LastExprs($1); puts("LastExpr(expr)"); }
  | exprs COMMA expr
        { $$ = new PairExprs($1, $3); puts("LastExpr(exprs,expr)"); }
;

arglist : /* empty */
        { $$ = new LastArgList(); puts("LastArgList()"); }
  | IDENTIFIER
        { $$ = new LastArgList($1); puts("LastArgList(id)"); }
  | arglist COMMA IDENTIFIER
        { $$ = new PairArgList($1, $3); puts("LastArgList(arglist,id)"); }
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
  | SEMICOLON multnewline
  | multnewline
;

multnewline : NEWLINE
  | multnewline NEWLINE
;

optnewline : /* empty */
  | multnewline
;

%%

void yyerror (const char *s)
{
      puts(s); 
}
