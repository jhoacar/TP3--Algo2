#include <iostream>
using namespace std;

#include "../src/funcionalidades/tda/Grafo.h"


void imprimir_string(string dato){
    cout<<" "<<dato<<" ";
}


int main() {

    Grafo<string> grafo;

    grafo.agregar_vertice("A");
    grafo.agregar_vertice("B");
    grafo.agregar_vertice("C");
    grafo.agregar_vertice("D");
    grafo.agregar_vertice("E");
    
    grafo.agregar_camino("A","B",4);
    grafo.agregar_camino("A","C",8);
    grafo.agregar_camino("B","D",2);
    grafo.agregar_camino("B","C",1);
    grafo.agregar_camino("C","D",4);
    grafo.agregar_camino("C","E",2);
    grafo.agregar_camino("D","E",7);

    grafo.calcular_matrices_Floyd();
    
    grafo.mostrar_grafo(imprimir_string);

    Lista<string> camino_minimo = grafo.obtener_camino_minimo("A","D");

    cout<<endl;
    camino_minimo.imprimir(imprimir_string);

    cout<<endl<<"El peso es: "<<grafo.obtener_peso_minimo("A","D")<<endl;

    return 0;
}
