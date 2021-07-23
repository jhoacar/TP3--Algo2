#ifndef ATAQUE_H
#define ATAQUE_H

#include "../mapa/Casilla.h"
#include"../funcionalidades/Funciones.h"
#include "../mapa/Tablero.h"
class Ser;

class Ataque {

protected:
    Ser *personaje;

public:

    Ataque(Ser *personaje);
    virtual ~Ataque();
    virtual void atacar(Casilla *casilla, Tablero* tablero) = 0;
    virtual void atacar(Casilla *casilla, Tablero* tablero, char arma) = 0;


    //PRE: recibe una casilla y un rango de distancia
    //POST: devuelve true si el objeto a atacar esta a su alcance
    bool validacion_rango_ataque(Lista<Coordenada> lista_casillas_posibles, Casilla *casilla_a_atacar);

    //PRE: recibe el minimo de energia necesario para atacar
    //POST: devuelve true si le alcanza
    bool energia_suficiente(int minimo);

    //PRE: recibe la cantidad a bajar
    //POST: baja la energia del personaje
    void consumir_energia(int cantidad);

    //PRE: recibe el valor del ataque
    //POST: baja la vida a partir de cuantos puntos de armadura tenga
    int calcular_vida_con_armadura(int valor_ataque, Casilla* casilla, int indice);

    //PRE: recibe la fuerza del personaje y el porcentaje que se aplicara
    //POST: devuelve el valor del danio que hara el ataque
    int calcular_porcentaje_fuerza(int fuerza, int porcentaje);


    //PRE: recibe el nombre del objeto
    //POST: devuelve la inicial
    char devolver_inicial(string objeto);


    //PRE: recibe una casilla que atacara y el nombre del personaje que atacara
    //POST: devuelve la posicion donde se encuentra el personaje en la lista,
    //si no lo encuentra devolvera -1
    int buscar_personaje(Casilla *casilla_a_atacar, string personaje);

    //PRE: recibe el nombre y la casilla que se encuentra el personaje
    //POST: devuelve la posicion del personaje
    int indice_personaje(char personaje, Casilla* casilla);

    void calcular_valores_ataque(int indice, int porcentaje, Casilla* casilla);

    Casilla* validacion_hay_personaje_en_casilla(Lista<Casilla *> lista_casillas, string personaje);




};


#endif //ATAQUE_H
