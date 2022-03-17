#ifndef H_LISTE_CHAINEE
#define H_LISTE_CHAINEE

typedef struct Element Element;
struct Element{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste{
    Element *premier;
    int nbElements;
};

Liste *initialisation();
void destruction(Liste *liste);
void insertion(Liste *liste, int nb);
void insertionAuMilieu(Liste *liste, int precedent, int nb);
void suppression(Liste *liste);
void suppressionAuMilieu(Liste *liste, int precedent);
void afficherListe(Liste *liste);

#endif
