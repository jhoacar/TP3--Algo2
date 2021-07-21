#include "Ataque.h"
#include "Ser.h"
#include "Vampiro.h"


Ataque::Ataque(Ser *personaje) {
    this -> personaje = personaje;
}
Ataque::~Ataque(){
}

bool Ataque::energia_suficiente(int minimo) {

    int energia = personaje -> devolver_energia();

    bool suficiente_energia = false;

    if(energia >= minimo){
        suficiente_energia = true;
    }
    return suficiente_energia;
}

void Ataque::quitar_vida(int cantidad){
    personaje -> bajar_vida(cantidad);
}


/*bool Ataque::validacion_rango_ataque(Casilla *casilla_a_atacar, int max_rango){

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
}*/

bool Ataque::validacion_rango_ataque(Lista<Coordenada> lista_casillas_posibles, Casilla *casilla_a_atacar){

    bool validacion = false;

    while(lista_casillas_posibles.existe_siguiente() && !validacion)
        validacion = lista_casillas_posibles.siguiente_dato() == casilla_a_atacar->obtener_posicion();

    return validacion;

}

void Ataque::calcular_valores_ataque(int indice, int porcentaje, Casilla* casilla){

    int valor_final;
    int fuerza = personaje -> devolver_fuerza();
    int valor_ataque = calcular_porcentaje_fuerza(fuerza, porcentaje);

    valor_final = calcular_vida_con_armadura(valor_ataque);
    ((Ser*) casilla -> obtener_objetos()[indice]) -> bajar_vida(valor_final);

}

void Ataque::consumir_energia(int cantidad){
    personaje -> consumir_energia(cantidad);
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


char Ataque::devolver_inicial(string objeto) {

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


int Ataque::buscar_personaje(Casilla *casilla_a_atacar, string personaje){

    int posicion;
    Objeto *objeto_referencia = new Vampiro();
    char inicial = devolver_inicial(personaje);
    objeto_referencia -> asignar_nombre(inicial);

    bool existe = casilla_a_atacar -> obtener_objetos().existe(objeto_referencia,comparacion_por_nombre);

    if(existe)
        posicion = casilla_a_atacar -> obtener_objetos().buscar_dato(0, objeto_referencia,comparacion_por_nombre);
    else
        posicion = NO_ENCONTRADO;

    return posicion;
}


int Ataque::indice_personaje(char personaje, Casilla* casilla){

    Objeto *objeto_referencia = new Vampiro();
    objeto_referencia -> asignar_nombre(personaje);
    int indice = casilla -> obtener_objetos().buscar_dato(0, objeto_referencia, comparacion_por_nombre);
    return indice;

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
	
