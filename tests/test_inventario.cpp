#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>

int main(){
    Coordenada posicion(3, 5);
    Casilla *lago = new Lago(posicion);
    Objeto* humano_prueba = new Humano(lago, 'h', "312");
    ((Ser *)humano_prueba)->encuentro_con_elemento();
    Objeto* zombi_prueba = new Zombie(lago, 'z', "321");
    ((Monstruo*)zombi_prueba) ->encuentro_con_elemento();
    Objeto* vampiro_prueba = new Vampiro(lago, 'v', "654");
    ((Monstruo*)vampiro_prueba) -> encuentro_con_elemento();
    return 0;
}
