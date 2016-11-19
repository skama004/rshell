#ifndef _BASE_H_
#define _BASE_H_

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

class Base {
  public:
  Base(){};
  virtual bool execute() = 0;
  virtual void setRight(Base* ) = 0;
  virtual void setLeft(Base* ) = 0;
  virtual Base* getLeft() = 0;
  virtual Base* getRight() = 0;
  
    
};

#endif