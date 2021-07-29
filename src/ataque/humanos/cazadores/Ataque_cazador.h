#ifndef ATAQUE_CAZADOR_H
#define ATAQUE_CAZADOR_H

#include "../Ataque_humano.h"

#include "../../../objetos/seres/humanos/cazador/Cazador.h"


class Ataque_cazador:public Ataque_humano{

    protected: 
        char arma;
        virtual void consumir_energia();
        virtual bool esta_en_rango_ataque(Coordenada posicion,char arma);
        virtual bool tiene_energia();
        virtual float obtener_ataque(char nombre_mostruo,char arma=NOMBRES_CHAR[ESCOPETA]);
    public:
        Ataque_cazador(Cazador *personaje);
};

#endif