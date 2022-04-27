#include <stdio.h>
#include <stdlib.h>
#include "taquin.h"
#include "matrice.h"

void rechercheAetoile (Etat *etatInitial, Etat *etatFinal, void genereSuccesseurs(), int h(), int g()){
    Liste *listeNoeuds = initialiseListe();
    inserer(etatInitial, listeNoeuds);
    Liste *noeudsDejaTraites = initialiseListe(); 
    
    while(!vide(listeNoeuds)){
        Etat *etatCourant = extraire(listeNoeuds);
        Liste *listeSuccesseurs = initialiseListe();
        afficheNoeud(etatCourant, LIGNE, COLONNE);
        if(etatSolution(etatCourant, etatFinal)){
            printf("Succes !! Arret sur l etat : \n");
            afficheNoeud(etatCourant, LIGNE, COLONNE);
            return;
        }else{
            listeSuccesseurs = initialiseListe();
            genereSuccesseurs(etatCourant, etatFinal, listeSuccesseurs);

            while(!vide(listeSuccesseurs)){
                
                Etat *element = extraire(listeSuccesseurs);
                if(!(appartient(element, listeNoeuds) || appartient(element, noeudsDejaTraites))){
                    inserer(element, listeNoeuds);
                }
            }

            inserer(etatCourant, noeudsDejaTraites);
        }
    }

    printf("Pas de solution !! ");

}

Liste *initialiseListe(){
    Liste *liste = (Liste*) malloc(sizeof(Liste));

    if(liste == NULL){
        exit(EXIT_FAILURE);
    }

    liste->premier = NULL;

    return liste;
}

Etat *initialiseEtat(int **matrice){
    
    Etat *etat = (Etat*) malloc(sizeof(Etat));
    if(etat == NULL){
        exit(EXIT_FAILURE);
    }
    
    etat->matrice = matrice;
    return etat;
}

void inserer(Etat *etatInitial, Liste *listeNoeuds){
    if(etatInitial == NULL || listeNoeuds == NULL){
        exit(EXIT_FAILURE);
    }

    Noeud *noeud = (Noeud*) malloc(sizeof(Noeud));
    if(noeud == NULL){
        exit(EXIT_FAILURE);
    }

    noeud->etat = etatInitial;
    noeud->suivant = NULL;

    //liste vide
    int estInsere = 0;
    
    Noeud *courant = listeNoeuds->premier;
    Noeud *precedent = NULL;
    
    //On insere dans la bonne position cad la liste sera tjs triee
    //insertion au debut de la liste 
    if(courant == NULL || etatInitial->cout <= courant->etat->cout){
        noeud->suivant = courant;
        listeNoeuds->premier = noeud;
    }else{
        //on boucle tant que l element n est pas insere et on est pas arrive a la fin de la liste
        precedent = courant;
        courant = courant->suivant;
        while (!estInsere && courant != NULL){

            if(etatInitial->cout <= courant->etat->cout){
                noeud->suivant = courant;
                precedent->suivant = noeud;
                estInsere = 1;
            }
            precedent = courant;
            courant = courant->suivant;
        }
        
        //on a parcouru la liste sans inserer l element donc ajout a la fin de la liste
        if(!estInsere){
            precedent->suivant = noeud;
        }  
    }
    

}

int vide(Liste *listeNoeuds){
    if(listeNoeuds == NULL){
        exit(EXIT_FAILURE);
    }

    if(listeNoeuds->premier == NULL){
        return 1;
    }

    return 0;
}

Etat *extraire(Liste *listeNoeuds){
    if(listeNoeuds == NULL){
        exit(EXIT_FAILURE);
    }

    Noeud *noeudAExtraire = NULL;
    if(listeNoeuds->premier != NULL){
        //extraction du 1 element de la liste
        noeudAExtraire = listeNoeuds->premier;

        listeNoeuds->premier = noeudAExtraire->suivant;  

        return noeudAExtraire->etat;
    }
    
    
}

int etatsSemblables(Etat *etatCourant, Etat *etatAutre){

    return matricesSemblables(etatCourant->matrice, etatAutre->matrice, LIGNE, COLONNE);
}

int etatSolution (Etat *etatCourant, Etat *etatFinal){

    return etatsSemblables(etatCourant, etatFinal);
}



int appartient(Etat *etatCourant, Liste *noeudsDejaTraites){
    if(etatCourant == NULL || noeudsDejaTraites == NULL){
        exit(EXIT_FAILURE);
    }

    //la liste vide
    if(vide(noeudsDejaTraites)){
        return 0;
    }

    Noeud *courant = noeudsDejaTraites->premier;
    while (courant != NULL){
        if(etatsSemblables(etatCourant, courant->etat)){
            return 1;
        }
        courant = courant->suivant;
    }
    return 0;
    
}

void genereSuccesseurs(Etat *etatCourant,  Etat *etatFinal, Liste *listeSuccesseurs){
    if(etatCourant == NULL || listeSuccesseurs == NULL){
        exit(EXIT_FAILURE);
    }

    //on recupere la position du 0
    Position *position = (Position*) malloc(sizeof(Position));
    position = recupererPosition(etatCourant->matrice, LIGNE, COLONNE, 0);

    //deplacement vers le haut
    if(position->x > 0){
        int **matriceCopie = allouerMemoireMatrice(LIGNE, COLONNE);
        copieMatrice(etatCourant->matrice, matriceCopie, LIGNE, COLONNE);

        matriceCopie[position->x][position->y] = matriceCopie[position->x - 1][position->y];
        matriceCopie[position->x - 1][position->y] = 0;

        Etat *etat = initialiseEtat(matriceCopie);
        etat->cout = heuristique(etat, etatFinal);
        etat->arc = coutArc(etatCourant);
        etat->estimation = estimation(etat, etatFinal);

        inserer(etat, listeSuccesseurs);
    }
    //deplacement vers le bas
    if(position->x < COLONNE - 1){
        int **matriceCopie = allouerMemoireMatrice(LIGNE, COLONNE);
        copieMatrice(etatCourant->matrice, matriceCopie, LIGNE, COLONNE);

        matriceCopie[position->x][position->y] = matriceCopie[position->x + 1][position->y];
        matriceCopie[position->x + 1][position->y] = 0;

        Etat *etat = initialiseEtat(matriceCopie);
        etat->cout = heuristique(etat, etatFinal);
        etat->arc = coutArc(etatCourant);
        etat->estimation = estimation(etat, etatFinal);

        inserer(etat, listeSuccesseurs);
    }
    //deplacement a droite
    if(position->y < COLONNE - 1){
        int **matriceCopie = allouerMemoireMatrice(LIGNE, COLONNE);
        copieMatrice(etatCourant->matrice, matriceCopie, LIGNE, COLONNE);

        matriceCopie[position->x][position->y] = matriceCopie[position->x][position->y + 1];
        matriceCopie[position->x][position->y + 1] = 0;

        Etat *etat = initialiseEtat(matriceCopie);
        etat->cout = heuristique(etat, etatFinal);
        etat->arc = coutArc(etatCourant);
        etat->estimation = estimation(etat, etatFinal);

        inserer(etat, listeSuccesseurs);

    }
    //deplacement a gauche
    if(position->y > 0){
        int **matriceCopie = allouerMemoireMatrice(LIGNE, COLONNE);
        copieMatrice(etatCourant->matrice, matriceCopie, LIGNE, COLONNE);

        matriceCopie[position->x][position->y] = matriceCopie[position->x][position->y - 1];
        matriceCopie[position->x][position->y - 1] = 0;

        Etat *etat = initialiseEtat(matriceCopie);
        etat->cout = heuristique(etat, etatFinal);
        etat->arc = coutArc(etatCourant);
        etat->estimation = estimation(etat, etatFinal);

        inserer(etat, listeSuccesseurs);
    }

    free(position);
}

void afficheNoeud(Etat *etatCourant, int ligne, int colonne){
    afficherMatrice(etatCourant->matrice, ligne, colonne);
    printf("h = %d\t", etatCourant->cout);
    printf("g = %d\t", etatCourant->arc);
    printf("f = %d", etatCourant->estimation);
    printf("\n\n");
}

void afficheListeNoeuds(Liste *listeNoeuds){
     if(listeNoeuds == NULL){
        exit(EXIT_FAILURE);
    }
    Noeud *courant = listeNoeuds->premier;
    int n = 0;
    while (courant != NULL){
        printf("Etat N %d\n", ++n);
        afficheNoeud(courant->etat, LIGNE, COLONNE);
        courant = courant->suivant;
        
    }
}

int heuristique(Etat *etatCourant, Etat *etatFinal){
    int evaluation = 0;
    if(etatCourant == NULL || etatFinal == NULL){
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < LIGNE; ++i){
        for (int j = 0; j < COLONNE; ++j){
            if(etatCourant->matrice[i][j] != etatFinal->matrice[i][j]){
                ++evaluation;
            }
        }  
    }

    return evaluation;
}

int coutArc(Etat *etatCourant){
    return (etatCourant->arc) + 1;
}

int estimation(Etat *etatCourant, Etat *etatFinal){

 return heuristique(etatCourant, etatFinal) + (etatCourant->arc);
}

