#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void lire(int *tab, int taille);
void afficher(int *tab, int taille);
void inverser(int *tab, int taille);
void trier(int *tab, int taille);
int estPremier(int a);
int premier(int *tab, int taille);
int rechercher(int *tab, int taille, int x);
int rechercherParDichotomie(int *tab, int taille, int x);
void concatener(int *tab1, int taille1, int *tab2, int taille2);

int main(int argc, int *argv[]){
    int taille = 0;
    int *tab = NULL;
    int taille2 = 0;
    int *tab2 = NULL;

    printf("Donner la taille du 1 tableau : ");
    scanf("%d", &taille);

    tab = malloc(taille * sizeof(int));
    lire(tab, taille);
    afficher(tab, taille);

    printf("Donner la taille du 2 tableau : ");
    scanf("%d", &taille2);

    tab2 = malloc(taille2 * sizeof(int));
    lire(tab2, taille2);
    afficher(tab2, taille2);

    printf("Apres concatenation des 2 tableaux : \n");
    tab = realloc(tab, (taille + taille2) * sizeof(int));
    concatener(tab, taille, tab2, taille2);
    afficher(tab, taille + taille2);
    


   /*  printf("Apres inversement du tableau : \n");
    inverser(tab, taille);
    afficher(tab, taille);
    printf("Apres tri du tableau : \n");
    trier(tab, taille);
    afficher(tab, taille);

    if(premier(tab, taille)){
        printf("Le tableau est premier.\n");
    }else{
        printf("Le tableau n'est pas premier.\n");
    }

    int x = 0;
    printf("Donner l'element a rechercher dans le tableau : ");
    scanf("%d", &x);
    if(rechercherParDichotomie(tab, taille, x) == -1){
        printf("L'element %d n'existe pas dans le tableau.\n", x);
    }else{
        printf("La prmeiere occurence de %d se trouve dans la position %d.\n", x, rechercher(tab, taille, x));
    } */

    free(tab);
    free(tab2);

    return 0;
}

void lire(int *tab, int taille){
    printf("Donner les elements du tableau : \n");
    for(int i = 0; i < taille; ++i){
        printf("tab[%d] : ", i);
        scanf("%d", (tab + i));
    }
    printf("\n\n");
}

void afficher(int *tab, int taille){
    printf("Les elements du tableau : \n");
    for(int i = 0; i < taille; ++i){
        printf("tab[%d]=%d  ", i, *(tab + i));   
    }
    printf("\n\n");
}

void inverser(int *tab, int taille){
    int temp = 0;

    for(int i = 0; i < taille / 2; ++i){
        temp = *(tab + i);
        *(tab + i) = *(tab + taille - 1 - i);
        *(tab + taille - 1 - i) = temp;
    }
}

void trier(int *tab, int taille){
     int temp = 0;

    for(int i = 0; i < taille -1 ; ++i){
        for (int j = i + 1; j < taille; ++j){
            if(*(tab + i) > *(tab + j)){
                temp = *(tab + i);
                *(tab + i) = *(tab + j);
                *(tab + j) = temp;
            }
        }
    }
}

int estPremier(int a){
    int racine = sqrt(a);
    if(a == 0 || a == 1){
        return 0;
    }else{
        for(int i = 2; i <= racine; ++i){
            if(a % i == 0){
                return 0;
            }
        }
        return 1;
    }
}

int premier(int *tab, int taille){
    for (int i = 0; i < taille; ++i){
        if( ! estPremier(*(tab + i))){
            return 0;
        }
    }
    return 1;
}

int rechercher(int *tab, int taille, int x){
    for (int i = 0; i < taille; ++i){
        if(*(tab + i) == x){
            return i;
        }
    }
    return -1;
}

int rechercherParDichotomie(int *tab, int taille, int x){
    trier(tab, taille);
    int milieu = 0;
    int min  = 0;
    int max = taille - 1;

    while (min <= max){
        milieu = (max + min) / 2;
        if(*(tab + milieu) == x){
            return milieu;
        }else if(*(tab + milieu) > x){
            max = milieu - 1;
        }else{
            min = milieu +1;
        }
    }
    return -1;
}

void concatener(int *tab1, int taille1, int *tab2, int taille2){
    
    for(int i = 0; i < taille2; ++i){
        *(tab1 + taille1 + i ) = *(tab2 + i);
    }
}