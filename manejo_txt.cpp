#include "manejo_txt.h"

manejo_txt::manejo_txt()
{

}

string manejo_txt::Str_Bin(string contenido)
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

string manejo_txt::Bin_Str(string CadCode)
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


string manejo_txt::codificar(int n, string CadText)
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
string manejo_txt::decodificar(int n, string CadBinario)
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
string manejo_txt::LectuArchi(){
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

void manejo_txt::Bin_lectura(){

    string archi2 = LectuArchi();
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
    archivo=txtBin;
}
void manejo_txt::escribir(string contenido,string txt)
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

string manejo_txt::getArchivo() const
{
    return archivo;
}

void manejo_txt::setArchivo(const string &value)
{
    archivo = value;
}


void manejo_txt::codi_escritura(){

    int longitud=archivo.length();
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
    escribir(txtBin,txt);
}

