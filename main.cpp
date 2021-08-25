#include <iostream>
#include <fstream>

using namespace std;

string LectuArchi();
bool confirAdmin( string claveAdmin, int longitud, string archivo);
bool confirUsu(int longitud, string claveUsuario,string archivo);

int main()
{

    string claveAdmin = "1234";
    unsigned int documento =10004;
    string claveUsuario = "10001 2003";
    unsigned int dinero = 45000;


    string archivo=LectuArchi();
    int longitud =archivo.length();

    confirAdmin(claveAdmin,longitud,archivo);

    string copiContraArchi;
    int contEspa=0,i;
    for (i =0;i< longitud;i++){
        if (archivo[i] != '\n' ){
            if (archivo[i]== ' ' and contEspa <2){
                contEspa++;
            }
            if(contEspa==2 and claveUsuario== copiContraArchi){
                cout<<"ingreso usuario permitido"<<endl;
                break;
            }
            copiContraArchi+=archivo[i];
        }
        else{
            copiContraArchi="";
        }
    }
    if (i == longitud){
        cout<<"ingreso Usuario No permitido"<<endl;
    }
    //s= confirUsu(longitud,claveUsuario,archivo);


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

bool confirUsu(int longitud, string claveUsuario,string archivo){
    string copiContraArchi;
    int contEspa=0;
    for (int i =0;i< longitud;i++){
        if (archivo[i] != '\n' ){
            if (archivo[i]== ' ' and contEspa <2){
                contEspa++;
            }
            if(contEspa==2 and claveUsuario== copiContraArchi){
                cout<<"ingreso usuario permitido"<<endl;
                return true;
            }
            else if(contEspa==2 and claveUsuario != copiContraArchi){
                cout<<"ingreso NO permitido"<<endl;
                return false;
            }
            copiContraArchi+=archivo[i];
        }
        else{
            copiContraArchi="";
        }
    }
}


