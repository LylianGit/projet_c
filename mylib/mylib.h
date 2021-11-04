#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

struct Line {
       char tekst[50000];
       struct Line *next;
};


int load(char rep[], struct Line **l);
int verifFinChaine(const char* chaine);
char * readFile();
void print(struct Line* n);
void add(struct Line** pp, const char *t);
void search(struct Line* n, char * x);

