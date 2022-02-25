#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int premier(int nombre);

int main(int argc, int *argv[]){
    /*
    char caractere = ' ';
    int compteurB = 0;
    int compteurEspace = 0;
    do{
        printf("Entrer un caractere ou * pour arreter : ");
        scanf("%c", &caractere);
        if(caractere == 'b'){
            ++compteurB;
        }else if(caractere == ' '){
            ++compteurEspace;
        }
    }while(caractere != '*');

    printf("Vous avez tape %d fois le caractere 'b' et %d espace(s)", compteurB, compteurEspace);
    */

   /*
   int max = -__INT_MAX__;
   int nombre = 0;
   int i = 0;
   int position = 0;
   do{
       ++i;
       printf("Donner le %d nombre : ", i);
       scanf("%d", &nombre);
       if(max < nombre){
        max = nombre;
        position = i;
       }
       
   }while(i < 5);

   printf("Le max des %d numeros saisis est %d et se trouve dans la position %d.\n", i, max, position);
    */
   int nombre = 0;
   do{
        printf("Donner un nombre strictement positif : ");
        scanf("%d", &nombre);
   }while(nombre <= 0);
   
   if(premier(nombre) == 1){
       printf("%d est premier.", nombre);
   }else{
       printf("%d n'est pas premier.", nombre);
   }

   return 0;
}

int premier(int nombre){
    if(nombre == 1){
        return 0;
    }
    int racine = sqrt(nombre);
    int i = 2;
    while(i <= racine){
        if(nombre % i == 0){
            return 0;
        }
        ++i;
    }
    return 1;

}