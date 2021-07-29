#ifndef ATAQUE_H
#define ATAQUE_H

#include "../mapa/Tablero.h"

class Ser;

bool tiene_humano(Casilla *casilla);

bool tiene_monstruo(Casilla *casilla);

int extraer_cantidad(Objeto *objeto);

class Ataque{

    protected: 
     
        Ser *personaje;
        
        //PRE:   
        //POST: verifica si la energia del personaje es suficiente para atacar.
        virtual bool tiene_energia()=0;
        
        //PRE: recibe una coordenada y puede recibir un arma  
        //POST: devuelve true si la posicion indicada esta en el rango de ataque del personaje.
        virtual bool esta_en_rango_ataque(Coordenada posicion,char arma=NO_ARMA)=0;
        
        //PRE: recibe una casilla para atacar y puede recibir un arma.
        //POST: encuentra el mounstruo que se encuentra en la casilla, calcula el valor del ataque y le baja la vida
        virtual void atacar_casilla(Casilla *casilla_ataque, char arma=NO_ARMA)=0;
    
        //PRE:    
        //POST: baja la energia del personaje
        virtual void consumir_energia()=0;
    
        //PRE: recibe un personaje
        //POST: devuelve el porcentaje a utilizar para el calculo de ataque
        float obtener_armadura(Ser *personaje);
    public:
    
     
        Ataque(Ser *personaje);
        virtual ~Ataque();
        
        //PRE: recibe una coordenada a atacar, el tablero y puede recibir un arma.
        //POST: ataca a un personaje.
        virtual void atacar(Coordenada posicion,Tablero *tablero,char arma=NO_ARMA)=0;
        
        //PRE: recibe una coordenada a atacar, el tablero y puede recibir un arma.
        //POST: verifica si se puede atacar.
        virtual bool se_puede_atacar(Coordenada posicion,Tablero *tablero,char arma=NO_ARMA)=0;
};

#endif
