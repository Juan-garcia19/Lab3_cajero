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

    int confirUsu(string claveUsuario);

    string NuevoUsu();

    int Dinero();

    string CambioDinero();

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
