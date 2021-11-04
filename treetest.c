#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "../mylib/mylib.h"

struct Line {
       char tekst[50000];
       struct Line *next;
};


/* Prototypes */
int load(char rep[], struct Line **l);
int verifFinChaine(const char* chaine);
char * readFile();
void print(struct Line* n);
void add(struct Line** pp, const char *t);
void search(struct Line* n, char * x);
/* -------------------------------- */


char * readFile(){
        FILE *f;
    f = fopen("tree.conf", "r");
 
    if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
    char *rootdir = malloc(sizeof(char));
    char ch;
    int lire=0;
    while((ch=fgetc(f))!=EOF){
      if(ch=='=')
        lire=1;
      if(lire==1){
        fread(rootdir, sizeof(char), -1, f); // rootdir:variable, -1 pour aller jusqu'à la fin du fichier
        }
    }
    //debug:
    //printf("valeur::%s\ntaille:%d\n", rootdir, strlen(rootdir));

    fclose(f);
    return rootdir;
}



int main(int argc, char *argv[]){

  if (argc != 2) {
      fprintf(stderr, "Usage: ./program directory_name\n");
      exit(EXIT_FAILURE);

  }else{

    struct Line *lst = NULL;
    load(readFile(), &lst);
    //Pour vérifier que l'arborescence est bien enregistrée dans la structure:
      //print(lst); 
    search(lst, argv[1]);
  }
}

