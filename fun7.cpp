#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <stdlib.h>
#include "cab7.h"

using namespace std;

int Validar()
{
    fflush(stdin);
    char str[256];
    cout<<"Valor: ";
    fgets(str,256,stdin);
    if (isdigit(str[0]))
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
    string str;
    for (int i=0;i<e;i++){
        p = new Mesa;
        cout<<"Numero de Caballero: ";
        p->id=Validar();
        cout<<"Nombre del caballero: ";
        cin>>str;
        p->nombre=str;
        cout<<"Años de Experiencia: ";
        p->exp=Validar();
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
        cout<<endl;
    }
    cout<<endl;
}

//b) Mostrar toda la información contenida en la mesa redonda
void Listar(Lista C, Lista p){
    if(C!=NULL){
        if (p==C)
        {
            cout<<"\n\nNumero de Caballero: "<<p->id;
            cout<<"nNombre: "<<p->nombre;
            cout<<"\nAños de Experiencia: "<<p->exp;
        }
        else
            cout<<"\n\nNumero de Caballero: "<<p->id;
            cout<<"\n\nNombre: "<<p->nombre;
            cout<<"\nAños de Experiencia: "<<p->exp;
            cout<<endl;
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
        cout<<"\n\nNumero de Caballero: "<<p->id;
        cout<<"\nNombre: "<<p->nombre;
        cout<<"\nAños de Experiencia: "<<p->exp;
        cout<<endl;
        p = p->sig;
        while(p != C){
            cout<<"\n\nNumero de Caballero: "<<p->id;
            cout<<"\nNombre: "<<p->nombre;
            cout<<"\nAños de Experiencia: "<<p->exp;
            cout<<endl;
            p = p->sig;
        }
    }
}

//c) Solicitar el valor de K, y elegir el nombre del caballero elegido

void Welta(Lista &Mesa,int i,int k, Lista &p, Lista &q, Lista &r)
{
  if (k==0)
    if (i=0){
            cout<<"k: "<<k;

        q->sig=p->sig;
        r->ant=p->ant;
        delete p;
        p=Mesa;
    system("pause");
    }
  if (k<0){
    cout<<"\nk: "<<k;
    system("pause");
    return Welta(Mesa,i,k+1,p->ant,p->sig,p->ant);
  }
  if (k>0){
    cout<<"\nk: "<<k;
    system("pause");
    return Welta(Mesa,i,k-1,p->sig,p->ant,p->sig);
  }
}

void Elegido(Lista &Mesa, int n)
{
  if (Mesa!=NULL)
  {
    int k;
  cout<<"Valor de k: "<<endl; //Se ingresa k
  k=Validar();
  Lista p=Mesa,q=p->ant,r=p->sig;
  //Paso 1 (con n caballeros): se avanza k posiciones, y se elimina el caballero en posición k
  int i=0;
  Welta(Mesa,i,k,p,q,r);
  cout<<"Aprobada primera welta\n";
  //Paso 2 (con n-1 caballeros): se avanza k posiciones y se elimina el próximo caballero (k+1 o k-1)
  for (i=1;i<n;i++)
  {
    Welta(Mesa,i,k,p,q,r);
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
  cout<<"\n\nCaballero Elegido: ";
  p=Mesa;
  Listar(Mesa,p);
  }
  else
    cout<<"No hay Caballeros que sortear.\n";
}

//d) Salir
