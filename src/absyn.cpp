#include "absyn.h"

#include <iostream>


/* ReturnValue functions */

ReturnValue::ReturnValue()
    :hasID{false}
{
    type = Types::ERROR;  // garbage
}

ReturnValue::ReturnValue(int v)
    :integer{v}, type{Types::Integer}, hasID{false}
{}

ReturnValue::ReturnValue(int v, string id)
    :integer{v}, type{Types::Integer}, varID{id}, hasID{true}
{}

ReturnValue::ReturnValue(bool v)
    :boolean{v}, type{Types::Boolean}, hasID{false}
{}

ReturnValue::ReturnValue(bool v, string id)
    :boolean{v}, type{Types::Boolean}, varID{id}, hasID{true}
{}

Types ReturnValue::getType()
{
    return type;
}

int ReturnValue::getInt()
{
    if (type != Types::Integer){
        cout << "[ RuntimeError ] ";
        if (hasID)
            cout << "Variable " << varID;
        else
            cout << "Value";
        cout << " is not an integer but integer needed..." << endl;
        exit(-1);
    }
        
    return integer;
}

bool ReturnValue::getBool()
{
    if (type != Types::Boolean){
        cout << "[ RuntimeError ] ";
        if (hasID)
            cout << "Variable '" << varID << "'";
        else
            cout << "Value";
        cout << " is not a boolean but boolean needed..." << endl;
        exit(-1);
    }

    return boolean;
}

string ReturnValue::getID()
{
    if (hasID)
        return varID;

    return "";
}


bool ReturnValue::equals(ReturnValue rv)
{
    if (type != rv.type)
        return false;
    
    switch (type)
    {
    case Types::Integer:
        return integer == rv.integer;
        break;
    case Types::Boolean:
        return boolean == rv.boolean;
        break;
    default:
        return false;
        break;
    }
}

void ReturnValue::print()
{
    switch (type)
    {
    case Types::Integer:
        cout << integer << endl;
        break;
    case Types::Boolean:
        cout << boolean << endl;
        break;
    default:
        break;
    }
}

/* Table functions */

Table::Table()
    :hasBackup{false}
{
    initTableVectors();
}

Table::~Table()
{
    free(tableMapInt);
    free(tableMapBool);
    free(tableMapFunction);
    free(tableMapTypes);
}

Table::Table(Table *t, DefStmt *parent)
    :hasBackup{true}, backupTable(t), parentFunction{parent}
{
    initTableVectors();
}

void Table::initTableVectors()
{
    tableMapInt = new map<string, int>; 
    tableMapBool = new map<string, bool>; 
    tableMapFunction = new map<string, DefStmt*>; 

    tableMapTypes = new map<string, Types>; 
}

void Table::update(string i, int v) 
{
    auto it = tableMapTypes->find(i);
    if (it != tableMapTypes->end())
        removeVariable(i);
    
    tableMapInt->insert(pair<string, int>(i, v));
    tableMapTypes->insert(pair<string, Types>(i, Types::Integer));       
};

void Table::update(string i, bool v) 
{   
    auto it = tableMapTypes->find(i);
    if (it != tableMapTypes->end())
        removeVariable(i);
    
    tableMapBool->insert(pair<string, bool>(i, v));
    tableMapTypes->insert(pair<string, Types>(i, Types::Boolean)); 
};

void Table::update(string i, DefStmt *v)
{
    auto it = tableMapFunction->find(i);
    if (it != tableMapFunction->end()){
        auto iter = tableMapFunction->find(i);
        iter->second = v;
    } else {
        tableMapFunction->insert(pair<string, DefStmt*>(i, v));
    }   
}

// Returns ERROR if not in table
Types Table::getType(string i)
{
    auto it = tableMapTypes->find(i);
    if (it != tableMapTypes->end())
        return it->second;
    else
        return Types::ERROR; // not in table
}

int Table::getInt(string i)
{
    auto it = tableMapInt->find(i);
    if (it != tableMapInt->end())
        return tableMapInt->find(i)->second;
        
    if (hasBackup)
        return backupTable->getInt(i);
    
    cout << "[ RuntimeError ] Variable '" << i << "' not defined or not declared as integer..." << endl;
    exit(-1);    
}

bool Table::getBool(string i)
{
    auto it = tableMapBool->find(i);
    if (it != tableMapBool->end())
        return tableMapBool->find(i)->second;
    
    if (hasBackup)
        return backupTable->getBool(i);

    cout << "[ RuntimeError ] Variable '" << i << "' not defined or not declared as boolean..." << endl;
    exit(-1);

}

DefStmt* Table::getFunct(string i)
{
    auto it = tableMapFunction->find(i);
    if (it != tableMapFunction->end())
        return tableMapFunction->find(i)->second;

    if (hasBackup)
        return backupTable->getFunct(i);

    cout << "[ RuntimeError ] Function '" << i << "' not defined..." << endl;
    exit(-1);
}

void Table::print()
{
    cout << "[tableMapTypes] " << endl;
    for(auto it = tableMapTypes->cbegin(); it != tableMapTypes->cend(); ++it)
        cout << "\t" << it->first << endl;

    cout << "[tableMapInt] " << endl;
    for(auto it = tableMapInt->cbegin(); it != tableMapInt->cend(); ++it)
        cout << "\t" << it->first << endl;

    cout << "[tableMapBool] " << endl;
    for(auto it = tableMapBool->cbegin(); it != tableMapBool->cend(); ++it)
        cout << "\t" << it->first << endl;

    cout << "[tableMapFunction] " << endl;
    for(auto it = tableMapFunction->cbegin(); it != tableMapFunction->cend(); ++it)
        cout << "\t" << it->first << endl;
}

void Table::removeVariable(string i)
{
    tableMapTypes->erase(i);
    tableMapInt->erase(i);
    tableMapBool->erase(i);
}

void Table::removeFunction(string i)
{
    tableMapFunction->erase(i);
}


/* Statement structs */

Program::Program(CompStmt *comp)
    : compStmt{comp}
{}

void Program::print()
{
    cout << "Program(" << endl << "\t";
    compStmt->print();
    cout << ")" << endl;
}

void Program::interp(Table *t)
{
    compStmt->interp(t);
}

Program::~Program()
{
    free(compStmt);
}


CompStmt::CompStmt(Stmt s)
    :isArray(false), stmt{s}
{}

CompStmt::CompStmt(Stmt s, CompStmt *comp)
    :isArray{true}, compStmt{comp}, stmt{s}
{}

void CompStmt::print()
{
    cout << "CompStmt(" << endl << "\t";
    stmt->print();
    if (isArray){
        cout << ",";
        compStmt->print();
    }
    cout << ")" << endl;
}

bool CompStmt::interp(Table *t)
{
    if (stmt->interp(t))
        return true;

    if (isArray)
        return compStmt->interp(t);

    return false;
}

CompStmt::~CompStmt()
{
    free(stmt);
    if (isArray)
        free(compStmt);
}


UndefStmt::UndefStmt(char* id)
    :identifier{id}
{
    free(id);
}

void UndefStmt::print()
{
    cout << "UNDEF( " << identifier << " )" << endl;
}

bool UndefStmt::interp(Table* t)
{
    // Check if name is not an predefined function
    if (std::find(PREDEFINEDFUNTIONS.begin(), PREDEFINEDFUNTIONS.end(), identifier) != PREDEFINEDFUNTIONS.end()){
        cout << "[ RuntimeError ] Cannot undefine '" << identifier << "' method..." << endl;
        exit(-1);
    }

    t->removeFunction(identifier);
    return false;
}


DefStmt::DefStmt(char* id, ArgList argl, CompStmt *comps)
    :identifier{id}, argList{argl}, compStmt{comps}
{
    free(id);
}

void DefStmt::print()
{
    cout << "DefStmt(id=" << identifier  << ", " << endl << "\t";
    argList->print();
    cout << "," << endl;
    compStmt->print();
    cout << ")" << endl;
}

bool DefStmt::interp(Table* t)
{
    // Check if name is not an predefined function
    if (std::find(PREDEFINEDFUNTIONS.begin(), PREDEFINEDFUNTIONS.end(), identifier) != PREDEFINEDFUNTIONS.end()){
        cout << "[ RuntimeError ] Cannot override '" << identifier << "' method..." << endl;
        exit(-1);
    }
    
    
    t->update(identifier, this);
    
    globalTable = t;

    // Local table has the global as backup
    localTable = new Table(t, this);

    return false;
}

ReturnValue DefStmt::run(Exprs exprs, Table *argTable)
{
    // check arg list length
    int len = exprs->getLength();
    if (len != argList->getLength()){
        cout << "[ RuntimeError ] Function '" << identifier << "' called with wrong amount of args... " << endl;
        exit(-1);
    }

    // Insert exprs in local table
    vector<string> argl = argList->interp(globalTable);
    vector<ReturnValue> expl = exprs->interp(argTable);
    for (int i = 0; i < len; i++){
        Types returnType = expl[i].getType();
        switch (returnType)
        {
        case Types::Integer:
            localTable->update(argl[i], expl[i].getInt());
            break;
        case Types::Boolean:
            localTable->update(argl[i], expl[i].getBool());
            break;
        default:
            break;
        }
    }

    compStmt->interp(localTable);  

    return returnVal;
}

void DefStmt::addReturnValue(ReturnValue rv)
{
    returnVal = rv;

}

DefStmt::~DefStmt()
{
    free(argList);
    free(compStmt);
}


ReturnStmt::ReturnStmt(Expr e)
    :expr{e}
{}

void ReturnStmt::print()
{
    cout << "ReturnStmt(" << endl << "\t";
    expr->print();
    cout << ")" << endl;
}

bool ReturnStmt::interp(Table *t)
{
    if (!t->hasBackup){
        cout << "[ ReturnStmt ] Cannot return outside a function..." << endl;
        exit(-1); 
    }
    t->parentFunction->addReturnValue(expr->interp(t));

    return true;
}

ReturnStmt::~ReturnStmt()
{
    free(expr);
}


Elsif::Elsif()
    :isEmpty(true)
{}

Elsif::Elsif(Expr e, CompStmt *comp, Elsif *elif)
    :isEmpty{false}, expr{e}, compStmt{comp}, elsifTail{elif}
{}

void Elsif::print()
{
    if (isEmpty){
        cout << "Elsif()" << endl;
        return;
    }
        
    cout << "Elsif(" << endl << "\t";
    expr->print();
    cout << "," << endl;
    compStmt->print();
    cout << "," << endl;
    elsifTail->print();
    cout << ")" << endl;
}

ReturnInfo Elsif::interp(Table *t)
{
    ReturnInfo ri;

    if (isEmpty)
        return ri;

    ReturnValue rv = expr->interp(t);

    if (rv.getBool()){
        ri.hasReturned = compStmt->interp(t);
        ri.isMatched = true;
        return ri;
    } else {
        return elsifTail->interp(t);
    }
}

Elsif::~Elsif()
{
    if(!isEmpty){
        free(expr);
        free(compStmt);
        free(elsifTail);
    }
}


Else::Else()
    :isEmpty{true}
{}

Else::Else(CompStmt *comp)
    :isEmpty{false}, compStmt{comp}
{}

void Else::print()
{
    cout << "Else(";
    if (!isEmpty){
        cout << endl << "\t";
        compStmt->print();
    }
    cout << ")" << endl;
}

bool Else::interp(Table *t)
{
    if (!isEmpty)
        return compStmt->interp(t);
    
    return false;
}

Else::~Else()
{
    if(!isEmpty)
        free(compStmt);
}


IfStmt::IfStmt(Expr e, CompStmt *comp, Elsif *eif, Else *el)
    :expr{e}, compStmt{comp}, elsif{eif}, els{el}
{}

void IfStmt::print()
{
    cout << "IfStmt(" << endl << "\t";
    expr->print();
    cout << "," << endl;
    compStmt->print();
    cout << "," << endl;
    elsif->print();
    cout << "," << endl;
    els->print();
    cout << ")" << endl;
}

bool IfStmt::interp(Table *t)
{
    ReturnValue rv = expr->interp(t);

    if (rv.getBool())
        return compStmt->interp(t);
    else {
        ReturnInfo ri = elsif->interp(t);
        if (!ri.isMatched){ // elsif->interp(t) returns returninfo for matchcheck and return check
            return els->interp(t);
        }
        return ri.hasReturned;
    }
}

IfStmt::~IfStmt()
{
    free(expr);
    free(compStmt);
    free(elsif);
    free(els);
}


UnlessStmt::UnlessStmt(Expr e, CompStmt *comp, Else *el)
    :expr{e}, compStmt{comp}, els{el}
{}

void UnlessStmt::print()
{
    cout << "UnlessStmt(" << endl << "\t";
    expr->print();
    cout << "," << endl;
    compStmt->print();
    cout << "," << endl;
    els->print();
    cout << ")" << endl;
}

bool UnlessStmt::interp(Table *t)
{
    ReturnValue rv = expr->interp(t);

    if (!rv.getBool())
        return compStmt->interp(t);
    else {
        return els->interp(t);
    }
}

UnlessStmt::~UnlessStmt()
{
    free(expr);
    free(compStmt);
    free(els);
}

WhileStmt::WhileStmt(Expr e, CompStmt *comp)
    :expr{e}, compStmt{comp}
{}

void WhileStmt::print()
{
    cout << "WhileStmt(" << endl << "\t";
    expr->print();
    cout << "," << endl;
    compStmt->print();
    cout << ")" << endl;
}

bool WhileStmt::interp(Table *t)
{
    ReturnValue rv = expr->interp(t);


    while (rv.getBool())
    {
        if (compStmt->interp(t))
            return true;

        rv = expr->interp(t);
    }
    return false;
}

WhileStmt::~WhileStmt()
{
    free(expr);
    free(compStmt);
}


UntilStmt::UntilStmt(Expr e, CompStmt *comp)
    :expr{e}, compStmt{comp}
{}

void UntilStmt::print()
{
    cout << "UntillStmt(" << endl << "\t";
    expr->print();
    cout << "," << endl;
    compStmt->print();
    cout << ")" << endl;
}

bool UntilStmt::interp(Table *t)
{
    ReturnValue rv = expr->interp(t);

    while (!rv.getBool())
    {
        if (compStmt->interp(t))
            return true;

        rv = expr->interp(t);
    }
    return false;
}

UntilStmt::~UntilStmt()
{
    free(expr);
    free(compStmt);
}


When::When()
    :isEmpty{true}
{}

When::When(Expr e, CompStmt *comp, When *w)
    :isEmpty{false}, expr{e}, compStmt{comp}, whenTail{w}
{}

void When::print()
{
    if (isEmpty){
        cout << "When()" << endl;
        return;
    }

    cout << "When(" << endl << "\t";
    expr->print();
    cout << "," << endl;
    compStmt->print();
    cout << "," << endl;
    whenTail->print();
    cout << ")" << endl;
}

ReturnInfo When::interp(Table *t, Expr e)
{
    ReturnInfo ri;

    if (isEmpty)
        return ri;
    
    ReturnValue rvCase = e->interp(t);
    ReturnValue rvWhen = expr->interp(t);

    if (rvCase.equals(rvWhen)){
        ri.hasReturned = compStmt->interp(t);
        ri.isMatched = true;
        return ri;
    } else
        return whenTail->interp(t, e);    
}

When::~When()
{
    if (!isEmpty){
        free(whenTail);
        free(expr);
        free(compStmt);
    }
}


CaseStmt::CaseStmt(Expr ce, Expr we, CompStmt *comp, When *w, Else *el)
    :caseExpr{ce}, whenExpr{we}, compStmt{comp}, when{w}, els{el}
{}

void CaseStmt::print()
{
    cout << "CaseStmt(" << endl << "\t";
    caseExpr->print();
    cout << "," << endl;
    whenExpr->print();
    cout << "," << endl;
    compStmt->print();
    cout << "," << endl;
    when->print();
    cout << "," << endl;
    els->print();
    cout << ")" << endl;
}

bool CaseStmt::interp(Table *t)
{
    ReturnValue rvCase = caseExpr->interp(t);
    ReturnValue rvWhen = whenExpr->interp(t);

    if (rvCase.equals(rvWhen)){
        return compStmt->interp(t);
    } else {
        ReturnInfo ri = when->interp(t, caseExpr);
        if (!ri.isMatched)
            return els->interp(t);
        return ri.hasReturned;
    }
}

CaseStmt::~CaseStmt()
{
    free(caseExpr);
    free(whenExpr);
    free(compStmt);
    free(when);
    free(els);
}

ExprStmt::ExprStmt(Expr e)
    :expr{e}
{}

void ExprStmt::print()
{
    cout << "ExprStmt(" << endl << "\t";
    expr->print();
    cout << ")" << endl;
}

bool ExprStmt::interp(Table *t)
{
    expr->interp(t);
    return false;
}

ExprStmt::~ExprStmt()
{
    free(expr);
}


/* Expression structs */

AssignOpExpr::AssignOpExpr(char* id, Assignop assop, Expr e)
    :identifier{id}, assignop{assop}, expr{e}
{
    free(id);
}

void AssignOpExpr::print()
{
    cout << "AssignOpExpr(id=" << identifier << ", [assignop]," << endl << "\t";
    expr->print();
    cout << ")" << endl;
}

ReturnValue AssignOpExpr::interp(Table* t)
{
    ReturnValue rv = expr->interp(t);

    switch (assignop)
    {
    case Assignop::Assign:
        if (rv.getType() == Types::Integer){
            int val = rv.getInt();
            t->update(identifier, val);
            return ReturnValue(val);
        } else {
            bool val = rv.getBool();
            t->update(identifier, val);
            return ReturnValue(val);
        }
            
        break;

    case Assignop::PlusAssign:
    case Assignop::MinAssign:
    case Assignop::MulAssign:
    case Assignop::DivAssign:
    {
        int idvInt = t->getInt(identifier);

        int resultInt;
        switch (assignop)
        {
        case Assignop::PlusAssign:
            resultInt = idvInt + rv.getInt();
            break;
        case Assignop::MinAssign:
            resultInt = idvInt - rv.getInt();
            break;
        case Assignop::MulAssign:
            resultInt = idvInt * rv.getInt();
            break;
        case Assignop::DivAssign:
            if (rv.getInt() == 0){
                cout << "[ RuntimeError ] Division by zero.." << endl;
                exit(-1);
            }
            resultInt = idvInt / rv.getInt();
            break;
        default:
            break;
        }

        t->update(identifier, resultInt);

        return ReturnValue(resultInt);
        break;
    }
    case Assignop::AndAssign:
    case Assignop::OrAssign:
    {
        bool idvBool = t->getBool(identifier);

        bool resultBool;
        switch (assignop)
        {
        case Assignop::AndAssign:
            resultBool = (idvBool && rv.getBool());
            break;
        case Assignop::OrAssign:
            resultBool = (idvBool || rv.getBool());
            break;
        default:
            break;
        }

        t->update(identifier, resultBool);

        return ReturnValue(resultBool);
        break;
    }
    default:
        break;
    }
}

AssignOpExpr::~AssignOpExpr()
{
    free(expr);
}


BinOpExpr::BinOpExpr(Expr eL, Binop bop, Expr eR)
    :exprL{eL}, binop{bop}, exprR{eR}
{}

void BinOpExpr::print()
{
    cout << "BinOpExpr(" << endl << "\t";
    exprL->print();
    cout << ", [assignop]," << endl;
    exprR->print();
    cout << ")" << endl;
}

ReturnValue BinOpExpr::interp(Table *t)
{
    ReturnValue rvL = exprL->interp(t);
    ReturnValue rvR = exprR->interp(t);

    switch (binop)
    {
    case Binop::Plus:
        return ReturnValue(rvL.getInt() + rvR.getInt());
        break;
    case Binop::Minus:
        return ReturnValue(rvL.getInt() - rvR.getInt());
        break;
    case Binop::Times:
        return ReturnValue(rvL.getInt() * rvR.getInt());
        break;
    case Binop::Div:
        if (rvR.getInt() == 0){
            cout << "[ RuntimeError ] Division by zero.." << endl;
            exit(-1);
        }
        return ReturnValue(rvL.getInt() / rvR.getInt());
        break;
    case Binop::Gt:
        return ReturnValue(rvL.getInt() > rvR.getInt());
        break;
    case Binop::Ge:
        return ReturnValue(rvL.getInt() >= rvR.getInt());
        break;
    case Binop::Lt:
        return ReturnValue(rvL.getInt() < rvR.getInt());
        break;
    case Binop::Le:
        return ReturnValue(rvL.getInt() <= rvR.getInt());
        break;    
    case Binop::Eq:
        return ReturnValue(rvL.equals(rvR));
        break;
    case Binop::Ne:
        return ReturnValue(!rvL.equals(rvR));
        break;
    case Binop::And:
        return ReturnValue(rvL.getBool() && rvR.getBool());
        break; 
    case Binop::Or:
        return ReturnValue(rvL.getBool() || rvR.getBool());
        break; 
    default:
        break;
    }
}

BinOpExpr::~BinOpExpr()
{
    free(exprL);
    free(exprR);
}


NotExpr::NotExpr(Expr e)
    :expr{e}
{}

void NotExpr::print()
{
    cout << "NotExpr(" << endl << "\t";
    expr->print();
    cout << ")" << endl;
}

ReturnValue NotExpr::interp(Table *t)
{
    return ReturnValue(!expr->interp(t).getBool());
}

NotExpr::~NotExpr()
{
    free(expr);
}


Literal::Literal(int v)
    :isInt{true}, intValue{v}
{}

Literal::Literal(bool v)
    :isInt{false}, boolValue{v}
{}

void Literal::print()
{   
    if (isInt)
        cout << "Literal(" << intValue << ")" << endl;
    else 
        cout << "Literal(" << boolValue << ")" << endl;
}

ReturnValue Literal::interp(Table *t)
{
    if (isInt)
        return ReturnValue(intValue);
    else 
        return ReturnValue(boolValue);
}


LitExpr::LitExpr(Literal *l)
    :lit{l}
{}

void LitExpr::print()
{   
    cout << "LitExpr(" << endl << "\t";
    lit->print();
    cout << ")" << endl;
}

ReturnValue LitExpr::interp(Table *t)
{
    return lit->interp(t);
}

LitExpr::~LitExpr()
{
    free(lit);
}


IdExpr::IdExpr(char* id)
    :identifier{id}
{
    free(id);
}

void IdExpr::print()
{   
    cout << "IdExpr( " << identifier << " )" << endl;
}

ReturnValue IdExpr::interp(Table *t)
{
    Types type = t->getType(identifier);

    switch (type)
    {
    case Types::Integer:
        return ReturnValue(t->getInt(identifier));
        break;
    case Types::Boolean:
        return ReturnValue(t->getBool(identifier));
        break;
    default:
        cout << "[ RuntimeError ] Variable '" << identifier << "' not defined.." << endl;
        exit(-1);
        break;
    }
}


MinExpr::MinExpr(Expr e)
    :expr{e}
{}

void MinExpr::print()
{
    cout << "MinExpr(" << endl << "\t";
    expr->print();
    cout << ")" << endl;
}

ReturnValue MinExpr::interp(Table *t)
{
    return ReturnValue(expr->interp(t).getInt() * (-1));
}

MinExpr::~MinExpr()
{
    free(expr);
}


FunctionExpr::FunctionExpr(char* id, Exprs e)
    :identifier{id}, exprs{e}
{
    free(id);
}

void FunctionExpr::print()
{
    cout << "FunctionExpr(" << identifier << "," << endl << "\t";
    exprs->print();
    cout << ")" << endl;
}

ReturnValue FunctionExpr::interp(Table *t)
{   
    // Check if name is not an predefined function
    if (std::find(PREDEFINEDFUNTIONS.begin(), PREDEFINEDFUNTIONS.end(), identifier) == PREDEFINEDFUNTIONS.end()){
        // Search in table
        DefStmt *f = t->getFunct(identifier);
        return f->run(exprs, t);
    }

    // Call predefined function
    if (identifier == "print"){
        PrintFunction pf;
        pf.interp(t, exprs);

        return ReturnValue();
    }
    
    return ReturnValue();
    
}

FunctionExpr::~FunctionExpr()
{
    free(exprs);
}


ErrorExpr::ErrorExpr()
{}

void ErrorExpr::print()
{
    cout << "ErrorExpr()" << endl;
}

ReturnValue ErrorExpr::interp(Table *t)
{
    return ReturnValue();
}


LastExprs::LastExprs()
    :isEmpty{true}
{}

LastExprs::LastExprs(Expr e)
    :isEmpty{false}, expr{e}
{}

void LastExprs::print()
{
    if (isEmpty){
        cout << "LastExprs()" << endl;
        return;
    }
    
    cout << "LastExprs(" << endl << "\t";
    expr->print();
    cout << ")" << endl;
}

int LastExprs::getLength()
{
    if (isEmpty)
        return 0;
    else
        return 1;
}

vector<ReturnValue> LastExprs::interp(Table *t)
{
    vector<ReturnValue> values;
    if (!isEmpty)
        values.push_back(expr->interp(t));

    return values;
}

LastExprs::~LastExprs()
{
    if (!isEmpty)
        free(expr);
}


PairExprs::PairExprs(Exprs exs, Expr e)
    :exprs{exs}, expr{e}
{}

void PairExprs::print()
{
    cout << "PairExprs(" << endl << "\t";
    exprs->print();
    cout << "," << endl;
    expr->print();
    cout << ")" << endl;
}   

int PairExprs::getLength()
{
    return exprs->getLength() + 1;
}

vector<ReturnValue> PairExprs::interp(Table *t)
{
    vector<ReturnValue> values = exprs->interp(t);
    values.push_back(expr->interp(t));

    return values;
}

PairExprs::~PairExprs()
{
    free(expr);
    free(exprs);
}


LastArgList::LastArgList()
    :isEmpty{true}
{}

LastArgList::LastArgList(char* id)
    :identifier{id}, isEmpty{false}
{
    free(id);
}

void LastArgList::print()
{
    if (isEmpty){
        cout << "LastArgList()" << endl;
        return;
    }
    
    cout << "LastArgList( \"" << identifier << "\" )" << endl;
}

int LastArgList::getLength()
{
    if (isEmpty)
        return 0;
    else
        return 1;
}

vector<string> LastArgList::interp(Table *t)
{
    vector<string> ids;
    if (!isEmpty)
        ids.push_back(identifier);
    
    return ids;
}


PairArgList::PairArgList(ArgList al, char* id)
    :argList{al}, identifier{id}
{
    free(id);
}

void PairArgList::print()
{
    cout << "PairArgList(" << endl << "\t";
    argList->print();
    cout << ", \"" << identifier << "\" )" << endl;
}

int PairArgList::getLength()
{
    return argList->getLength() + 1;
}

vector<string> PairArgList::interp(Table *t)
{
    vector<string> ids = argList->interp(t);

    ids.push_back(identifier);

    return ids;
}

PairArgList::~PairArgList()
{
    free(argList);
}

/* Predefined functions */

void PrintFunction::interp(Table *t, Exprs e)
{
    //check length
    if (e->getLength() != 1){
        cout << "[ RuntimeError ] Funtion 'print' called with wrong amount of args... " << endl;
        exit(-1);
    }

    vector<ReturnValue> rv;
    rv = e->interp(t);

    if (rv[0].getType() == Types::Integer)
        cout << rv[0].getInt() << endl;
    else{
        if (rv[0].getBool())
            cout << "true" << endl;
        else 
            cout << "false" << endl;
    } 
}