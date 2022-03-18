#ifndef H_FILE
#define H_FILE

typedef struct Element Element;
struct Element{
    int nombre;
    Element *suivant;
};

typedef struct File File;
struct File{
    int nbElement;
    Element *premier;
};

File *initialiser();
void enfiler(File *file, int nb);
int defiler(File *file);
void afficherFile(File *file);

#endif