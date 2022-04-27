#ifndef H_CRUCHES_D_EAU
#define H_CRUCHES_D_EAU

typedef struct Etat Etat;

struct Etat{
    int x;
    int y;
};

typedef struct Noeud Noeud;

struct Noeud{
    Etat *etat;
    Noeud *suivant;
};

typedef struct Liste Liste;

struct Liste{
    Noeud *premier;
};

Liste *initialisation();
void Inserer(Etat *etatInitial, Liste *listeNoeuds);
int Vide (Liste *listeNoeuds);
Etat *Extraire (Liste *listeNoeuds);
int EtatSolution (Etat *etatCourant);
int Appartient (Etat *etatCourant, Liste *NoeudsDejaTraites);
void RechercheLargeur(Etat etatInitial, Etat etatFinal, void GenereSuccesseurs());
void GenereSuccesseurs (Etat *etatCourant);


#endif