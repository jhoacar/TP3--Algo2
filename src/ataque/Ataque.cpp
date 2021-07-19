#include "Ataque.h"
#include "../objetos/seres/Ser.h"



Ataque::Ataque(Ser *personaje) {
    this -> personaje = personaje;
}


bool Ataque::energia_suficiente(int minimo) {

    int energia = personaje -> devolver_energia();

    bool suficiente_energia = false;

    if(energia >= minimo){
        suficiente_energia = true;
    }
    return suficiente_energia;
}


bool Ataque::validacion_rango_ataque(Casilla *casilla_a_atacar, int max_rango){

    int posicion_x_atacar = casilla_a_atacar -> obtener_fila();
    int posicion_y_atacar = casilla_a_atacar -> obtener_columna();

    Casilla* casilla_atacante = personaje -> obtener_casilla();
    int posicion_x_atacante = casilla_atacante -> obtener_fila();
    int posicion_y_atacante = casilla_atacante -> obtener_columna();

    bool rango_valido = false;
    int resta_coord_x = abs(posicion_x_atacar - posicion_x_atacante);
    int resta_coord_y = abs(posicion_y_atacar - posicion_y_atacante);

    if((resta_coord_x <= max_rango && resta_coord_x > 0) || (resta_coord_y <= max_rango && resta_coord_x > 0)){
        rango_valido = true;
    }

    return rango_valido;
}



void Ataque::consumir_energia(int cantidad){
    personaje -> bajar_energia(cantidad);
}




int Ataque::calcular_vida_con_armadura(int valor_ataque){

    int armadura = personaje -> devolver_armadura();
    int valor_final;

    if(armadura == 0)
        valor_final = valor_ataque;
    else if(armadura == 1)
        valor_final = ((valor_ataque * 10)/100);
    else if(armadura == 2)
        valor_final = valor_ataque - ((valor_ataque * 20)/100);
    else if (armadura >= 2)
        valor_final = valor_ataque - ((valor_ataque * 80)/100);

    return valor_final;
}



int Ataque::calcular_porcentaje_fuerza(int fuerza, int porcentaje){

    int valor = (fuerza * porcentaje)/100;

    return valor;
}





/*bool Ataque::validacion_rango_ataque_estaca(int coord_x, int coord_y, int max_rango){

    bool rango_valido = false;
    int resta_coord_x = abs(coord_x - coordenada_x_actual);
    int resta_coord_y = abs(coord_y - coordenada_y_actual);

    if(((resta_coord_x <= max_rango) && (resta_coord_x > 0) && (coordenada_y_actual == coord_y)) || ((resta_coord_y <= max_rango) && (resta_coord_x > 0)&& (coordenada_y_actual == coord_y))){
        rango_valido = true;
    }

    return rango_valido;
}*/
	
