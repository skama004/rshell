#rshell
###By Raqtan Hoq and Siddaardha Kamarsu

rshell is our own personal bash terminal which reads in commands the user types in, reads the commands and connectors inputted and works to properly run the commands in the correct order. 

This is done by parsing the user input into two arrays, commands and connectors, and then using execvp and fork to properly run the commands. We also hard coded how rshell will handle the connectors.


##Connectors

`||` - The or command will run the first command if it return true. If it returns false, then the second command will run.

`&&` - The and connector will run both commands if both return true. If one returns false, then it will not run at all.

`;` - The semicolon will split up commands and if any command is true that specific comamnd will run.

`#`- Comments are mean that anything after the # will not be ran.


##How to run:
```
 $ git clone  https://github.com/skama004/rshell.git
 $ cd rshell
 $ git checkout hw2
 $ make
 $ bin/rshell
```

##Bugs and Limitations



if any bugs were found please report to either skama004@ucr.edu or rhoq001@ucr.edu
