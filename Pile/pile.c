#include <stdio.h>
#include <stdlib.h>
#include "pile.h"


Pile *initialiser(){
    Pile *pile = (Pile*) malloc(sizeof(Pile));
   

    if(pile == NULL){
        exit(EXIT_FAILURE);
    }

    pile->nbElement = 0;
    pile->premier = NULL;

    return pile;

}

void empiler(Pile *pile, int nb){
    if (pile == NULL){
        exit(EXIT_FAILURE);
    }

    Element *nouveau = (Element*) malloc(sizeof(Element));
    if(nouveau == NULL){
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nb;
    nouveau->suivant = pile->premier;

    pile->premier = nouveau;
    ++pile->nbElement; 

}

int depiler(Pile *pile){
    int nbDepile = 0;
    if(pile == NULL){
        exit(EXIT_FAILURE);
    }

    if(pile->premier != NULL){
        Element *elementDepile = pile->premier;
        nbDepile = elementDepile->nombre;
        pile->premier = elementDepile->suivant;
        --pile->nbElement;
        free(elementDepile);
    }

    return nbDepile;
}

void afficherPile(Pile *pile){
    if(pile == NULL){
        exit(EXIT_FAILURE);
    }

    Element *courant = pile->premier;

    while (courant != NULL){
        printf("%d\n", courant->nombre);
        courant = courant->suivant;
    }

    printf("\n");
}