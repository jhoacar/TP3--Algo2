#ifndef VAMPIRELLA_H
#define VAMPIRELLA_H

#include "Vampiro.h"

class Vampirella : public Vampiro
{
public:
    Vampirella();
    Vampirella(Casilla *casilla,char nombre,string ID);
    void mostrar();
    void regenerar_energia();
    ~Vampirella();

    void defender();
    void defender(Tablero* tablero){};
    void defender(int accion, Tablero* tablero){};
    void defender(int eleccion){}


    void atacar(Casilla *casilla, Tablero* tablero);
    bool validacion_ataque(Casilla *casilla, Tablero* tablero);

    // PRE: Vampirella se defiende.
    // POS: Se convierte en murcielago, por lo tanto establece murcielago en true.
    void convertir_en_murcielago();

    // PRE: Vampirella se ha defendido en el turno anterior, por lo tanto muricelago es true.
    // POS: Vampirella se vuelve a convertir en vampiro, por lo tanto se establece murcielago en false.
    void convertir_en_vampiro();

    // PRE: -
    // POS: Devuelve true si es murcielago, caso contrario devuelve false.
    bool es_murcielago();

    bool validacion_defensa(int valor);

protected:
private:
    bool murcielago;
};

#endif