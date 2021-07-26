#include "Defensa.h"
#include "../objetos/seres/Ser.h"
#include "../objetos/seres/humanos/Humano.h"

Defensa::Defensa(Ser *personaje){
    this -> personaje = personaje;
}
Defensa::~Defensa(){
}

bool Defensa::validar_energia(int minimo) {

    bool energia_suficiente = false;
    int energia = personaje ->devolver_energia();

    if(energia >= minimo)
        energia_suficiente = true;

    return energia_suficiente;
}
bool es_tipo_humano_(Objeto* personaje){

    if(personaje == nullptr)
        return false;

    return personaje->obtener_nombre() == NOMBRES_CHAR[HUMANO]
           || personaje->obtener_nombre() == NOMBRES_CHAR[HUMANO_CAZADOR]
           || personaje->obtener_nombre() == NOMBRES_CHAR[VANESA];
}

bool es_tipo_monstruo_(Objeto* personaje){

    if(personaje == nullptr)
        return false;

    return personaje->obtener_nombre() == NOMBRES_CHAR[ZOMBIE]
           || personaje->obtener_nombre() == NOMBRES_CHAR[VAMPIRO]
           || personaje->obtener_nombre() == NOMBRES_CHAR[VAMPIRELLA]
           || personaje->obtener_nombre() == NOMBRES_CHAR[NOSFERATU];
}

bool hay_humano_en_casilla_(Casilla* casilla){

    if(casilla == nullptr)
        return false;
    return casilla->obtener_objetos().filtrar_datos(0, es_tipo_humano_).obtener_tamano() != 0;


}

int Defensa::indice_personaje(char personaje, Casilla* casilla){

    Objeto *objeto_referencia = new Humano();
    objeto_referencia -> asignar_nombre(personaje);
    int indice = casilla -> obtener_objetos().buscar_dato(0, objeto_referencia, comparacion_por_nombre);
    return indice;
}

bool hay_monstruo_en_casilla_(Casilla* casilla){

    if(casilla == nullptr)
        return false;
    return casilla->obtener_objetos().filtrar_datos(0, es_tipo_monstruo_).obtener_tamano() != 0;
}

Lista<Casilla *> Defensa::obtener_casilla_con_personaje(Lista<Casilla *> lista_casillas, string personaje){


    Lista<Casilla*> lista_casillas_con_personaje;
    if(personaje == NOMBRES_STRING[HUMANO])
        lista_casillas_con_personaje = lista_casillas.filtrar_datos(0, hay_humano_en_casilla_);
    else
        lista_casillas_con_personaje = lista_casillas.filtrar_datos(0, hay_monstruo_en_casilla_);

    return lista_casillas_con_personaje;


}

