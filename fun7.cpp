#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <stdlib.h>
#include "cab7.h"

using namespace std;

int Validar()
{
    locale loc;
    char str[256];
    fgets(str,256,stdin);
    if (isdigit(str[0],loc))
    {
        int i=atoi(str);
        return i;
    }
    else{
        cout<<"Caracter ingresado no valido. Ingrese un numero.\n";
    }
    Validar();
}

//a) Generar los N caballeros de la mesa redonda
void Agregar(Lista &C, int e)
{
    Lista p;
    for (int i=0;i<e;i++){
        p = new Mesa;
        cout<<"Nombre del caballero: ";
        getline(cin,p->nombre);
        cout<<"Titulo Nobiliario: ";
        getline(cin,p->titulo);
        cout<<"Años de Experiencia: ";
        cin>>p->exp;
        p->ant = p;
        p->sig = p;

        if(C == NULL){
            C = p;
        }
        else{
            p->ant = C;
            p->sig = C->sig;
            p->sig->ant = p;
            C ->sig = p;

        }
    }
}

//b) Mostrar toda la información contenida en la mesa redonda
void Listar(Lista C, Lista p){
    if(C!=NULL){
        if (p==C)
        {
            cout<<"\n\nNombre: "<<p->nombre;
            cout<<"\nTitulo Nobiliario: "<<p->titulo;
            cout<<"\nAños de Experiencia: "<<p->exp;
        }
        else
            cout<<"\n\nNombre: "<<p->nombre;
            cout<<"\nTitulo Nobiliario: "<<p->titulo;
            cout<<"\nAños de Experiencia: "<<p->exp;
            return Listar(C,p->sig);
    }
    else{
        cout<<"No hay caballeros presentes\n";
    }
}

void Listar2(Lista C, Lista p){
    cout << endl << "Caballeros de la mesa redonda " << endl;
    if(C!=NULL){
        p = C;
        cout<<"\n\nNombre: "<<p->nombre;
        cout<<"\nTitulo Nobiliario: "<<p->titulo;
        cout<<"\nAños de Experiencia: "<<p->exp;
        p = p->sig;
        while(p != C){
            cout<<"\n\nNombre: "<<p->nombre;
            cout<<"\nTitulo Nobiliario: "<<p->titulo;
            cout<<"\nAños de Experiencia: "<<p->exp;
            p = p->sig;
        }
    }
}

//c) Solicitar el valor de K, y elegir el nombre del caballero elegido
void Eliminar(Lista &Mesa_s, int k, Lista &p, Lista &q, Lista &r)
{
    if (k>0)
    {
        q->sig=p->sig->sig;
        r->ant=p;
        delete p->sig;
        p=q;
    }
    else
    {
        q->sig=p;
        r->ant=p->ant->ant;
        delete p->ant;
        p=r;
    }
}

void Welta(Lista &Mesa,int i,int k, Lista &p, Lista &q, Lista &r)
{
  if (k==0)
    if (i=0){
        q->sig=p->sig;
        r->ant=p->ant;
        delete p;
        p=Mesa;
    }
  if (k<0)
    return Welta(Mesa,i,k+1,p->ant,p->sig,p->ant);
  if (k>0)
    return Welta(Mesa,i,k-1,p->sig,p->ant,p->sig);
}

void Elegido(Lista &Mesa, int n)
{
  int k;
  cout<<"Ingrese k: "<<endl; //Se ingresa k
  cin>>k;
  Lista p=Mesa,q=p->ant,r=p->sig;
  //Paso 1 (con n caballeros): se avanza k posiciones, y se elimina el caballero en posición k
  int i=0;
  Welta(Mesa,i,k,p,q,r);
  //Paso 2 (con n-1 caballeros): se avanza k posiciones y se elimina el próximo caballero (k+1 o k-1)
  for (i=1;i<n;i++)
  {
    Welta(Mesa,i,k,p,q,r);
    Eliminar(Mesa,k,p,q,r);
  }
  cout<<"\n\nCaballero Elegido: ";
  p=Mesa;
  Listar(Mesa,p);
}

//d) Salir
