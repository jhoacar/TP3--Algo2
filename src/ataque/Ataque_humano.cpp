#include "Ataque_humano.h"
#include "Escopeta.h"
#include "Bala.h"
#include "Vampiro.h"
#include "Nosferatu.h"
#include "Vampirella.h"
#include "Zombie.h"
#include <stdlib.h>
#include <iostream>
#include "Constantes.h"

using namespace std;

Ataque_humano::Ataque_humano(Humano *personaje): Ataque(personaje){
}


Ataque_humano::~Ataque_humano(){
}




bool Ataque_humano::tiene_arma(char arma_elegida){

    Objeto *objeto_referencia = new Escopeta();
    objeto_referencia -> asignar_nombre(arma_elegida);
    Lista<Objeto*> inventario = personaje -> obtener_inventario();

    return inventario.existe(objeto_referencia,comparacion_por_nombre);

}



bool Ataque_humano::tiene_balas(int cantidad_minima_balas){

    bool balas_necesarias = false;

    Objeto *objeto_referencia = new Bala();
    char inicial = NOMBRES_CHAR[BALA];
    objeto_referencia -> asignar_nombre(inicial);
    bool esta_en_inventario = personaje -> obtener_inventario().existe(objeto_referencia,comparacion_por_nombre);

    if(esta_en_inventario){
        int posicion_balas = personaje -> obtener_inventario().buscar_dato(0, objeto_referencia,comparacion_por_nombre);


        int cantidad_balas = ((Elemento*) personaje -> obtener_inventario()[posicion_balas]) -> obtener_cantidad();

        if(cantidad_balas >= cantidad_minima_balas)
            balas_necesarias = true;
    }
    return balas_necesarias;
}

void Ataque_humano::bajar_cantidad_objeto(char arma){

    Objeto *objeto_referencia = new Bala();
    objeto_referencia -> asignar_nombre(arma);
    int posicion = personaje -> obtener_inventario().buscar_dato(0, objeto_referencia,comparacion_por_nombre);

    if(posicion != NO_ENCONTRADO){
        if(arma == NOMBRES_CHAR[BALA])
            ((Elemento*) personaje -> obtener_inventario()[posicion]) -> disminuir_cantidad(2);
        else if(arma == NOMBRES_CHAR[AGUA])
            ((Elemento*) personaje -> obtener_inventario()[posicion]) -> disminuir_cantidad(1);
    }


}


char Ataque_humano::eleccion_arma(){

    char arma_a_utilizar;
    char eleccion;
    cout << "Con que arma quiere atacar?:" << endl;
    cout << "1. Escopeta" << endl;
    cout << "2. Agua bendita" << endl;
    cout << "3. Estaca" << endl;

    cin  >> eleccion;

    while((eleccion != '1') && (eleccion != '2') && (eleccion != '3')){
        cout << "Ingrese un valor de 1 a 3:" << endl;
        cin >> eleccion;
    }
    if(eleccion == '1')
        arma_a_utilizar = 'E';
    else if(eleccion == '2')
        arma_a_utilizar = 'a';
    else
        arma_a_utilizar = 'e';

    return arma_a_utilizar;

}

bool Ataque_humano::validacion_mounstruo_oculto(Casilla *casilla, char arma_elegida){

    Objeto *objeto_referencia = new Vampiro();
    objeto_referencia -> asignar_nombre(NOMBRES_CHAR[VAMPIRO]);

    Lista<Objeto*> lista_objetos = casilla -> obtener_objetos();

    int indice_vampiro = buscar_personaje(casilla, NOMBRES_STRING[VAMPIRO]);
    int indice_zombie = buscar_personaje(casilla, NOMBRES_STRING[ZOMBIE]);
    int indice_vampirella = buscar_personaje(casilla, NOMBRES_STRING[VAMPIRELLA]);

    bool oculto = false;

    if(indice_vampiro != NO_ENCONTRADO){
        oculto = ((Vampiro*)lista_objetos[indice_vampiro]) -> esta_oculto();
    }
    else if(indice_zombie != NO_ENCONTRADO) {
        oculto = ((Zombie*)lista_objetos[indice_zombie]) -> esta_escondido();
    }
    else if(indice_vampirella != NO_ENCONTRADO){
        oculto = ((Vampirella*)lista_objetos[indice_vampirella]) -> esta_oculto();
        if(arma_elegida == NOMBRES_CHAR[ESCOPETA])
            oculto = true;
    }

    return oculto;



}

bool Ataque_humano::validacion_ataque(Casilla *casilla_a_atacar, char arma_elegida){

    bool validacion_ataque;



    Casilla* casilla_personaje = personaje ->obtener_casilla();
    Coordenada centro = casilla_personaje ->obtener_posicion();

    Lista<Coordenada> lista_casillas_posibles = obtener_cuadrado(centro, 1);

    bool validacion_rango = validacion_rango_ataque(lista_casillas_posibles, casilla_a_atacar);

    bool energia_suficiente_ = energia_suficiente(5);
    bool tiene_arma_ = tiene_arma(arma_elegida);
    bool tiene_suficientes_balas = tiene_balas(2);
    bool mounstruo_oculto = validacion_mounstruo_oculto(casilla_a_atacar, arma_elegida);

    if(validacion_rango && energia_suficiente_ && tiene_arma_ && tiene_suficientes_balas && !mounstruo_oculto)
        validacion_ataque = true;
    else
        validacion_ataque = false;

    return validacion_ataque;
}



void Ataque_humano::calcular_ataque_valores_fijos(int indice, int valor_a_sacar, Casilla* casilla){

    int valor_final;
    valor_final = calcular_vida_con_armadura(valor_a_sacar);
    ((Ser*) casilla -> obtener_objetos()[indice]) -> bajar_vida(valor_final);

}




void Ataque_humano::bajar_vida(Casilla* casilla){

    int indice_zombie = indice_personaje(NOMBRES_CHAR[ZOMBIE], casilla);
    int indice_vampiro = indice_personaje(NOMBRES_CHAR[VAMPIRO], casilla);
    int indice_nosferatu = indice_personaje(NOMBRES_CHAR[NOSFERATU], casilla);
    int indice_vampirella = indice_personaje(NOMBRES_CHAR[VAMPIRELLA], casilla);

    if(indice_zombie != NO_ENCONTRADO)
        calcular_valores_ataque(indice_zombie, 100, casilla);
    if(indice_vampiro != NO_ENCONTRADO)
        calcular_valores_ataque(indice_vampiro, 20, casilla);
    if(indice_nosferatu != NO_ENCONTRADO)
        calcular_valores_ataque(indice_nosferatu, 20, casilla);
    if(indice_vampirella != NO_ENCONTRADO)
        calcular_valores_ataque(indice_vampirella, 20, casilla);
}


void Ataque_humano::atacar(Casilla *casilla) {

    char arma_elegida = NOMBRES_CHAR[ESCOPETA];
    bool validacion = validacion_ataque(casilla, arma_elegida);

    if(validacion){

        Lista<Objeto*> lista_objetos = casilla -> obtener_objetos();

        int posicion;
        posicion = buscar_personaje(casilla, NOMBRES_STRING[ZOMBIE]);

        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[VAMPIRO]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[VAMPIRELLA]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[NOSFERATU]);

        if(posicion != NO_ENCONTRADO){
            consumir_energia(5);
            bajar_cantidad_objeto(arma_elegida);
            bajar_vida(casilla);
        }


    }
}
Casilla* Ataque_humano::validacion_hay_personaje_en_casilla(Lista<Casilla *> lista_casillas){

    bool validacion_hay_personaje = false;
    Casilla* casilla_objeto;

    while(lista_casillas.existe_siguiente() && !validacion_hay_personaje) {
        Casilla *casilla_actual = lista_casillas.siguiente_dato();
        while (casilla_actual->obtener_objetos().existe_siguiente() && !validacion_hay_personaje) {

            Objeto *objeto_actual = casilla_actual->obtener_objetos().siguiente_dato();
            char nombre_actual = objeto_actual->obtener_nombre();


            if (nombre_actual == NOMBRES_CHAR[ZOMBIE] || nombre_actual == NOMBRES_CHAR[VAMPIRO] ||
                nombre_actual == NOMBRES_CHAR[VAMPIRELLA] || nombre_actual == NOMBRES_CHAR[NOSFERATU]) {
                validacion_hay_personaje = true;
                casilla_objeto = objeto_actual -> obtener_casilla();
            }
        }
    }
    return casilla_objeto;
}


void Ataque_humano::atacar(Tablero* tablero) {

    Casilla *casilla_personaje = (personaje -> obtener_casilla());
    Coordenada centro = casilla_personaje->obtener_posicion();

    Lista<Coordenada> lista_coordenadas = obtener_cuadrado(centro, 1);
    Lista<Casilla *> lista_casillas = tablero -> obtener_lista_casillas(lista_coordenadas);

    Casilla* casilla_objeto = validacion_hay_personaje_en_casilla(lista_casillas);

    char arma_elegida = NOMBRES_CHAR[ESCOPETA];
    bool validacion = false;
    if(casilla_objeto != nullptr)
        validacion = validacion_ataque(casilla_objeto, arma_elegida);

    if((casilla_objeto != nullptr) && validacion){

        Lista<Objeto*> lista_objetos = casilla_objeto -> obtener_objetos();

        int posicion;
        posicion = buscar_personaje(casilla_objeto, NOMBRES_STRING[ZOMBIE]);

        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_objeto, NOMBRES_STRING[VAMPIRO]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_objeto, NOMBRES_STRING[VAMPIRELLA]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_objeto, NOMBRES_STRING[NOSFERATU]);

        if(posicion != NO_ENCONTRADO){
            consumir_energia(5);
            bajar_cantidad_objeto(arma_elegida);
            bajar_vida(casilla_objeto);
        }
    }
}



