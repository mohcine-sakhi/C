#include <stdio.h>
#include <stdlib.h>

long long suite(int terme);

int main(int argc, int *argv[]){
  
    int rang = 0;
    do{
        printf("Donner le rang de la suite : ");
        scanf("%d", &rang);
    }while (rang < 0);

    if(rang == 0){
        printf("U0 = %ld\n", suite(rang));
    } else if(rang == 1){
        printf("U1 = %ld\n", suite(rang));
    }else{
        printf("U%d = %ld\n", rang, suite(rang));
    }
   
   printf("Les 100 premiers termes de la suite sont : \n");
   for(int i = 0; i <= 100; ++i){
       printf("U%d = %ld\n", i, suite(i));
   }
    
    return 0;
}

long long suite(int terme){
    long long u0 = 4;
    long long u1 = 4;
    long long un = 0;

    if(terme == 0){
        return u0;
    } else if(terme == 1){
        return u1;
    }else{
        for(int i = 2; i <= terme; ++i){
            un = 3 * u1 + 4 * u0 + 6;
            u0 = u1;
            u1 = un;
        }
        return un;
    }

}