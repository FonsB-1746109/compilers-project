#ifndef ABSYN_H
#define ABSYN_H

#include <string>
#include <vector>

using namespace std;

/* Struct pointer declarations */
struct Program_ {};
struct CompStmt_ {};
struct Stmt_ {};
struct Expr_ {};
struct Exprs_ {};
struct ArgList_{};

struct ElseIf_{}
struct Else_{}

/* Struct typedefs */
typedef Program_* Program;
typedef CompStmt_* CompStmt;
typedef Stmt_* Stmt;
typedef Expr_* Expr;
typedef Exprs_* Exprs;
typedef ArgList_* ArgList;

typedef ElseIf_* ElseIf;
typedef Else_* Else;

/* Assignment operations */
typedef enum {Assign, PlusAssign, MinAssign, MulAssign, DivAssign, AndAssign, OrAssign} Assingop;

/* Binairy operations */
typedef enum {Plus, Minus, Times, Div, Gt, Ge, Lt, Le, Eq, Ne, And, Or} Binop;


/* Statement structs */

struct UndefStmt : public Stmt_
{
    string identifier;
    UndefStmt(char* id);
}

struct DefStmt : public Stmt_
{
    string identifier;
    ArgList argList;
    CompStmt compStmt;
    DefStmt(char* id, ArgList argl, CompStmt comps);
}

struct ReturnStmt : public Stmt_
{
    Expr expr;
    ReturnStmt(Expr e);
}

struct IfStmt : public Stmt_
{
    Expr expr;
    CompStmt compStmt;
    ElseIf elseifs;
    Else else;

    IfStmt(Expr e, CompStmt comps, ElseIf eif, Else el);
}





#endif 