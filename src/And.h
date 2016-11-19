#ifndef _AND_H_
#define _AND_H_

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

class And : public Base {
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

bool And::execute(){
    bool x;
    x = left->execute();
    if(x){
        x = right->execute();
        return x;
    }
    else {
        return false;
    }
    
}

void And::setRight(Base* temp){
    right = temp;
}

void And::setLeft(Base* temp){
    left = temp;
}

#endif