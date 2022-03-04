#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
int min(int a, int b);

int main(int argc, int *argv[]){
    int a = 0;
    int b = 0;

    printf("Donner le 1 entier : ");
    scanf("%d", &a);
    printf("Donner le 2 entier : ");
    scanf("%d", &b);

    printf("Le max de %d et %d est : %d\n", a, b, max(a, b));
    printf("Le min de %d et %d est : %d\n", a, b, min(a, b));

    return 1;
}

int max(int a, int b){
    return (a > b) ? a : b;
}
int min(int a, int b){
    return (a < b) ? a : b;
}
