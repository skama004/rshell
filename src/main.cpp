#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
using namespace std;

int exec(string input);

void run(vector<string> &cmd, vector<int> &cnct){
     unsigned int i = 0;
     int j = 0;
     string str = cmd.at(0);
     j = exec(str);
     while(i < cnct.size()){
         if(cnct.at(i) == 0){
            j = exec(cmd.at(i+1));
            i++;
         }
         else if(cnct.at(i) == 1){
              if(j == 0){
                 j = exec(cmd.at(i+1));
              }
              i++;
         }
         else if(cnct.at(i) == 2){
              if(j == -1){
                 j = exec(cmd.at(i+1));
              }
              i++; 
         }
     }

}

void getCommands(string input, vector<string> &v){
     unsigned int pos = 0;
     string temp = " ";
     for(unsigned int i = 0; i < input.size(); i++){
         if(input.at(i) == '&' || input.at(i) == '|'){
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


void getConnectors(const string &input, vector<int> & v){
     for(unsigned int i = 0; i < input.size(); i++){
        if(input.at(i) == ';'){
           while(input.at(i) != ' '){
                i++;
           }
           if(input.at(i) == ';' || input.at(i) == '&' || 
              input.at(i) == '|'){
             //error FIX LATER
           }
           else{
              v.push_back(0);
           }
        }
        else if(input.at(i) == '&'){
             if(input.at(i+1) != '&'){
                //error FIX LATER
             }
             else{
                while(input.at(i) != ' '){
                   i++;
                }
                if(input.at(i) == ';' || input.at(i) == '&' || 
                   input.at(i) == '|'){
                   
                   //error FIX LATER
                }
                else{
                   v.push_back(1);
                }
             }
        }
        else if(input.at(i) == '|'){
             if(input.at(i+1) != '|'){
               //error FIX LATER
             }
             else{
               while(input.at(i) != ' '){
                   i++;
               }
               if(input.at(i) == ';' || input.at(i) == '&' ||
                  input.at(i) == '|'){
                  //error FIX LATER
               }
               else{
                  v.push_back(2);
               }
             }
        } 
     }
}

int exec(string input){
     //cout << "in exec" << endl;
     int status;
     int i = 0;
     char *arg[10000];
     char *inputC;
     char *cmd;
     inputC = new char[input.size()];
     strcpy(inputC, input.c_str());
     cmd = strtok(inputC, " \t");
     while(cmd != NULL){
         arg[i] = cmd;
         cmd = strtok(NULL, " \t");
         i++;
     }
     int a = fork();
     if(a == -1){
        perror("Error with fork");
     }
     if(a == 0){
        if(execvp(arg[0], arg) == -1){
            perror("Error with execvp");
            return -1;
        }
        exit(0);
     }
     if(wait(&status) == -1){
        perror("Error with wait");
     }
     for(int s = 0; s < i; s++){
        arg[s] = NULL;
     }
     delete inputC;
     return 0;
}

int main(){
    vector<string> cmd;
    vector<int> cnct;
    string userIn;
    getline(cin, userIn);
    getConnectors(userIn, cnct);
    getCommands(userIn, cmd); 
    run(cmd, cnct);
    return 0;
}
