#include <iostream>
#include "cabecera.h"

using namespace std;

void agregar(Lista &C)
{
    int e;
    cout <<"Ingrese numero de caballeros a crear"<<endl;
    cin>>e;
    Lista2 p;
    for (int i=0;i<e;i++){
        p = new Nodo;
        p->Info = 65+rand()%25;
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

void Listar(Lista C){
    Lista2 p;
    cout << endl << "Caballeros de la mesa redonda " << endl;
    if(C!=NULL){
        p = C;
        printf(" valor : %c ",p->info);
        p = p->sig;
        while(p != C){
            printf(" valor : %c ",p->info);
            p = p->sig;
        }
    }
}

void Welta(lista Mesa, int k, lista p,lista q,lista r)
{
  if (k==0)
    q->sig=p->sig;
    r->ant=p->ant;
    delete p;
  if (k<0)
    return Welta(Mesa,k+1,p->ant,p->sig,p->ant);
  if (k>0)
    return Welta(Mesa,k-1,p->sig,p->ant,p->sig);
}

void Elegido(lista Mesa, int n)
{
  int k;
  cout<<"Ingrese k: "<<endl;
  cin>>k;
  Lista p=C,q=p->ant,q=p->sig;
  Welta(Mesa,k,p,q,r);
  for (int i=0;i<n;i++)
  {
    Welta(Mesa,k,p->sig,q->sig,r);
  }
}
