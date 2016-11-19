Script started on Fri 18 Nov 2016 06:19:54 PM PST
]0;skama004@hammer:~/CS100/2016/rshell[?1034h[skama004@hammer rshell]$ make
g++ -g -Wall -Werror -ansi -pedantic src/main.cpp -o bin/rshell
b]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ bin/rshell
$ test -e main.cpp
(False) 
$ ls
bin  LICENSE.md  makefile  README.md  src  tests  test_test.sh
$ test -t e src/main.cpp
(True) 
$ test -f tests
(False) 
$ test -e   d tests
(True) 
$ test -e tests
(True) 
$ teste    -e sdkfjdshlgkh
(False) 
$ [ -  -e na  mainc.p   .cpp]
Error: syntax with test
$ [  -main    e main.cpp ]
Error: syntax with test
$ [ -em  main,cpp    .cpp]
Error: syntax with test
$ - [[ -e     -e main.cpp ]
(False) 
$ [-    -e src/main.cpp ]
(True) 
$ [ -d src]  
Error: syntax with test
$ ^[[A    [   -d src ]
(True) 
$ [ -f s src/main.cpp]           Test.h]    ]
(True) 
$ pwd
/home/csmajs/skama004/CS100/2016/rshell
$ test -e /home/csmajs/skama004/CS100/2016/rshell/src
(True) 
$ test -e /home/csmajs/skama004/CS100/2016/rshell/asdf
(False) 
$ exit
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ exit
exit

Script done on Fri 18 Nov 2016 06:22:55 PM PST
