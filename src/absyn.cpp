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
    if (type != Types::Integer){
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
    tableMapFunction = new map<string, DefStmt>; 

    tableMapTypes = new map<string, Types>; 
}

void Table::update(string i, int v) 
{
    auto it = tableMapTypes->find(i);
    if (it != tableMapTypes->end()){
        if (it->second == Types::Integer)
            tableMapInt->find(i)->second = v;
        else {
            cout << "[ Table::update(string,int) ] ID was found but not an int..." << endl;
            return;
        }
    } else {
        tableMapInt->insert(pair<string, int>(i, v));
        tableMapTypes->insert(pair<string, Types>(i, Types::Integer));
    }        
};

void Table::update(string i, bool v) 
{
    auto it = tableMapTypes->find(i);
    if (it != tableMapTypes->end()){
        if (it->second == Types::Boolean)
            tableMapBool->find(i)->second = v;
        else {
            cout << "[ Table::update(string,bool) ] ID was found but not a bool..." << endl;
            exit(-1);
        }
    } else {
        tableMapBool->insert(pair<string, bool>(i, v));
        tableMapTypes->insert(pair<string, Types>(i, Types::Boolean));
    }   
        
};

void Table::update(string i, DefStmt v)
{
    auto it = tableMapTypes->find(i);
    if (it != tableMapTypes->end()){
        if (it->second == Types::Function){
            auto iter = tableMapFunction->find(i);
            iter->second = v;
        } else {
            cout << "[ Table::update(string,DefStmt) ] ID was found but not a function..." << endl;
            exit(-1);
        }
    } else {
        tableMapFunction->insert(pair<string, DefStmt>(i, v));
        tableMapTypes->insert(pair<string, Types>(i, Types::Function));
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

DefStmt Table::getFunct(string i)
{
    auto it = tableMapFunction->find(i);
    if (it != tableMapFunction->end())
        return tableMapFunction->find(i)->second;
    else 
        cout << "[ Table::getFunct() ] Function not found in table..." << endl;
    
    if (hasBackup){
        cout << "[ Table::getFunct() ] Checking backup..." << endl;
        return backupTable->getFunct(i);
    }

    exit(-1);
}

void Table::remove(string i)
{
    tableMapTypes->erase(i);
    tableMapInt->erase(i);
    tableMapBool->erase(i);
    tableMapFunction->erase(i);
}


/* Statement structs */

Program_::Program_(CompStmt comp)
    : compStmt{comp}
{}

void Program_::print()
{
    cout << "Program(" << endl << "\t";
    compStmt->print();
    cout << ")" << endl;
}

void Program_::interp(Table *t)
{
    compStmt->interp(t);
}


CompStmt_::CompStmt_(Stmt s)
    :isArray(false), stmt{s}
{}

CompStmt_::CompStmt_(Stmt s, CompStmt comp)
    :isArray{true}, compStmt{comp}, stmt{s}
{}

void CompStmt_::print()
{
    cout << "CompStmt(" << endl << "\t";
    compStmt->print();
    cout << ",";
    stmt->print();
    cout << ")" << endl;
}

void CompStmt_::interp(Table *t)
{
    compStmt->interp(t);
    stmt->interp(t);
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

void PrintStmt::interp(Table *t)
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
}


UndefStmt::UndefStmt(char* id)
    :identifier{id}
{}

void UndefStmt::print()
{
    cout << "UNDEF( " << identifier << " )" << endl;
}

void UndefStmt::interp(Table* t)
{
    t->remove(identifier);
}


DefStmt::DefStmt(char* id, ArgList argl, CompStmt comps)
    :argList{argl}, compStmt{comps}
{
    identifier = string(id);
}

void DefStmt::print()
{
    cout << "DefStmt(id=" << identifier  << ", " << endl << "\t";
    argList->print();
    cout << "," << endl;
    compStmt->print();
    cout << ")" << endl;
}

void DefStmt::interp(Table* t)
{
    t->update(identifier, this);

    globalTable = t;

    // Local table has the global as backup
    localTable = new Table(t, this);
}

ReturnValue DefStmt::run(Exprs exprs)
{
    // check arg list length
    int len = exprs->getLength();
    if (len != argList->getLength()){
        cout << "[ DefStmt::run(Exprs) ] Function called with wrong amount of args..." << endl;
        exit(-1);
    }

    // Insert exprs in local table
    vector<string> argl = argList->interp(globalTable);
    vector<ReturnValue> expl = exprs->interp(globalTable);
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

void ReturnStmt::interp(Table *t)
{
    t->parentFunction->addReturnValue(expr->interp(t));
}


Elsif_::Elsif_()
    :isEmpty(true)
{}

Elsif_::Elsif_(Expr e, CompStmt comp, Elsif elif)
    :isEmpty{false}, expr{e}, compStmt{comp}, elsifTail{elif}
{}

void Elsif_::print()
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

bool Elsif_::interp(Table *t)
{
    if (isEmpty)
        return false;

    ReturnValue rv = expr->interp(t);

    if (rv.getType() != Types::Boolean){
        cout << "[ Elsif_::interp(Table) ] Expression is not a boolean..." << endl;
        exit(-1);
    }

    if (rv.getBool()){
        compStmt->interp(t);
        return true;
    } else {
        return elsifTail->interp(t);
    }
}

Else_::Else_()
    :isEmpty{true}
{}

Else_::Else_(CompStmt comp)
    :isEmpty{false}, compStmt{comp}
{}

void Else_::print()
{
    cout << "Else(" << endl << "\t";
    compStmt->print();
    cout << ")" << endl;
}

void Else_::interp(Table *t)
{
    compStmt->interp(t);
}


IfStmt::IfStmt(Expr e, CompStmt comp, Elsif eif, Else el)
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

void IfStmt::interp(Table *t)
{
    ReturnValue rv = expr->interp(t);

    if (rv.getType() != Types::Boolean){
        cout << "[ IfStmt::interp(Table) ] Expression is not a boolean..." << endl;
        exit(-1);
    }

    if (rv.getBool())
        compStmt->interp(t);
    else {
        if (!elsif->interp(t)) // elsif->interp(t) returns true if an elsif is matched 
            els->interp(t);
    }
}


UnlessStmt::UnlessStmt(Expr e, CompStmt comp, Else el)
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

void UnlessStmt::interp(Table *t)
{
    ReturnValue rv = expr->interp(t);

    if (rv.getType() != Types::Boolean){
        cout << "[ UnlessStmt::interp(Table) ] Expression is not a boolean..." << endl;
        exit(-1);
    }

    if (!rv.getBool())
        compStmt->interp(t);
    else {
        els->interp(t);
    }
}


WhileStmt::WhileStmt(Expr e, CompStmt comp)
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

void WhileStmt::interp(Table *t)
{
    ReturnValue rv = expr->interp(t);

    if (rv.getType() != Types::Boolean){
        cout << "[ WhileStmt::interp(Table) ] Expression is not a boolean..." << endl;
        exit(-1);
    }

    while (rv.getBool())
    {
        compStmt->interp(t);

        // Again check type
        if (rv.getType() != Types::Boolean){
            cout << "[ WhileStmt::interp(Table) ] Expression is not a boolean..." << endl;
            exit(-1);
        }
    }
}


UntilStmt::UntilStmt(Expr e, CompStmt comp)
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

void UntilStmt::interp(Table *t)
{
    ReturnValue rv = expr->interp(t);

    if (rv.getType() != Types::Boolean){
        cout << "[ UntillStmt::interp(Table) ] Expression is not a boolean..." << endl;
        exit(-1);
    }

    while (!rv.getBool())
    {
        compStmt->interp(t);

        // Again check type
        if (rv.getType() != Types::Boolean){
            cout << "[ UntillStmt::interp(Table) ] Expression is not a boolean..." << endl;
            exit(-1);
        }
    }
}


When_::When_()
    :isEmpty{true}
{}

When_::When_(Expr e, CompStmt comp, When w)
    :isEmpty{false}, expr{e}, compStmt{comp}, whenTail{w}
{}

void When_::print()
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

bool When_::interp(Table *t, Expr e)
{
    if (isEmpty)
        return false;
    
    ReturnValue rvCase = e->interp(t);
    ReturnValue rvWhen = expr->interp(t);

    if (rvCase.equals(rvWhen)){
        compStmt->interp(t);
        return true;
    } else
        return whenTail->interp(t, e);    
}


CaseStmt::CaseStmt(Expr ce, Expr we, CompStmt comp, When w, Else el)
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

void CaseStmt::interp(Table *t)
{
    ReturnValue rvCase = caseExpr->interp(t);
    ReturnValue rvWhen = whenExpr->interp(t);

    if (rvCase.equals(rvWhen)){
        compStmt->interp(t);
    } else {
        if (!when->interp(t, caseExpr))
            els->interp(t);
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

void ExprStmt::interp(Table *t)
{
    expr->interp(t);
}


/* Expression structs */

AssignOpExpr::AssignOpExpr(char* id, Assignop assop, Expr e)
    :assignop{assop}, expr{e}
{
    identifier = string(id);
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
        if (rv.getType() == Types::Integer) 
            t->update(identifier, rv.getInt());
        else 
            t->update(identifier, rv.getBool());
        break;

    case Assignop::PlusAssign:
    case Assignop::MinAssign:
    case Assignop::MulAssign:
    case Assignop::DivAssign:
        int idv = t->getInt(identifier);

        int result;
        switch (assignop)
        {
        case Assignop::PlusAssign:
            result = idv + rv.getInt();
            break;
        case Assignop::MinAssign:
            result = idv - rv.getInt();
            break;
        case Assignop::MulAssign:
            result = idv * rv.getInt();
            break;
        case Assignop::DivAssign:
            result = idv / rv.getInt();
            break;
        default:
            break;
        }

        t->update(identifier, result);
        break;

    case Assignop::AndAssign:
    case Assignop::OrAssign:
        bool idv = t->getBool(identifier);

        bool result;
        switch (assignop)
        {
        case Assignop::AndAssign:
            result = (idv && rv.getBool());
            break;
        case Assignop::OrAssign:
            result = (idv || rv.getBool());
            break;
        default:
            break;
        }

        t->update(identifier, result);
        break;
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

    bool isInt = (rvL.getType() == Types::Integer);
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


Literal_::Literal_(int v)
    :isInt{true}, intValue{v}
{}

Literal_::Literal_(bool v)
    :isInt{false}, boolValue{v}
{}

void Literal_::print()
{   
    if (isInt)
        cout << "Literal(" << intValue << ")" << endl;
    else 
        cout << "Literal(" << boolValue << ")" << endl;
}

ReturnValue Literal_::interp(Table *t)
{
    if (isInt)
        return ReturnValue(intValue);
    else 
        return ReturnValue(boolValue);
}


LitExpr::LitExpr(Literal l)
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
{
    identifier = string(id);
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
        cout << "[ IdExpr::interp(Table) ] var is not a boolean or an integer..." << endl;
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
    :exprs{e}
{
    identifier = string(id);
}

void FunctionExpr::print()
{
    cout << "FunctionExpr(" << identifier << "," << endl << "\t";
    exprs->print();
    cout << ")" << endl;
}

ReturnValue FunctionExpr::interp(Table *t)
{
    DefStmt f = t->getFunct(identifier);
    return f.run(exprs);
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