#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct Nodo{
    string nombre;
    string titulo;
    struct Nodo *ant;
    struct Nodo *sig;
};

typedef Nodo *Lista;

void agregar(Lista &, int );
void Listar(Lista );


#endif // CABECERA_H_INCLUDED
