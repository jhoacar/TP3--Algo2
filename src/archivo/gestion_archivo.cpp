#include "gestion_archivo.h"

string Gestion_archivo::obtener_texto(const string nombre_fichero){

	fstream archivo( nombre_fichero.c_str() , fstream::in );

	if(!archivo){
	
		cout << "No se pudo abrir el fichero " << nombre_fichero << endl;
	
		return "";
	
	}
  	
	string datos_texto;
  	
	getline(archivo, datos_texto, '\0');
  	
	archivo.close();

  	return datos_texto;
}

bool Gestion_archivo::mostrar_fichero(string name){

bool mostrado = false;

string fichero = "src/interfaz/"+name+".txt";

    string mostrar = obtener_texto(fichero);
    
    if(mostrar.length()>0){

        mostrar.replace(mostrar.find("\\"),1,"\\\\");

        cout << mostrar;
		
        mostrado = true;
    }

    return mostrado;
}

void Gestion_archivo::guardar_partida(Lista<string>* lista){
    
    ofstream archivo;
    archivo.open( "d://TP3--Algo2//partida.txt", ios::out );
    if(archivo.fail()){
        cout << "no se pudo guardar partida";
        exit(1);
    }
    else{
        int i = 0;
        int tam = lista->obtener_tamano();
        while(i < tam){
        archivo << lista->operator[](i);  
        i++;
        }
    }   
    archivo.close();
}

