#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorielle(int nombre);

int main(int argc, int *argv[]){

    double x = 0;
    int rang = 0;
    double somme = 0;
    double sommeApprochee = 0;

    do{
        printf("Donner le rang de la suite : ");
        scanf("%d", &rang);
    }while (rang < 0);

    do{
        printf("Donner x : ");
        scanf("%lf", &x);
    }while (x <= 0 );

    for(int i = 0; i <= rang; ++i){
        somme += pow(x, i) / factorielle(i);
    }

    printf("La somme de la suite est %lf\n", somme);

    int terme = 0;
    somme = 0;

    do {
        sommeApprochee = somme;
        somme += pow(x, terme) / factorielle(terme);
        ++terme;
        printf("Somme : %lf\n", sommeApprochee);

    } while ((somme - sommeApprochee <= 0.000000001) || (somme - sommeApprochee >= -0.000000001));
    
    printf("Une valeur approchee (a 10-6 pres) de la suite est %lf\n", sommeApprochee);

    return 0;
}

int factorielle(int nombre){
    if(nombre == 0 || nombre == 1){
        return 1;
    }else{
        return nombre * factorielle(nombre - 1);
    }
    
}