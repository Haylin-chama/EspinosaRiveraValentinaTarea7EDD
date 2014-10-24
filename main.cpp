using namespace std;

int main()
{

   system("color f0");//Se agrega color al sistema
    char opcion;
    int n,k;
    Lista M,p,q,r;
    do
    {
        system("cls");
        cout<<"	BIENVENIDO REY ARTURO\n\n   M   E   N   U\n";
        cout<<"1) Generar los N caballeros de la mesa redonda"<<endl;
        cout<<"2) Mostrar toda la información contenida en la mesa redonda"<<endl;
        cout<<"3) Solicitar el valor de K, y elegir el nombre del caballero elegido"<<endl;
        cout<<"0) Salir"<<endl;
        cout<<endl<<"Ingrese una opcion: ";
        cin>>opcion;
        switch(opcion){
            case '1':{
                cout <<"Numero de caballeros en la mesa: "<<endl;
                n=Validar();
                Agregar(M,n);
                break;
            }
             case '2':{
                cout<<"CABALLEROS PRESENTES\n";
                p=M;
                Listar2(M,p);
                break;
            }
             case '3':{
                cout<<"Valor de k: ";
                k=Validar();
                Elegido(M,k);
                break;
            }
        }

    }while(opcion!='0');

}
