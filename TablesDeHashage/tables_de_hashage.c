#include <stdio.h>
#include <stdlib.h>
#include "tables_de_hashage.h"

int hashage(char *chaine){
    int sommeLettre = 0;

    int i = 0;
    while (chaine[i] != '\0'){
        sommeLettre += chaine[i];
        ++i;
    }

    return sommeLettre % 100;
    
}

Eleve* rechercheTableHachage(Eleve* tableau[100], char *nom){
    int indice = hashage(nom);

    return tableau[indice];
}

void insertion(Eleve* tableau[100], Eleve* eleve){
    int indice = hashage(eleve->nom);
    tableau[indice] = eleve;
}