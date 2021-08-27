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
    /*En el metodo Str_bin se encarga de cambiar una varible string a un numero
     * binario, ya puede ser una cadena de texto o un caracter
    */

    string codificar(int n, string archiEnt);//
    /*En el metodo codificar se encarga de codificar el string archiEnt por el metodo de
     * convertir el archivo a binario, luego se separa en bloques de n bits. Cada bit
     * dentro de un grupo se desplaza una posición, de manera que el primer bit del grupo
     * codificado corresponde al último bit del grupo sin codificar, el segundo bit
     * codificado corresponde alprimero sin codificar y así sucesivamente hasta que el último
     * corresponde al penúltimo sincodificar.
    */

    string decodificar(int n, string CadBinario);//
    /*En el metodo decodificar se encarga de hacer el proceso inverso del metodo codificar
     * primero decofica segun el metodo utilizado y despues cambia el numero binario decodificado
     * a string
    */

    string Bin_Str(string CadCode);//
    /*En el metodo Bin_Str se encarga de cambiar una varible binarioa un string
     * ya puede ser una cadena de texto o un caracter
    */

    void Bin_lectura();//
    /*En el metodo Bin_lectura se encarga de leer el archivo.txt, hacer el proceso de
     * decodificacion y despues modificar el contenido de un string con tosa la informacion
     * que se encuentra en el txt
    */

    void codi_escritura();//
    /*En el metodo codi:escritura se encarga de cambiar el contenido de la variable string
     * que posee la informacion por la misma informacion pero codificada y despues
     * pasa a escribir toda la variable en un txt
    */

    string LectuArchi();
    /*En el metodo LectuArchi se encarga de leer un archivo.txt y colocarlo todo
     *  en una variable tipo string
    */


    void escribir( string contenido,string txt);
    /*En el metodo escribir se encarga de escribir un archivo.txt con la informacion correspondiente
     *  en una variable tipo string
    */


    string getArchivo() const;
    void setArchivo(const string &value);

private:
    string txt="../Lab3_cajero/BD/BaseDatos.txt";

    string archivo;

    int n=4;

};

#endif // MANEJO_TXT_H
