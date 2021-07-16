#include "Archivo_tablero.h"

Lista<Casilla*>* Archivo_tablero::obtener_datos_de_terreno(){
    
    Lista<Casilla*>* terrenos = nullptr;

    datos_tablero = obtener_texto(FICHERO_TABLERO);    

    if(datos_tablero != ""){
        terrenos = new Lista<Casilla*>;
        Casilla* casilla;
        for(int i = 0; i < fila; i++){
            for(int j = 0; j < columna; j++){
                Coordenada pos(i, j);
                casilla = separar_terrenos(datos_tablero, pos);
                terrenos->agregar(casilla);
            }
        }
    }

    return terrenos;            
}

Casilla* Archivo_tablero::separar_terrenos(string texto, Coordenada &posicion){
    Casilla* terreno = nullptr;
    int i = 0;
    int tipo_terreno;
    while(texto[i] != '\0'){
        tipo_terreno = obtener_tipo_terreno(texto[i]);
        if(tipo_terreno != -1){
            switch(tipo_terreno){
                case MONTANA: terreno = new Montana(posicion);
                    break;
                case PRECIPICIO: terreno = new Precipicio(posicion);
                    break;
                case LAGO: terreno = new Lago(posicion);
                    break;
                case VOLCAN: terreno = new Volcan(posicion);
                    break;
                case CAMINO: terreno = new Camino(posicion);
                    break;
                case VACIO: terreno = new Vacio(posicion);
                    break;
            }
        }
        i++;
    }
    return terreno;
} 

int Archivo_tablero::obtener_tipo_terreno(char c){
    int tipo = -1;

    if(c != ',' && c != '\n' && c != '\0'){
        for(int i = 0; i < MAX_TIPOS_MAPA; i++){
            if(c == TIPO_MAPA_CHAR[i]){
                tipo = i;
                i = MAX_TIPOS_MAPA;
            }
        }
    }

    return tipo;
}