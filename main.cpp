#include <iostream>
#include <fstream>

using namespace std;

string LectuArchi();
bool confirAdmin( string claveAdmin, int longitud, string archivo);
int confirUsu(int longitud, string claveUsuario, string archivo);
void escribir( string contenido);
int Dinero(int longitud, string archivo, int A);




int main()
{

    string claveAdmin = "1234";
    unsigned int documento =10004, opcion=1;
    string claveUsuario = "10004 2002", usuNuev="12345 adcf 46000";
    unsigned int dinero = 5000;


    string archivo=LectuArchi();
    int longitud =archivo.length(),A, cash;

    bool confirAd = confirAdmin(claveAdmin,longitud,archivo);

    string copiaArchi;
/*
    if (confirAd == true){
        archivo+='\n';
        archivo+=usuNuev;
        escribir(archivo);
    }

*/



    A= confirUsu(longitud,claveUsuario,archivo);

    cash=Dinero(longitud,archivo,A);

    //consulta de saldo

    switch(opcion){
        case 1:
            if (cash >1000){
                cout<<"su saldo es de "<<cash<<endl;
                cash-=1000;
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
            }
            break;
        case 2:
            if (cash >1000){
                cash-=dinero;
                cout<<"Gracias por usar el cajero, vuelva pronto"<<endl;
                cash-=1000;
            }






}
    // validar contraseña usuario



    return 0;
}

string LectuArchi(){
   string data;

   // Abre el archivo en modo lectura
   ifstream infile;

   // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
   infile.open("../Lab3_cajero/BD/BaseDatos.txt");

   // Se comprueba si el archivo fue abierto exitosamente
   if (!infile.is_open())
   {
     cout << "Error abriendo el archivo" << endl;
     exit(1);
   }

   cout << "Leyendo el archivo" << endl;
   infile >> data;

   // Se escribe el dato en la pantalla
   cout << data << endl;

   string linea;
   int contador =0;
   while(!infile.eof()){
       contador++;

       if (contador>1){
           data+='\n';
       }
       getline(infile,linea);
       data+=linea;

   }

   // Se cierra el archivo abierto
   infile.close();
   return data;
}

void escribir(string contenido)
{
    ofstream archi;

    archi.open("../Lab3_cajero/BD/BaseDatos.txt");

    if (!archi.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    archi << contenido;

    archi.close();
}



bool confirAdmin( string claveAdmin, int longitud, string archivo){
    //validar contraseña Administrador
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

int confirUsu(int longitud, string claveUsuario,string archivo){
    string copiContraArchi;
    int contEspa=0, i, contUsu=0;
    for (i =0;i< longitud;i++){
        if (archivo[i] != '\n' ){
            if (archivo[i]== ' ' and contEspa <2){
                contEspa++;
            }
            if(contEspa==2 and claveUsuario== copiContraArchi){
                cout<<"ingreso usuario permitido"<<endl;
                return contUsu;
            }
            copiContraArchi+=archivo[i];
        }
        else{
            copiContraArchi="";
            contUsu++;
        }
    }

    cout<<"ingreso Usuario No permitido"<<endl;
    return 0;

}

int Dinero(int longitud,string archivo,int A){
    string copiContraArchi;
    int contaEsp = 0, contUsu=0, cash=0;
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



