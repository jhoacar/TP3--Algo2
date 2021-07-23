#include "../src/funcionalidades/tda/Lista.h"
#include "../src/funcionalidades/Funciones.h"
#include <iostream>
#include <string>
using namespace std;

template <class Dato>
void imprimir_numero(Dato numero){
	cout<<" "<<numero<<",";
}
bool filtro_numero(int numero){
	return numero==4;
}
string convertir_numero(int numero){
	return "NUMERO: " + to_string(numero);
}

int main(){
	
	activar_color();

	cout<<"Test lista"<<endl;

	int num1[13] = {4,6,7,2,3,4,3,3,2,4,5,6,4};
	int num2[4] = {10,4,3,5};
	int num3[5] = {10,7,5,3,8};
	Lista<int> numeros1(num1,13);
	Lista<int> numeros2(num2,4);
	Lista<int> numeros3(num3,5);

	cout<<"Test REVERTIR: "<<endl;
	numeros1.imprimir(imprimir_numero);
	cout<<endl;
	numeros1.revertir();
	numeros1.imprimir(imprimir_numero);
	cout<<endl<<endl;

	cout<<"Test ORDENAR: "<<endl;
	numeros2.imprimir(imprimir_numero);
	cout<<endl;
	numeros2.ordenar(comparacion);
	numeros2.imprimir(imprimir_numero);
	cout<<endl<<endl;

	cout<<"TEST FILTRAR 4"<<endl;
	numeros3.imprimir(imprimir_numero);
	cout<<endl;
	Lista<int> filtro = numeros3.filtrar_datos(0,filtro_numero);
	filtro.imprimir(imprimir_numero);
	cout<<endl<<endl;

	cout<<"TEST MAPEAR A STRING: "<<endl;
	Lista<string> mapeado = numeros3.mapear_datos<string>(0,convertir_numero);
	mapeado.imprimir(imprimir_numero);
	cout<<endl<<endl;

	cout<<"TEST RESTA"<<endl;
	numeros1.imprimir(imprimir_numero);
	cout<<" - ";
	numeros2.imprimir(imprimir_numero);
	cout<<endl;
	(numeros1-numeros2).imprimir(imprimir_numero);
	cout<<endl<<endl;
	numeros2.imprimir(imprimir_numero);
	cout<<" - ";
	numeros1.imprimir(imprimir_numero);
	cout<<endl;
	(numeros2-numeros1).imprimir(imprimir_numero);
	cout<<endl<<endl;

	cout<<"Test OBTENER CANTIDAD (3): "<<endl;
	numeros1.imprimir(imprimir_numero);
	cout<<endl;
	cout<<"HAY : "<<numeros1.obtener_cantidad_dato(3)<<endl<<endl;

	cout<<"Test OBTENER COINCIDENCIAS (3): "<<endl;
	numeros1.imprimir(imprimir_numero);
	cout<<endl<<"Se encontraron en las posiciones: ";
	numeros1.buscar_todo_dato(3).imprimir(imprimir_numero);
	cout<<endl<<endl;

	cout<<"Test BORRAR 2 CANTIDADES DEL DATO (3): "<<endl;
	numeros1.imprimir(imprimir_numero);
	cout<<endl;
	cout<<"CANTIDAD ELIMINADA: "<<numeros1.borrar_cantidad_dato(3,2)<<endl;
	numeros1.imprimir(imprimir_numero);
	cout<<endl<<endl;

	cout<<"Test BORRAR TODAS LAS CANTIDADES DEL DATO (6): "<<endl;
	numeros1.imprimir(imprimir_numero);
	cout<<endl;
	cout<<"CANTIDAD ELIMINADA: "<<numeros1.borrar_toda_occurrencia(6)<<endl;
	numeros1.imprimir(imprimir_numero);
	cout<<endl<<endl;

	cout<<"Test LIMPIAR: "<<endl;
	numeros1.imprimir(imprimir_numero);
	cout<<endl;
	numeros1.limpiar();
	numeros1.imprimir(imprimir_numero);
	cout<<endl<<endl;

	cout<<"Test MEZCLAR: "<<endl;
	numeros2.imprimir(imprimir_numero);
	cout<<endl;
	numeros3.imprimir(imprimir_numero);
	cout<<endl;
	numeros2.mezclar(numeros3);
	numeros2.imprimir(imprimir_numero);
	cout<<endl<<endl;

	pausa();
}
