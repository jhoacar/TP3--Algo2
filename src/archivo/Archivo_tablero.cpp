#include "Archivo_tablero.h"

Lista<string>* Archivo_tablero::obtener_datos_de_mapa(){
    Lista<string>* mapa_ptr = nullptr;
    fstream archivo( "tablero.txt" , fstream::in );

	if(!archivo){
	
		cout << "No se pudo abrir el fichero tablero.txt" << endl;

	}else{
        mapa_ptr = new Lista<string>;
        string linea;
        archivo >> linea;
        while(!archivo.eof()){
            archivo >> linea;
            mapa_ptr->agregar(linea);
        }
    }

    return mapa_ptr;            
}