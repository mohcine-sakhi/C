#include <stdio.h>
#include <stdlib.h>

int A = 0;
int B = 0;

void lecture();
int somme(int a, int b);
int produit(int a, int b);

int main(int argc, int *argv[]){
    lecture();
    printf("La somme de %d et %d est : %d\n", A, B, somme(A, B));
    printf("Le produit de %d et %d est : %d\n", A, B, produit(A, B));
    return 0;
}

void lecture(){
    printf("Donner un entier : ");
    scanf("%d", &A);
    printf("Donner un entier : ");
    scanf("%d", &B);
}
int somme(int a, int b){
    return a + b;
}
int produit(int a, int b){
    return a * b;
}