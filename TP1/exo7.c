#include <stdio.h>
#include <stdlib.h>

double suite(int terme, double x);

int main(int argc, int *argv[]){
    
   double x = 0;
   int rang = 0;

    do{
        printf("Donner le rang de la suite : ");
        scanf("%d", &rang);
    }while (rang < 0);

    do{
        printf("Donner x : ");
        scanf("%lf", &x);
    }while (x < -1 ||  x > 1 );

    if(rang == 0){
        printf("T0 = %.2lf\n", suite(rang, x));
    } else if(rang == 1){
        printf("T1 = %.2lf\n", suite(rang, x));
    }else{
        printf("T%d = %.2lf\n", rang, suite(rang, x));
    }
    

    return 0;
}

double suite(int terme, double x){
    double t0 = 1;
    double t1 = x;
    double tn = 0;

    if(terme == 0){
        return t0;
    } else if(terme == 1){
        return t1;
    }else{
        for(int i = 2; i <= terme; ++i){
            tn = 2 * x * t1 - t0;
            t0 = t1;
            t1 = tn;
        }
        return tn;
    }

}