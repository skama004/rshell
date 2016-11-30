#ifndef _CD_H_
#define _CD_H_

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

class CD : public Base{
    private:
    string input;
    int flag;
    
    bool change();
    bool prev();
    bool home();
    
    void setFlag(int );
    
    public:
    bool execute();
    void setLeft(Base* ){ };
    void setRight(Base* ){ };
    CD(string str);
    Base* getLeft(){ return NULL; }
    Base* getRight(){ return NULL; }
};

CD::CD(string str){
    str.erase(str.find_last_not_of(" ") + 1);
    str.erase(0, str.find_first_not_of(" "));
    if(str == "cd"){
        flag = 3;
        input = str;
    }
    else{
        str.erase(0, 3);
        if(str == "-"){
            flag = 2;
            input = str;
        }
        else{
            flag = 1;
            input = str;
        }
    }
    
}

bool CD::execute(){
    switch(flag){
        case 1:
        return change();
        break;
        
        case 2:
        return prev();
        break;
        
        case 3:
        return home();
        break;
        
        default:
        return change();
        break;
    }
}

void CD::setFlag(int i){
    flag = i;
}

//Function to handle cd and prints current directory name
bool CD::change(){
    string temp = input;
    const char* c = temp.c_str();
    if(chdir(c) == 0){
        char* currDir = getenv("PWD");
        if(setenv("OLDPWD", currDir, 1) == 0){
            currDir = get_current_dir_name();
            if(setenv("PWD", currDir, 1) == 0){
                return true;
            }
            else{
                cerr << "Error w/ setenv()1" << endl;
                return false;
            }
        }
        else{
            cerr << "Error w/ setenv()2" << endl;
            return false;
        }
    }
    else{
        cerr << "Error w/ chdir()" << endl; 
        return false; 
    }
}

//Function to handle cd - 
bool CD::prev(){
    char* c = getenv("OLDPWD");
    if(chdir(c) == 0){
        char* d = getenv("PWD");
        if(setenv("OLDPWD", d, 1) == 0){
            if(setenv("PWD", c, 1) == 0){
                return true;
            }
            else{
                cerr << "Error w/ setenv()1" << endl;
                return false;
            }
        }
        else{
            cerr << "Error w/ setenv()2" << endl;
            return false;
        }
    }
    else{
        cerr << "Error w/ chdir()" << endl;
        return false;
    }
}

//Function to handle cd by itself
bool CD::home(){
    char* c = getenv("HOME");
    if(chdir(c) == 0){
        char* d = getenv("PWD");
        if(setenv("OLDPWD", d, 1) == 0){
            if(setenv("PWD", c, 1) == 0){
                return true;
            }
            else{
                cerr << "Error w/ setenv()1" << endl;
                return false;
            }
        }
        else{
            cerr << "Error w/ setenv()2" << endl;
            return false;
        }
    }
    else{
        cerr << "Error w/ chdir()" << endl;
        return false;
    }
}
#endif