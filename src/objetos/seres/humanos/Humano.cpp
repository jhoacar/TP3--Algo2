#include "Humano.h"
#include "../../../defensa/humanos/Defensa_humano.h"
#include "../../../ataque/humanos/Ataque_Humano.h"
#include "../../../ataque/monstruos/vampiros/Ataque_vampiro.h"
#include "../../../ataque/monstruos/zombies/Ataque_zombie.h"
#include <iostream>
using namespace std;

Humano::Humano():Ser(){
	this->cantidad_agua=0;
    this->cantidad_balas=0;
    this->cantidad_cruces=0;
    this->cantidad_estacas=0;
    this->tiene_escopeta=false;
}

Humano::Humano(Casilla *casilla,char nombre,string ID):Ser(casilla,nombre,ID)
{
    this->cantidad_agua=0;
    this->cantidad_balas=0;
    this->cantidad_cruces=0;
    this->cantidad_estacas=0;
    this->tiene_escopeta=false;
}

void Humano::mostrar(){
    cout<<"Objeto: Humano "<<endl;
}

Humano::~Humano()
{

}
void Humano::regenerar_energia() {
    this -> energia += REGENERAR_ENERGIA[HUMANO];
}

void Humano::encuentro_con_elemento() {
    
    Lista<Objeto*> solo_elementos = casilla->obtener_objetos().filtrar_datos(0,es_elemento);
    inventario += solo_elementos;
    actualizar_inventario();
    casilla->eliminar_objetos(solo_elementos);
}

void Humano::actualizar_inventario(){
    extraer_agua();
    extraer_balas();
    extraer_escopeta();
    extraer_cruces();
    extraer_estacas();
}

void Humano::defender(Tablero *tablero,int opcion){
    if(defensa==nullptr)
        defensa = new Defensa_humano(this);
    defensa->defender(tablero,opcion);
}

void Humano::atacar(Coordenada posicion, Tablero *tablero, char arma){
    if(se_puede_atacar(posicion,tablero))
        ataque->atacar(posicion,tablero);
}


bool Humano::se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma){

    if(ataque==nullptr)
        ataque = new Ataque_humano(this);
    return ataque->se_puede_atacar(posicion,tablero);
}

bool Humano::tiene_agua_bendita(){
    return cantidad_agua>0;
}
bool Humano::tiene_cruz(){
    return cantidad_cruces>0;
}

void Humano::extraer_escopeta(){
    tiene_escopeta = inventario.filtrar_datos(0,es_escopeta).obtener_tamano()!=0;
}

void Humano::extraer_balas(){
    cantidad_balas = 0;
    if(tiene_escopeta){       
        Lista<Objeto*> balas = inventario.filtrar_datos(0,es_bala);
        Lista<int> balas_totales = balas.mapear_datos<int>(0,extraer_cantidad);
        while(balas_totales.existe_siguiente())
            cantidad_balas+=balas_totales.siguiente_dato();
    }
}

void Humano::extraer_estacas(){
    cantidad_estacas = 0;
    Lista<Objeto*> estacas = inventario.filtrar_datos(0,es_estaca);
    Lista<int> estacas_totales = estacas.mapear_datos<int>(0,extraer_cantidad);
    while(estacas_totales.existe_siguiente())
            cantidad_balas+=estacas_totales.siguiente_dato();
}
void Humano::extraer_agua(){
    cantidad_agua = 0;
    Lista<Objeto*> agua = inventario.filtrar_datos(0,es_estaca);
    Lista<int> agua_total = agua.mapear_datos<int>(0,extraer_cantidad);
    while(agua_total.existe_siguiente())
            cantidad_agua+=agua_total.siguiente_dato();
}
void Humano::extraer_cruces(){
    cantidad_cruces = 0;
    Lista<Objeto*> cruces = inventario.filtrar_datos(0,es_cruz);
    Lista<int> cruces_totales = cruces.mapear_datos<int>(0,extraer_cantidad);
    while(cruces_totales.existe_siguiente())
            cantidad_cruces+=cruces_totales.siguiente_dato();
}
