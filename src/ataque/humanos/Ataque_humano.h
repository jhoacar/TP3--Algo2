#ifndef ATAQUE_HUMANO_H
#define ATAQUE_HUMANO_H

#include "../Ataque.h"
#include "../../objetos/seres/humanos/Humano.h"

#include "../../objetos/seres/monstruos/vampiros/Vampiro.h"
#include "../../objetos/seres/monstruos/zombies/Zombie.h"


class Ataque_humano:public Ataque{

    protected: 
        
        virtual bool tiene_energia();
        void consumir_energia();
        virtual bool esta_en_rango_ataque(Coordenada posicion,char arma);
        void atacar_casilla(Casilla *casilla_ataque, char arma);
        
    
        //PRE: recibe un arma.
        //POST: verifica si el personaje tiene el arma en el inventario.
        bool tiene_arma(const char arma);
    
        //PRE: recibe un arma
        //POST: le baja la cantidad usada del arma o balas al personaje
        void consumir_arma(const char arma);
    
         //PRE:
        //POST: borro un agua del inventario del personaje
        void consumir_agua();
    
        //PRE:
        //POST: borra todas las aguas que haya en el inventario del personaje
        void consumir_toda_agua();
        
        //PRE:
        //POST: le baja las balas utilizadas al personaje
        void consumir_balas();
        
    
         //PRE:
        //POST: baja la cantidad de balas, y si tiene menos de 2 balas en una posicion, elimina el elemento
        void eliminar_balas_inventario();
    
         //PRE: recibe el nombre a atacar y el arma
        //POST: verifica si estan escondidos
        bool hay_casos_especiales(Monstruo *monstruo, char arma);
        
    
         //PRE: recibe el nombre a atacar y el arma
        //POST: calcula cuanta vida tiene que bajarle al personaje atacado
        virtual float obtener_ataque(char nombre_mostruo,char arma);

    public:
        Ataque_humano(Humano *personaje);
        void atacar(Coordenada posicion, Tablero *tablero, char arma=NOMBRES_CHAR[ESCOPETA]);
        bool se_puede_atacar(Coordenada posicion,Tablero *tablero, char arma=NO_ARMA);

};

#endif
