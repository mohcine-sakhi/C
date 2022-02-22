#include <stdio.h>
#include <stdlib.h>

int main(int argc, int *argv[]){
    int longueur = 0;
    int largeur = 0;
    int perimetre = 0;
    int surface = 0;
    char chaine[10];

    printf("Donner la longueur du rectangle en m : ");
    fgets(chaine, 10, stdin);
    longueur = strtol(chaine, NULL, 10);

    printf("Donner la largeur du rectangle en m: ");
    fgets(chaine, 10, stdin);
    largeur = strtol(chaine, NULL, 10);

    perimetre = 2 * (longueur + largeur);
    surface = longueur * largeur;

    printf("Le perimetre du rectangle est %dm et sa surface est %dm².\n", perimetre, surface);
    



    return 0;
}