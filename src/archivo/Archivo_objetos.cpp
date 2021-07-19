#include "Archivo_objetos.h"

Archivo_objetos::Archivo_objetos(const string nombre_fichero):Archivo(nombre_fichero){

    mapa_objetos = nullptr;
    if(contenido.length()>0){
        extraer_dimensiones();
    }

}

void Archivo_objetos::extraer_dimensiones(){

    string primera_linea = dividir_texto(contenido,'\n')[0];
    Lista<string> dimensiones = dividir_texto(primera_linea,' ');
    
    fila = convertir_entero(dimensiones[0]);
    columna = convertir_entero(dimensiones[1]);
    
    if(fila<0 || columna<0 )
        fila = columna = 0;
}

void Archivo_objetos::cargar_mapa_objetos(Tablero* tablero){
    if((fila > 0 && columna > 0) && tablero){
        if(contenido != ""){
        
            mapa_objetos = tablero;

            Lista<string> datos = dividir_texto(contenido,'\n');
	
	        cargar_objetos(datos);

            cout << endl << "hasta aca sin errores" << endl;

            mapa_objetos->cargar_lista_objetos(objetos);
        }    
    }
}

void Archivo_objetos::cargar_objetos(Lista<string> &lineas){
	
	for(int i = 1; i < (int)lineas.obtener_tamano(); i++){

		Lista<string> division_datos = dividir_texto(lineas[i],' ');

		Coordenada posicion_objeto = convertir_posicion(lineas[i]);

        string ID = convertir_id(division_datos);

		string nombre_objeto	= convertir_nombre(division_datos);

		int	cantidad_objeto = convertir_cantidad(division_datos);

		int tipo_objeto = 	buscar_dato(NOMBRES_STRING,MAX_NOMBRES,nombre_objeto);
		
		Objeto *objeto = crear_objeto(tipo_objeto,NOMBRES_CHAR[tipo_objeto],posicion_objeto,cantidad_objeto,ID);

		this->objetos.agregar(objeto);

    }
}


Objeto* Archivo_objetos::crear_objeto(const int tipo_objeto,const char nombre,Coordenada posicion, int cantidad, string ID){

	Objeto* objeto = nullptr;

    Casilla* casilla = nullptr;
    casilla = mapa_objetos->obtener_casilla(posicion);

	switch(tipo_objeto) {
		case AGUA: 			objeto = new Agua(casilla,nombre,cantidad,ID); break;

		case BALA: 			objeto = new Bala(casilla,nombre,cantidad,ID); break;

		case CRUZ: 			objeto = new Cruz(casilla,nombre,cantidad,ID); break;

		case ESTACA: 		objeto = new Estaca(casilla,nombre,cantidad, ID); break;

		case ESCOPETA: 		objeto = new Escopeta(casilla,nombre,cantidad, ID); break;

		case HUMANO: 		objeto = new Humano(casilla,nombre,ID); break;

		case HUMANO_CAZADOR:objeto = new Cazador(casilla,nombre,ID); break;

		case VANESA: 		objeto = new Vanessa(casilla,nombre,ID); break;

		case VAMPIRO: 		objeto = new Vampiro(casilla,nombre,ID); break;

		case VAMPIRELLA: 	objeto = new Vampirella(casilla,nombre,ID); break;

		case NOSFERATU: 	objeto = new Nosferatu(casilla,nombre,ID); break;

		case ZOMBIE: 		objeto = new Zombie(casilla,nombre,ID); break;	

		default: 			cout<<"No se ha encontrado el objeto de nombre: "<<nombre<<endl; break;
	}

	return objeto;
}

string Archivo_objetos::convertir_nombre(Lista<string> &datos){
	
	string es_cazador = datos[1].find(CAZADOR)	==	string::npos ?	"" : " "+CAZADOR;
	
	string nombre = datos[0] + es_cazador;
	
	return nombre;
}

Coordenada Archivo_objetos::convertir_posicion(const string &linea){
	
	Lista<string> datos = dividir_texto(linea,'(');
	Lista<string> posicion = dividir_texto(datos[1],',');
	
	int posicion_x = convertir_entero( posicion[0] );
	
	int posicion_y = convertir_entero( posicion[1] );
	
	Coordenada coordenada(posicion_x , posicion_y );

	return coordenada;
}

int Archivo_objetos::convertir_cantidad(Lista<string> &datos){
	
	int cantidad=1;

	if(datos[1].find("(")	==	string::npos)
		
		cantidad = convertir_entero(datos[1]);

	return cantidad == NO_ENCONTRADO ? NO_ENCONTRADO : cantidad;
}

string Archivo_objetos::convertir_id(Lista<string> &datos){
    string ID{};
    if((int)datos.obtener_tamano() == 4) ID = datos[3];
    else ID = datos[4];
    return ID;
}

Lista<Objeto*> Archivo_objetos::obtener_lista_objetos(){ return objetos; }