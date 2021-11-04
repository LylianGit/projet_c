#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "mylib.h"

void search(struct Line* n, char * x)
{
  char *slashChaine = malloc(sizeof(char));
  sprintf(slashChaine, "/%s", x);
  char *verifEntreeRepertoire = malloc(sizeof(char));
  sprintf(verifEntreeRepertoire, "%s/", x);
     for ( ; n; n = n->next ){
         if(strstr(n->tekst, slashChaine) != NULL && strstr(n->tekst, verifEntreeRepertoire) == NULL)
         { // si il y a un '/' avant l'argument, et pas de '/' après (pour que l'on obtienne seulement l'entrée du répertoire).
            printf("%s\n", n->tekst);
         }
     }
     //debug:
     //printf("x:%s s:%s v:%s", x, slashChaine, verifEntreeRepertoire);
     free(slashChaine);
     free(verifEntreeRepertoire);
}