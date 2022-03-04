#include <stdio.h>
#include <stdlib.h>

void mention(double note);

int main(int argc, int *argv[]){
    double note = 0;

    do{
        printf("Donner votre note (>= 0 et <= 20) : ");
        scanf("%lf", &note);
    } while (note < 0 || note > 20);
    
    mention(note);

    return 0;
}

void mention(double note){
    printf("Votre mention est : ");
    if(note < 10){
        printf("Renvoye\n");
    }else if(note < 12){
        printf("Ajourne\n");
    }
    else if(note < 14){
        printf("A Bien\n");
    }else if(note < 16){
        printf("Bien\n");
    }else if(note < 18){
        printf("Très Bien\n");
    }else{
        printf("Excellent\n");
    }
}