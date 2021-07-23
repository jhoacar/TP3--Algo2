#include "Archivo_tablero.h"

Archivo_tablero::Archivo_tablero(const string nombre_fichero):Archivo(nombre_fichero){
    
    if(contenido.length()>0){

        extraer_dimensiones();
        tablero = new Tablero(fila,columna);
        if(fila > 0 && columna > 0)
            cargar_tablero();
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

void Archivo_tablero::cargar_tablero(){
    
    Lista<Casilla*> casillas;

    if(contenido != ""){
        
        casillas = separar_terrenos(contenido);

        tablero->asignar_casillas(casillas);
    }
}

Tablero* Archivo_tablero::obtener_tablero(){
    return tablero;    
}

Lista<Casilla*> Archivo_tablero::separar_terrenos(string texto){
    
    Lista<Casilla*> terrenos;
    Casilla* terreno = nullptr;

    Lista<string> datos_filas = dividir_texto(texto,'\n');
    
    datos_filas.borrar(0); //Se elimina la primera linea que seria la de las dimensiones 

    for(int i = 0; i< datos_filas.obtener_tamano() ; i++){ //Recorremos una matriz comunmente

        Lista<string> datos_columna = dividir_texto(datos_filas[i],',');        
        
        for(int j = 0; j < datos_columna.obtener_tamano() ; j++ ){

            Coordenada posicion(i, j);
            int tipo_terreno = obtener_tipo_terreno(datos_columna[j][0]);

            switch(tipo_terreno){
                case MONTANA:   terreno = new Montana(posicion);
                    break;
                case PRECIPICIO:terreno = new Precipicio(posicion);
                    break;
                case LAGO:      terreno = new Lago(posicion);
                    break;
                case VOLCAN:    terreno = new Volcan(posicion);
                    break;
                case CAMINO:    terreno = new Camino(posicion);
                    break;
                case VACIO:     terreno = new Vacio(posicion);
                    break;
            }
            if(tipo_terreno != NO_ENCONTRADO)
                terrenos.agregar(terreno);
        }
    }
    return terrenos;
} 

int Archivo_tablero::obtener_tipo_terreno(const char terreno){
    
    return buscar_dato(TIPO_MAPA_CHAR , MAX_TIPOS_MAPA ,terreno );
}