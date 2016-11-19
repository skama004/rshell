#ifndef _SEMICOLON_H_
#define _SEMICOLON_H_

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <unistd.h>
#include "Base.h"
using namespace std;

class SemiColon : public Base {
    private:
    Base* right;
    Base* left;
    
    public:
    bool execute();
    void setRight(Base* );
    void setLeft(Base* );
    Base* getLeft(){ return left; }
    Base* getRight(){ return right; }
};


//simply executes both children and returns the truth value of
//whether the right child failed or succeeded
bool SemiColon::execute(){
    bool x;
    x = left->execute();
    x = right->execute();
    return x;
}

void SemiColon::setRight(Base* temp){
    right = temp;
}

void SemiColon::setLeft(Base* temp){
    left = temp;
}

#endif
