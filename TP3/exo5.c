#include <stdio.h>
#include <stdlib.h>
#include "exo5.h"


int main(int argc, int *argv[]){
    int menu = 0;
    int ligne1 = 0;
    int colonne1 = 0;
    int ligne2 = 0;
    int colonne2 = 0;
    int x = 0;
    int **matrice1 = NULL;
    int **matrice2 = NULL;
    int **somme = NULL;
    int **produit = NULL;

    do{
        printf("Choisir l'operation a effectuer : \n");
        printf(" 1 : Somme de deux matrices\n");
        printf(" 2 : Produit de deux matrices\n");
        printf(" 3 : Est ce que la matriced est nulle ?\n");
        printf(" 4 : Rechercher dans une matrice\n\n");
        scanf("%d", &menu);
        if(menu < 0 || menu > 4){
            printf("Il faut choisir un numero valable !!\n\n");
        }
    }while(menu < 0 || menu > 4);

    switch (menu){
    case 1:
        printf("Somme de deux matrices\n");
        printf("Matrice 1\n");
        lireDimentionsMatrice(&ligne1, &colonne1);
        printf("Matrice 2\n");
        lireDimentionsMatrice(&ligne2, &colonne2);
        if(ligne1 == ligne2 && colonne1 == colonne2){
        //L'allocation de la memoire
        matrice1 = allouerMemoire(ligne1, colonne1);
        matrice2 = allouerMemoire(ligne2, colonne2);
        somme = allouerMemoire(ligne1, colonne1);

        //Traitement
        printf("Matrice 1\n");
        lire(matrice1, ligne1, colonne1);

        printf("Matrice 2\n");
        lire(matrice2, ligne2, colonne2);

        printf("Matrice 1\n");
        afficher(matrice1, ligne1, colonne1);

        printf("Matrice 2\n");
        afficher(matrice2, ligne2, colonne2);

        printf("La somme des deux matrices\n");
        sommeMatrices(somme, matrice1, matrice2, ligne1, colonne1);
        afficher(somme, ligne1, colonne1);

        //La liberation de la memoire
        libererMemoire(matrice1, ligne1);
        libererMemoire(matrice2, ligne2);
        libererMemoire(somme, ligne1);

        }else {
            printf("La somme des deux matrices n'est pas possible\n");
        }
        break;

    case 2:
        printf("Produit de deux matrices\n");
        printf("Matrice 1\n");
        lireDimentionsMatrice(&ligne1, &colonne1);
        printf("Matrice 2\n");
        lireDimentionsMatrice(&ligne2, &colonne2);
        if(colonne1 == ligne2){
        //L'allocation de la memoire
        matrice1 = allouerMemoire(ligne1, colonne1);
        matrice2 = allouerMemoire(ligne2, colonne2);
        produit = allouerMemoire(ligne1, colonne2);

        //Traitement
        printf("Matrice 1\n");
        lire(matrice1, ligne1, colonne1);

        printf("Matrice 2\n");
        lire(matrice2, ligne2, colonne2);

        printf("Matrice 1\n");
        afficher(matrice1, ligne1, colonne1);

        printf("Matrice 2\n");
        afficher(matrice2, ligne2, colonne2);

        printf("Le produit des deux matrices\n");
        produitMatrices(produit, matrice1, ligne1, colonne1, matrice2, ligne2, colonne2);
        afficher(produit, ligne1, colonne2);

        //La liberation de la memoire
        libererMemoire(matrice1, ligne1);
        libererMemoire(matrice2, ligne2);
        libererMemoire(produit, ligne1);

        }else {
            printf("Le produit des deux matrices n'est pas possible\n");
        }
        break;

    case 3:
        printf("Est ce que la matriced est nulle ?\n");
        lireDimentionsMatrice(&ligne1, &colonne1);
        //L'allocation de la memoire
        matrice1 = allouerMemoire(ligne1, colonne1);

        lire(matrice1, ligne1, colonne1);
        afficher(matrice1, ligne1, colonne1);

        if(nulle(matrice1, ligne1, colonne1)){
            printf("La matrice est nulle\n");
        }else{
            printf("La matrice n'est pas nulle\n");
        }
        //La liberation de la memoire
        libererMemoire(matrice1, ligne1);
        break;
    
    case 4:
        printf("Rechercher dans une matrice\n");
        lireDimentionsMatrice(&ligne1, &colonne1);
        //L'allocation de la memoire
        matrice1 = allouerMemoire(ligne1, colonne1);

        lire(matrice1, ligne1, colonne1);
        afficher(matrice1, ligne1, colonne1);

        printf("Donner l'element a rechercher : ");
        scanf("%d", &x);

        int trouve = rechercher(matrice1, ligne1, colonne1, x);
        if(trouve == -1){
            printf("%d n'existe pas dans la matrice\n", x);
        }

        //La liberation de la memoire
        libererMemoire(matrice1, ligne1);
        break;
    
    }

    return 0;
}

