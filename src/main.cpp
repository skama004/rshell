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

void login(string &prompt){ //Function created to get user login and hostname and print with prompt
   char host[512]; 
   if(getlogin() == NULL){
      perror("Error with getlogin()");
   }
   if(gethostname(host, 500) != 0){
      perror("Error with gethostname()");
   }
   if(getlogin() != NULL && gethostname(host, 500) == 0){
      for(int i = 0; i < 100; i++){
         if(host[i] == '.'){
           host[i] = '\0';
         }
         prompt = getlogin();
         prompt = prompt + "@" + host + ":";
      }
   }
   

}


int main(){
    string prompt;
    login(prompt);
    while(true){
        char* dir = getenv("PWD"); 
        cout << prompt << dir << " $ ";
        string userIn;
        getline(cin, userIn);//Prompts user for input
        userIn.erase(userIn.find_last_not_of(" ") + 1);
        userIn.erase(0, userIn.find_first_not_of(" "));
        if(userIn != ""){
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
    }
    return 0;
}