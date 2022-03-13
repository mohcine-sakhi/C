#include <stdio.h>
#include <stdlib.h>

int **allouerMemoire(int ligne, int colonne);
void libererMemoire(int **matrice, int ligne);
void lireDimentionsMatrice(int *ligne, int *colonne);
void lire(int **matrice, int ligne, int colonne);
void afficher(int **matrice, int ligne, int colonne); 
void sommeMatrices(int **somme, int **matrice1, int **matrice2, int ligne, int colonne);
void produitMatrices(int **produit, int **matrice1, int ligne1, int colonne1, int **matrice2, int ligne2, int colonne2);
int nulle(int **matrice, int ligne, int colonne);
int rechercher(int **matrice, int ligne, int colonne, int x);

int **allouerMemoire(int ligne, int colonne){
    int **matrice = NULL;

    matrice = (int **) malloc(ligne * sizeof(int*));
    if(matrice == NULL){
        printf("ERREUR !!!!");
    }

    for(int i = 0; i < ligne; ++i){
        matrice[i] = (int * )malloc(colonne * sizeof(int));
        if(matrice[i] == NULL){
            printf("ERREUR !!!!");
        }
    }
    return matrice;
}

void libererMemoire(int **matrice, int ligne){
    for(int i = 0; i < ligne; ++i){
            free(matrice[i]);
    }
    free(matrice);
}

void lireDimentionsMatrice(int *ligne, int *colonne){
    printf("Donner le nombre de lignes de la matrice : ");
    scanf("%d", ligne);

    printf("Donner le nombre de colonnes de la matrice : ");
    scanf("%d", colonne);
}

void lire(int **matrice, int ligne, int colonne){
    printf("Donner les elements de la matrice : \n");
    for(int i = 0; i < ligne; ++i){
        for(int j = 0; j < colonne; ++j){
            printf("T[%d][%d] = ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
    printf("\n\n");
}

void afficher(int **matrice, int ligne, int colonne){
    printf("Les elements de la matrice sont : \n");
    for(int i = 0; i < ligne; ++i){
        for(int j = 0; j < colonne; ++j){
            printf("T[%d][%d] = %d\t", i, j, matrice[i][j]);
        }
        printf("\n");
    }
     printf("\n\n");
} 

void sommeMatrices(int **somme, int **matrice1, int **matrice2, int ligne, int colonne){
    for(int i = 0; i < ligne; ++i){
        for(int j = 0; j < colonne; ++j){
            somme[i][j] = matrice1[i][j] + matrice2[i][j];
        }
        
    }
}

void produitMatrices(int **produit, int **matrice1, int ligne1, int colonne1, int **matrice2, int ligne2, int colonne2){
    int somme = 0;
    for(int i = 0; i <ligne1; ++i){
        for(int j = 0; j < colonne2; ++j){
            somme = 0;
            for(int k = 0; k < colonne1; ++k){
                somme += matrice1[i][k] * matrice2[k][j];
            }
            produit[i][j] = somme;
        }
    }
}

int nulle(int **matrice, int ligne, int colonne){
    for(int i = 0; i < ligne; ++i){
        for(int j = 0; j < colonne; ++j){
            if(matrice[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

int rechercher(int **matrice, int ligne, int colonne, int x){
    for(int i = 0; i < ligne; ++i){
        for(int j = 0; j < colonne; ++j){
            if(matrice[i][j] == x){
                printf("L'element %d se trouve a la position (%d, %d)\n", x, i, j);
                return 1;
            }
        }
    }
    return -1;
}
