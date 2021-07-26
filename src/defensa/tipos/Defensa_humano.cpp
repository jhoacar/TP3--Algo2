#include "Defensa_humano.h"
#include "../../objetos/elementos/Agua.h"

bool tiene_agua_bendita(Humano *personaje){
    Objeto *objeto_referencia = new Agua();
    objeto_referencia->asignar_nombre(NOMBRES_CHAR[AGUA]); //Le asigno el nombre que quiera buscar en la lista
    return personaje->obtener_inventario().existe(objeto_referencia,comparacion_por_nombre);
}

Defensa_humano::Defensa_humano(Humano *personaje):Defensa(personaje){
}

void Defensa_humano::defender(int accion){

    if (!tengo_objeto(NOMBRES_CHAR[AGUA])){
        aumentar_energia();
        cout << "|||| No tengo agua bendita, pero aumenté mi energía ||||" << endl;
    }
    else {
        if (accion == REGENERAR_ENERGIA){
            consumir_agua_bendita();
            cout << "|||| Regeneré mi energía ||||" << endl;
        }
        else{
            aumentar_armadura();
            cout << "|||| Mejoré mi armadura ||||" << endl;
        }
    }
}

bool Defensa_humano::tengo_objeto(char arma){

    Objeto *objeto_referencia = new Agua();
    objeto_referencia -> asignar_nombre(arma);
    bool esta_en_inventario = personaje -> obtener_inventario().existe(objeto_referencia,comparacion_por_nombre);

    return esta_en_inventario;

}

void Defensa_humano::aumentar_energia() {
    ((Humano*) personaje) -> regenerar_energia_defensa();
}

void Defensa_humano::aumentar_armadura() {
    personaje ->aumentar_armadura();
    //armadura_aumentada = true;
}

void Defensa_humano::consumir_agua_bendita() {
    ((Humano*) personaje) -> regeneracion_maxima_energia(ENERGIA_MAXIMA);
    personaje -> obtener_inventario().borrar(buscar_objeto(NOMBRES_CHAR[AGUA]));
}

int Defensa_humano::buscar_objeto(char arma) {

    Objeto *objeto_referencia = new Agua();
    objeto_referencia -> asignar_nombre(arma);
    return personaje->obtener_inventario().buscar_dato(0,objeto_referencia,comparacion_por_nombre);
}

void Defensa_humano::consumir_objeto(char arma) {
    personaje -> obtener_inventario().borrar(buscar_objeto(arma));
}


/*
int Humano::elegir_accion() {
    int opcion;
    cout << "Tengo agua bendita en mi inventario." << endl;
    cout << "¿Qué debo hacer?" << endl;
    cout << "(1) Regenerar toda mi energía." << endl;
    cout << "(2) Aumentar mi armadura." << endl;
    cin >> opcion;
    while (opcion != REGENERAR_ENERGIA  && opcion != AUMENTAR_ARMADURA ){
        cout << "No lo entiendo. ¿Qué debo hacer?" << endl;
        cin >> opcion;
    }
    return opcion;
}
*/

