#include "absyn.h"

#include <iostream>


/* ReturnValue functions */

ReturnValue::ReturnValue()
{
    type = Types::ERROR;  // garbage
}

ReturnValue::ReturnValue(int v)
    :integer{v}, type{Types::Integer}
{}

ReturnValue::ReturnValue(bool v)
    :boolean{v}, type{Types::Boolean}
{}

Types ReturnValue::getType()
{
    return type;
}

int ReturnValue::getInt()
{
    if (type != Types::Integer){
        cout << "[ ReturnValue::getInt() ] Return value is not an int..." << endl;
        exit(-1);
    }
        
    return integer;
}

bool ReturnValue::getBool()
{
    if (type != Types::Boolean){
        cout << "[ ReturnValue::getBool() ] Return value is not a bool..." << endl;
        exit(-1);
    }

    return boolean;
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
        cout << "No value.." << endl;
        break;
    }
}

/* Table functions */

Table::Table()
    :hasBackup{false}
{
    initTableVectors();
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
    else 
        cout << "[ Table::getInt() ] Int not found in table..." << endl;
    
    if (hasBackup){
        cout << "[ Table::getInt() ] Checking backup..." << endl;
        return backupTable->getInt(i);
    }
    exit(-1);    
}

bool Table::getBool(string i)
{
    auto it = tableMapBool->find(i);
    if (it != tableMapBool->end())
        return tableMapBool->find(i)->second;
    else 
        cout << "[ Table::getBool() ] Bool not found in table..." << endl;
    
    if (hasBackup){
        cout << "[ Table::getBool() ] Checking backup..." << endl;
        return backupTable->getBool(i);
    }

    exit(-1);

}

DefStmt* Table::getFunct(string i)
{
    auto it = tableMapFunction->find(i);
    if (it != tableMapFunction->end())
        return tableMapFunction->find(i)->second;

    if (hasBackup){
        return backupTable->getFunct(i);
    }

    cout << "[ Table::getFunct() ] Function is not defined..." << endl;
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


PrintStmt::PrintStmt(Expr e)
    :expr{e}
{}

void PrintStmt::print()
{
    cout << "PrintStmt(" << endl << "\t";
    expr->print();
    cout << ")" << endl;
}

bool PrintStmt::interp(Table *t)
{
    ReturnValue rv;
    rv = expr->interp(t);

    if (rv.getType() == Types::Integer)
        cout << rv.getInt() << endl;
    else{
        if (rv.getBool())
            cout << "true" << endl;
        else 
            cout << "false" << endl;
    } 

    return false;
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
        
        cout << "[ DefStmt::run(Exprs) ] Function called with wrong amount of args... " << endl;
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

    if (rv.getType() != Types::Boolean){
        cout << "[ Elsif::interp(Table) ] Expression is not a boolean..." << endl;
        exit(-1);
    }

    if (rv.getBool()){
        ri.hasReturned = compStmt->interp(t);
        ri.isMatched = true;
        return ri;
    } else {
        return elsifTail->interp(t);
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
    if (rv.getType() != Types::Boolean){
        cout << "[ IfStmt::interp(Table) ] Expression is not a boolean..." << endl;
        exit(-1);
    }
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

    if (rv.getType() != Types::Boolean){
        cout << "[ UnlessStmt::interp(Table) ] Expression is not a boolean..." << endl;
        exit(-1);
    }

    if (!rv.getBool())
        return compStmt->interp(t);
    else {
        return els->interp(t);
    }
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

    if (rv.getType() != Types::Boolean){
        cout << "[ WhileStmt::interp(Table) ] Expression is not a boolean..." << endl;
        exit(-1);
    }

    while (rv.getBool())
    {
        if (compStmt->interp(t))
            return true;

        // Again check type
        if (rv.getType() != Types::Boolean){
            cout << "[ WhileStmt::interp(Table) ] Expression is not a boolean..." << endl;
            exit(-1);
        }
        rv = expr->interp(t);
    }
    return false;
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

    if (rv.getType() != Types::Boolean){
        cout << "[ UntillStmt::interp(Table) ] Expression is not a boolean..." << endl;
        exit(-1);
    }

    while (!rv.getBool())
    {
        if (compStmt->interp(t))
            return true;

        // Again check type
        if (rv.getType() != Types::Boolean){
            cout << "[ UntillStmt::interp(Table) ] Expression is not a boolean..." << endl;
            exit(-1);
        }
        rv = expr->interp(t);
    }
    return false;
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
        cout << "[ IdExpr::interp(Table) ] " << identifier << " not defined.." << endl;
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
    DefStmt *f = t->getFunct(identifier);
    return f->run(exprs, t);
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