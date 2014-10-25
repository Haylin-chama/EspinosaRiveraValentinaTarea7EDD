#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include "cab7.h"

using namespace std;

int main()
{

   system("color f0");//Se agrega color al sistema
    char opcion;
    int n,k;
    Lista M=NULL,p,q,r;
    do
    {
        system("cls");
        cout<<"	BIENVENIDO REY ARTURO\n\n   M   E   N   U\n";
        cout<<"1) Generar los N caballeros de la mesa redonda"<<endl;
        cout<<"2) Mostrar toda la información contenida en la mesa redonda"<<endl;
        cout<<"3) Solicitar el valor de K, y elegir el nombre del caballero elegido"<<endl;
        cout<<"S) Salir"<<endl;
        cout<<endl<<"Ingrese una opcion: ";
        cin>>opcion;
        switch(opcion){
            case '1':{
                cout <<"Numero de caballeros en la mesa: "<<endl;
                n=Validar();
                Agregar(M,n);
                system("pause");
                break;
            }
             case '2':{
                cout<<"CABALLEROS PRESENTES\n";
                p=M;
                Listar2(M,p);
                system("pause");
                break;
            }
             case '3':{
                Elegido(M,k);
                system("pause");
                break;
            }
        }

    }while(opcion!='S');

}
