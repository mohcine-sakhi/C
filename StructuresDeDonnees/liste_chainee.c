#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"

int main(int argc, int *argv[]){
    Liste *liste = initialisation();
    
    insertion(liste, 4);
    insertion(liste, 8);
    insertion(liste, 15);
    insertion(liste, 20);

    afficherListe(liste);
    printf("Le nombre des elements de la liste est : %d\n", liste->nbElements);

    insertionAuMilieu(liste, 15, 10);
    insertionAuMilieu(liste, 10, 30);
    insertionAuMilieu(liste, 4, 1);
    
    printf("\nApres insertion de 10 apres 15, 30 apres 10 et 1 apres 4\n");
    afficherListe(liste);

    
    suppression(liste);
    printf("\nApres suppresion du premier element\n");
    afficherListe(liste);

    suppressionAuMilieu(liste, 10);;
    suppressionAuMilieu(liste, 4);
    printf("\nApres suppresion du 10 et 4\n");
    afficherListe(liste);
    printf("\nLe nombre des elements de la liste est : %d\n", liste->nbElements);

    return 0;
    
}




