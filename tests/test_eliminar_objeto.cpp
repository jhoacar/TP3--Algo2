#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>

int main(){
    
    Casilla *lago = new Lago({0,0});
    Casilla *camino = new Camino({0,1});
    Casilla *volcan = new Volcan({1,0});
    Casilla *montana = new Montana({1,1});

    Tablero *tablero = new Tablero(2,2);

    tablero->asignar_casilla(lago);
    tablero->asignar_casilla(camino);
    tablero->asignar_casilla(volcan);
    tablero->asignar_casilla(montana);

    tablero->mostrar_tablero();

    Lista<Objeto*> objetos;

    objetos.agregar( new Agua(lago,'a',23,"123"));
    objetos.agregar( new Bala(lago,'b',10,"124"));
    objetos.agregar( new Escopeta(lago,'e',1,"125"));
    objetos.agregar( new Estaca(lago,'E',23,"126"));
    objetos.agregar( new Cruz(lago,'c',5,"127"));
    objetos.agregar( new Agua(lago,'a',10,"128"));
    objetos.agregar( new Bala(lago,'b',3,"129"));
    objetos.agregar( new Estaca(lago,'E',2,"122"));

    Vanessa* humano_prueba = new Vanessa(lago, 'h', "312");
    Zombie* zombi_prueba = new Zombie(camino, 'z', "321");
    Nosferatu* vampiro_prueba = new Nosferatu(volcan, 'v', "654");
    

    lago->agregar_objetos(objetos);

    lago->agregar_objeto(humano_prueba);
    
    camino->agregar_objeto(zombi_prueba);
    volcan->agregar_objeto(vampiro_prueba);

    humano_prueba->encuentro_con_elemento();
    zombi_prueba ->encuentro_con_elemento();
    vampiro_prueba ->encuentro_con_elemento();

    
    humano_prueba->defender(tablero);
        

    delete tablero;

    pausa();
    
    return 0;
}
