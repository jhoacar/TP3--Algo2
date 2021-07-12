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

//si se guarda los datos de partida en una lista.
void Gestion_archivo::guardar_partida(Lista<string>* datos_juego){
    
    ofstream archivo;
    archivo.open( "d://TP3--Algo2//partida.txt", ios::out );
    if(archivo.fail()){
        cout << "no se pudo guardar partida";
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


Lista<string>* Gestion_archivo::obtener_datos_de_partida(){
    Lista<string>* datos_ptr = nullptr;
    fstream archivo( "partida.txt" , fstream::in );

	if(!archivo){
	
		cout << "No se encontro una partida guardada." << endl;

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
