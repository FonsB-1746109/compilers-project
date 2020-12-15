#ifndef ABSYN_H
#define ABSYN_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

/* Assignment operations */
typedef enum
{
    Assign,
    PlusAssign,
    MinAssign,
    MulAssign,
    DivAssign,
    AndAssign,
    OrAssign
} Assignop;

/* Binairy operations */
typedef enum
{
    Plus,
    Minus,
    Times,
    Div,
    Gt,
    Ge,
    Lt,
    Le,
    Eq,
    Ne,
    And,
    Or
} Binop;

/* Possible types */
typedef enum
{
    Boolean,
    Integer,
    Function,
    ERROR
} Types;

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

    map<string, int> *tableMapInt;
    map<string, bool> *tableMapBool;
    map<string, DefStmt*> *tableMapFunction;

    map<string, Types> *tableMapTypes;

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
    void update(string i, DefStmt *v);

    Types getType(string i);

    int getInt(string i);
    bool getBool(string i);
    DefStmt* getFunct(string i);

    void print();

    void remove(string i);

private:
    void initTableVectors();
};

/* Struct pointer declarations */
struct Stmt_
{
    virtual void print(){};

    virtual void interp(Table *t){};
    virtual ~Stmt_(){};
};

struct Expr_
{
    virtual void print(){};

    virtual ReturnValue interp(Table *t) { return ReturnValue(); };
    virtual ~Expr_(){};
};

struct Exprs_
{
    virtual void print(){};

    virtual int getLength() { return 0; }
    virtual vector<ReturnValue> interp(Table *t) { return std::vector<ReturnValue>(); };
    virtual ~Exprs_(){};
};

struct ArgList_
{
    virtual void print(){};

    virtual int getLength() { return 0; }
    virtual vector<string> interp(Table *t) { return std::vector<string>(); };
    virtual ~ArgList_(){};
};


/* forward decl types */
struct CompStmt;

/* Struct typedefs */
typedef Stmt_ *Stmt;
typedef Expr_ *Expr;
typedef Exprs_ *Exprs;
typedef ArgList_ *ArgList;

struct Program
{
    CompStmt *compStmt;

    Program() {};
    Program(CompStmt *comp);

    void print();
    void interp(Table *t);

    ~Program(){};
};

struct CompStmt
{
    bool isArray;
    CompStmt *compStmt;
    Stmt stmt;

    CompStmt(Stmt s);
    CompStmt(Stmt s, CompStmt *comp);

    void print();
    void interp(Table *t);

    ~CompStmt(){};
};

/* Statement structs */

struct PrintStmt : public Stmt_
{
    Expr expr;

    PrintStmt(Expr e);

    void print();
    void interp(Table *t);

    ~PrintStmt(){};
};

struct UndefStmt : public Stmt_
{
    string identifier;

    UndefStmt(char *id);

    void print();
    void interp(Table *t);

    ~UndefStmt(){};
};

struct DefStmt : public Stmt_
{
    string identifier;
    ArgList argList;
    CompStmt *compStmt;

    ReturnValue returnVal;

    // local table == glob + all locals
    Table *localTable;
    Table *globalTable;

    DefStmt(char *id, ArgList argl, CompStmt *comps);

    void print();
    void interp(Table *t);
    ReturnValue run(Exprs exprs, Table *argTable);
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
struct Elsif
{
    bool isEmpty;
    Elsif *elsifTail;
    Expr expr;
    CompStmt *compStmt;

    Elsif();
    Elsif(Expr e, CompStmt *comp, Elsif *elif);

    void print();
    bool interp(Table *t);

    ~Elsif(){};
};

struct Else
{
    bool isEmpty;
    CompStmt *compStmt;

    Else();
    Else(CompStmt *comp);

    void print();
    void interp(Table *t);

    ~Else(){};
};

struct IfStmt : public Stmt_
{
    Expr expr;
    CompStmt *compStmt;
    Elsif *elsif;
    Else *els;

    IfStmt(){};
    IfStmt(Expr e, CompStmt *comp, Elsif *eif, Else *el);

    void print();
    void interp(Table *t);

    ~IfStmt(){};
};

struct UnlessStmt : public Stmt_
{
    Expr expr;
    CompStmt *compStmt;
    Else *els;

    UnlessStmt(){};
    UnlessStmt(Expr e, CompStmt *comp, Else *el);

    void print();
    void interp(Table *t);

    ~UnlessStmt(){};
};

struct WhileStmt : public Stmt_
{
    Expr expr;
    CompStmt *compStmt;

    WhileStmt(Expr e, CompStmt *comp);

    void print();
    void interp(Table *t);

    ~WhileStmt(){};
};

struct UntilStmt : public Stmt_
{
    Expr expr;
    CompStmt *compStmt;

    UntilStmt(Expr e, CompStmt *comp);

    void print();
    void interp(Table *t);

    ~UntilStmt(){};
};

struct When
{
    bool isEmpty;
    When *whenTail;
    Expr expr;
    CompStmt *compStmt;

    When();
    When(Expr e, CompStmt *comp, When *w);

    void print();
    bool interp(Table *t, Expr e);

    ~When(){};
};

struct CaseStmt : public Stmt_
{
    Expr caseExpr;
    Expr whenExpr;
    CompStmt *compStmt;
    When *when;
    Else *els;

    CaseStmt(){};
    CaseStmt(Expr ce, Expr we, CompStmt *comp, When *w, Else *el);

    void print();
    void interp(Table *t);

    ~CaseStmt(){};
};

struct ExprStmt : public Stmt_
{
    Expr expr;

    ExprStmt(Expr e);

    void print();
    void interp(Table *t);

    ~ExprStmt(){};
};

/* Expression Structs */

struct AssignOpExpr : public Expr_
{
    string identifier;
    Assignop assignop;
    Expr expr;

    AssignOpExpr(char *id, Assignop assop, Expr e);

    void print();
    ReturnValue interp(Table *t);

    ~AssignOpExpr(){};
};

struct BinOpExpr : public Expr_
{
    Expr exprL, exprR;
    Binop binop;

    BinOpExpr(Expr eL, Binop bop, Expr eR);

    void print();
    ReturnValue interp(Table *t);

    ~BinOpExpr(){};
};

struct NotExpr : public Expr_
{
    Expr expr;

    NotExpr(Expr e);

    void print();
    ReturnValue interp(Table *t);

    ~NotExpr(){};
};

struct Literal
{
    bool isInt;
    int intValue;
    bool boolValue;

    Literal(int v);
    Literal(bool v);

    void print();
    ReturnValue interp(Table *t);

    ~Literal(){};
};

struct LitExpr : public Expr_
{
    Literal *lit;

    LitExpr(Literal *l);

    void print();
    ReturnValue interp(Table *t);

    ~LitExpr(){};
};

struct IdExpr : public Expr_
{
    string identifier;

    IdExpr(char *id);

    void print();
    ReturnValue interp(Table *t);

    ~IdExpr(){};
};

struct MinExpr : public Expr_
{
    Expr expr;

    MinExpr(Expr e);

    void print();
    ReturnValue interp(Table *t);

    ~MinExpr(){};
};

struct FunctionExpr : public Expr_
{
    string identifier;
    Exprs exprs;

    FunctionExpr(char *id, Exprs e);

    void print();
    ReturnValue interp(Table *t);

    ~FunctionExpr(){};
};

struct ErrorExpr : public Expr_
{
    ErrorExpr();

    void print();
    ReturnValue interp(Table *t);

    ~ErrorExpr(){};
};

struct LastExprs : public Exprs_
{
    bool isEmpty;
    Expr expr;
    
    LastExprs();
    LastExprs(Expr e);

    void print();
    int getLength();
    vector<ReturnValue> interp(Table *t);

    ~LastExprs(){};
};

struct PairExprs : public Exprs_
{
    Expr expr;
    Exprs exprs;   

    PairExprs(Exprs exs, Expr e);

    void print();
    int getLength();
    vector<ReturnValue> interp(Table *t);

    ~PairExprs(){};
};

struct LastArgList : public ArgList_
{
    bool isEmpty;
    string identifier;
    
    LastArgList();
    LastArgList(char* id);
    
    void print();
    int getLength();
    vector<string> interp(Table *t);

    ~LastArgList(){};
};

struct PairArgList : public ArgList_
{
    string identifier;
    ArgList argList;
    
    PairArgList(ArgList al, char* id);

    void print();
    int getLength();
    vector<string> interp(Table *t);

    ~PairArgList(){};
};

#include "absyn.cpp"

#endif

//======================================================================
// CPP FILE TEST

