#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

int **allouerMemoireMatrice(int ligne, int colonne){
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

void libererMemoireMatrice(int **matrice, int ligne){
    for(int i = 0; i < ligne; ++i){
            free(matrice[i]);
    }
    free(matrice);
}


void lireMatrice(int **matrice, int ligne, int colonne){
    for(int i = 0; i < ligne; ++i){
        for(int j = 0; j < colonne; ++j){
            printf("T[%d][%d] = ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
    printf("\n\n");
}

void afficherMatrice(int **matrice, int ligne, int colonne){
    
    for(int i = 0; i < ligne; ++i){
        for(int j = 0; j < colonne; ++j){
            if(matrice[i][j] == 0){
                printf("  ");
            }else{
                printf("%d ", matrice[i][j]);
            }
            
        }
        printf("\n");
    }
}

int matricesSemblables(int **matriceSource, int **matriceDestination, int ligne, int colonne){

    if(matriceSource == NULL || matriceDestination == NULL){
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < ligne; ++i){
        for (int j = 0; j < colonne; ++j){
            if(matriceSource[i][j] != matriceDestination[i][j]){
                return 0;
            }
        }  
    }
    return 1;
} 


void copieMatrice(int **matriceSource, int **matriceDestination, int ligne, int colonne){
    for(int i = 0; i < ligne; ++i){
        for (int j = 0; j < colonne; ++j){
            matriceDestination[i][j] = matriceSource[i][j];      
        }  
    }

}

Position *recupererPosition(int **matrice, int ligne, int colonne, int valeur){

    Position *position = (Position*) malloc(sizeof(Position));
    if(position == NULL){
        exit(EXIT_FAILURE);
    }
    position->x = -1;
    position->y = -1;
    int quitter = 0;
    for(int i = 0; !quitter && i < ligne; ++i){
        for (int j = 0; !quitter && j < colonne; ++j){
            if(matrice[i][j] == valeur){
                position->x = i;
                position->y = j;
                quitter = 1;
            }       
        }  
    }

    return position;

}






