#ifndef ABSYN_H
#define ABSYN_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


/* Assignment operations */
typedef enum {Assign, PlusAssign, MinAssign, MulAssign, DivAssign, AndAssign, OrAssign} Assingop;

/* Binairy operations */
typedef enum {Plus, Minus, Times, Div, Gt, Ge, Lt, Le, Eq, Ne, And, Or} Binop;

/* Possible types */
typedef enum {Boolean, Integer, Function} Types;


/* Struct for returning multiple types */
struct ReturnValue
{
    int integer;
    bool boolean;
    Types type;

    ReturnValue(); // for init purpose
    ReturnValue(int v);
    ReturnValue(bool v);
    
    Types getType();
    int getInt();
    bool getBool();
};


struct DefStmt; // forward declaration
struct Table
{
    map<string, int>* tableMapInt;
    map<string, bool>* tableMapBool;
    map<string, DefStmt>* tableMapFunction;

    map<string, Types>* tableMapTypes;

    Table();
    
    // Update for integers
    void update(string i, int v);

    // Update for booleans
    void update(string i, bool v);

    // Update for functions
    void update(string i, DefStmt v);

    int getInt(string i);
    bool getBool(string i);
    DefStmt getFunct(string i);

    void remove(string i);
};


/* Struct pointer declarations */
struct Stmt_ 
{
    virtual void interp(Table *t) {};
    virtual ~Stmt_() {};
};

struct Expr_ 
{
    virtual ReturnValue interp(Table *t) { return ReturnValue(); };
    virtual ~Expr_() {};
};

struct Exprs_ 
{
    virtual int getLength() { return 0; }
    virtual vector<ReturnValue> interp(Table *t) { return std::vector<ReturnValue>(); };
    virtual ~Exprs_() {};
};

struct ArgList_
{
    virtual int getLength() { return 0; }
    virtual vector<string> interp(Table *t) { return std::vector<string>(); };
    virtual ~ArgList_() {};
};

/* Struct typedefs */
typedef Stmt_* Stmt;
typedef Expr_* Expr;
typedef Exprs_* Exprs;
typedef ArgList_* ArgList;

struct Program_
{
    void interp(Table *t) { cout << "TEST"; };
    ~Program_() {};
};
typedef Program_* Program;

struct CompStmt_
{
    void interp(Table *t) {};
    ~CompStmt_() {};
};
typedef CompStmt_* CompStmt;


/* Statement structs */

struct UndefStmt : public Stmt_
{
    string identifier;
    UndefStmt(char* id);
    
    void interp(Table* t);

    ~UndefStmt(){};
};

struct DefStmt : public Stmt_
{   
    // ook locale table maken en OOK meegeven aan comstmt
    string identifier;
    ArgList argList;
    CompStmt compStmt;
    Table* localTable;
    Table* globalTable;

    DefStmt(char* id, ArgList argl, CompStmt comps);

    void interp(Table* t);
    void run(Exprs exprs);

    ~DefStmt(){};
};

struct ReturnStmt : public Stmt_
{
    Expr expr;
    ReturnStmt(Expr e);

    ~ReturnStmt(){};
};

/* If statement structs */
struct Elsif_
{
    Elsif_();

    void interp(Table *t) {};
    
    ~Elsif_() {};
};
typedef Elsif_* Elsif;

struct Else_
{
    Else_();
    
    void interp(Table *t) {};
    
    ~Else_() {};
};
typedef Else_* Else;

struct IfStmt : public Stmt_
{
    Expr expr;
    CompStmt compStmt;
    Elsif elsifs;
    Else els;

    IfStmt(Expr e, CompStmt comps, Elsif eif, Else el);
};



#endif 