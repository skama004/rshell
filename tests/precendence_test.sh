Script started on Fri 18 Nov 2016 06:23:40 PM PST
]0;skama004@hammer:~/CS100/2016/rshell[?1034h[skama004@hammer rshell]$ make
g++ -g -Wall -Werror -ansi -pedantic src/main.cpp -o bin/rshell
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ bin/rshell 
$ echo a && echo b || echo c && echo d
a
b
d
$ (echo a && echo b) || (echo c && echo d)
a
b
$ (eho  cho a && (echo b || echo c))^[[D^[[D         ^[[D                                (  echo a && echo b) || echo c)^[[D                                  echo a && (echo c   b && echo c || eco   ho d) 
a
b
c
$ echo a || echo b || echo c
a
$ (echo a ( || (echo b || echoc ==       c))                              echo a || (echo       echo b && echo c
a
c
$ echo a      (echo a || ( echo b && echo c))
a
$ (   (  echo a && echo b))
Error: syntax with parentheses
$ ((echo a && echo b)
Error: syntax with parentheses
$ echo    (echo a
Error: syntax with parentheses
$ ((    || echo a)
Error with syntax
$ (ehoc   cho a)
a
$ e (echo a        test   -e main    src/main.cpp && echo a   ^H   ) && (echo          || (e     && (echo b || echo c  ) 
(True) 
a
b
$ exit
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ exixt
bash: exixt: command not found
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ exit
exit

Script done on Fri 18 Nov 2016 06:31:38 PM PST
