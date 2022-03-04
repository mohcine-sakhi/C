#include <stdio.h>
#include <stdlib.h>

int carre(int a);

int main(int argc, int *argv[]){
    int a = 0;
    printf("Donner un entier : ");
    scanf("%d", &a);
    printf("Le carre de %d est : %d\n", a , carre(a));
    
    return 1;
}

int carre(int a){
    return a * a;
}