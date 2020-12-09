#ifndef ABSYN_H
#define ABSYN_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


/* Assignment operations */
typedef enum {Assign, PlusAssign, MinAssign, MulAssign, DivAssign, AndAssign, OrAssign} Assignop;

/* Binairy operations */
typedef enum {Plus, Minus, Times, Div, Gt, Ge, Lt, Le, Eq, Ne, And, Or} Binop;

/* Possible types */
typedef enum {Boolean, Integer, Function, ERROR} Types;


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

    bool equals(ReturnValue rv);
};


struct DefStmt; // forward declaration
struct Table
{   
    bool hasBackup;
    Table *backupTable;
    DefStmt *parentFunction;

    map<string, int>* tableMapInt;
    map<string, bool>* tableMapBool;
    map<string, DefStmt>* tableMapFunction;

    map<string, Types>* tableMapTypes;

    Table();
    
    /* NOT copy constructor, but "backup" table add
        If value isn't in this table, check backup table  
    */
    Table(Table *t, DefStmt *parent); 
    
    // Update for integers
    void update(string i, int v);

    // Update for booleans
    void update(string i, bool v);

    // Update for functions
    void update(string i, DefStmt v);

    Types getType(string i);

    int getInt(string i);
    bool getBool(string i);
    DefStmt getFunct(string i);

    void remove(string i);

private:
    void initTableVectors();
};


/* Struct pointer declarations */
struct Stmt_ 
{
    virtual void print() {};

    virtual void interp(Table *t) {};
    virtual ~Stmt_() {};
};

struct Expr_ 
{
    virtual void print() {};

    virtual ReturnValue interp(Table *t) { return ReturnValue(); };
    virtual ~Expr_() {};
};

struct Exprs_ 
{
    virtual void print() {};

    virtual int getLength() { return 0; }
    virtual vector<ReturnValue> interp(Table *t) { return std::vector<ReturnValue>(); };
    virtual ~Exprs_() {};
};

struct ArgList_
{
    virtual void print() {};

    virtual int getLength() { return 0; }
    virtual vector<string> interp(Table *t) { return std::vector<string>(); };
    virtual ~ArgList_() {};
};

/* forward decl types */
struct CompStmt_; typedef CompStmt_* CompStmt;

/* Struct typedefs */
typedef Stmt_* Stmt;
typedef Expr_* Expr;
typedef Exprs_* Exprs;
typedef ArgList_* ArgList;

struct Program_
{
    CompStmt compStmt;

    Program_(CompStmt comp);

    void print();
    void interp(Table *t);

    ~Program_() {};
};
typedef Program_* Program;

struct CompStmt_
{
    bool isArray;
    CompStmt compStmt;
    Stmt stmt;

    CompStmt_(Stmt s);
    CompStmt_(Stmt s, CompStmt comp);

    void print();
    void interp(Table *t);

    ~CompStmt_() {};
};


/* Statement structs */

struct PrintStmt : public Stmt_
{
    Expr expr;

    PrintStmt(Expr e);

    void print();
    void interp(Table* t);

    ~PrintStmt(){};
};

struct UndefStmt : public Stmt_
{
    string identifier;

    UndefStmt(char* id);
    
    void print();
    void interp(Table* t);

    ~UndefStmt(){};
};

struct DefStmt : public Stmt_
{   
    string identifier;
    ArgList argList;
    CompStmt compStmt;

    ReturnValue returnVal;

    // local table == glob + all locals
    Table* localTable;
    Table* globalTable;

    DefStmt(char* id, ArgList argl, CompStmt comps);

    void print();
    void interp(Table* t);
    ReturnValue run(Exprs exprs);
    void addReturnValue(ReturnValue rv);

    ~DefStmt(){};
};

struct ReturnStmt : public Stmt_
{
    Expr expr;

    ReturnStmt(Expr e);

    void print();
    void interp(Table *t);

    ~ReturnStmt(){};
};

/* If statement structs */
struct Elsif_;
typedef Elsif_* Elsif;
struct Elsif_
{
    bool isEmpty;
    Elsif elsifTail;
    Expr expr;
    CompStmt compStmt;

    Elsif_();
    Elsif_(Expr e, CompStmt comp, Elsif elif);

    void print();
    bool interp(Table *t);
    
    ~Elsif_() {};
};

struct Else_
{
    bool isEmpty;
    CompStmt compStmt;

    Else_();
    Else_(CompStmt comp);
    
    void print();
    void interp(Table *t);
    
    ~Else_() {};
};
typedef Else_* Else;

struct IfStmt : public Stmt_
{
    Expr expr;
    CompStmt compStmt;
    Elsif elsif;
    Else els;

    IfStmt() {};
    IfStmt(Expr e, CompStmt comp, Elsif eif, Else el);

    void print();
    void interp(Table *t);

    ~IfStmt() {};
};

struct UnlessStmt : public Stmt_
{
    Expr expr;
    CompStmt compStmt;
    Else els;

    UnlessStmt() {};
    UnlessStmt(Expr e, CompStmt comp, Else el);

    void print();
    void interp(Table* t);

    ~UnlessStmt(){};
};


struct WhileStmt : public Stmt_
{
    Expr expr;
    CompStmt compStmt;

    WhileStmt(Expr e, CompStmt comp);

    void print();
    void interp(Table* t);

    ~WhileStmt(){};
};

struct UntilStmt : public Stmt_
{
    Expr expr;
    CompStmt compStmt;

    UntilStmt(Expr e, CompStmt comp);

    void print();
    void interp(Table* t);

    ~UntilStmt(){};
};

struct When_;
typedef When_* When;
struct When_
{
    bool isEmpty;
    When whenTail;
    Expr expr;
    CompStmt compStmt;

    When_();
    When_(Expr e, CompStmt comp, When w);

    void print();
    bool interp(Table *t, Expr e);

    ~When_(){};
};

struct CaseStmt : public Stmt_
{
    Expr caseExpr;
    Expr whenExpr;
    CompStmt compStmt;
    When when;
    Else els;

    CaseStmt(){};
    CaseStmt(Expr ce, Expr we, CompStmt comp, When w, Else el);

    void print();
    void interp(Table* t);

    ~CaseStmt(){};
};

struct ExprStmt : public Stmt_
{
    Expr expr;

    ExprStmt(Expr e);

    void print();
    void interp(Table* t);

    ~ExprStmt(){};
};


/* Expression Structs */

struct AssignOpExpr : public Expr_
{
    string identifier;
    Assignop assignop;
    Expr expr;

    AssignOpExpr(char* id, Assignop assop, Expr e);

    void print();
    ReturnValue interp(Table* t);

    ~AssignOpExpr(){};
};

struct BinOpExpr : public Expr_
{
    Expr exprL, exprR;
    Binop binop;

    BinOpExpr(Expr eL, Binop bop, Expr eR);

    void print();
    ReturnValue interp(Table* t);

    ~BinOpExpr(){};
};

struct NotExpr : public Expr_
{
    Expr expr;

    NotExpr(Expr e);

    void print();
    ReturnValue interp(Table* t);

    ~NotExpr(){};
};

struct Literal_
{
    bool isInt;
    int intValue;
    bool boolValue;
    
    Literal_(int v);
    Literal_(bool v);

    void print();
    ReturnValue interp(Table* t);

    ~Literal_(){};
};
typedef Literal_* Literal;

struct LitExpr : public Expr_
{
    Literal lit;

    LitExpr(Literal l);

    void print();
    ReturnValue interp(Table* t);

    ~LitExpr(){};
};

struct IdExpr : public Expr_
{
    string identifier;

    IdExpr(char* id);

    void print();
    ReturnValue interp(Table* t);

    ~IdExpr(){};
};

struct MinExpr : public Expr_
{
    Expr expr;

    MinExpr(Expr e);

    void print();
    ReturnValue interp(Table* t);

    ~MinExpr(){};
};

struct FunctionExpr : public Expr_
{
    string identifier;
    Exprs exprs;

    FunctionExpr(char* id, Exprs e);

    void print();
    ReturnValue interp(Table* t);

    ~FunctionExpr(){};
};

struct ErrorExpr : public Expr_
{
    ErrorExpr();

    void print();
    ReturnValue interp(Table* t);

    ~ErrorExpr(){};
};



#endif 