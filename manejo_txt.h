#ifndef MANEJO_TXT_H
#define MANEJO_TXT_H
#include <iostream>
#include <fstream>
#include "usu_admin.h"


using namespace std;


class manejo_txt
{
public:
    manejo_txt();

    string Str_Bin(string contenido);//

    string codificar(int n, string archiEnt);//

    string decodificar(int n, string CadBinario);//

    string Bin_Str(string CadCode);//

    void Bin_lectura();//

    void codi_escritura();//

    string LectuArchi();

    void escribir( string contenido,string txt);



    string getArchivo() const;
    void setArchivo(const string &value);

private:
    string txt="../Lab3_cajero/BD/BaseDatos.txt";

    string archivo;

    int n=4;

};

#endif // MANEJO_TXT_H
