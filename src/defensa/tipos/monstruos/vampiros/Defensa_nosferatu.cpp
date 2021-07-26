#include "Defensa_nosferatu.h"



Defensa_nosferatu::Defensa_nosferatu(Nosferatu *personaje):Defensa_vampiro(personaje){
}

bool es_vampiro(Objeto* personaje){

    if(personaje == nullptr)
        return false;

    return personaje->obtener_nombre() == NOMBRES_CHAR[VAMPIRO] || personaje->obtener_nombre() == NOMBRES_CHAR[VAMPIRELLA];
}

bool esta_nosferatu(Casilla* casilla){

    if(casilla == nullptr)
        return false;
    return casilla->obtener_objetos().filtrar_datos(0, es_vampiro).obtener_tamano() != 0;


}

Lista<Casilla *> Defensa_nosferatu::obtener_casilla_con_personaje(Lista<Casilla *> lista_casillas){


    Lista<Casilla*> lista_casillas_con_personaje;
    lista_casillas_con_personaje = lista_casillas.filtrar_datos(0, esta_nosferatu);


    return lista_casillas_con_personaje;


}




void Defensa_nosferatu::defender(Tablero* tablero) {

    Lista<Coordenada> lista_coordenadas = obtener_cuadrado(personaje -> obtener_casilla()->obtener_posicion(), 2);
    Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);
    Lista<Casilla *> lista_casillas_con_personaje = obtener_casilla_con_personaje(lista_casillas);


    if(lista_casillas_con_personaje.obtener_tamano() >= 1) {
        Casilla *casilla = lista_casillas_con_personaje.siguiente_dato();

        Objeto* objeto = casilla->obtener_objetos()[0];


        int vida_otro_vampiro = ((Ser*)objeto)->devolver_vida();
        int vida_nosferatu = personaje->devolver_vida();
        int aux = vida_nosferatu;
        personaje->asignar_vida(vida_otro_vampiro);
        ((Ser *) casilla->obtener_objetos()[0])->asignar_vida(aux);
    }
}



/*bool Defensa_nosferatu::validar_vampiro_cercano(Tablero* tablero){

    Lista<Coordenada> lista_coordenadas = obtener_cuadrado(personaje -> obtener_casilla()->obtener_posicion(), 2);
    Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);
    Lista<Casilla *> lista_casillas_con_personaje = obtener_casilla_con_personaje(lista_casillas, NOMBRES_STRING[HUMANO]);
    Casilla* casilla_objeto = obtener_casilla_con_personaje(lista_casillas, MONSTRUO)[0];

    int indice_vampiro = indice_personaje(NOMBRES_CHAR[VAMPIRO], casilla_objeto);

    if(indice_vampiro != NO_ENCONTRADO)
        return true;
}*/




