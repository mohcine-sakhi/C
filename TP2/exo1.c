#include <stdio.h>
#include <stdlib.h>

void lireTableau(int *tab, int taille);
void afficherTableau(int *tab, int taille);
int minTableau(int *tab, int taille);
int maxTableau(int *tab, int taille);
double moyenneTableau(int *tab, int taille);
void inverserTableau(int *tab, int taille);
void trierTableau(int *tab, int taille);

int main(int argc, int *argv[]){

    int taille = 0;
    int *tab = NULL;
    int min = 0;
    int max = 0;
    double moyenne = 0;

    printf("Donner la taille du tableau : ");
    scanf("%d", &taille);

    tab = malloc(taille * sizeof(int));

    lireTableau(tab, taille);
    afficherTableau(tab, taille);
    min = minTableau(tab, taille);
    max = maxTableau(tab, taille);
    moyenne = moyenneTableau(tab, taille);
    
    printf("\nLe min du tableau est %d", min);
    printf("\nLe max du tableau est %d", max);
    printf("\nLa moyenne du tableau est %.2lf\n", moyenne);
    
    printf("\nLe tableau inverse est : ");
    inverserTableau(tab, taille);
    afficherTableau(tab, taille);

    printf("\nLe tableau trie est : ");
    trierTableau(tab, taille);
    afficherTableau(tab, taille);

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
    printf("\nLes elements du tableau sont : \n");
     for (int i = 0; i < taille; ++i){
        printf("T[%d] = %d  ", i, tab[i]);
        
    }
}

int minTableau(int *tab, int taille){
    int min = tab[0];
    for (int i = 1; i < taille; ++i){
        if(tab[i] < min){
            min = tab[i];
        }
    }
    return min;
}

int maxTableau(int *tab, int taille){
    int max = *tab;
    for(int i = 1; i < taille; ++i){
        if(*(tab + i) > max){
            max  = *(tab + i);
        }
    }
    return max;
}

double moyenneTableau(int *tab, int taille){
    int somme = 0;
    for(int i = 0; i < taille; ++i){
        somme += tab[i];
    }

    return ((double) somme) / taille;

}

void inverserTableau(int *tab, int taille){
    int temp = 0;
    for(int i = 0; i < taille / 2; ++i){
        temp = tab[i];
        tab[i] = tab[taille - 1 - i];
        tab[taille - 1 - i] = temp;
    }
}
void trierTableau(int *tab, int taille){
    int temp = 0;
    for(int i = 0; i < taille - 1; ++i){
        for(int j = i + 1; j < taille ; ++j){
            if(tab[i] > tab[j]){
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }

}