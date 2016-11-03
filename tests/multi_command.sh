Script started on Wed 02 Nov 2016 05:49:34 PM PDT
]0;skama004@hammer:~/CS100/2016/rshell[?1034h[skama004@hammer rshell]$ make
g++ -g -Wall -Werror -ansi -pedantic src/main.cpp -o bin/rshell
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ bin/rshell 
skama004@hammer$ ls -a; echo hello  ; echo hi
.  ..  bin  .git  LICENSE.md  makefile	multi_command.sh  README.md  src  tests
hello
hi
skama004@hammer$ ls   && echo what || echo hi
bin  LICENSE.md  makefile  multi_command.sh  README.md	src  tests
what
skama004@hammer$ ls || echo hi || echo hello
bin  LICENSE.md  makefile  multi_command.sh  README.md	src  tests
skama004@hammer$ echo    pwd && asdfghj || echo hi || echo what's up && ls
/home/csmajs/skama004/CS100/2016/rshell
Error with execvp: No such file or directory
hi
bin  LICENSE.md  makefile  multi_command.sh  README.md	src  tests
skama004@hammer$ echo hek llo && asdf || ls && ls -a && ls -l && echo hi  ; echo h hey
hello
Error with execvp: No such file or directory
bin  LICENSE.md  makefile  multi_command.sh  README.md	src  tests
.  ..  bin  .git  LICENSE.md  makefile	multi_command.sh  README.md  src  tests
total 40
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:49 bin
-rw-r--r-- 1 skama004 csmajs 18017 Nov  2 17:37 LICENSE.md
-rw-r--r-- 1 skama004 csmajs   135 Nov  2 17:37 makefile
-rw-r--r-- 1 skama004 csmajs     0 Nov  2 17:49 multi_command.sh
-rw-r--r-- 1 skama004 csmajs  1111 Nov  2 17:37 README.md
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:42 src
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:48 tests
hi
hey
skama004@hammer$ echo hello;  ;; echo hi
Error: syntax with connectors
skama004@hammer$ echo hello  ;;;;ech hi   o hi
Error: syntax with connectors
skama004@hammer$ echo hello &&&&&& echo hi
Error: syntax with connectors
skama004@hammer$ echo hey |||||| echo hi
Error: syntax with connectors
skama004@hammer$ ls -l   l; echo hi || echo hello &&& echo hey &
Error: syntax with connectors
skama004@hammer$ exit 
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ exit
exit

Script done on Wed 02 Nov 2016 05:53:23 PM PDT
