#include "../src/funcionalidades/tda/Lista.h"
#include "../src/funcionalidades/Funciones.h"
#include <iostream>
#include <string>
using namespace std;

template <class Dato>
void imprimir_numero(Dato numero){
	cout<<" - "<<numero<<" - ";
}
bool filtro_numero(int numero){
	return numero==4;
}

string convertir_string(int numero){
	return to_string(numero);
}

int main(){
	
	activar_color();

	cout<<"Test lista"<<endl;
	
	int num[13] = {4,6,7,2,3,4,3,3,2,4,5,6,4};
	int num2[4] = {1,3,4,5};
	Lista<int> numeros(num,13);
	Lista<int> numeros2(num2,4);
	
	color(AMARILLO);
	numeros.imprimir(imprimir_numero);
	color(RESET);
	cout<<endl;

	cout<<"Test REVERTIR: "<<endl;
	//reverse
	color(AZUL);
	numeros.revertir();
	numeros.imprimir(imprimir_numero);
	color(RESET);
	cout<<endl;

	cout<<"Test ORDENAR: "<<endl;
	//sort
	color(VERDE);
	numeros.ordenar(comparacion);
	numeros.imprimir(imprimir_numero);
	color(RESET);
	cout<<endl;

	cout<<"TEST FILTRAR 4"<<endl;
	Lista<int> n = numeros.filtrar_datos(0,filtro_numero);
	n.imprimir(imprimir_numero);
	cout<<endl;

	cout<<"TEST RESTA"<<endl;
	(numeros-numeros2).imprimir(imprimir_numero);
	cout<<endl;
	(numeros2-numeros).imprimir(imprimir_numero);
	cout<<endl;

	cout<<"TEST MAPEAR: "<<endl;
	Lista<int> numeros3 = numeros;
	Lista<string> numeros_string = numeros3.mapear_datos<string>(0,convertir_string);

	numeros_string.imprimir(imprimir_numero);
	cout<<endl;

	pausa();
}
