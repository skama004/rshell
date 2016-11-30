#rshell
###By Raqtan Hoq and Siddaardha Kamarsu

rshell is our own personal bash terminal which reads in commands the user types in, reads the commands and connectors inputted and works to properly run the commands in the correct order. 

This is done by parsing the user input into two arrays, commands and connectors, and then using execvp and fork to properly run the commands. We also hard coded how rshell will handle the connectors. 

We built upon this so rshell now functions with the test command (also with the brackets operators) and with precendence operators. So rshell will now take precendence into account and can test files and directories and will return true or false whether they exist or not.


##Connectors

`||` - The or command will run the first command if it return true. If it returns false, then the second command will run.

`&&` - The and connector will run both commands if both return true. If one returns false, then it will not run at all.

`;` - The semicolon will split up commands and if any command is true that specific comamnd will run.

`#`- Comments are mean that anything after the # will not be ran.


##Test Functionality and Precendence Operators
We built on rshell to function with precendence and can use the test operators to test files and directories. To use these one can use either the `test` command or the brackets `[ ]` to test their files with 3 flags:

`-e` - Tests if exists

`-f` - Tests if file and exists

`-d` - Tests if directory and exists


And if flag is not specified then `-e` will be the default. 

Ex. `test -e main.cpp` 

For brackets one must simply put the flag and the file in between brackets.

Ex. `[ -e main.cpp ]`

We also implemented precendence operators to change precendence of returns of commands, connectors, and chains of connectors. So if using parantheses, rshell takes the user input and equates whatever user types based on the precendence.

##CD Functionality
We built upon rshell again so now that rshell can handle the `cd` function to change between directories. rshell is capable of handling:

`cd <PATH> ` to go through any path that exists on the system

`cd` by itself will take you to the user's home directory

`cd - ` will take you to the previous directory you were on 

The functionality now will also print the current working directory before the prompt to show the user the exact path that they are on as they traverse through.


##How to run:
```
 $ git clone  https://github.com/skama004/rshell.git
 $ cd rshell
 $ git checkout hw3
 $ make
 $ bin/rshell
```

##Bugs and Limitations


if any bugs were found please report to either skama004@ucr.edu or rhoq001@ucr.edu
