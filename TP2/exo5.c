#include <stdio.h>
#include <stdlib.h>

void lireTableau(int *tab, int taille);
void afficherTableau(int *tab, int taille);

int main(int argc, int *argv[]){
    int taille = 0;
    int *tab = NULL;
    int elementAChercher = 0;
    int trouve = 0;

    printf("Entrer la taille du tableau : ");
    scanf("%d", &taille);

    tab = malloc(taille * sizeof(int));

    lireTableau(tab, taille);
    afficherTableau(tab, taille);

    printf("\n\nDonner l'element a chercher : ");
    scanf("%d", &elementAChercher);

    for(int  i = 0; i < taille; ++i){
        if(tab[i] == elementAChercher){
            //Pour afficher le msg la 1 fois
            if(! trouve){
                printf("%d se trouve dans la(es) position(s) : ", elementAChercher);
            }
            trouve = 1;
            printf("%d\t", i);
        }
    }
    if(! trouve){
            printf("%d ne se trouve pas dans le tableau.\n", elementAChercher);
        }


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