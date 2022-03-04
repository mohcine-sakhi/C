#include <stdio.h>
#include <stdlib.h>

void eliminerOccurences(int *tab1, int *tab2, int taille, int *taille2);
void lireTableau(int *tab, int taille);
void afficherTableau(int *tab, int taille);

int main(int argc, int *argv[]){
    int taille = 0;
    int taille2 = 0;
    int *tab1 = NULL;
    int *tab2 = NULL;

    printf("Donner la taille du tableau : ");
    scanf("%d", &taille);

    tab1 = malloc(taille * sizeof(int));
    tab2 = malloc(taille * sizeof(int));

    lireTableau(tab1, taille);
    eliminerOccurences(tab1, tab2, taille, &taille2);
    afficherTableau(tab1, taille);
    printf("Apres elimination des occurences. \n");
    afficherTableau(tab2, taille2);
    return 0;
}

void lireTableau(int *tab, int taille){
    for (int i = 0; i < taille; ++i){
        printf("T[%d] = ", i);
        scanf("%d", tab + i);
    } 
    printf("\n\n");
}

void afficherTableau(int *tab, int taille){
    printf("Les elements du tableau sont : \n");
     for (int i = 0; i < taille; ++i){
        printf("T[%d] = %d  ", i, tab[i]);
        
    }
    printf("\n\n");
}

// on prends un element du 1 tableau, et on parcours le 2 tableau pour verifier
// s'il existe, sinn on l'ajoute dans le 2 tableau

void eliminerOccurences(int *tab1, int *tab2, int taille, int *taille2){
    *taille2 = 0;
    int trouve = 0;
    int j = 0;
    for(int i = 0; i < taille; ++i){
        trouve = 0;
        j = 0;

        while(! trouve && j < *taille2 ){
            if(tab2[j] == tab1[i]){
                trouve = 1;
            }
            ++j;
        }
        if(! trouve){
            tab2[(*taille2)] = tab1[i];
            ++(*taille2);
        }
    }
}
