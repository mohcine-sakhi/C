#include <stdio.h>
#include <stdlib.h>

int sommeDiviseurs(int nombre);
int amicaux(int a, int b);
void lireTableau(int *tab, int taille);
void afficherTableau(int *tab, int taille);


int main(int argc, int *argv[]){

    int taille = 0;
    int *tab = NULL;

    printf("Donner la taille du tableau : ");
    scanf("%d", &taille);

    tab = malloc(taille * sizeof(int));

    lireTableau(tab, taille);
    afficherTableau(tab, taille);
    printf("\nLes couples amicaux sont : \n");

    for(int i = 0; i < taille - 1; ++i){
        for(int j = i + 1; j < taille; ++j){
            if(amicaux(tab[i], tab[j])){
                printf("(%d, %d)\n", tab[i], tab[j]);
            }
        }
    }

    return 0;
}

int sommeDiviseurs(int nombre){
    int somme =0;
    for(int i = 1; i <= nombre / 2; ++i){
        if(nombre % i == 0){
            somme += i;
        }
    }

    return somme;
}


int amicaux(int a, int b){
    int sommeDiviseursA = sommeDiviseurs(a);
    int sommeDiviseursB = sommeDiviseurs(b);

    return ( a != b && sommeDiviseursA == b && sommeDiviseursB == a ) ? 1 : 0;
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