#ifndef ATAQUE_VAMPIRO_H
#define ATAQUE_VAMPIRO_H

#include "../Ataque_monstruo.h"

#include "../../../objetos/seres/monstruos/vampiros/Vampiro.h"

#include "../../../objetos/seres/humanos/Humano.h"

bool hay_casos_especiales(Humano *humano);

class Ataque_vampiro:public Ataque_monstruo{
    
    protected:
        virtual void consumir_energia();
        virtual bool tiene_energia();
        virtual bool esta_en_rango_ataque(Coordenada posicion,char arma=NO_ARMA);
        virtual void atacar_casilla(Casilla *casilla_ataque,char arma=NO_ARMA);
        
    public:
        Ataque_vampiro(Vampiro *personaje);

};

#endif