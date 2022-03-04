#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void lireTableau(int *tab, int taille);
void afficherTableau(int *tab, int taille);
int estTrie(int *tab, int taille);
int premier(int nombre);
int estPremier(int *tab, int taille);

int main(int argc, int *argv[]){

    int taille = 0;
    int *tab = NULL;

    printf("Donner la taille du tableau : ");
    scanf("%d", &taille);

    tab = malloc(taille * sizeof(int));

    lireTableau(tab, taille);

    afficherTableau(tab, taille);

    if(estTrie(tab, taille)){
        printf("Le tableau est trie.\n");
    }else{
        printf("Le tableau n'est pas trie.\n");
    }

     if(estPremier(tab, taille)){
        printf("Le tableau est premier.\n");
    }else{
        printf("Le tableau n'est pas premier.\n");
    }

    free(tab);
    
    return 0;
}

void lireTableau(int *tab, int taille){
    for (int i = 0; i < taille; ++i){
        printf("T[%d] = ", i);
        scanf("%d", tab + i);
    } 
}

void afficherTableau(int *tab, int taille){
    printf("\nLes elements du tableau sont : \n\n");
     for (int i = 0; i < taille; ++i){
        printf("T[%d] = %d  ", i, tab[i]); 
    }
    printf("\n\n");
}

int estTrie(int *tab, int taille){
    for(int i = 0; i < taille - 1; ++i){
        if(tab[i] > tab[i+1]){
            return 0;
        }
    }

    return 1;
}

int premier(int nombre){
    if(nombre == 1){
        return 0;
    }
    int racine = sqrt(nombre);
    int i = 2;
    while(i <= racine){
        if(nombre % i == 0){
            return 0;
        }
        ++i;
    }
    return 1;
}

int estPremier(int *tab, int taille){
    for(int i = 0; i < taille; ++i){
        if(! premier(tab[i])){
            return 0;
        }
    }

    return 1;
}