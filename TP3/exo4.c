#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int chaine_vers_entier(char *s);
char* miroir(char *s);
char* cherche_remplace(char c, char r, char *s);
int length(const char *src);

int main(int argc, int *argv[]){

    char *chaine = NULL;
    char c = ' ';
    char r = ' ';

    chaine = (char*) malloc(100 * sizeof(char));
    
    printf("Entrer un entier sous forme de chaine : ");
    scanf("%s", chaine);

    printf("Vous avez entre le nombre : %d\n", chaine_vers_entier(chaine));

    printf("Entrer la chaine a renverser : ");
    scanf("%s", chaine);

    printf("La chaine renversee est : %s\n",  miroir(chaine));

    printf("Entrer une chaine : ");
    scanf("%s", chaine);

    printf("Entrer le caractere a remplacer : ");
    getchar();
    scanf("%c", &c);

    printf("Entrer le caractere de remplacement : ");
    getchar();
    scanf("%c", &r);

    printf("La chaine apres remplacement de %c par %c est : %s\n", c, r, cherche_remplace(c, r, chaine));

    return 0;
}

int length(const char *src){
    int i = 0;
    while(src[i] != '\0'){
        ++i;
    }
    return i;
}

int chaine_vers_entier(char *s){
    int i = 0 ;
    int entier = 0;
    while(i < length(s)){
        //48 represente le code ASCII de 0, 49 pour 1 ...
        entier += (s[i] - '0') * round(pow(10, length(s) - 1 - i));
        ++i;
    }

    return entier;
}

char* miroir(char *s){
    char temp = ' ';
    for(int i = 0; i < length(s) / 2; ++i){
        temp = s[i];
        s[i] = s[length(s) - 1 - i];
        s[length(s) - 1 - i] = temp;
    }

    return s;
}

char* cherche_remplace(char c, char r, char *s){
    int i = 0;
    while (i < length(s)){
        if(s[i] == c){
            s[i] = r;
        }
        ++i;
    }
    
    return s;
}