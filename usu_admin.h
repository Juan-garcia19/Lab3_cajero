#ifndef USU_ADMIN_H
#define USU_ADMIN_H

#include <iostream>
#include <fstream>
#include "manejo_txt.h"

using namespace std;


class Usu_Admin
{
public:
    Usu_Admin();

    bool confirAdmin( string claveAdmin);
    /*En el metodo confirAdmin se encarga de verificar si la contraseña ingresada por el
     *  administrador coincide en con la contraseña en la base de datos
    */

    int confirUsu(string claveUsuario);
    /*En el metodo confirUsu se encarga de verificar si la contraseña ingresada por el
     *  usuario coincide en con la contraseña en la base de datos
    */

    string NuevoUsu();
    /*En el metodo NuevoUsu se encarga de ingresar en un txt el nuevo usuario del cajero
     *
    */

    int Dinero();
    /*En el metodo dinero se encarga de sacar el dinero del usuario encontrado
     *  en la variable tipo string

    */

    string CambioDinero();
    /*En el metodo CambioDinero se encarga de cambiar la informacion del dinero despues del
     * retiro o el descuento por la cuota de manejo en la variable string
    */

    string getArchivo() const;
    void setArchivo(const string &value);

    unsigned int getCash() const;
    void setCash(unsigned int value);

private:
    string NuevoUsuario;

    string claveUsuario;

    unsigned int dinero, cash=0;

    string archivo;

    int A=0;
};

#endif // USU_ADMIN_H
