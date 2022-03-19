#include <stdio.h>
#include <stdlib.h>
#include "tables_de_hashage.c"

int main(int argc, int *argv[]){
    Eleve* tableau[100];

    for(int i = 0; i < 100; ++i){
        tableau[i] = NULL;
    }
    
    Eleve *eleve = (Eleve*) malloc(sizeof(Eleve));
    eleve->nom = "Mohcine SAKHI";
    eleve->age = 30;
    eleve->note = 19;

    insertion(tableau, eleve);
    Eleve *eleveRecherche = rechercheTableHachage(tableau, "Mohcine SAKHI");
    if(eleveRecherche != NULL){
        printf("Eleve : \n");
        printf("    Nom : %s\n", eleveRecherche->nom);
        printf("    Age : %d\n", eleveRecherche->age);
        printf("    Note : %.2f\n", eleveRecherche->note);
    }else{
        printf("Cet eleve n'existe pas !!\n");
    }
    
}