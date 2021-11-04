#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "mylib.h"

/* 
*  Code récursif qui parcours les dossiers et fichiers d'une arborescence choisi en paramètre 
*   et sauvegarde leur chemin dans une structure mise en paramètre 
*/

int load(char rep[], struct Line **l){
  
  add(&(*l), rep); // on ajoute le texte mit en paramètre (dossier)
  DIR *dp; 
  struct dirent *dirp;
  char *sousRep;
  dp = opendir(rep);

   if(!dp){
     printf("répertoire introuvable ou manque de permission\n");
     return 1;
   }
   //Tant qu'il y a des fichiers/dossiers à lire :
   while((dirp = readdir(dp)) != NULL){

     //Pour afficher le chemin complet et non pas seulement le nom du fichier:

      if (strcmp(dirp->d_name,".") != 0 && strcmp(dirp->d_name,"..") != 0){

        if(verifFinChaine(rep)){
          rep = strcat(rep,"/");
        }
        sousRep = malloc(sizeof(rep)+sizeof(dirp->d_name));
        sprintf(sousRep,"%s%s",rep,dirp->d_name); //range dans sousRep le chemin déjà connu + le nom du dossier/fichier actuel


        if(dirp->d_type == DT_DIR){ // si c'est un dossier

          load(sousRep, l); //récursivité

        }else{ // si c'est un fichier

          add(&(*l), sousRep); //ajout dans la structure (fichier)
        }
      }
    }

  closedir(dp);
  return 0;
  exit(EXIT_SUCCESS);
}

int verifFinChaine(const char* chaine)
{
    int nombreDeCaracteres = 0;
    char caractereActuel = 0;

    do
    {
        caractereActuel = chaine[nombreDeCaracteres];
        nombreDeCaracteres++;
    }
    while(caractereActuel != '\0'); // On boucle tant qu'on n'est pas arrivé à \0

    if(chaine[nombreDeCaracteres-2] == '/'){

      return 0;

    }else{

      return 1;

    }
}

void add(struct Line** pp, const char *t)
{
    struct Line *p = malloc(sizeof(*p));
    strcpy(p->tekst, t);
    while (*pp){ // is not null
        pp = &(*pp)->next;}
    *pp = p;
    //free(p);
}

void print(struct Line* n)
{
     for ( ; n; n = n->next )
         printf("%s\n", n->tekst);
     printf("\n");
}
