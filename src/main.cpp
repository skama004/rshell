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
#include "makeTree.h"

using namespace std;



int main(){
    // string prompt;
    // login(prompt);
    while(true){
        cout << "$" << " ";
        string userIn;
        getline(cin, userIn);//Prompts user for input
        userIn.erase(userIn.find_last_not_of(" ") + 1);
        userIn.erase(0, userIn.find_first_not_of(" "));
        if(userIn.at(0) == ';' || userIn.at(0) == '|' || userIn.at(0) == '&'){
           cerr << "Error: beginning connectors" << endl;
        }
        else{
           if(userIn.find("#") != string::npos){ //Check for comments
              userIn.erase(userIn.find("#"), userIn.length());
           }
           makeTree* test = new makeTree(userIn);
           test->run();
        }
    }
    return 0;
}