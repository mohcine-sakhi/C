#include <stdio.h>
#include <stdlib.h>

void lireTableau(int *tab, int taille);
void afficherTableau(int *tab, int taille);
int chercherElement(int *tab, int taille, int x);
void afficherOccurrence(int *tab, int taille, int x);
void supprimerOccurrence(int *tab, int taille, int *tabSansOccurences, int *taille2, int x);
int chercherElementDansTableauTrie(int *tab, int taille, int x);


int main(int argc, int *argv[]){
    int taille = 0;
    int *tab = NULL;
    int taille2 = 0;
    int *tabSansOccurences = NULL;
    int elementAChercher = 0;

    printf("Entrer la taille du tableau : ");
    scanf("%d", &taille);

    tab = malloc(taille * sizeof(int));
    tabSansOccurences = malloc(taille * sizeof(int));

    lireTableau(tab, taille);
    afficherTableau(tab, taille);

    printf("\n\nDonner l'element a chercher : ");
    scanf("%d", &elementAChercher);

    if(chercherElement(tab, taille, elementAChercher)){
        printf("%d se trouve dans la(es) position(s) : ", elementAChercher);
        afficherOccurrence(tab, taille, elementAChercher);
        printf("\nApres la suppression des occurences de %d ", elementAChercher);
        supprimerOccurrence(tab, taille, tabSansOccurences, &taille2, elementAChercher);
        afficherTableau(tabSansOccurences, taille2);
    }else{
        printf("%d ne se trouve pas dans le tableau.\n", elementAChercher);
    }

    printf("%d", chercherElementDansTableauTrie(tab, taille, elementAChercher));
  
    return 0 ;
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

int chercherElement(int *tab, int taille, int x){
    for(int  i = 0; i < taille; ++i){
        if(tab[i] == x){
            return 1;
        }
    }
    return 0;
}

void afficherOccurrence(int *tab, int taille, int x){
    for(int  i = 0; i < taille; ++i){
        if(tab[i] == x){
            printf("%d  ", i);
        }
    }
}

void supprimerOccurrence(int *tab, int taille, int *tabSansOccurences, int *taille2, int x){
    *taille2 = 0;
    for(int  i = 0; i < taille; ++i){
        if(tab[i] != x){
            tabSansOccurences[*taille2] = tab[i];
            ++(*taille2);
        }
    }
}

int chercherElementDansTableauTrie(int *tab, int taille, int x){
    int min = 0;
    int max = taille;
    int milieu = 0;

    while (min <= max){
        milieu = (min + max) / 2;
        if(tab[milieu] == x){
            return milieu;
        }else if(tab[milieu] < x){
            min = milieu + 1;
        }else{
            max = milieu - 1;
        }
    }
    return -1;
}