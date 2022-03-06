#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void lire(int *tab, int taille);
void afficher(int *tab, int taille);
void inverser(int *tab, int taille);
void trier(int *tab, int taille, int ordre);
int estPremier(int a);
int premier(int *tab, int taille);
int rechercher(int *tab, int taille, int x);
int rechercherParDichotomie(int *tab, int taille, int x);
void concatener(int *tab1, int taille1, int *tab2, int taille2);
int menu();

int main(int argc, int *argv[]){
    int taille1 = 0;
    int *tab = NULL;
    int taille2 = 0;
    int *tab2 = NULL;
    int taille = 0;
    int numeroMenu = 0;
    int x = 0;

    printf("Donner la taille du 1 tableau : ");
    scanf("%d", &taille1);

    tab = malloc(taille1 * sizeof(int));
    lire(tab, taille1);
    afficher(tab, taille1);

    numeroMenu = menu();

    switch (numeroMenu){
    case 1 :
        printf("Apres inversement du tableau : \n");
        inverser(tab, taille1);
        afficher(tab, taille1);
        break;
    
    case 2 :
        printf("Apres le tri croissant du tableau : \n");
        trier(tab, taille1, 1);
        afficher(tab, taille1);
        break;

    case 3 :
        printf("Apres le tri decroissant du tableau : \n");
        trier(tab, taille1, -1);
        afficher(tab, taille1);
        break;

    case 4 :
        if(premier(tab, taille1)){
            printf("Le tableau est premier.\n");
        }else{
            printf("Le tableau n'est pas premier.\n");
        }
        break;    
    
    case 5 :
        printf("Donner l'element a rechercher dans le tableau : ");
        scanf("%d", &x);
        if(rechercher(tab, taille1, x) == -1){
            printf("L'element %d n'existe pas dans le tableau.\n", x);
        }else{
            printf("La prmeiere occurence de %d se trouve dans la position %d.\n", x, rechercher(tab, taille1, x));
        } 
        break;

    case 6 :
        printf("Donner l'element a rechercher dans le tableau : ");
        scanf("%d", &x);
        if(rechercherParDichotomie(tab, taille1, x) == -1){
            printf("L'element %d n'existe pas dans le tableau.\n", x);
        }else{
            printf("La prmeiere occurence de %d se trouve dans la position %d.\n", x, rechercherParDichotomie(tab, taille1, x));
        }
        break;    

    case 7 :
        printf("Donner la taille du 2 tableau : ");
        scanf("%d", &taille2);

        tab2 = malloc(taille2 * sizeof(int));
        lire(tab2, taille2);
        afficher(tab2, taille2);

        printf("Apres concatenation des 2 tableaux : \n");
        taille = taille1 + taille2;
        tab = realloc(tab, taille * sizeof(int));
        concatener(tab, taille1, tab2, taille2);
        afficher(tab, taille);
        break;    
    }
    
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

void trier(int *tab, int taille, int ordre){
    int temp = 0;
    //ordre croissant
    if(ordre == 1){
        for(int i = 0; i < taille -1 ; ++i){
            for (int j = i + 1; j < taille; ++j){
                if(*(tab + i) > *(tab + j)){
                    temp = *(tab + i);
                    *(tab + i) = *(tab + j);
                    *(tab + j) = temp;
                }
            }
        }
    //ordre decroissant    
    }else{
        for(int i = 0; i < taille -1 ; ++i){
            for (int j = i + 1; j < taille; ++j){
                if(*(tab + i) < *(tab + j)){
                    temp = *(tab + i);
                    *(tab + i) = *(tab + j);
                    *(tab + j) = temp;
                }
            }
        }
    }
   
}

//verifier si un nombre est premier
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

//verifier si un tableau est premier
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
    trier(tab, taille, 1);
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

int menu(){
    int menu = 0;
    printf("=================Menu==============\n");
    printf("1. Inverser\n");
    printf("2. Trier par ordre croissant\n");
    printf("3. Trier par ordre decroissant\n");
    printf("4. Est-il premier ?\n");
    printf("5. Rechercher\n");
    printf("6. Rechercher par dichotomie\n");
    printf("7. Concatener avec un 2 tableau\n\n");

    do{
        printf("Choisir l'operation a appliquer au tableau : ");
        scanf("%d", &menu);
        printf("\n");
    }while (menu < 1 || menu > 7);
    
    return menu;
}