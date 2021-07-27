#include "../src/funcionalidades/Funciones.h"

#ifdef __linux__
const char ARRIBA    = 65;//'W';
const char ABAJO     = 66;//'S';
const char DERECHA   = 67;//'D';
const char IZQUIERDA = 68;//'A';
const int CANT_OPCIONES = 3;
const int POS_OPCION_1 = 3;
const int POS_OPCION_2 = 4;
const int POS_OPCION_3 = 5;
#endif

#ifdef __MINGW32__
const char ARRIBA    = 72;//'W';
const char ABAJO     = 80;//'S';
const char DERECHA   = 77;//'D';
const char IZQUIERDA = 75;//'A';
const int CANT_OPCIONES = 3;
const int POS_OPCION_1 = 3;
const int POS_OPCION_2 = 4;
const int POS_OPCION_3 = 5;
#endif

void mover_arriba(Coordenada &posicion){
    if (posicion.obtener_fila() != POS_OPCION_1)
        posicion={(posicion.obtener_fila()-1),posicion.obtener_columna()};
    else
        posicion={POS_OPCION_3, posicion.obtener_columna()};
}
void mover_abajo(Coordenada &posicion){
    if (posicion.obtener_fila() != POS_OPCION_3)
        posicion={(posicion.obtener_fila()+1),posicion.obtener_columna()};
    else
        posicion={POS_OPCION_1, posicion.obtener_columna()};
}
void mover_izquierda(Coordenada &posicion){
    posicion={posicion.obtener_fila(),posicion.obtener_columna()-1};
}
void mover_derecha(Coordenada &posicion){
    posicion={posicion.obtener_fila(),posicion.obtener_columna()+1};
}


void imprimir_menu(){
    cout<<"Menu: "<<endl<<endl;
    cout<<"Opcion: 1"<<endl;
    cout<<"Opcion: 2"<<endl;
    cout<<"Opcion: 3"<<endl;
}

Coordenada elegir_opcion(){
    char tecla=0;
    Coordenada posicion={3,10};
    while(tecla!=' '){

        gotoxy(posicion);
        cout<<"*";
        tecla = caracter_mayuscula((char)tecla_pulsada());
        //cout<<"TECLA: "<<tecla<<" NUMERO: "<<(int)tecla<<endl;
        switch(tecla){
            case ARRIBA:
                gotoxy(posicion);
                cout<<" ";
                mover_arriba(posicion);
                break;
            case ABAJO:
                gotoxy(posicion);
                cout<<" ";
                mover_abajo(posicion);
                break;
        }
    }
    return posicion;
}

int main(){
    Coordenada eleccion;

    limpiar_pantalla();

    imprimir_menu();
    eleccion = elegir_opcion();
    switch(eleccion.obtener_fila()){
        case POS_OPCION_1:
            gotoxy(0, 7);
            cout << "Ha elegido la opcion 1" << endl;
            break;
        case POS_OPCION_2:
            gotoxy(0, 7);
            cout << "Ha elegido la opcion 2" << endl;
            break;
        case POS_OPCION_3:
            gotoxy(0, 7);
            cout << "Ha elegido la opcion 3" << endl;
            break;
    }

    return 0;
}
