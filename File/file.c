#include <stdio.h>
#include <stdlib.h>
#include "file.h"

File *initialiser(){
    File *file = (File*) malloc(sizeof(File));

    if(file == NULL){
        exit(EXIT_FAILURE);
    }

    file->premier = NULL;
    file->nbElement = 0;

    return file;
}

void enfiler(File *file, int nb){

    if(file == NULL){
        exit(EXIT_FAILURE);
    }

    Element *nouveau = (Element*) malloc(sizeof(Element));
    if(nouveau == NULL){
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nb;
    nouveau->suivant = NULL;
    //file est vide
    if(file->premier == NULL){
        file->premier = nouveau;
        ++file->nbElement;
    }else{
        Element *courant = file->premier;
        while (courant->suivant != NULL){
            courant = courant->suivant;
        }
        courant->suivant = nouveau;
        ++file->nbElement;
    }
     
}

int defiler(File *file){
    int nbDefile = 0;
    if(file == NULL){
        exit(EXIT_FAILURE);
    }

    // file nn nulle
    if(file->premier != NULL){
        Element *elementDefile = file->premier;
        nbDefile = elementDefile->nombre;

        file->premier = elementDefile->suivant;
        --file->nbElement;
        free(elementDefile);
    }

    return nbDefile;

}

void afficherFile(File *file){
    if(file == NULL){
        exit(EXIT_FAILURE);
    }

    Element *courant = file->premier;

    while (courant != NULL){
        printf("%d  ", courant->nombre);
        courant = courant->suivant;
    }
    printf("\n");
}