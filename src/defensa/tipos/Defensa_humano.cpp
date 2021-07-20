#include "Defensa_humano.h"
#include "../../objetos/elementos/Agua.h"
/*
bool tiene_agua_bendita(Humano *personaje){
    Objeto *objeto_referencia = new Agua();
    objeto_referencia->asignar_nombre(NOMBRES_CHAR[AGUA]); //Le asigno el nombre que quiera buscar en la lista
    return personaje->obtener_inventario().existe(objeto_referencia,comparacion_por_nombre);
}

Defensa_humano::Defensa_humano(Humano *personaje):Defensa(personaje){
    
    personaje->armadura_aumentada=false;

}

void Humano::defenderse(){
    
    if (!tengo_agua_bendita()){
        aumentar_energia();
        cout <<endl<< "|||| No tengo agua bendita, pero aumenté mi energía ||||" << endl;
    }
    else {
        int accion = elegir_accion();
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

bool Humano::tengo_agua_bendita() {

    objeto_referencia->asignar_nombre(NOMBRES_CHAR[AGUA]); //Le asigno el nombre que quiera buscar en la lista
    return inventario.existe(objeto_referencia,comparacion_por_nombre);
}

void Humano::aumentar_energia() {
    energia +=3;
}

void Humano::aumentar_armadura() {
    armadura++;
    armadura_aumentada = true;
}

void Humano::consumir_agua_bendita() {
    energia = ENERGIA_MAXIMA;
    inventario.borrar(buscar_agua_bendita());
}

int Humano::buscar_agua_bendita() {

    objeto_referencia->asignar_nombre(NOMBRES_CHAR[AGUA]);
    return inventario.buscar_dato(0,objeto_referencia,comparacion_por_nombre);
}

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

void Defensa_humano::defender(){

    
    
}
*/
