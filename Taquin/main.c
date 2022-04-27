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

    //Liste *listeDesNoeuds = initialiseListe();
    
    //inserer(etatFinal, listeDesNoeuds);
    //inserer(etatInitial, listeDesNoeuds);
    //inserer(etatInitial, listeDesNoeuds);
    //inserer(etatInitial, listeDesNoeuds);
    //inserer(etatFinal, listeDesNoeuds);
    
    
    //afficheListeNoeuds(listeDesNoeuds); 

    //printf("Appartient : %d\n", appartient(etatFinal, listeDesNoeuds));

    //Liste *listeSuccesseurs = initialiseListe();
    //genereSuccesseurs(etatInitial, etatFinal, listeSuccesseurs);
    
    //afficheListeNoeuds(listeSuccesseurs);
    
   
    //CopieMatrice(matriceInitiale, etatInitial->estimation);
    

   /*  printf("etatInitial\n");
    afficheNoeud(etatInitial, LIGNE, COLONNE);
    printf("etatFinal\n");
    afficheNoeud(etatFinal, LIGNE, COLONNE);  */

    free(matriceInitiale);
    free(matriceFinale);
    free(etatInitial);
    free(etatFinal);
    //free(listeSuccesseurs);
    return 0;
}