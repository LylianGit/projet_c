
%:%.c
	gcc -Wall -o $@ $@.c -lm

localiser : localiser.c
	cc -o localiser localiser.c 

treetest:treetest.c
	cc -o treetest treetest.c -l mylib -L ./mylib

