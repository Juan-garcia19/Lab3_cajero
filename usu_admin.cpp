#include "usu_admin.h"
#include "manejo_txt.h"

Usu_Admin::Usu_Admin()
{

}
bool Usu_Admin::confirAdmin( string claveAdmin){
    //validar contraseña Administrador
    int longitud=archivo.length();
    string copiContraArchi;
    for (int i =0;i< longitud;i++){
        if (archivo[i] != '\n' ){
            copiContraArchi+=archivo[i];
        }
        else{
            break;
        }
    }
    if (copiContraArchi == claveAdmin){
        cout<<"ingreso permitido"<<endl;
        return true;
    }
    else{
        return false;
    }
}

int Usu_Admin::confirUsu(string claveUsuario){
    int longitud=archivo.length();
    string copiContraArchi;
    int contEspa=0, i;
    for (i =0;i< longitud;i++){
        if (archivo[i] != '\n' ){
            if (archivo[i]== ' ' and contEspa <2){
                contEspa++;
            }
            if(contEspa==2 and claveUsuario== copiContraArchi){
                cout<<"ingreso usuario permitido"<<endl;

                return A;
            }
            copiContraArchi+=archivo[i];
        }
        else{
            copiContraArchi="";
            A++;
        }
    }

    cout<<"ingreso Usuario No permitido"<<endl;
    return 0;

}
string Usu_Admin::CambioDinero(){
    int longitud=archivo.length();
    string copiaArchi;
    int contador=0,contaEsp=0;
    for (int i =0;i< longitud;i++){
        if (archivo[i] == '\n' ){
            contador++;
        }
        if (contador==A and archivo[i]==' '){
            contaEsp++;
        }
        if(contador==A and contaEsp==2){
            copiaArchi+=' ';
            copiaArchi+=to_string(cash);
            contaEsp++;

        }
        else if (contador==A and contaEsp==3){
        }
        else{

            copiaArchi+=archivo[i];
        }
    }
    return copiaArchi;
}


string Usu_Admin::getArchivo() const
{
    return archivo;
}

void Usu_Admin::setArchivo(const string &value)
{
    archivo = value;
}

unsigned int Usu_Admin::getCash() const
{
    return cash;
}

void Usu_Admin::setCash(unsigned int value)
{
    cash = value;
}



string Usu_Admin::NuevoUsu(){
    string documento,contrasena,dinero;

    cout<<"ingreselo de la siguente forma:"<<endl;
    cout<<"documento:";
    cin>>documento;
    cout<<"contrasena";
    cin>>contrasena;
    cout<<"dinero";
    cin>>dinero;
    string usuNuev=documento+" "+contrasena+' '+dinero;
    archivo+='\n';
    archivo+=usuNuev;
    return archivo;
}

int Usu_Admin::Dinero(){
    int longitud=archivo.length();
    string copiContraArchi;
    int contaEsp = 0, contUsu=0;
    for (int i =0;i < longitud;i++){
        if (archivo[i] != '\n' ){

            if (contaEsp==2 and contUsu ==A){
                copiContraArchi+=archivo[i];
            }
            if (archivo[i] == ' ' and contUsu == A){
                contaEsp++;}
        }
        else{
            contUsu++;
            if (contUsu ==(A+1)){
                cash=(stoi(copiContraArchi));
                return cash;
            }
            else{
            copiContraArchi="";
            }
        }
    }

    cash=(stoi(copiContraArchi));
    return cash;
}

