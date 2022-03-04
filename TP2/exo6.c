#include <stdio.h>
#include <stdlib.h>

void lireTableau(int *tab, int taille);
void afficherTableau(int *tab, int taille);
void fusionnerTableaux(int *tab1, int taille1, int *tab2, int taille2, int *tab3);

int main(int argc, int *argv[]){
    int taille1 = 0;
    int taille2 = 0;
    int *tab1 = NULL;
    int *tab2 = NULL;
    int *tab3 = NULL;

    printf("Donner la taille du 1 tableau : ");
    scanf("%d", &taille1);
    tab1 = malloc(taille1 * sizeof(int));
    lireTableau(tab1, taille1);

    printf("Donner la taille du 2 tableau : ");
    scanf("%d", &taille2);
    tab2 = malloc(taille2 * sizeof(int));
    lireTableau(tab2, taille2);

    tab3 = malloc((taille1 + taille2) * sizeof(int));
    fusionnerTableaux(tab1, taille1, tab2, taille2, tab3);  

    printf("=======TAB1=======\n");
    afficherTableau(tab1, taille1);
    printf("=======TAB2=======\n");
    afficherTableau(tab2, taille2);
    printf("=======TAB3=======\n");
    afficherTableau(tab3, taille1 + taille2);

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

void fusionnerTableaux(int *tab1, int taille1, int *tab2, int taille2, int *tab3){
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < taille1 && j < taille2){
        if(tab1[i] <= tab2[j]){
            tab3[k] = tab1[i];
            ++k;
            ++i;
        }else{
            tab3[k] = tab2[j];
            ++k;
            ++j;
        }
    }
    // les elements qui restent du tab1
    if(i < taille1){
        while(i < taille1 ){
            tab3[k] = tab1[i];
            ++k;
            ++i;
        }
    }else{
         while(j < taille2 ){
            tab3[k] = tab2[j];
            ++k;
            ++j;
        }
    }
}