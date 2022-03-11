#include <stdio.h>
#include <stdlib.h>

void lire(int **matrice, int ligne, int colonne);
void afficher(int **matrice, int ligne, int colonne); 
void sommeMatrices(int **somme, int **matrice1, int **matrice2, int ligne, int colonne);

int main(int argc, int *argv[]){
    int ligne = 0;
    int colonne = 0;
    int **matrice1 = NULL;
    int **matrice2 = NULL;
    int **somme = NULL;

    printf("Donner le nombre de lignes de la matrice : ");
    scanf("%d", &ligne);

    printf("Donner le nombre de colonnes de la matrice : ");
    scanf("%d", &colonne);

    //L'allocation de la memoire
    matrice1 = malloc(ligne * sizeof(*matrice1));
    if(matrice1 == NULL){
        printf("ERREUR !!!!");
    }

    for(int i = 0; i < ligne; ++i){
        matrice1[i] = malloc(colonne * sizeof(**matrice1));
        if(matrice1[i] == NULL){
            printf("ERREUR !!!!");
        }
    }

    matrice2 = malloc(ligne * sizeof(*matrice2));
    if(matrice2 == NULL){
        printf("ERREUR !!!!");
    }

    for(int i = 0; i < ligne; ++i){
        matrice2[i] = malloc(colonne * sizeof(**matrice2));
        if(matrice2[i] == NULL){
            printf("ERREUR !!!!");
        }
    }

    somme = malloc(ligne * sizeof(*somme));
    if(somme == NULL){
        printf("ERREUR !!!!");
    }

    for(int i = 0; i < ligne; ++i){
        somme[i] = malloc(colonne * sizeof(**somme));
        if(somme[i] == NULL){
            printf("ERREUR !!!!");
        }
    }

    //Traitement
    lire(matrice1, ligne, colonne);
    afficher(matrice1, ligne, colonne);

    lire(matrice2, ligne, colonne);
    afficher(matrice2, ligne, colonne);

    sommeMatrices(somme, matrice1, matrice2, ligne, colonne);
    afficher(somme, ligne, colonne);

    //La liberation de la memoire
    for(int i = 0; i < ligne; ++i){
        free(matrice1[i]);
    }
    free(matrice1);

    for(int i = 0; i < ligne; ++i){
        free(matrice2[i]);
    }
    free(matrice2);

    for(int i = 0; i < ligne; ++i){
        free(somme[i]);
    }
    free(somme);

    

    

    return 0;
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
