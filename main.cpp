#include <iostream>
#include <fstream>

using namespace std;

string LectuArchi(string txt);
bool confirAdmin( string claveAdmin, int longitud, string archivo);
int confirUsu(int longitud, string claveUsuario, string archivo);

void escribir( string contenido,string txt);
int Dinero(int longitud, string archivo, int A);
string CambioDinero(int longitud,string archivo,int A,int cash);
void codi_escritura(string archivo,int longitud);


string Str_Bin(string contenido);
string codificar(int n, string archiEnt);
string decodificar(int n, string CadBinario);
string Bin_Str(string CadCode);
string Bin_lectura(string txt);

int main()
{

    string B;

    string claveUsuario = "10003 2003" ;
    unsigned int dinero = 5000;

    string txt="../Lab3_cajero/BD/BaseDatos.txt";
    string archivo=LectuArchi(txt),archi2=LectuArchi("../Lab3_cajero/BD/pruebaBin.txt");
    int longitud =archivo.length(),A, cash;



    cout<<"Bienvenido!!"<<endl;
    cout<<"introduzca el numero que le aparece en pantalla para ingresar: "<<endl;
    cout<<"0.Administrador"<<endl;
    cout<<"1.Usuario"<<endl;
    cout<<"2.Salir"<<endl;
    cout<<">>";
    unsigned int opcion=1;

    switch(opcion){
        case 0:

            cout<<"por favor introduzca la contraseña:"<<endl;
            cout<<">>";
            string claveAdmin = "1234";
            bool confirAd = confirAdmin(claveAdmin,longitud,archivo);

            if (confirAd ==true){
                int opc=0;
                cout<<"Bienvenido administrador"<<endl;
                cout<<"Ingrese el numero correspondiente: "<<endl;
                cout<<"0.ingresar nuevo usuario"<<endl;
                cout<<"1.salir"<<endl;
                cout<<">>";
                if (opc ==0){


                }
            }


    break;
    }









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
                B=CambioDinero(longitud,archivo,A,cash);
                codi_escritura(B,longitud);




            }
            break;
        case 2:
            if (cash >1000){
                cash-=dinero;
                cout<<"Gracias por usar el cajero, vuelva pronto"<<endl;
                cash-=1000;
                B=CambioDinero(longitud,archivo,A,cash);
            }






}
    // validar contraseña usuario



    return 0;
}

void NuevoUsu(){
    cout<<"ingreselo de la siguente forma:"<<endl;
    cout<<"(documento)(espacio)(constraseña)(espacio)(dinero)"<<endl;
    cout<<">>";
    string usuNuev="12345 adcf 46000";
    archivo+='\n';
    archivo+=usuNuev;
    codi_escritura(archivo)
}

string decodificar(int n, string CadBinario)
{

    string CadCode;
    string CadTxt;



    int Especial=0, PartSup;

    int Longitud=CadBinario.length();

    for(int elem = 0; elem<Longitud;elem++){
        CadCode += ' ';
    }

    if (Longitud%n != 0){
        Especial++;
    }
    PartSup = Especial == 1 ? (Longitud/n)+1 : Longitud/n;
    for(int NLego = 0 ;NLego < PartSup; NLego ++){
        Especial=Longitud%n;
        if(NLego==Longitud/n){
            CadCode[(NLego*n + Especial)-1] = CadBinario[NLego*n];
            for (int i = n*NLego ;i < (NLego*n + Especial-1) ; i++){
                CadCode[i]=CadBinario[i+1];
            }
        }
        else{
            CadCode[n*(NLego+1)-1]=CadBinario[NLego*n];
            for (int i = n*NLego ;i < (n*(NLego+1)-1); i++){
                CadCode[i]=CadBinario[i+1];
            }

        }
    }

    CadTxt=Bin_Str(CadCode);
    return CadTxt;

}


string Bin_Str(string CadCode)
{
  int tamCad= CadCode.length(),multiplicador=1;
  int decimal=0;

  string CadTxt;

  for(int cont=0;cont<tamCad/8;cont++){
      multiplicador=1;
      decimal=0;
        for(int elem=0, palBin=(cont + 1)*8-1 ; elem<8 ; elem++,palBin--){
            if (CadCode[palBin] == '1'){
                decimal += multiplicador;
            }
            multiplicador = multiplicador*2;
        }
        CadTxt+=decimal;
  }
  return CadTxt;
}


string codificar(int n, string CadText)
{
    string CadBinario;
    string CadCode;


    CadBinario = Str_Bin(CadText);

    int Especial=0, PartSup;

    int Longitud=CadBinario.length();


    for(int elem = 0; elem<Longitud;elem++){
        CadCode += ' ';
    }

    if (Longitud%n != 0){
        Especial++;
    }
    PartSup = Especial == 1 ? (Longitud/n)+1 : Longitud/n;
    for(int NLego = 0 ;NLego < PartSup; NLego ++){
        Especial=Longitud%n;
        if(NLego==Longitud/n){
            CadCode[NLego*n] = CadBinario[(NLego*n + Especial)-1];
            for (int i = n*NLego ;i < (NLego*n + Especial-1) ; i++){
                CadCode[i+1]=CadBinario[i];
            }
        }
        else{
            CadCode[NLego*n]=CadBinario[n*(NLego+1)-1];
            for (int i = n*NLego ;i < (n*(NLego+1)-1); i++){
                CadCode[i+1]=CadBinario[i];
            }
        }
    }
    return CadCode;

}


string Str_Bin(string contenido)
{
    int tamCad = contenido.length();

    string cadBinario;
    for(int i=0;i < tamCad*8;i++){
        cadBinario += ' ';
    }
    int carac=0;
    for(int cont=0;cont<tamCad;cont++){
        carac = (int)contenido[cont];
            for(int elem=0, palBin=(cont + 1)*8-1 ; elem<8 ; elem++,palBin--){
                cadBinario[palBin]=(char)(carac%2+48);
                carac/=2;
            }
    }
    return cadBinario;
}


string LectuArchi(string txt){
   string data;

   // Abre el archivo en modo lectura
   ifstream infile;

   // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
   infile.open(txt);

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

void escribir(string contenido,string txt)
{
    ofstream archi;

    archi.open(txt);

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

string CambioDinero(int longitud,string archivo,int A,int cash){
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

void codi_escritura(string archivo,int longitud){
    string copiaArch,C,txtBin;
    for(int i=0;i<longitud;i++){
        if (archivo[i]=='\n' or archivo[i]==' '){
            C=codificar(4,copiaArch);
            txtBin+=C;
            if (archivo[i]=='\n'){
                txtBin+='\n';
            }
            else{
                txtBin+=' ';
            }
            copiaArch="";
        }
        else {
            copiaArch+=archivo[i];

        }
    }
    C=codificar(4,copiaArch);
    txtBin+=C;
    escribir(txtBin,"../Lab3_cajero/BD/pruebaBin.txt");
}

string Bin_lectura(string txt){


    string archi2 = LectuArchi(txt);
    string copiaArch,C,txtBin;
    int longitud2 = archi2.length();


    for(int i=0;i<longitud2;i++){
        if (archi2[i]=='\n' or archi2[i]==' '){
            C=decodificar(4,copiaArch);
            txtBin+=C;
            if (archi2[i]=='\n'){
                txtBin+='\n';
            }
            else{
                txtBin+=' ';
            }
            copiaArch="";
        }
        else {
            copiaArch+=archi2[i];

        }
    }
    C=decodificar(4,copiaArch);
    txtBin+=C;
    return txtBin;
}
