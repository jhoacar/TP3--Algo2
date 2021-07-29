#ifndef ATAQUE_NOSFERATU_H
#define ATAQUE_NOSFERATU_H

#include "Ataque_vampiro.h"

#include "../../../objetos/seres/monstruos/vampiros/Nosferatu.h"

class Ataque_nosferatu:public Ataque_vampiro{
    
    virtual void consumir_energia();
    
    //PRE: recibe el humano a convertir
    //POST: le cambia el nombre, y le cambia su ataque y defensa a los de tipo vampiro
    void convertir_vampiro(Humano *humano);
    virtual bool tiene_energia();
    virtual bool esta_en_rango_ataque(Coordenada posicion,char arma=NO_ARMA);
    virtual void atacar_casilla(Casilla *casilla_ataque, char arma=NO_ARMA);
    public:
        Ataque_nosferatu(Nosferatu *personaje);       
};

#endif
