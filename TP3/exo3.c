#include <stdio.h>
#include <stdlib.h>

char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
int strcmp(const char *str1, const char *str2);
char *strncat(char *dest, const char *src, size_t n);
int length(const char *src);


int main(int argc, int *argv[]){
    char *dest = NULL;
    char *src = NULL;

    src = (char*) malloc(100 * sizeof(char));
    dest = (char*) malloc(100 * sizeof(char));

    printf("Entrer une 1 chaine : ");
    scanf("%s", src);

    //strncpy(dest, src, 1);
    //strncpy(dest, src, 1);

    printf("Entrer une 2 chaine : ");
    scanf("%s", dest);

    printf("source : %s\n", src);
    printf("destination : %s\n", dest);

    /* if(strcmp(dest, src)){
        printf("Les deux chaines sont identiques\n");
    }else{
        printf("Les deux chaines ne sont pas identiques\n");
    } */

    strncat(dest, src, 10);
    
    printf("source : %s\n", src);
    printf("destination : %s\n", dest);

    return 0;
}

char *strcpy(char *dest, const char *src){
    int i = 0;
    do{
        dest[i] = src[i];
        ++i;
    }while (src[i] != '\0');

   return dest;   
}

char *strncpy(char *dest, const char *src, size_t n){
    int i = 0;
    do{
        dest[i] = src[i];
        ++i;
    }while (src[i] != '\0' && i < n);
    dest[i] = '\0';
   return dest; 
}

int strcmp(const char *str1, const char *str2){
    int i = 0;
    while(str1[i] != '\0'){
        if(str1[i] != str2[i]){
            return 0;
        }
        ++i;
    }
    return 1;
}

int length(const char *src){
    int i = 0;
    while(src[i] != '\0'){
        ++i;
    }
    return i;
}

char *strncat(char *dest, const char *src, size_t n){
    int tailleChaine1 = length(dest);
    int i = 0;

    dest[tailleChaine1] = ' ';
    
    do{
        dest[tailleChaine1 + 1 + i] = src[i];
        ++i;
    } while (src[i] != '\0' && i < n);

    return dest;
}

