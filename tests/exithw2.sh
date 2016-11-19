Script started on Wed 02 Nov 2016 06:41:35 PM PDT
]0;skama004@hammer:~/CS100/2016/rshell[?1034h[skama004@hammer rshell]$ make
g++ -g -Wall -Werror -ansi -pedantic src/main.cpp -o bin/rshell
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ bin/rshell 
skama004@hammer$ ls -s   a || exit
.  ..  bin  exit.sh  .git  LICENSE.md  makefile  README.md  src  tests
skama004@hammer$ ls -l && exit
total 40
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 18:41 bin
-rw-r--r-- 1 skama004 csmajs     0 Nov  2 18:41 exit.sh
-rw-r--r-- 1 skama004 csmajs 18017 Nov  2 17:37 LICENSE.md
-rw-r--r-- 1 skama004 csmajs   135 Nov  2 17:37 makefile
-rw-r--r-- 1 skama004 csmajs  1111 Nov  2 17:37 README.md
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 18:39 src
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:56 tests
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ bin/rshell 
skama004@hammer$ ls                exot    it 
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ bin/rshell 
skama004@hammer$   exit               
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ bin/rshell 
skama004@hammer$ ls -l;                                          exit ;
total 40
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 18:41 bin
-rw-r--r-- 1 skama004 csmajs     0 Nov  2 18:41 exit.sh
-rw-r--r-- 1 skama004 csmajs 18017 Nov  2 17:37 LICENSE.md
-rw-r--r-- 1 skama004 csmajs   135 Nov  2 17:37 makefile
-rw-r--r-- 1 skama004 csmajs  1111 Nov  2 17:37 README.md
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 18:39 src
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:56 tests
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ bin/rshell 
skama004@hammer$ exitl
Error with execvp: No such file or directory
skama004@hammer$ lexit
Error with execvp: No such file or directory
skama004@hammer$ echo hello && ls   ; exitasdf || exit
hello
bin  exit.sh  LICENSE.md  makefile  README.md  src  tests
Error with execvp: No such file or directory
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ exit'
> e[K^C
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ exit
exit

Script done on Wed 02 Nov 2016 06:42:45 PM PDT
