#include <iostream>
#include <fstream>
#include "manejo_txt.h"
#include "usu_admin.h"

using namespace std;


int main()
{
    manejo_txt archiv;
    Usu_Admin Usuari;

    string B;
    //ingresa usuario
    string claveUsuario = "10003 2003" ;


    string claveAdmin;

    archiv.Bin_lectura();
    Usuari.setArchivo(archiv.getArchivo());
    unsigned int opcion = 0 ,opcion2 = 0;
    int dinero=0;
    string documento,contrasena;

    cout<<"Bienvenido!!"<<endl;
    cout<<"introduzca el numero que le aparece en pantalla para ingresar: "<<endl;
    cout<<"0.Administrador"<<endl;
    cout<<"1.Usuario"<<endl;
    cout<<"2.Salir"<<endl;
    cout<<">>";
    cin>>opcion;



    switch(opcion){
        case 0:
            cout<<"por favor introduzca la contraseña:"<<endl;
            cout<<">>";
            cin>>claveAdmin;

            if (Usuari.confirAdmin(claveAdmin)){
                int opc=0;
                cout<<"Bienvenido administrador"<<endl;
                cout<<"Ingrese el numero correspondiente: "<<endl;
                cout<<"0.ingresar nuevo usuario"<<endl;
                cout<<"1.salir"<<endl;
                cout << " >> ";
                cin>>opc;

                if (opc ==0){
                    archiv.setArchivo(Usuari.NuevoUsu());
                    archiv.codi_escritura();
                }
                else{
                    break;
                }
            }
            else{
                cout<<"Contraseña incorrecta, ingreso no permitido"<<endl;
            }
        break;

        case 1:
            cout<<"por favor introduzca la contraseña:"<<endl;
            cout<<"ingreselo de la siguente forma:"<<endl;
            cout<<"documento:";
            cin>>documento;
            cout<<"contrasena:";
            cin>>contrasena;
            claveUsuario=documento+' '+contrasena;


            if (Usuari.confirUsu(claveUsuario)){
                cout<<"Bienvenido!!"<<endl;
                cout<<"Ingrese el numero correspondiente: "<<endl;
                cout<<"0. consultar saldo"<<endl;
                cout<<"1.retirar dinero"<<endl;
                cout<<"2.salir"<<endl;
                cout<<">>";
                cin>>opcion2;


                switch(opcion2){

                    case 0:

                        if (Usuari.Dinero() >1000){
                            cout<<"su saldo es de "<<Usuari.getCash()<<endl;
                            Usuari.setCash((Usuari.getCash())-1000);
                            archiv.setArchivo(Usuari.CambioDinero());
                            archiv.codi_escritura();
                        }
                        else{
                            cout<<"la opcion no es permitida"<<endl;
                            cout<<"¡Vuelva pronto!";
                        }
                        break;
                    case 1:
                        cout<<"ingrese la cantidad de dinero a retirar:"<<endl;
                        cout<<">>";
                        cin>>dinero;


                        if (Usuari.Dinero() > (1000+dinero)){
                            Usuari.setCash((Usuari.getCash())-dinero);
                            cout<<"Gracias por usar el cajero, vuelva pronto"<<endl;
                            cout<<"Su saldo restante es de "<<Usuari.getCash();
                            Usuari.setCash((Usuari.getCash())-1000);;
                            archiv.setArchivo(Usuari.CambioDinero());
                            archiv.codi_escritura();
                        }
                        else{
                            cout<<"la opcion no es permitida, no cuenta con suficiente dinero"<<endl;
                        }
                        break;

                    case 2:
                        break;
                    }
                }
            }


    return 0;
}












