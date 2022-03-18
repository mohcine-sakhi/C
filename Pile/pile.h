#ifndef H_PILE
#define H_PILE

typedef struct Element Element;
struct Element{
    int nombre;
    Element *suivant;
};

typedef struct Pile Pile;
struct Pile{
    Element *premier;
    int nbElement;
};

Pile *initialiser();
void empiler(Pile *pile, int nb);
int depiler(Pile *pile);
void afficherPile(Pile *pile);

#endif