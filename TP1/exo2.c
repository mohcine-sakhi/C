#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void devinerLettre(char caractere);
void majusculeOuMinuscule(char caractere);
void afficherJour(int jour);
void resoudreEquation(int a, int b, int c);


int main(int argc, int *argv[]){
    char caractere = ' ';
    int jour = 0;
    int a = 0;
    int b = 0;
    int c = 0;

    printf("Deviner une lettre : ");
    scanf("%c", &caractere);
    devinerLettre(caractere);
    majusculeOuMinuscule(caractere);

    printf("Donner le numero du jour : ");
    scanf("%d", &jour);
    afficherJour(jour);

    printf("Entrer les coeficients de l'eqatuion ax² + bx + c.\n");

    printf(" a : ");
    scanf("%d", &a);
    printf(" b : ");
    scanf("%d", &b);
    printf(" c : ");
    scanf("%d", &c);

    resoudreEquation(a, b, c);
    return 0;
}

void devinerLettre(char caractere){

    if(caractere == 'A' || caractere == 'a'){
        printf("Vous avez devine la lettre. Bravoooooo !!\n");
    }else{
        printf("Votre reponse est fausse. Dommaaaaage !!\n");
    }
}

void majusculeOuMinuscule(char caractere){

    if(caractere >= 'A' && caractere <= 'Z'){
        printf("%c est une majuscule !!\n", caractere);

    }else  if(caractere >= 'a' && caractere <= 'z'){
        printf("%c est une miniscule !!\n", caractere);

    }else{
        printf("Ce n'est pas une lettre !!\n");
    }
}

void afficherJour(int jour){
    switch (jour){
    case 1 :
        printf("C'est Lundi !\n");
        break;
    case 2 :
        printf("C'est Mardi !\n");
        break;
    case 3 :
        printf("C'est Mercredi !\n");
        break;
    case 4 :
        printf("C'est Jeudi !\n");
        break;
        
    case 5 :
        printf("C'est Vendredi !\n");
        break;  
    case 6 :
        printf("C'est Samedi !\n");
        break;  
    case 7 :
        printf("C'est Dimanche !\n");
        break;    
    
    default:
        printf("Ce n'est pas un jour !!!\n");
    }

}

void resoudreEquation(int a, int b, int c){
    int delta = b * b - 4 * a * c;
    double x1 = 0;
    double x2 = 0;

    if(delta < 0){
        printf("L'equation n'a pas de solutions !!\n");
    }else if (delta == 0){
        x1 = (double)-b / (2 * a);
        printf("La solution de l'equation est %f.\n", x1);
    }else{
        x1 = (double)(-b - sqrt(delta)) / (2 * a);
        x2 = (double)(-b + sqrt(delta)) / (2 * a);
        printf("Les solutions de l'equation sont %f et %f.\n", x1, x2);
    }
}