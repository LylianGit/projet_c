#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "../mylib/mylib.h"

/* 
*  Code qui teste les fonctions load et search
*   load charge en mémoire une arborescence et search recherche une valeur dedans.
*/

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


char * readFile()  // Va lire dans tree.conf ce qu'il y a après le '='
{                   // pour ensuite le mettre en paramètre de la fonction load
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
        fread(rootdir, sizeof(char), -1, f); // rootdir:variable, qui prend la valeur d'un char, -1 pour aller jusqu'à la fin du fichier, f:fichier
        }
    }
    //debug:
      //printf("valeur::%s\ntaille:%d\n", rootdir, strlen(rootdir));

    fclose(f);
    return rootdir;
}



int main(int argc, char *argv[]){
  
  //On vérifie que le nombre d'arguments est à 2:

  if (argc != 2) {
      fprintf(stderr, "Usage: ./program directory_name\n");
      exit(EXIT_FAILURE);

  }else{
    struct Line *lst = NULL;

    load(readFile(), &lst); //On charge en mémoire

    search(lst, argv[1]); //On recherche une entrée de répertoire

        //Debug pour vérifier que l'arborescence est bien enregistrée dans la structure:
      //print(lst); 
  }
}

