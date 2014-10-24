#ifndef CAB7_H_INCLUDED
#define CAB7_H_INCLUDED
#include <iostream>

using namespace std;

//Mesa Redonda
typedef struct Mesa{
    string nombre;
    string titulo;
    int exp;
    struct Mesa *ant;
    struct Mesa *sig;
}Mesa_s;

typedef Mesa *Lista;

//Operaciones
int Validar();
void Agregar(Lista &, int);
void Listar(Lista,Lista);
void Listar2(Lista,Lista);
void Eliminar(Lista &, int , Lista &, Lista &, Lista &);
void Welta(Lista &,int ,int , Lista &, Lista &, Lista &);
void Elegido(Lista &, int );

#endif // CAB7_H_INCLUDED
