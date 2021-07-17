#include "Archivo_tablero.h"

Archivo_tablero::Archivo_tablero(const string nombre_fichero):Archivo(nombre_fichero){
    if(contenido.length()>0){

        extraer_dimensiones();
        
        tablero = new Tablero(fila,columna);
    }
}

void Archivo_tablero::extraer_dimensiones(){

    string primera_linea = dividir_texto(contenido,'\n')[0];
    Lista<string> dimensiones = dividir_texto(primera_linea,' ');
    
    fila = convertir_entero(dimensiones[0]);
    columna = convertir_entero(dimensiones[1]);
    
    if(fila<0 || columna<0 )
        fila = columna = 0;
}


Tablero* Archivo_tablero::obtener_datos_de_terreno(){
    
    Tablero* mapa = nullptr;    

    Lista<Casilla*>* casillas;

    if(contenido != ""){
        
        casillas = separar_terrenos(contenido);

        mapa->asignar_casillas(casillas);

    }

    delete casillas;

    return mapa;            
}

Lista<Casilla*>* Archivo_tablero::separar_terrenos(string texto){
    Lista<Casilla*>* terrenos;
    Casilla* terreno = nullptr;
    int i = 0, j;
    int tipo_terreno;

    terrenos = new Lista<Casilla*>;

    while(texto[i] != '\n') i++;

    for(int k = 0; k < fila; k++){
        i++;
        j = 0;
        while(texto[i] != '\n' && texto[i] != '\0'){
            
            Coordenada posicion(k, j);
            tipo_terreno = obtener_tipo_terreno(texto[i]);
        
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
            
            if(tipo_terreno != NO_ENCONTRADO){
                j++;
                terrenos->agregar(terreno);
            }
            i++;
        }
    }
    delete terreno;

    return terrenos;
} 

int Archivo_tablero::obtener_tipo_terreno(const char terreno){
    
    int indice = buscar_dato(TIPO_MAPA_CHAR ,MAX_TIPOS_MAPA ,terreno );

    return indice != NO_ENCONTRADO ? TIPO_MAPA_CHAR[indice] : NO_ENCONTRADO;
}