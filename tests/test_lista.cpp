#include "../src/funcionalidades/Lista.h"
#include "../src/funcionalidades/Funciones.h"
#include <iostream>
using namespace std;

void imprimir_numero(int numero){
	cout<<" - "<<numero<<" - ";
}

int main(){
	
	activar_color();

	cout<<"Test lista"<<endl;
	
	int num[6] = {4,6,7,2,3,4};
	Lista<int> numeros(num,6);
	
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

	pausa();
}
