#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>
#include <windows.h>

void imprimir_coordenada(Coordenada c){
    cout<<"("<<c.obtener_fila()<<","<<c.obtener_columna()<<")";
}

void imprimir_casilla(Casilla *casilla){
    if(casilla!=nullptr)
        imprimir_coordenada(casilla->obtener_posicion());
}

int main(){

    limpiar_pantalla();
    
    Casilla *lago = new Lago({0,0});
    Casilla *camino = new Camino({0,1});
    Casilla *volcan = new Volcan({1,0});
    Casilla *montana = new Montana({1,1});
    Casilla *lago_1 = new Lago({0,2});
    Casilla *camino_1 = new Camino({2,0});
    Casilla *volcan_1 = new Volcan({2,2});
    Casilla *montana_1 = new Montana({2,1});
    Casilla *montana_2 = new Montana({1,2});
    

    Tablero *tablero = new Tablero(3,3);

    tablero->asignar_casilla(lago);
    tablero->asignar_casilla(camino);
    tablero->asignar_casilla(volcan);
    tablero->asignar_casilla(montana);
    tablero->asignar_casilla(lago_1);
    tablero->asignar_casilla(camino_1);
    tablero->asignar_casilla(volcan_1);
    tablero->asignar_casilla(montana_1);
    tablero->asignar_casilla(montana_2);


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

    
    //humano_prueba->defender(tablero);
        

    Lista<Casilla*> camino_minimo = tablero->obtener_camino_minimo({0,0},{2,2},TIPO_HUMANO);

    Coordenada incremento = {1,1};

    gotoxy(humano_prueba->obtener_posicion()+incremento);
    cout<<humano_prueba->obtener_nombre();

    Casilla *anterior = lago;
    
    cursor(false);

    while(camino_minimo.existe_siguiente()){

        demorar(1);
        
        gotoxy(humano_prueba->obtener_posicion()+incremento);
        color(anterior->obtener_color());
        cout<<" ";
        color(RESET);


        anterior->eliminar_objeto(humano_prueba->obtener_nombre()); 
        Casilla *casilla_nueva = camino_minimo.siguiente_dato();
        humano_prueba->asignar_casilla( casilla_nueva );
        humano_prueba->encuentro_con_elemento();
        casilla_nueva->agregar_objeto(humano_prueba);

        gotoxy(humano_prueba->obtener_posicion()+incremento);
        cout<<humano_prueba->obtener_nombre();

        anterior = casilla_nueva; 
        
    }

    cursor(true);

    delete tablero;

    pausa();
    
    return 0;
}
