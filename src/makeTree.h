#ifndef _MAKETREE_H_
#define _MAKETREE_H_

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <stack>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <unistd.h>
#include "Base.h"
#include "Or.h"
#include "And.h"
#include "SemiColon.h"
#include "Commands.h"
#include "Test.h"
using namespace std;

class makeTree{
    
    private:
    vector<Base* > commands;
    vector<Base* > connectors;
    stack<string > cncts;
    vector<string > expression;
    
    bool getConnectors(const string &input);
    void getCommands(string input);
    bool operate;
    Base* root;
    bool checkTest(string &str);
    bool checkParentheses(string );
    void postfix();
    string post;
    bool checkBoth(string );
    
    public:
    makeTree(string input);
    ~makeTree();
    void run();
    void deleteChildren(Base* );
    
    bool getOperater(){ 
        return operate;
        
    };
    
    
};

makeTree::makeTree(string input){
    operate = true;
    operate = getConnectors(input);
    
    if(!operate){
        cerr << "Error: syntax with connectors" << endl;
    }
    else if(!checkParentheses(input)){
        cerr << "Error: syntax with parentheses" << endl;
    }
    else if(!checkBoth(input)){
        cerr << "Error with syntax" << endl;
    }
    else{
        getCommands(input);
        postfix();
    }
}

makeTree::~makeTree(){
    deleteChildren(root);
    root = 0;
}

void makeTree::deleteChildren(Base* parent){
    if(parent->getLeft()){
        deleteChildren(parent->getLeft());
    }
    if(parent->getRight()){
        deleteChildren(parent->getRight());
    }
    if(!parent->getLeft() && !parent->getRight()){
        delete parent;
    }
}

bool makeTree::checkBoth(string input){
    bool val = false;
    for(unsigned int i = 0; i < input.size(); i++){
        if(input.at(i) == '('){
            val = true;
        }
        if((input.at(i) == '|' || input.at(i) == '&' || input.at(i) == ';') && val){
            return false;
        }
        if(input.at(i) != '(' && input.at(i) != ' '){
            val = false;
        }
    }
    return true;
}


bool makeTree::checkParentheses(string str){
    int open = 0;
    int close = 0;
    for(unsigned int i = 0; i < str.size(); i++){
        if(str.at(i) == '('){
            open++;
        }
        else if(str.at(i) == ')'){
            close++;
        }
    }
    if(open == close){
        return true;
    }
    return false;
}

void makeTree::postfix(){
    stack<Base* > temp;
    for(unsigned int i = 0; i < expression.size(); i++){
        if(expression.at(i) == "&"){
            And* op1 = new And();
            op1->setRight(temp.top());
            temp.pop();
            op1->setLeft(temp.top());
            temp.pop();
            temp.push(op1);
        }
        else if(expression.at(i) == "|"){
            Or* op2 = new Or();
            op2->setRight(temp.top());
            temp.pop();
            op2->setLeft(temp.top());
            temp.pop();
            temp.push(op2);
        }
        else if(expression.at(i) == ";"){
            SemiColon* op3 = new SemiColon();
            op3->setRight(temp.top());
            temp.pop();
            op3->setLeft(temp.top());
            temp.pop();
            temp.push(op3);
        }
        else{
            string str;
            str = expression.at(i);
             if(checkTest(str)){
                 temp.push(new Test(str));
             }
             else{
                temp.push(new Commands(str));
             }
        }
    }
    root = temp.top();
}

void makeTree::getCommands(string input){
    int pos = 0;
     string temp = " ";
     bool afterClosed = false;
     for(unsigned int i = 0; i < input.size(); i++){
         if(input.at(i) == '('){
             cncts.push("(");
             pos = i + 1;
             i++;
         }
         else if(input.at(i) == ')'){
             if(!afterClosed){
                 temp = input.substr(pos, i - pos);
                 expression.push_back(temp);
             }
             while(cncts.top() != "("){
                 expression.push_back(cncts.top());
                 cncts.pop();
             }
             cncts.pop();
             pos = i + 1;
             afterClosed = true;
         }
         else if(input.at(i) == '&'){ //Tests if a connector is found
            if(!afterClosed){
                 temp = input.substr(pos, i - pos);
                 expression.push_back(temp);
                 pos = i + 2;
                 i = i + 2;
            }
            else{
                i = i + 2;
                while(input.at(i) != ' '){
                    i++;
                }
                if(input.at(i) == '('){
                    i--;
                }
                pos = i;
                afterClosed = false;
            }
             if(!cncts.empty() && cncts.top() != "("){
                expression.push_back(cncts.top());
                cncts.pop();
             }
             cncts.push("&");
         }
         else if(input.at(i) == '|'){
             if(!afterClosed){
                 temp = input.substr(pos, i - pos);
                 expression.push_back(temp);
                 pos = i + 2;
                 i = i + 2;
             } 
             else{
                i = i + 2;
                while(input.at(i) != ' '){
                    i++;
                }
                if(input.at(i) == '('){
                    i--;
                }
                pos = i;
                afterClosed = false;
            }
             if(!cncts.empty() && cncts.top() != "("){
                expression.push_back(cncts.top());
                cncts.pop();
             }
             cncts.push("|");
         }
         else if(input.at(i) == ';'){
             if(!afterClosed){
                 temp = input.substr(pos, i - pos);
                 expression.push_back(temp);
                 pos = i + 1;
                 i = i + 1;
             } 
             else{
                i = i + 1;
                while(input.at(i) != ' '){
                    i++;
                }
                if(input.at(i) == '('){
                    i--;
                }
                pos = i;
                afterClosed = false;
            }
             if(!cncts.empty() && cncts.top() != "("){
                expression.push_back(cncts.top());
                cncts.pop();
             }
             cncts.push(";");
             
         }
         else if(i == input.size() - 1){
             temp = input.substr(pos, i - pos + 1);
             expression.push_back(temp);
             if(!cncts.empty() && cncts.top() != "("){
                expression.push_back(cncts.top());
                cncts.pop();
             }
         }

     }
     while(!cncts.empty()){
         expression.push_back(cncts.top());
        cncts.pop();
    }
}

bool makeTree::checkTest(string &str){
    str.erase(str.find_last_not_of(" ") + 1);
    str.erase(0, str.find_first_not_of(" "));
    if(str.substr(0, 5) == "test "){
        str.erase(0, 5);
        return true;
    }
    else if(str.substr(0, 2) == "[ "){
        if(str.substr(str.size() - 2, 2) == " ]"){
            str.erase(0, 1);
            str.erase(str.size() - 1, 1);
            return true;
        }
        else{
            return false;
        }
    }
    else if(str.at(str.size() - 1 == ']')){
        return false;
    }
    return false;
}

bool makeTree::getConnectors(const string &input){
     for(unsigned int i = 0; i < input.size(); i++){
        if(input.at(i) == ';'){ //Test for semicolons
           i++;
           if(i >= input.size()) break;
           while(input.at(i) == ' '){ //Test for whitespace
                i++;
                if(i >= input.size()) break;
           }
           if(input.at(i) == ';' || input.at(i) == '&' || 
              input.at(i) == '|'){
              return false; 
           }
        }
        else if(input.at(i) == '&'){
             if(i + 1 >= input.size()) break;
             if(input.at(i+1) != '&'){ //Tests for &&
                return false;
             }
             else{
                i += 2;
                if(i >= input.size()) break;
                while(input.at(i) == ' '){
                   i++;
                   if(i >= input.size()) break;
                }
                if(input.at(i) == ';' || input.at(i) == '&' || 
                   input.at(i) == '|'){
                   
                   return false;
                }
             }
        }
        else if(input.at(i) == '|'){
             if(i + 1 >= input.size()) break;
             if(input.at(i+1) != '|'){
               return false;
             }
             else{
               i += 2;
               if(i >= input.size()) break;
               while(input.at(i) == ' '){
                   i++;
                   if(i >= input.size()) break;
               }
               if(input.at(i) == ';' || input.at(i) == '&' ||
                  input.at(i) == '|'){
                  return false;
               }
             }
        } 
     }
     return true;
}

void makeTree::run(){
    if(root){
        root->execute();
    }
}

#endif
