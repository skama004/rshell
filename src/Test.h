#ifndef _TEST_H_
#define _TEST_H_

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

#include "Base.h"

class Test : public Base {
    private:
    string input;
    int flag;
    
    bool check();
    bool reg();
    bool dir();
    
    void setFlag(int );
    
    public:
    bool execute();
    void setLeft(Base* ){ };
    void setRight(Base* ){ };
    Test(string str);
    Base* getLeft(){ return NULL; }
    Base* getRight(){ return NULL; }
};

Test::Test(string str){
    str.erase(str.find_last_not_of(" ") + 1);
    str.erase(0, str.find_first_not_of(" "));
    input = str;
    if(input.substr(0, 3) == "-e "){
        input.erase(0, 3);
        setFlag(1);
    }
    else if(input.substr(0, 3) == "-f "){
        input.erase(0, 3);
        setFlag(2);
    }
    else if(input.substr(0, 3) == "-d "){
        input.erase(0, 3);
        setFlag(3);
    }
    else{
        setFlag(1);
    }
    
}

bool Test::check(){
    struct stat sb;
    string str = input;
    const char* testing = str.c_str();
    if (stat(testing, &sb) == 0)
    {
        cout << "(True) " << endl;
        return true;
    }
    cout << "(False) " << endl;
    return false;
}

bool Test::reg(){
    struct stat sb;
    string str = input;
    const char* testing = str.c_str();
    if (stat(testing, &sb) == 0 && S_ISREG(sb.st_mode))
    {
        cout << "(True) " << endl;
        return true;
    }
    cout << "(False) " << endl;
    return false;
}

bool Test::dir(){
    struct stat sb;
    string str = input;
    const char* testing = str.c_str();
    if (stat(testing, &sb) == 0 && S_ISDIR(sb.st_mode))
    {
        cout << "(True) " << endl;
        return true;
    }
    cout << "(False) " << endl;
    return false;
}

void Test::setFlag(int i){
    flag = i;
}

bool Test::execute(){
    switch(flag){
        
        case 1:
        return check();
        break;
        
        case 2:
        return reg();
        break;
        
        case 3:
        return dir();
        break;
        
        default:
        return check();
    }
}

#endif
