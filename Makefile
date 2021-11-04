%:%.c
	gcc -Wall -o $@ $@.c -lm


treetest:treetest.c
	cc -o treetest treetest.c -l mylib -L ./mylib

