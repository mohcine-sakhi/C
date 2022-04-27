#ifndef H_MATRICE
#define H_MATRICE

typedef struct Position Position;
struct Position {
    int x ;
    int y;
}; 

int **allouerMemoireMatrice(int ligne, int colonne);
void libererMemoireMatrice(int **matrice, int ligne);
void lireMatrice(int **matrice, int ligne, int colonne);
void afficherMatrice(int **matrice, int ligne, int colonne); 
int matricesSemblables(int **matriceSource, int **matriceDestination, int ligne, int colonne);
void copieMatrice(int **matriceSource, int **matriceDestination, int ligne, int colonne);
Position *recupererPosition(int **matrice, int ligne, int colonne, int valeur);


#endif



