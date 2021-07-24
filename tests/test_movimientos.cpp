#include "../src/funcionalidades/Funciones.h"

#ifdef __linux__
const char ARRIBA    = 65;//'W';
const char ABAJO     = 66;//'S';
const char DERECHA   = 67;//'D';
const char IZQUIERDA = 68;//'A';
#endif

#ifdef __MINGW32__
const char ARRIBA    = 72;//'W';
const char ABAJO     = 80;//'S';
const char DERECHA   = 77;//'D';
const char IZQUIERDA = 75;//'A';
#endif

void mover_arriba(Coordenada &posicion){
    posicion={(posicion.obtener_fila()-1),posicion.obtener_columna()};
}
void mover_abajo(Coordenada &posicion){
    posicion={(posicion.obtener_fila()+1),posicion.obtener_columna()};
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

int main(){

    char tecla=0;
    Coordenada posicion={3,10};
    limpiar_pantalla();

    imprimir_menu();

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

    return 0;
}
