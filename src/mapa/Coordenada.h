#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada
{
	int fila;
	int columna;
	public:

		//Post: Crea una coordenada a (0,0)
		Coordenada();

		//Pre: Una coordenada en fila e columna
		//Post: Crea una coordenada con la posicion (fila,columna)
		Coordenada(int fila, int columna);

		~Coordenada() = default;
		
		//Post: Devuelve la abscisa 

		int obtener_fila();
		
		//Post: Devuelve la ordenada
		int obtener_columna();

		//Pre: Una coordenada a asignar
		//Post: Asigna la coordenada que fue brindada 
		Coordenada& operator =(Coordenada coordenada);
		
		//Pre: Una coordenada a evaluar
		//Post: Devuelve verdadero si son diferentes , falso caso contrario
		bool operator !=(Coordenada coordenada);
		
		//Pre: Una coordenada a evaluar
		//Post: Devuelva verdadero si son iguales, falso caso contrario
		bool operator ==(Coordenada coordenada);
		
		//Pre: Una coordenada a evaluar
		//Post: Devuelve verdadero si tanto en fila como en columna es menor a las componentes de la coordenada
		bool operator	<(Coordenada coordenada);
		
		//Pre: Una coordenada a evaluar
		//Post: Devuelve verdadero si tanto en fila como en columna es macolumnaor a las componentes de la coordenada
		bool operator	>(Coordenada coordenada);
		
		//Pre: Un numero de decremento
		//Post: Le resta tanto a fila como a columna el valor del decremento
		void operator -=(const int decremento);
};

#endif
