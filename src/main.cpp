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

void exec(string input, int& status);
//Declared function here so we can use it in run 
//Actual implentation further below


void run(vector<string> &cmd, vector<int> &cnct){ //Function used to actually run
     unsigned int i = 0;
     int j;
     string str = cmd.at(0);
     exec(str, j);
     while(i < cnct.size()){
         if(cnct.at(i) == 0){
            exec(cmd.at(i+1), j);
            i++;
         }
         else if(cnct.at(i) == 1){
              if(j == 0){
                 exec(cmd.at(i+1), j);
              }
              i++;
         }
         else if(cnct.at(i) == 2){
              if(j != 0){
                 exec(cmd.at(i+1), j);
              }
              i++; 
         }
     }

}

void getCommands(string input, vector<string> &v){ //Function that takes commands and places in array 
     int pos = 0;
     string temp = " ";
     for(unsigned int i = 0; i < input.size(); i++){
         if(input.at(i) == '&' || input.at(i) == '|'){ //Tests if a connector is found
             temp = input.substr(pos, i - pos);
             v.push_back(temp);
             pos = i + 2;
             i = i + 2;
         }
         else if(input.at(i) == ';'){
             temp = input.substr(pos, i - pos);
             v.push_back(temp);
             pos = i + 1;
             i = i + 1;
         }
         if(i == input.size() - 1){
             temp = input.substr(pos, i - pos + 1);
             v.push_back(temp);
             
         }

     }
     
}


bool getConnectors(const string &input, vector<int> & v){ //Function that gets connectors from user string and places in array with numerical vals
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
           else{
              v.push_back(0); //Returns value we set 0 as semicols
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
                else{
                   v.push_back(1);//Returns 1 for &
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
               else{
                  v.push_back(2);//Returns 2 for ||
               }
             }
        } 
     }
     return true;
}

void exec(string input, int& status){ //Function that executes the commands
     //cout << "in exec" << endl;
     unsigned int i = 0;
     char *argv[10000]; //Set as huge size to take as many commands as user can write (hopefully)
     char *inputC;
     char *cmd;
     input.erase(input.find_last_not_of(" ") + 1);
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
}

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
         prompt = prompt + "@" + host + "$";
      }
   }
   else {
      prompt = "$";  //If failed then output just a $
   }
   

}

int main(){

    bool operate = true;
    string prompt;
    login(prompt);
    while(true){ //Infinite loop for continuous commands until user types in exit
        cout << prompt << " ";
        vector<string> cmd;
        vector<int> cnct;
        cmd.clear();
        cnct.clear();
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
           operate = getConnectors(userIn, cnct);
           if(operate){
               getCommands(userIn, cmd);
               if(cmd.size() != cnct.size() + 1) cnct.pop_back();
               run(cmd, cnct);
           }
           else{
              cerr << "Error: syntax with connectors" << endl;
           }
        }
    }
    return 0;
}
