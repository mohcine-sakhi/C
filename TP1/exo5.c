#include <stdio.h>
#include <stdlib.h>

int sommeDiviseurs(int nombre);
int amicaux(int a, int b);

int main(int argc, int *argv[]){

     int nombre1 = 0;
     int nombre2 = 0;
    do{
        printf("Donner le 1 numero : ");
        scanf("%d", &nombre1);
    }while(nombre1 <= 0);

    do{
        printf("Donner le 2 numero : ");
        scanf("%d", &nombre2);
    }while(nombre2 <= 0);

    if(amicaux(nombre1, nombre2)){
        printf("%d et %d sont des nombres amicaux.\n", nombre1, nombre2);
    }else{
        printf("%d et %d ne sont pas des nombres amicaux.\n", nombre1, nombre2);
    }
    
    return 0;
}

int sommeDiviseurs(int nombre){
    int somme =0;
    for(int i = 1; i <= nombre / 2; ++i){
        if(nombre % i == 0){
            somme += i;
        }
    }

    return somme;
}
int amicaux(int a, int b){
    int sommeDiviseursA = sommeDiviseurs(a);
    int sommeDiviseursB = sommeDiviseurs(b);

    return ( a != b && sommeDiviseursA == b && sommeDiviseursB == a ) ? 1 : 0;
}