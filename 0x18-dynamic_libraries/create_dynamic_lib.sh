#!/bin/bash
gcc -c -Wall -Wextra -Werror -fPIC *.c
gcc -shared -o liball.so *.o
