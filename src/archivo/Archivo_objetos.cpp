#include "Archivo_objetos.h"
#include "../funcionalidades/Includes_Objetos.h"

Archivo_objetos::Archivo_objetos(const string nombre_fichero, Tablero *tablero):Archivo(nombre_fichero),objetos(){

    cargar_tablero(tablero);
}

void Archivo_objetos::cargar_tablero(Tablero* tablero){
    
    if(contenido.length()==0||tablero==nullptr)
        return;

    Lista<string> datos = dividir_texto(contenido,'\n');

    datos.borrar(0); //Seria la primera linea de las dimensiones

    cargar_objetos(datos,tablero);

    tablero->cargar_lista_objetos(objetos.obtener_valores());   
}

void Archivo_objetos::cargar_objetos(Lista<string> &lineas, Tablero *tablero){
	
	for(int i = 0; i < (int)lineas.obtener_tamano(); i++){
        
        Lista<string> division_datos = dividir_texto(lineas[i],' ');

		Coordenada posicion_objeto = convertir_posicion(lineas[i]);
        string ID = convertir_id(division_datos);
        string nombre_objeto	= convertir_nombre(division_datos);
        int	cantidad_objeto = convertir_cantidad(division_datos);
		
        int tipo_objeto = 	buscar_dato(NOMBRES_STRING,MAX_NOMBRES,nombre_objeto);
        char nombre = tipo_objeto!=NO_ENCONTRADO ? NOMBRES_CHAR[tipo_objeto] : 0;
        Casilla *casilla = tablero->obtener_casilla(posicion_objeto);

		Objeto *objeto = crear_objeto(tipo_objeto,nombre,casilla,cantidad_objeto,ID);

		objetos[ID] = objeto;
    }
}


Objeto* Archivo_objetos::crear_objeto(const int tipo_objeto,const char nombre,Casilla *casilla, int cantidad, string ID){

	Objeto* objeto = nullptr;

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
	string fila_str = dividir_texto(datos[1],',')[0];
	string columna_str = dividir_texto(dividir_texto(datos[1],',')[1],')')[0];
	
	int fila = convertir_entero( fila_str );
	
	int columna = convertir_entero( columna_str );
	
	Coordenada coordenada(fila-1 , columna-1 ); //Se le resta una posicion para que se encuentre en la matriz

	return coordenada;
}

int Archivo_objetos::convertir_cantidad(Lista<string> &datos){
	
	int cantidad=1;

	if(datos[1].find("(")	==	string :: npos)

		cantidad = convertir_entero(datos[1]);

	return cantidad;
}

string Archivo_objetos::convertir_id(Lista<string> &datos){

    return (int)datos.obtener_tamano() == 4 ? datos[3] : datos[4];
}

Lista<Objeto*> Archivo_objetos::obtener_lista_objetos(){ 
    return objetos.obtener_valores(); 
}