#ifndef H_TAQUIN
#define H_TAQUIN

#define LIGNE 3
#define COLONNE 3

typedef struct Etat Etat;

struct Etat{
    int **matrice;
    int cout;
    int arc;
    int estimation;
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

void rechercheAetoile (Etat *etatInitial, Etat *etatFinal, void genereSuccesseurs(), int h(), int g());
Liste *initialiseListe();
Etat *initialiseEtat(int **matrice);
void inserer(Etat *etatInitial, Liste *listeNoeuds);
int vide (Liste *listeNoeuds);
Etat *extraire (Liste *listeNoeuds);
int etatsSemblables(Etat *etatCourant, Etat *etatAutre);
int etatSolution (Etat *etatCourant, Etat *etatFinal);
int appartient (Etat *etatCourant, Liste *NoeudsDejaTraites);
void genereSuccesseurs(Etat *etatCourant,  Etat *etatFinal, Liste *listeSuccesseurs);
void afficheNoeud(Etat *etatCourant, int ligne, int colonne);
void afficheListeNoeuds(Liste *listeNoeuds);
int heuristique(Etat *etatCourant, Etat *etatFinal);
int coutArc(Etat *etatCourant);
int estimation(Etat *etatCourant, Etat *etatFinal);


#endif