
#include "Archivo_partida.h"

void Archivo_partida::guardar_partida(Lista<string>* datos_juego){
    
    std::ofstream archivo;
    archivo.open( RUTA_GUARDADO_PARTIDA, std::ios::out );
    
    if(archivo.fail()){
        std::cout << "No se pudo guardar partida";
        exit(1);
    }
    else{
        int i = 0;
        int tam = datos_juego->obtener_tamano();
        while(i < tam){
        archivo << datos_juego->operator[](i);  
        i++;
        }
    }   
    archivo.close();
}

Lista<string>* Archivo_partida::obtener_datos_de_partida(){
    Lista<string>* datos_ptr = nullptr;
    fstream archivo( FICHERO_PARTIDA , fstream::in );

	if(!archivo){
	
		std::cout << "No se encontro una partida guardada." << endl;

	}else{
        datos_ptr = new Lista<string>;
        string linea;
        while(!archivo.eof()){
            archivo >> linea;
            datos_ptr->agregar(linea);
        }
    }

    return datos_ptr;            
}
