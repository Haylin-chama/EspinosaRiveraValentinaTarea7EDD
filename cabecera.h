#ifndef CAB7_H_INCLUDED
#define CAB7_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct Mesa{
    string nombre;
    string titulo;
    int exp;
    struct Mesa *ant;
    struct Mesa *sig;
}Mesa_s;

typedef Mesa *Lista;

void Agregar(Lista &);
void Listar(Lista );
void Eliminar(Lista &, int , Lista &, Lista &, Lista &);
void Welta(Lista &,int ,int , Lista &, Lista &, Lista &);
void Elegido(Lista &, int );

#endif // CAB7_H_INCLUDED
