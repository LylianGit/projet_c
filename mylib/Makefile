libmylib.a:load.o search.o
	ar -rs libmylib.a load.o search.o

load.o:load.c mylib.h
	gcc -Wall -c load.c 
search.o:search.c mylib.h
	gcc -Wall -c search.c 
