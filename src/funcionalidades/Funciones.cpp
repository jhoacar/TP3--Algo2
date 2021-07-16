#include "Funciones.h"

#ifdef __linux__
#define LIMPIAR "clear"
#include <termios.h>
/* reads from keypress, doesn't echo */
int getch(void)
{
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}
void pausa(){
	cout<<"Pulse una tecla para continuar...";
	cin.get();
}
#endif // __linux__

#ifdef __MINGW32__
#define LIMPIAR "CLS"
#include "conio.h"
void pausa(){
	system("pause");
}
#endif // __MINGW32__


char tecla_pulsada(void){
	return (char)getch();
	//La funcion getch devuelve el caracter presionado sin imprimirlo en consola
}


void activar_color(void){
	limpiar_pantalla();
}

void gotoxy(int x,int y)    
{
    cout<<(char)0x1B<<"["<<y<<";"<<x<<"f";
}

void gotoxy(Coordenada posicion)    
{
    cout<<(char)0x1B<<"["<<posicion.obtener_fila()<<";"<<posicion.obtener_columna()<<"f";
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

Lista<Coordenada> obtener_cruz(Coordenada centro, int longitud,Coordenada limite_inferior, Coordenada limite_superior){
	Lista<Coordenada> cruz;
	int x,y;
	for(int i=1;i<=longitud; i++){
		
		x = centro.obtener_fila();
		y = centro.obtener_columna();

		if(x+i<limite_superior.obtener_fila())
			cruz.agregar({x+i,y});
		if(y+i<limite_superior.obtener_columna())
			cruz.agregar({x,y+i});
		if(x-i>=limite_inferior.obtener_fila())
			cruz.agregar({x-i,y});
		if(y-i>=limite_inferior.obtener_columna())
			cruz.agregar({x,y-i});
	}
	return cruz;
}

int convertir_entero(string cadena){

	return stoi(solo_numeros(cadena));

}

int valor_absoluto(int numero){
	
	return numero < 0  ? numero*-1 : numero ; 
}
int minimo(int A, int B){
	return A < B ?  A : B;
}

bool es_par(int numero){

  return numero%2==0;

}

string obtener_nombre_del_objeto(char nombre_char){
	
	int indice = buscar_dato(NOMBRES_CHAR,MAX_NOMBRES,nombre_char);
	
	return indice!=NO_ENCONTRADO ? NOMBRES_STRING[indice] : "";
}

