Script started on Fri 18 Nov 2016 06:46:26 PM PST
]0;skama004@hammer:~/CS100/2016/rshell[?1034h[skama004@hammer rshell]$ bin/rsje[K[Khell 
$ echoa  a # echo      && echo b
a
$ echo a && # echo b
Error: syntax with connectors
$ echo a # echo b
a
$ e (echo a && eho  cho b)#)
a
b
$ ech   (echo a #)  &&   echo b) && echo c || echod  d
Error: syntax with parentheses
$ echo a        echo a # echo b) && echo c || echo d
a
$ [ -e t src/main.cp ]  p ] #  echo i hate you 
(True) 
$ [ test - #  -e main.cpp
$ test -e         test#     test -e main n.cpp  # [ -e main.cpp ]
(False) 
$ test -e         [ -e main.cpp #]
Error: syntax with test
$ echo works #fini    Finished test
works
$ exit
]0;skama004@hammer:~/CS100/2016/rshell[skama004@hammer rshell]$ exit
exit

Script done on Fri 18 Nov 2016 06:51:12 PM PST
