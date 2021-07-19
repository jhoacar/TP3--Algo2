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


char Ataque_humano::devolver_inicial(string objeto) {

    char inicial;
    if(objeto == "agua")
        inicial = NOMBRES_CHAR[AGUA];
    if(objeto == "bala")
        inicial = NOMBRES_CHAR[BALA];
    if(objeto == "cruz")
        inicial = NOMBRES_CHAR[CRUZ];
    if(objeto == "estaca")
        inicial = NOMBRES_CHAR[ESTACA];
    if(objeto == "escopeta")
        inicial = NOMBRES_CHAR[ESCOPETA];
    if(objeto == "humano")
        inicial = NOMBRES_CHAR[HUMANO];
    if(objeto == "humano CV")
        inicial = NOMBRES_CHAR[HUMANO_CAZADOR];
    if(objeto == "Vanesa")
        inicial = NOMBRES_CHAR[VANESA];
    if(objeto == "vampiro")
        inicial = NOMBRES_CHAR[VAMPIRO];
    if(objeto == "Vampirella")
        inicial = NOMBRES_CHAR[VAMPIRELLA];
    if(objeto == "Nosferatu")
        inicial = NOMBRES_CHAR[NOSFERATU];
    if(objeto == "zombi")
        inicial = NOMBRES_CHAR[ZOMBIE];

    return inicial;



}




bool Ataque_humano::tiene_arma(string arma_elegida){

    Objeto *objeto_referencia = new Escopeta();
    char inicial = devolver_inicial(arma_elegida);
    objeto_referencia -> asignar_nombre(inicial);
    return personaje -> obtener_inventario().existe(objeto_referencia,comparacion_por_nombre);

}


int Ataque_humano::buscar_personaje(Casilla *casilla_a_atacar, string personaje){

    int posicion;
    Objeto *objeto_referencia = new Vampiro();
    char inicial = devolver_inicial(personaje);
    objeto_referencia -> asignar_nombre(inicial);

    bool existe = casilla_a_atacar -> obtener_objetos().existe(objeto_referencia,comparacion_por_nombre);

    if(existe)
        posicion = casilla_a_atacar -> obtener_objetos().buscar_dato(0, objeto_referencia,comparacion_por_nombre);
    else
        posicion = -1;

    return posicion;
}




bool Ataque_humano::tiene_balas(int cantidad_minima_balas){

    bool balas_necesarias = false;

    Objeto *objeto_referencia = new Bala();
    char inicial = NOMBRES_CHAR[BALA];
    objeto_referencia -> asignar_nombre(inicial);
    bool esta_en_inventario = personaje -> obtener_inventario().existe(objeto_referencia,comparacion_por_nombre);

    if(esta_en_inventario){
        int posicion_balas = personaje -> obtener_inventario().buscar_dato(0, objeto_referencia,comparacion_por_nombre);

        Objeto* balas = personaje -> obtener_inventario()[posicion_balas];
        int cantidad_balas = balas -> obtener_cantidad();

        if(cantidad_balas >= cantidad_minima_balas)
            balas_necesarias = true;
    }
    return balas_necesarias;
}

void Ataque_humano::bajar_cantidad_objeto(int cantidad_gastada, string arma){

    Objeto *objeto_referencia = new Bala();
    char inicial = devolver_inicial(arma);
    objeto_referencia -> asignar_nombre(inicial);
    int posicion_balas = personaje -> obtener_inventario().buscar_dato(0, objeto_referencia,comparacion_por_nombre);

    if(posicion_balas != -1){
        Objeto* balas = personaje -> obtener_inventario()[posicion_balas];
        balas -> disminuir_cantidad(cantidad_gastada);
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
    else if (eleccion == '2')
        arma_a_utilizar = "agua";
    else
        arma_a_utilizar = "estaca";

    return arma_a_utilizar;

}





bool Ataque_humano::validacion_ataque(Casilla *casilla_a_atacar, string arma_elegida){

    bool validacion_ataque;
    bool validacion_rango = validacion_rango_ataque(casilla_a_atacar, 1);

    bool energia_suficiente_ = energia_suficiente(5);
    bool tiene_arma_ = tiene_arma(arma_elegida);
    bool tiene_suficientes_balas = tiene_balas(2);

    if(validacion_rango && energia_suficiente_ && tiene_arma_ && tiene_suficientes_balas)
        validacion_ataque = true;
    else
        validacion_ataque = false;

    return validacion_ataque;
}


int Ataque_humano::indice_personaje(string personaje, Casilla* casilla){

    Objeto *objeto_referencia = new Vampiro();
    char inicial = devolver_inicial(personaje);
    objeto_referencia -> asignar_nombre(inicial);
    int indice = casilla -> obtener_objetos().buscar_dato(0, objeto_referencia, comparacion_por_nombre);
    return indice;

}

void Ataque_humano::bajar_vida(Casilla* casilla){

    int indice_zombie = indice_personaje(NOMBRES_STRING[ZOMBIE], casilla);
    int indice_vampiro = indice_personaje(NOMBRES_STRING[VAMPIRO], casilla);
    int indice_nosferatu = indice_personaje(NOMBRES_STRING[NOSFERATU], casilla);
    int indice_vampirella = indice_personaje(NOMBRES_STRING[VAMPIRELLA], casilla);

    int valor_ataque;
    int valor_final;
    int fuerza = personaje -> devolver_fuerza();

    if(indice_zombie != -1) {
        valor_ataque = calcular_porcentaje_fuerza(fuerza, 100);
        valor_final = calcular_vida_con_armadura(valor_ataque);

        Zombie *zombie = casilla -> obtener_objetos()[indice_zombie];
        zombie -> bajar_vida(valor_final);

    }
    if(indice_vampiro != -1){
        valor_ataque = calcular_porcentaje_fuerza(fuerza, 20);
        valor_final = calcular_vida_con_armadura(valor_ataque);
        Vampiro *vampiro = casilla -> obtener_objetos()[indice_vampiro];
        vampiro -> bajar_vida(valor_final);
    }
    if(indice_nosferatu != -1){
        valor_ataque = calcular_porcentaje_fuerza(fuerza, 20);
        valor_final = calcular_vida_con_armadura(valor_ataque);
        Nosferatu *nosferatu = casilla -> obtener_objetos()[indice_nosferatu];
        nosferatu -> bajar_vida(valor_final);
    }
    if(indice_vampirella != -1){
        valor_ataque = calcular_porcentaje_fuerza(fuerza, 20);
        valor_final = calcular_vida_con_armadura(valor_ataque);
        Vampirella *vampirella = casilla -> obtener_objetos()[indice_nosferatu];
        vampirella -> bajar_vida(valor_final);
    }

}




void Ataque_humano::atacar(Casilla *casilla) {

    validacion_ataque(casilla, arma_elegida);

    if(validacion_ataque){

        Lista<Objeto*> lista_objetos = casilla -> obtener_objetos();

        int posicion;
        posicion = buscar_personaje(casilla, NOMBRES_STRING[ZOMBIE]);

        if(posicion == -1)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[VAMPIRO]);
        if(posicion == -1)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[VAMPIRELLA]);
        if(posicion == -1)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[NOSFERATU]);

        consumir_energia(5);
        bajar_cantidad_objeto(2, NOMBRES_STRING[BALA]);

        bajar_vida(casilla);
    }
    delete ataque;
}






