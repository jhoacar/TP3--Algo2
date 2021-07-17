#include "Humano.h"
#include <iostream>
using std::cout;
using std::endl;

Humano::Humano():Ser(){
	this->armadura_aumentada = false;
}

Humano::Humano(Casilla *casilla,char nombre,string ID):Ser(casilla,nombre,ID)
{
	this->armadura_aumentada = false;
}

void Humano::mostrar(){
    cout<<"Objeto: Humano "<<endl;
}

Humano::~Humano()
{
}

void Humano::regenerar_energia() {
    this -> energia += 5;
}

void Humano::encuentro_con_elemento() {
    
    Lista<Objeto*> objetos_casilla;
    Lista<Objeto*> solo_elementos;

    objetos_casilla = casilla->obtener_objetos();
    solo_elementos = objetos_casilla.filtrar_datos(0,es_elemento);

    inventario += solo_elementos;
    
    if(solo_elementos.obtener_tamano()>0)
        cout << "Se agregaron con exito los elementos al inventario" << endl;

    casilla->eliminar_objetos(solo_elementos);

}

void Humano::defenderse() {
    
    if (!tengo_agua_bendita()){
        aumentar_energia();
        cout << "|||| No tengo agua bendita, pero aumenté mi energía ||||" << endl;
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

    Lista<Objeto*> objetos_casilla;
    Lista<Objeto*> solo_elementos;

    objetos_casilla = this -> casilla ->obtener_objetos();
    solo_elementos = objetos_casilla.filtrar_datos(0, es_elemento);

    this ->inventario += solo_elementos;
    cout << "Se agregaron con exito los elementos al inventario" << endl;

    for (int i = 0; i < solo_elementos . obtener_tamano(); i++)
        this ->casilla -> eliminar_objeto(solo_elementos[i]->obtener_ID());
}



bool Humano::tiene_arma(string arma_elegida){

    objeto_referencia -> asignar_nombre(NOMBRES_CHAR[arma_elegida]); //Le asigno el nombre que quiera buscar en la lista
    return inventario.existe(objeto_referencia,comparacion_por_nombre);

}

bool Humano::tiene_balas(int cantidad_minima_balas){

    objeto_referencia -> asignar_nombre(NOMBRES_STRING[BALA]); //Le asigno el nombre que quiera buscar en la lista
    bool esta_en_inventario = inventario.existe(objeto_referencia,comparacion_por_nombre);


    if(esta_en_inventario){
        if(inventario[indice] -> obtener_cantidad() >= cantidad_minima_balas)
            balas_necesarias = true;
    }
    return balas_necesarias;
}

void Humano::bajar_cantidad_objeto(int cantidad_gastada, string arma){

    objeto_referencia -> asignar_nombre(NOMBRES_STRING[arma]); //Le asigno el nombre que quiera buscar en la lista
    int posicion_balas = inventario.buscar_dato(objeto_referencia,comparacion_por_nombre);

    if(posicion_balas != -1){
        inventario[indice] -> disminuir_cantidad();
    }
}



void Humano::validacion_ataque(Ataque* ataque, int posicion_x_elegida, int posicion_y_elegida, string arma_elegida){

    validacion_rango = ataque -> validacion_rango_ataque(posicion_x_elegida, posicion_y_elegida, 1);

    bool energia_suficiente = ataque -> energia_suficiente(5, energia);
    bool tiene_arma = tiene_arma(arma_elegida);
    bool tiene_suficientes_balas = tiene_balas(2);

    if(validacion_rango && energia_suficiente && arma && tiene_suficientes_balas)
        ataque -> validacion_ataque = true;
    else
        ataque -> validacion_ataque = false;

}



int Humano::indice_personaje(string personaje, Lista<Objeto*> lista_objetos){

    objeto_referencia -> asignar_nombre(personaje);
    int indice = lista_objetos.buscar_dato(0, objeto_referencia, comparacion_por_nombre);
    return indice;

}

void Humano::atacar(Tablero* tablero, int posicion_x_elegida, int posicion_y_elegida, string arma_elegida) {

    int posicion_x = casilla -> posicion.obtener_x();
    int posicion_y = casilla -> posicion.obtener_y();

    bool validacion_rango;

    Ataque* ataque = new Ataque_humano(tablero, posicion_x, posicion_y, this -> energia);

    validacion_ataque(ataque, posicion_x_elegida, posicion_y_elegida, arma_elegida);

    if(ataque -> validacion_ataque){

        Coordenada posicion(posicion_x_elegida, posicion_y_elegida);
        Casilla* casilla = tablero -> obtener_casilla(posicion);
        Lista<Objeto*> lista_objetos = casilla.obtener_objetos();

        consumir_energia(5);
        bajar_cantidad_objeto(2, NOMBRES_STRING[BALA]);

        ataque -> bajar_vida(lista_objetos, casilla);
    }
    delete ataque;
}