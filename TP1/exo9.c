#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sommeSuite(int nombre);

int main(int argc, int *argv[]){

    double somme = 0;
    double sommeApprochee = 0;
    int rang = 1;

    do{
        sommeApprochee = somme;
        somme = sommeSuite(rang);
        ++rang;
    }while (somme - sommeApprochee  > 0.000001 || somme - sommeApprochee <-0.000001);
    

    printf("une approximation de π (a 10-6 pres) est %lf\n", sqrt(6 * somme));

    return 0;
}

double sommeSuite(int nombre){
    double somme = 0;

    for(int i = 1; i <= nombre; ++i){
        somme += 1 / (double) (i * i);
    }

    return somme;
}