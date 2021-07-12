#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada
{
	int x;
	int y;
	public:

		//Post: Crea una coordenada a (0,0)
		Coordenada();
		
		//Pre: Una coordenada en X e Y
		//Post: Crea una coordenada con la posicion (x,y)
		Coordenada(int x, int y);

		~Coordenada() = default;
		
		//Post: Devuelve la abscisa 
		int obtener_x();
		
		//Post: Devuelve la ordenada
		int obtener_y();

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
		//Post: Devuelve verdadero si tanto en X como en Y es menor a las componentes de la coordenada
		bool operator	<(Coordenada coordenada);
		
		//Pre: Una coordenada a evaluar
		//Post: Devuelve verdadero si tanto en X como en Y es mayor a las componentes de la coordenada
		bool operator	>(Coordenada coordenada);
		
		//Pre: Un numero de decremento
		//Post: Le resta tanto a X como a Y el valor del decremento
		void operator -=(const int decremento);
};

#endif
