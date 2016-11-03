Script started on Wed 02 Nov 2016 05:53:51 PM PDT
]0;skama004@hammer:~/CS100/2016/rshell[?1034h[skama004@hammer rshell]$ ls
commented_command.sh  LICENSE.md  makefile  README.md  [0m[01;34msrc[0m  [01;34mtests[0m
[m]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ make
g++ -g -Wall -Werror -ansi -pedantic src/main.cpp -o bin/rshell
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ bin/rshell 
skama004@hammer$ echo hello  ; echo hi  ; ec  l pwd && ec    echo hi # hello
hello
hi
/home/csmajs/skama004/CS100/2016/rshell
hi
skama004@hammer$ ls - #-l
bin  commented_command.sh  LICENSE.md  makefile  README.md  src  tests
skama004@hammer$ ls - -l
total 40
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:53 bin
-rw-r--r-- 1 skama004 csmajs     0 Nov  2 17:53 commented_command.sh
-rw-r--r-- 1 skama004 csmajs 18017 Nov  2 17:37 LICENSE.md
-rw-r--r-- 1 skama004 csmajs   135 Nov  2 17:37 makefile
-rw-r--r-- 1 skama004 csmajs  1111 Nov  2 17:37 README.md
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:42 src
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:53 tests
skama004@hammer$ ls -a
.  ..  bin  commented_command.sh  .git	LICENSE.md  makefile  README.md  src  tests
skama004@hammer$ ls #-a
bin  commented_command.sh  LICENSE.md  makefile  README.md  src  tests
skama004@hammer$ ls    echo hello #### echo hi 
hello
skama004@hammer$ echo he  hey && echo hi ##   e  pwd 
hey
hi
skama004@hammer$ exit
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ exit
exit

Script done on Wed 02 Nov 2016 05:56:37 PM PDT
