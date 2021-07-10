#include "../src/funcionalidades/tda/Lista.h"
#include "../src/funcionalidades/Funciones.h"
#include <iostream>
using namespace std;

void imprimir_numero(int numero){
	cout<<" - "<<numero<<" - ";
}
bool filtro_numero(int numero){
	return numero==4;
}

int main(){
	
	activar_color();

	cout<<"Test lista"<<endl;
	
	int num[12] = {4,6,7,2,3,4,3,3,2,4,5,6};
	Lista<int> numeros(num,12);
	
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

	pausa();
}
