#ifndef NOSFERATU_H
#define NOSFERATU_H

#include "Vampiro.h"

class Nosferatu : public Vampiro
{
public:
    Nosferatu();
    Nosferatu(Casilla *casilla,char nombre,string ID);
    void mostrar();
    void regnerar_energia();

    void defender(Tablero* tablero);
    void defender(){};
    void defender(int accion, Tablero* tablero){};
    void defender(int eleccion){}



    void atacar(Casilla *casilla, Tablero* tablero);
    ~Nosferatu();
    bool validacion_ataque(Casilla *casilla, Tablero* tablero);

    bool validacion_defensa(int valor);


protected:
};

#endif
