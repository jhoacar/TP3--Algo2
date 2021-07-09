#include "Funciones.h"

#include <fstream>
#include <sstream>

using std::stringstream;
using std::fstream;
using std::cin;

#ifdef __linux__
#define LIMPIAR "clear"
void pausa(){
	cout<<"Pulse una tecla para continuar...";
	cin.get();
}
#endif // __linux__

#ifdef __MINGW32__
#define LIMPIAR "CLS"
void pausa(){
	system("pause");
}
#endif // __MINGW32__

void activar_color(void){
	limpiar_pantalla();
}

void gotoxy(int x,int y)    
{
    cout<<(char)0x1B<<"["<<y<<";"<<x<<"f";
}

void color(int color){

	if(color >= 0 && color< (int)CANTIDAD_COLORES)
		cout<<ANSI_COLOR[color];
}

int obtener_numero_aleatorio(int min, int max){

	return rand()%( max - min + 1 ) + min;

}

void limpiar_pantalla(){

	system(LIMPIAR);
}

bool es_minuscula(char letra){

	return (int)letra >= (int)'a' && (int)letra <= (int)'z';

}
char caracter_mayuscula(char caracter){

	if(es_minuscula(caracter))

		caracter = (char)( (int)caracter - ( (int)'a' - (int)'A' ));

	return caracter;

}

string cadena_mayuscula(string cadena){

	for( size_t i=0 ; i < cadena.length() ; i++)
	
		cadena[i] = caracter_mayuscula(cadena[i]);
	
	return cadena;
}

string obtener_texto(const string nombre_fichero){

	fstream archivo( nombre_fichero.c_str() , fstream::in );

	if(!archivo){
	
		cout<<"No se pudo abrir el fichero "<<nombre_fichero<<endl;
	
		return "";
	
	}
  	
	string datos_texto;
  	
	getline(archivo,datos_texto,'\0');
  	
	archivo.close();

  	return datos_texto;
}

Lista<string> dividir_texto(const string texto,const char delim){

	stringstream buffer_texto(texto);

	string cadena;
	
	Lista<string> informacion;
	
	while(getline(buffer_texto,cadena,delim))
	
		informacion.agregar(cadena);
	
	return informacion;
}

string solo_numeros(string &cadena){

	size_t i=0;

	while (i < cadena.length()) {
  	
	  	if (!isdigit(cadena[i]))	
	
		  cadena.erase(i,1);
	
		else	
	
			i++; // Incrementamos siempre que no eliminemos un caracter
  	}
	
	return cadena.length() > 0 ? cadena : NO_NUMERO; //Si no habian numeros regresamos -1

}
int convertir_entero(string cadena){

	return stoi(solo_numeros(cadena));

}
int minimo(int A, int B){
	return A < B ?  A : B;
}

Lista<Coordenada> obtener_cruz(Coordenada centro, int longitud,Coordenada limite_inferior, Coordenada limite_superior){
	Lista<Coordenada> cruz;
	int x,y;
	for(int i=1;i<=longitud; i++){
		
		x = centro.obtener_x();
		y = centro.obtener_y();

		if(x+i<limite_superior.obtener_x())
			cruz.agregar({x+i,y});
		if(y+i<limite_superior.obtener_y())
			cruz.agregar({x,y+i});
		if(x-i>=limite_inferior.obtener_x())
			cruz.agregar({x-i,y});
		if(y-i>=limite_inferior.obtener_y())
			cruz.agregar({x,y-i});
	}
	return cruz;
}

Lista<Coordenada> obtener_cuadrado(Coordenada centro, int tamano, Coordenada limite_inferior, Coordenada limite_superior){
	Lista<Coordenada> cuadrado;
	int x,y;
	for(int i=1; i<=tamano; i++){
		
		x = centro.obtener_x();
		y = centro.obtener_y();

		if(x+i<limite_superior.obtener_x())
			cuadrado.agregar({x+i,y});
		if(y+i<limite_superior.obtener_y())
			cuadrado.agregar({x,y+i});
		if(x+i<limite_superior.obtener_x() && y+i<limite_superior.obtener_y())
			cuadrado.agregar({x+i,y+i});
		if(x-i>=limite_inferior.obtener_x() && y-i>=limite_inferior.obtener_y())
			cuadrado.agregar({x-i,y-i});
		if(x-i>=limite_inferior.obtener_x()){
			cuadrado.agregar({x-i,y});
			if(y+i<limite_superior.obtener_y())
				cuadrado.agregar({x-i,y+i});
		}
		if(y-i>=limite_inferior.obtener_y()){
			cuadrado.agregar({x,y-i});
			if(x+i<limite_superior.obtener_x())
				cuadrado.agregar({x+i,y-i});
		}
	}

	return cuadrado;
}

int pedir_dato(string opciones_menu,string error,int inicio,int fin,char opcion_salir){

	string respuesta;
	bool bandera = false;

	while(!bandera){

		limpiar_pantalla();

		cout<<opciones_menu;
		
		getline(cin,respuesta,'\n');
		
		respuesta = cadena_mayuscula(respuesta);

		if(respuesta[0]==opcion_salir)
			return NO_ENCONTRADO;
		else
			bandera = convertir_entero(respuesta) >= inicio && convertir_entero(respuesta) <= fin;

		if(!bandera){
			cout<<error<<endl;
			pausa();
		}
	}
	return convertir_entero(respuesta);
}

bool mostrar_fichero(string name){
    
    string fichero = "src/interfaz/"+name+".txt";

    string mostrar = obtener_texto(fichero);
    
    if(mostrar.length()>0){

        mostrar.replace(mostrar.find("\\"),1,"\\\\");

        cout<<mostrar;
		
        return true;
    }
    else
        return false;
}

bool es_par(int numero){

  return numero%2==0;

}
