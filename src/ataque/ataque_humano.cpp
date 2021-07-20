#include "Ataque_humano.h"
#include "../objetos/elementos/Escopeta.h"
#include "../objetos/elementos/Bala.h"
#include "../objetos/seres/monstruos/vampiros/Vampiro.h"
#include "../objetos/seres/monstruos/vampiros/Nosferatu.h"
#include "../objetos/seres/monstruos/vampiros/Vampirella.h"
#include "../objetos/seres/monstruos/zombies/Zombie.h"
#include <stdlib.h>
#include <iostream>
#include "../constantes/Constantes.h"

using namespace std;

Ataque_humano::Ataque_humano(Humano *personaje): Ataque(personaje){
}







bool Ataque_humano::tiene_arma(string arma_elegida){

    Objeto *objeto_referencia = new Escopeta();
    char inicial = devolver_inicial(arma_elegida);
    objeto_referencia -> asignar_nombre(inicial);
    return personaje -> obtener_inventario().existe(objeto_referencia,comparacion_por_nombre);

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

void Ataque_humano::bajar_cantidad_objeto(string arma){

    Objeto *objeto_referencia = new Bala();
    char inicial = devolver_inicial(arma);
    objeto_referencia -> asignar_nombre(inicial);
    int posicion = personaje -> obtener_inventario().buscar_dato(0, objeto_referencia,comparacion_por_nombre);

    if(posicion != NO_ENCONTRADO){
        if(arma == NOMBRES_STRING[BALA])
            ((Elemento*) personaje -> obtener_inventario()[posicion]) -> disminuir_cantidad(2);
        else if(arma == NOMBRES_STRING[AGUA])
            ((Elemento*) personaje -> obtener_inventario()[posicion]) -> disminuir_cantidad(1);
    }


}




string Ataque_humano::eleccion_arma(){

    string arma_a_utilizar;
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
        arma_a_utilizar = "escopeta";
    else if(eleccion == '2')
        arma_a_utilizar = "agua";
    else
        arma_a_utilizar = "estaca";

    return arma_a_utilizar;

}



bool Ataque_humano::validacion_ataque(Casilla *casilla_a_atacar, string arma_elegida){

    bool validacion_ataque;

    Casilla* casilla_personaje = personaje ->obtener_casilla();
    Coordenada centro = casilla_personaje ->obtener_posicion();

    Lista<Coordenada> lista_casillas_posibles = obtener_cuadrado(centro, 1);

    bool validacion_rango = validacion_rango_ataque(lista_casillas_posibles, casilla_a_atacar);

    bool energia_suficiente_ = energia_suficiente(5);
    bool tiene_arma_ = tiene_arma(arma_elegida);
    bool tiene_suficientes_balas = tiene_balas(2);

    if(validacion_rango && energia_suficiente_ && tiene_arma_ && tiene_suficientes_balas)
        validacion_ataque = true;
    else
        validacion_ataque = false;

    return validacion_ataque;
}





void Ataque_humano::calcular_valores_ataque(int indice, int porcentaje, Casilla* casilla){

    int valor_final;
    int fuerza = personaje -> devolver_fuerza();
    int valor_ataque = calcular_porcentaje_fuerza(fuerza, porcentaje);

    valor_final = calcular_vida_con_armadura(valor_ataque);
    ((Ser*) casilla -> obtener_objetos()[indice]) -> bajar_vida(valor_final);

}

void Ataque_humano::calcular_ataque_valores_fijos(int indice, int valor_a_sacar, Casilla* casilla){

    int valor_final;
    valor_final = calcular_vida_con_armadura(valor_a_sacar);
    ((Ser*) casilla -> obtener_objetos()[indice]) -> bajar_vida(valor_final);

}




void Ataque_humano::bajar_vida(Casilla* casilla){

    int indice_zombie = indice_personaje(NOMBRES_STRING[ZOMBIE], casilla);
    int indice_vampiro = indice_personaje(NOMBRES_STRING[VAMPIRO], casilla);
    int indice_nosferatu = indice_personaje(NOMBRES_STRING[NOSFERATU], casilla);
    int indice_vampirella = indice_personaje(NOMBRES_STRING[VAMPIRELLA], casilla);

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

    string arma_elegida = eleccion_arma();
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






