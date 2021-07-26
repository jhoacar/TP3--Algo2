#ifndef ATAQUE_HUMANO_H
#define ATAQUE_HUMANO_H

#include "../Ataque.h"
#include "../../objetos/seres/humanos/Humano.h"
#include <string>

using namespace std;

class Ataque_humano : public Ataque{


public:
    Ataque_humano(Humano *personaje);
    ~Ataque_humano();

    void atacar(Casilla *casilla, Tablero* tablero);
    void atacar(Casilla *casilla, Tablero* tablero, char arma);



    //PRE: recibe el arma que utilizara
    //POST: verifica si existe ese arma en su inventario
    bool tiene_arma(char arma_elegida);

    bool validacion_atacar_personaje(Casilla *casilla, Tablero* tablero);
    bool validacion_atacar_personaje(Casilla *casilla, Tablero* tablero, char arma);


    //PRE: recibe la cantidad minima de balas para atacar
    //POST: devuelve si tiene suficientes balas o no
    bool tiene_balas(int cantidad_minima_balas);

     //PRE: recibe la casilla a atacar y el arma que va a utilizar
    //POST: devuelve si puede atacar o no
    bool validacion_ataque(char arma_elegida, int energia_suficiente);

    //PRE: recibe una cantidad de cuantos objetos gasto y que objeto
    //POST: baja la cantidad de ese objeto
    void bajar_cantidad_objeto(char arma);


    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: le baja la vida al personaje
    void bajar_vida(Casilla* casilla);

    //PRE: recibe la casilla del personaje a bajarle la vida y el arma elegida
    //POST: valida si el mounstruo esta oculto
    bool validacion_mounstruo_oculto(Casilla* casilla, char arma_elegida);

    //PRE: recibe la casilla del personaje a bajarle la vida el indice donde se encuentra en la lista y el valor a sacar
    //POST: calcula el valor del ataque con el valor recibido calcula a partir de la armadura que tenga el personaje atacado.
    void calcular_ataque_valores_fijos(int indice, int valor_a_sacar, Casilla* casilla);

    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: devuelve la casilla donde se encuentra el personaje a atacar
    Casilla* devolver_casilla_aleatoria_en_tablero(Tablero* tablero, Coordenada centro, char arma_elegida, int rango_escopeta);

    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: devuelve la casilla donde se encuentra el personaje a atacar
    Casilla* devolver_casilla_especifica_en_tablero(Tablero* tablero, Casilla* casilla);

    //PRE: recibe el tablero, donde se encuentra el atacante, el arma elegida y el rango de escopeta
    //POST: devuelve si hay algun personaje para atacar
    bool validacion_rango_aleatorio(Tablero* tablero,Coordenada centro, char arma_elegida, int rango_escopeta);


    bool validacion_rango_especifico(Casilla* casilla_a_atacar, char arma_elegida, int rango_escopeta);

    //PRE: recibe la coordenada donde se encuentra el atacante, el arma elegida y el rango de escopeta
    //POST: devuelve la lista de coordenadas posibles a atacar segun el arma usada
    Lista<Coordenada> obtener_lista_coordenadas_segun_arma(Coordenada centro, char arma_elegida, int rango_escopeta);




};


#endif //ATAQUE_HUMANO_H
