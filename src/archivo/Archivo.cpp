#include "Archivo.h"

Archivo::Archivo():contenido(){
}

Archivo::Archivo(const string nombre_fichero){

    contenido = obtener_texto(nombre_fichero);

}

string Archivo::obtener_texto(const string nombre_fichero){

	fstream archivo( nombre_fichero.c_str() , fstream::in );

	if(!archivo){
	
		std::cout << "No se pudo abrir el fichero " << nombre_fichero << endl;
	
		return "";
	
	}
  	
	string datos_texto;
    
    getline(archivo, datos_texto, '\0');
  	
	archivo.close();

  	return datos_texto;
}

bool Archivo::mostrar_contenido(){

    bool mostrado = false;

    if(contenido.length()>0){

        contenido.replace(contenido.find("\\"),1,"\\\\");

        std::cout << contenido;
        
        mostrado = true;
    }

    return mostrado;
}