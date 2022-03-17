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
    int nbElements;
};

Liste *initialisation();
void insertion(Liste *liste, int nb);
void insertionAuMilieu(Liste *liste, int precedent, int nb);
void suppression(Liste *liste);
void suppressionAuMilieu(Liste *liste, int precedent);
void afficherListe(Liste *liste);

Liste *initialisation(){
    Liste *liste = (Liste*) malloc(sizeof(Liste));
    Element *element = (Element*) malloc(sizeof(Element));

    if(liste == NULL || element == NULL){
        exit(EXIT_FAILURE);

    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;
    liste->nbElements = 1;

    return liste;
}


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
    ++liste->nbElements;

}

void insertionAuMilieu(Liste *liste, int precedent, int nb){
    Element *nouveau = (Element*) malloc(sizeof(Element));

    if(liste == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }

    Element *courant = liste->premier;
    while (courant != NULL){
        if(courant->nombre == precedent){
            nouveau->suivant = courant->suivant;
            nouveau->nombre = nb;
            courant->suivant = nouveau;
            ++liste->nbElements;
        }

        courant = courant->suivant;
    }
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
        --liste->nbElements;
    }
}

void suppressionAuMilieu(Liste *liste, int precedent){

    if(liste == NULL){
        exit(EXIT_FAILURE);
    }
        
    Element *courant = liste->premier;
    //Au cas ou l element est au debut de la liste
    if(courant != NULL && courant->nombre == precedent){
        suppression(liste);
    }else{
        int trouve = 0;
        Element *elementSuivant = courant->suivant;
        while (elementSuivant != NULL && ! trouve){
            if(elementSuivant->nombre == precedent){
                courant->suivant = elementSuivant->suivant;
                free(elementSuivant);
                --liste->nbElements;
                trouve = 1;
            }
            courant = elementSuivant;
            elementSuivant = elementSuivant->suivant;
        }
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