#include <stdio.h>
#include <stdlib.h>
#include "taquin.h"
#include "taquin.c"
#include "matrice.h"
#include "matrice.c"

int main(int argc, int *argv[]){

     //Initialisation
    int **matriceInitiale = allouerMemoireMatrice(LIGNE, COLONNE);
    int **matriceFinale = allouerMemoireMatrice(LIGNE, COLONNE);
    int **matrice1 = allouerMemoireMatrice(LIGNE, COLONNE); 
    int **matrice2 = allouerMemoireMatrice(LIGNE, COLONNE); 

    printf("Etat initial\n");
    lireMatrice(matriceInitiale, LIGNE, COLONNE);
    printf("Etat final\n");
    lireMatrice(matriceFinale, LIGNE, COLONNE);    
   
    Etat *etatInitial = initialiseEtat(matriceInitiale);
    Etat *etatFinal = initialiseEtat(matriceFinale);
    

    etatInitial->arc = 0;
    etatInitial->cout = heuristique(etatInitial, etatFinal);
    etatInitial->estimation = estimation(etatInitial, etatFinal);

    etatFinal->arc = coutArc(etatInitial);
    etatFinal->cout = heuristique(etatFinal, etatFinal);
    etatFinal->estimation = estimation(etatFinal, etatFinal);

    rechercheAetoile (etatInitial, etatFinal, genereSuccesseurs, heuristique, coutArc);

    free(matriceInitiale);
    free(matriceFinale);
    free(etatInitial);
    free(etatFinal);
    
    return 0;
}