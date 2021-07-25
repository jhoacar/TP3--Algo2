#include "Ataque.h"
#include "../objetos/seres/Ser.h"
#include "../objetos/seres/monstruos/vampiros/Vampiro.h"
#include "../objetos/Objeto.h"

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

    valor_final = calcular_vida_con_armadura(valor_ataque, casilla, indice);
    Objeto* objeto = casilla -> obtener_objetos()[indice];
    ((Ser*) objeto) -> bajar_vida(valor_final);
    //((Ser*) casilla -> obtener_objetos()[indice]) -> bajar_vida(valor_final);

}

void Ataque::consumir_energia(int cantidad){
    personaje -> consumir_energia(cantidad);
}




int Ataque::calcular_vida_con_armadura(int valor_ataque, Casilla* casilla, int indice){

    Objeto* objeto = casilla ->obtener_objetos()[indice];
    int armadura = ((Ser*) objeto)->devolver_armadura();
    int valor_final;

    if(armadura == 0)
        valor_final = valor_ataque;
    else if(armadura == 1)
        valor_final = ((valor_ataque * 10)/100);
    else if(armadura == 2)
        valor_final = valor_ataque - ((valor_ataque * 20)/100);
    else if (armadura > 2)
        valor_final = valor_ataque - ((valor_ataque * 80)/100);

    return valor_final;
}



int Ataque::calcular_porcentaje_fuerza(int fuerza, int porcentaje){

    int valor = (fuerza * porcentaje)/100;

    return valor;
}


char Ataque::devolver_inicial(string nombre_objeto) {

    int indice = buscar_dato(NOMBRES_STRING, MAX_NOMBRES,nombre_objeto);

    if(indice != NO_ENCONTRADO)
        return NOMBRES_CHAR[indice];
    else
        return 0;
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


bool es_tipo_humano(Objeto* personaje){

    if(personaje == nullptr)
        return false;

    return personaje->obtener_nombre() == NOMBRES_CHAR[HUMANO]
           || personaje->obtener_nombre() == NOMBRES_CHAR[HUMANO_CAZADOR]
           || personaje->obtener_nombre() == NOMBRES_CHAR[VANESA];
}

bool es_tipo_monstruo(Objeto* personaje){

    if(personaje == nullptr)
        return false;

    return personaje->obtener_nombre() == NOMBRES_CHAR[ZOMBIE]
           || personaje->obtener_nombre() == NOMBRES_CHAR[VAMPIRO]
           || personaje->obtener_nombre() == NOMBRES_CHAR[VAMPIRELLA]
           || personaje->obtener_nombre() == NOMBRES_CHAR[NOSFERATU];
}

bool hay_humano_en_casilla(Casilla* casilla){

    if(casilla == nullptr)
        return false;
    return casilla->obtener_objetos().filtrar_datos(0, es_tipo_humano).obtener_tamano() != 0;


}

bool hay_monstruo_en_casilla(Casilla* casilla){

    if(casilla == nullptr)
        return false;
    return casilla->obtener_objetos().filtrar_datos(0, es_tipo_monstruo).obtener_tamano() != 0;


}

Casilla* Ataque::validacion_hay_personaje_en_casilla(Lista<Casilla *> lista_casillas, string personaje){

    Casilla* casilla_objeto = nullptr;
    Lista<Casilla*> lista_casillas_con_personaje;
    if(personaje == "humano")
        lista_casillas_con_personaje = lista_casillas.filtrar_datos(0, hay_humano_en_casilla);
    else
        lista_casillas_con_personaje = lista_casillas.filtrar_datos(0, hay_monstruo_en_casilla);

    if(lista_casillas_con_personaje.obtener_tamano() > 0)
        casilla_objeto = lista_casillas_con_personaje[0];

    return casilla_objeto;
}
