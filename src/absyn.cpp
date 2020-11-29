#include "absyn.h"

#include <iostream>


/* ReturnValue functions */

ReturnValue::ReturnValue()
{
    integer = INT16_MIN;    // garbage
    boolean = false;        // garbage
    type = Types::Integer;  // garbage
}

ReturnValue::ReturnValue(int v)
    :integer{v}, type{Types::Integer}
{
    boolean = false; // garbage
}

ReturnValue::ReturnValue(bool v)
    :boolean{v}, type{Types::Boolean}
{
    integer = INT16_MIN; // garbage
}

Types ReturnValue::getType()
{
    return type;
}

int ReturnValue::getInt()
{
    return integer;
}

bool ReturnValue::getBool()
{
    return boolean;
}


/* Table functions */

Table::Table()
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
            return;
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
            return;
        }
    } else {
        tableMapFunction->insert(pair<string, DefStmt>(i, v));
        tableMapTypes->insert(pair<string, Types>(i, Types::Function));
    }   
}

int Table::getInt(string i)
{
    auto it = tableMapInt->find(i);
    if (it != tableMapInt->end())
        return tableMapInt->find(i)->second;
    else 
        cout << "[ Table::getInt() ] Int not found in table..." << endl;
    
    return -1; // garbage
}

bool Table::getBool(string i)
{
    auto it = tableMapBool->find(i);
    if (it != tableMapBool->end())
        return tableMapBool->find(i)->second;
    else 
        cout << "[ Table::getBool() ] Bool not found in table..." << endl;
    
    return false; // garbage

}

DefStmt Table::getFunct(string i)
{
    auto it = tableMapFunction->find(i);
    if (it != tableMapFunction->end())
        return tableMapFunction->find(i)->second;
    else 
        cout << "[ Table::getFunct() ] Function not found in table..." << endl;
    
    exit(-1);
}

void Table::remove(string i)
{
    tableMapTypes->erase(i);
    tableMapInt->erase(i);
    tableMapBool->erase(i);
    tableMapFunction->erase(i);
}


UndefStmt::UndefStmt(char* id)
    :identifier{id}
{}

void UndefStmt::interp(Table* t)
{
    t->remove(identifier);
}


DefStmt::DefStmt(char* id, ArgList argl, CompStmt comps)
    :argList{argl}, compStmt{comps}
{
    identifier = string(id);
}

void DefStmt::interp(Table* t)
{
    t->update(identifier, this);

    globalTable = t;
    localTable = new Table();
}

void DefStmt::run(Exprs exprs)
{
    // check arg list length
    int len = exprs->getLength();
    if (len != argList->getLength()){
        cout << "[ DefStmt::run(Exprs) ] Function called with wrong amount of args..." << endl;
        return;
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

    //run compstmt with glob and local table
        
}
