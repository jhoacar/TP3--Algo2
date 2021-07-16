#include "../src/funcionalidades/Funciones.h"

const char ARRIBA    = 72;//'W';
const char ABAJO     = 80;//'S';
const char DERECHA   = 77;//'D';
const char IZQUIERDA = 75;//'A';

void mover_arriba(Coordenada &posicion){
    posicion={posicion.obtener_fila()-3,posicion.obtener_columna()};
}
void mover_abajo(Coordenada &posicion){
    posicion={posicion.obtener_fila()+3,posicion.obtener_columna()};
}
void mover_izquierda(Coordenada &posicion){
    posicion={posicion.obtener_fila(),posicion.obtener_columna()-3};
}
void mover_derecha(Coordenada &posicion){
    posicion={posicion.obtener_fila(),posicion.obtener_columna()+3};
}



int main(){

    char tecla=0;
    Coordenada posicion={10,10};
    limpiar_pantalla();

    while(tecla!=' '){

        gotoxy(posicion);
        //cout<<"*";
        tecla = caracter_mayuscula((char)tecla_pulsada());
        
        switch(tecla){
            case ARRIBA:
                mover_arriba(posicion);
                break;
            case ABAJO:
                mover_abajo(posicion);
                break;
            case IZQUIERDA:
                mover_izquierda(posicion);
                break;
            case DERECHA:
                mover_derecha(posicion);
                break;
        }
    }

    return 0;
}