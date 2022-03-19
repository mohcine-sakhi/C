#ifndef H_TABLES_HASHAGE
#define H_TABLES_HASHAGE

typedef struct Eleve Eleve;
struct Eleve{
    char *nom;
    int age;
    double note;
};


int hashage(char *chaine);
Eleve* rechercheTableHachage(Eleve* tableau[100], char *nom);
void insertion(Eleve* tableau[100], Eleve* eleve);

#endif