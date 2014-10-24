#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED
typedef struct Nodo{
    int info;
    struct Nodo *ant;
    struct Nodo *sig;
};

typedef Nodo *Lista;

void agregar(Lista &, int );
void Listar(Lista );


#endif // CABECERA_H_INCLUDED
