#include <stdio.h>
#include <stdlib.h>

int parfait(int nombre);

int main(int argc, int* argv[]){

    /* int nombre = 0;
    do{
        printf("Entrer un numero : ");
        scanf("%d", &nombre);
    }while(nombre <= 0);
    

    if(parfait(nombre)){
        printf("%d est parfait.\n", nombre);
    }else{
        printf("%d n'est pas parfait.\n", nombre);
    } */

    int nombre = 0;
    do{
        printf("Donner un seuil : ");
        scanf("%d", &nombre);
    }while(nombre <= 0);

    printf("Les nombres parfaits inferieurs a %d sont : \n", nombre);
    for(int i = 1; i <=nombre; ++i){
        if(parfait(i)){
            printf("%d ", i);
        }
    }

    return 0;
}

int parfait(int nombre){
    int somme = 0;
    for(int i = 1; i <= nombre / 2; ++i){
        if(nombre % i == 0){
            somme += i;
        }
    }

    return (nombre == somme) ? 1 : 0;
}