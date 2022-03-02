#include <stdio.h>
#include <stdlib.h>
#define N1 100
#define N2 50

int compare(char *s1, char *s2);
int length(char *s);
void copy(char *s1, char *s2);
void concatenate(char *s1, char *s2);
int contain(char *s1, char *s2);

int main(int argc, int *argv[]){
    char s1[N1] = "";
    char s2[N2] = "";
    char s3[N1] = "";

    printf("Donner la 1 chaine : ");
    scanf("%s", s1);

    printf("Donner la 2 chaine : ");
    scanf("%s", s2);

    //La comparaison
    if(compare(s1 , s2)){
        printf("Les deux chaines sont identiques.\n");
    }else{
        printf("Les deux chaines ne sont pas identiques.\n");
    }

    //est ce S1 contient S2
    if(contain(s1 , s2)){
        printf("La chaine %s est contenue dans %s.\n", s2, s1);
    }else{
        printf("La chaine %s n'est pas contenue dans %s.\n", s2, s1);
    }

    printf("=========Avant==========\n");
    printf("S1 : %s\n", s1);
    printf("S2 : %s\n", s2);
    printf("S3 : %s\n", s3);
    //La concatenation de deux chaines
    concatenate(s1, s2);
    //La copie d'une chaine dans une autre
    copy(s1, s3);
    printf("=========Apres==========\n");
    printf("S1 : %s\n", s1);
    printf("S2 : %s\n", s2);
    printf("S3 : %s\n", s3);
   
   


    return 0;
}


int length(char *s){
    int taille = 0;
    while (s[taille] != '\0'){
        ++taille;
    }
    return taille;    
}

int compare(char *s1, char *s2){

    if(length(s1) != length(s2)){
        return 0;
    }else{
        int i = 0;
        while (i < length(s1)){
            if(s1[i] != s2[i]){
                return 0;
            }
            ++i;
        }
       return 1;  
    }
    
}

void copy(char *s1, char *s2){
    int i = 0;
    while (s1[i] != '\0'){
        s2[i] = s1[i];
        ++i;
    }
    // le \0 ne va pas etre copier dans la boucle
    s2[i] = '\0';
}

void concatenate(char *s1, char *s2){
    int tailleChaine1 = length(s1);
    int tailleChaine2 = length(s2);
    int i = 0;
    s1[tailleChaine1] = ' ';
    do{
        s1[tailleChaine1 + 1 + i] = s2[i];
        ++i;
    }while(i < tailleChaine2);

}

int contain(char *s1, char *s2){
    if(length(s2) > length(s1)){
        return 0;
    }else{
        int i = 0;
        while (i < length(s1)){
            int j = 0;
            if(s2[j] == s1[i]){
                while (i < length(s1) && j < length(s2) && s2[j] == s1[i]){
                    ++i;
                    ++j;
                }
                if(j == length(s2)){
                    return 1;
                }
            }
            ++i;
        }
        return 0;
    }
}