#ifndef CAZADOR_H
#define CAZADOR_H

#include "../Humano.h"


class Cazador : public Humano
{
public:
    Cazador();
    Cazador(Casilla *casilla,char nombre,string ID);
    void mostrar();
    void regenerar_energia();
    ~Cazador();
    void defender(int accion, Tablero* tablero);
    void defender(int eleccion){}
    void defender(Tablero* tablero){}
    void defender(){}
    void atacar(Casilla *casilla, Tablero* tablero);
    void atacar(Casilla *casilla, Tablero* tablero, char arma);

    bool validacion_defensa(int valor);

    bool validacion_ataque(Casilla *casilla, Tablero* tablero, char arma);


protected:
};

#endif