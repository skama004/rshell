Script started on Wed 02 Nov 2016 05:44:08 PM PDT
]0;skama004@hammer:~/CS100/2016/rshell[?1034h[skama004@hammer rshell]$ make
g++ -g -Wall -Werror -ansi -pedantic src/main.cpp -o bin/rshell
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ ls
[0m[01;34mbin[0m  LICENSE.md  makefile  README.md  single_command.sh  [01;34msrc[0m  [01;34mtests[0m
[m]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ cd [K[K[Kbin/rshell 
skama004@hammer$ ls
bin  LICENSE.md  makefile  README.md  single_command.sh  src  tests
skama004@hammer$ ls -a
.  ..  bin  .git  LICENSE.md  makefile	README.md  single_command.sh  src  tests
skama004@hammer$ ls -l
total 40
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:44 bin
-rw-r--r-- 1 skama004 csmajs 18017 Nov  2 17:37 LICENSE.md
-rw-r--r-- 1 skama004 csmajs   135 Nov  2 17:37 makefile
-rw-r--r-- 1 skama004 csmajs  1111 Nov  2 17:37 README.md
-rw-r--r-- 1 skama004 csmajs     0 Nov  2 17:44 single_command.sh
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:42 src
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:43 tests
skama004@hammer$ ls -  r
tests  src  single_command.sh  README.md  makefile  LICENSE.md	bin
skama004@hammer$ pwd
/home/csmajs/skama004/CS100/2016/rshell
skama004@hammer$ cal
    November 2016   
Su Mo Tu We Th Fr Sa
       1 [7m 2[27m  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30

skama004@hammer$ cat e RE	      cat makefile
CC = g++
CFLAGS = -g -Wall -Werror -ansi -pedantic

all: rshell

rshell: 
	@mkdir -p bin
	$(CC) $(CFLAGS) src/main.cpp -o bin/rshell


skama004@hammer$ p echo hello
hello
skama004@hammer$ echo hi
hi
skama004@hammer$ vi ma     ls -a  -l
ls: invalid option -- '-'
Try `ls --help' for more information.
skama004@hammer$ ls -a -l
total 52
drwxr-xr-x 6 skama004 csmajs  4096 Nov  2 17:44 .
drwxr-xr-x 8 skama004 csmajs  4096 Nov  2 17:37 ..
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:44 bin
drwxr-xr-x 8 skama004 csmajs  4096 Nov  2 17:41 .git
-rw-r--r-- 1 skama004 csmajs 18017 Nov  2 17:37 LICENSE.md
-rw-r--r-- 1 skama004 csmajs   135 Nov  2 17:37 makefile
-rw-r--r-- 1 skama004 csmajs  1111 Nov  2 17:37 README.md
-rw-r--r-- 1 skama004 csmajs     0 Nov  2 17:44 single_command.sh
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:42 src
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:43 tests
skama004@hammer$ ls -a -l -r
total 52
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:43 tests
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:42 src
-rw-r--r-- 1 skama004 csmajs     0 Nov  2 17:44 single_command.sh
-rw-r--r-- 1 skama004 csmajs  1111 Nov  2 17:37 README.md
-rw-r--r-- 1 skama004 csmajs   135 Nov  2 17:37 makefile
-rw-r--r-- 1 skama004 csmajs 18017 Nov  2 17:37 LICENSE.md
drwxr-xr-x 8 skama004 csmajs  4096 Nov  2 17:41 .git
drwxr-xr-x 2 skama004 csmajs  4096 Nov  2 17:44 bin
drwxr-xr-x 8 skama004 csmajs  4096 Nov  2 17:37 ..
drwxr-xr-x 6 skama004 csmajs  4096 Nov  2 17:44 .
skama004@hammer$ sl
Error with execvp: No such file or directory
skama004@hammer$ pdw
Error with execvp: No such file or directory
skama004@hammer$ ehco heytrhwe
Error with execvp: No such file or directory
skama004@hammer$ dskjgdskflgj
Error with execvp: No such file or directory
skama004@hammer$ exit
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ exit
exit

Script done on Wed 02 Nov 2016 05:46:03 PM PDT
