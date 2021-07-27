#include "../src/archivo/Archivo_tablero.h"
#include "../src/archivo/Archivo_objetos.h"
#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>
#include <ctime>

void imprimir_coordenada(Coordenada coord){
    cout<<"("<<coord.obtener_fila()<<","<<coord.obtener_columna()<<")\t";
}
void imprimir_objeto(Objeto *objeto){
    if(objeto!=nullptr){
        cout<<" " <<convertir_nombre(objeto->obtener_nombre())<<" ";
        imprimir_coordenada(objeto->obtener_posicion());
        cout<<objeto->obtener_ID();
    }
    cout<<endl;
}


int main(){
    
    srand(time(0));

    Archivo_tablero datos_tablero(FICHERO_TABLERO);
    Archivo_objetos datos_objeto(FICHERO_OBJETOS,datos_tablero.obtener_tablero());

    Tablero *tablero = datos_tablero.obtener_tablero();

    tablero->mostrar_tablero();

    //datos_objeto.obtener_lista_objetos().imprimir(imprimir_objeto);

    Ser *atacante =(Ser*)(tablero->obtener_objeto({1,0},NOMBRES_CHAR[HUMANO]));

    atacante->asignar_energia(30);
    atacante->asignar_fuerza(10);
    atacante->obtener_inventario().agregar(new Escopeta(nullptr,NOMBRES_CHAR[ESCOPETA],1,"234"));
    atacante->obtener_inventario().agregar(new Bala(nullptr,NOMBRES_CHAR[BALA],3,"023"));
    atacante->encuentro_con_elemento();

    if(atacante==nullptr)
        return 1;

    Zombie *zombie = (Zombie*)tablero->obtener_casilla({0,0})->obtener_objeto(NOMBRES_CHAR[ZOMBIE]);
    zombie->asignar_vida(20);

    cout<<atacante->se_puede_atacar({0,0},tablero)<<endl;
    cout<<"Vida antes del ataque: "<<zombie->obtener_vida()<<endl;
    atacante->atacar({0,0},tablero);
    cout<<"Vida luego del ataque: "<<zombie->obtener_vida()<<" con armadura "<<zombie->obtener_armadura();
    
    
    pausa();

    return 0;
}
