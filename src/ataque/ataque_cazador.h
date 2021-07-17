
#ifndef ATAQUE_CPP_ATAQUE_HUMANO_CV_H
#define ATAQUE_CPP_ATAQUE_HUMANO_CV_H


#include "Ataque.h"

class Ataque_cazador : public Ataque {
	
public:

    Ataque_cazador(Tablero* tablero, int coordenada_x, int coordenada_y, int fuerza_actual);
    Ataque_cazador();
	
    
    void bajar_vida(Lista<Objeto*> lista_objetos, Casilla* casilla);


	
};


#endif //ATAQUE_CPP_ATAQUE_HUMANO_CV_H
