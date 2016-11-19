#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <unistd.h>


using namespace std;

#include "Base.h"

class Commands : public Base {
    private:
    string input;
    
    public:
    bool execute();
    void setLeft(Base* ){ };
    void setRight(Base* ){ };
    Commands(string str);
    Base* getLeft(){ return NULL; }
    Base* getRight(){ return NULL; }
};

Commands::Commands(string str){
    input = str;
}

bool Commands::execute(){
    int status;
    unsigned int i = 0;
    char *argv[10000]; //Set as huge size to take as many commands as user can write (hopefully)
    char *inputC;
    char *cmd;
    input.erase(input.find_last_not_of(" ") + 1);
    input.erase(0, input.find_first_not_of(" "));
    if(input.at(0) == '[' || input.at(input.size() - 1) == ']'){
        cerr << "Error: syntax with test" << endl;
        return false;
    }
    while(input.at(i) == ' '){
        i++;
    }
    if(input.substr(i, 4) == "exit"){ //Checks if exit is found by itself or in addition with other characters
        if(i + 4 < input.size()){
            i += 4;
        }
        else{
            exit(0);
        }
        while(input.at(i) == ' '){
            if(i + 1 >= input.size()) exit(0);
            else i++;
        }
            if(input.at(i) == ';' || input.at(i) == '|' || input.at(i) == '&') exit(0);
    }
    i = 0;
    inputC = new char[input.size()];
    strcpy(inputC, input.c_str());
    cmd = strtok(inputC, " \t");//Parses based on spaces and tabs
    while(cmd != NULL){
        argv[i] = cmd;
        cmd = strtok(NULL, " \t");
        i++;
    }
    argv[i] = NULL;
    int a = fork();
    if(a == -1){
        perror("Error with fork");
    }
    if(a == 0){
        if(execvp(argv[0], argv) == -1){ //Executes the command based on argument user types in 
            perror("Error with execvp");
            exit(-1);
        }
        for(unsigned int s = 0; s < i; s++){
            argv[s] = NULL;
        }
        exit(0);
    }
    else if(a > 0){
        delete inputC;
    }
    if(wait(&status) == -1){
        perror("Error with wait");
    }
    if(!status){
        return true;
    }
    else{
        return false;
    }
}

#endif