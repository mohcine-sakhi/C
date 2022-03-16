#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste{
    Element *premier;
};

Liste *initialiser();
void insertion(Liste *liste, int nb);
void suppression(Liste *liste);
void afficherListe(Liste *liste);

void insertion(Liste *liste, int nb){
    //creation du nouvelelement
    Element *nouveau = (Element*) malloc(sizeof(Element));
    if(liste == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nb;
    //insertion de l element au debut de la liste
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;

}

void suppression(Liste *liste){

    if(liste == NULL){
        exit(EXIT_FAILURE);
    }
    
    if(liste->premier != NULL){
        //recupeartion de l element a supprimer
        Element *aSupprimer = liste->premier;

        //suppression de l'element
        liste->premier = aSupprimer->suivant;
        free(aSupprimer);
    }
    

}

void afficherListe(Liste *liste){

    if(liste == NULL){
        exit(EXIT_FAILURE);
    }

    Element *courant = liste->premier;

    while (courant != NULL){
        printf("%d -> ", courant->nombre);
        courant = courant->suivant;
    }
    printf("NULL\n");
}