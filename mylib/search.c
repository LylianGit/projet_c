#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "mylib.h"

/* 
*  Code qui parcours les occurences d'une structure choisie en paramètre 
*   et affiche les valeurs correspondant avec la valeur recherchée écrite en paramètre 
*/

void search(struct Line* n, char * x)
{
    //slash avant la chaine
    char *slashChaine = malloc(sizeof(char));
    sprintf(slashChaine, "/%s", x);

    //slash après la chaine
    char *verifEntreeRepertoire = malloc(sizeof(char));
    sprintf(verifEntreeRepertoire, "%s/", x);
    
    for ( ; n; n = n->next ) //Pour chaque valeur stockée
     {
         // Si il y a un '/' avant l'argument, et pas de '/' après (pour que l'on obtienne seulement l'entrée du répertoire):
         if(strstr(n->tekst, slashChaine) != NULL && strstr(n->tekst, verifEntreeRepertoire) == NULL)
         { 
            printf("%s\n", n->tekst);
         }
     }
     //debug:
        //printf("x:%s s:%s v:%s", x, slashChaine, verifEntreeRepertoire);
     free(slashChaine);
     free(verifEntreeRepertoire);
}