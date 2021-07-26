#ifndef DEFENSA_H
#define DEFENSA_H

#include "../mapa/Tablero.h"

class Ser;

class Defensa{

    protected:
        Ser *personaje;
    public:
        Defensa(Ser *personaje);
        virtual ~Defensa();
        virtual void defender()=0;
        virtual void defender(int eleccion) = 0;
        virtual void defender(Tablero* tablero) = 0;
        virtual void defender(int accion, Tablero*)=0;
        bool validar_energia(int minimo);
        Lista<Casilla *> obtener_casilla_con_personaje(Lista<Casilla *> lista_casillas, string personaje);
        int indice_personaje(char personaje, Casilla* casilla);
};
#endif