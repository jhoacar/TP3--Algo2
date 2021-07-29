#include <iostream>
using namespace std;

#include "../src/funcionalidades/tda/Grafo.h"


void imprimir_string(string dato){
    cout<<" "<<dato<<" ";
}


int main() {

    Grafo<string> grafo;

    grafo.agregar_vertice("V1");
    grafo.agregar_vertice("V2");
    grafo.agregar_vertice("V3");
    grafo.agregar_vertice("V4");
    grafo.agregar_vertice("V5");
    
    grafo.agregar_camino("V1","V2",7);
    grafo.agregar_camino("V1","V3",2);
    grafo.agregar_camino("V2","V5",1);
    grafo.agregar_camino("V3","V4",2);
    grafo.agregar_camino("V3","V2",4);
    grafo.agregar_camino("V4","V2",1);
    grafo.agregar_camino("V4","V5",1);

    grafo.calcular_matrices_Floyd();
    
    grafo.mostrar_grafo(imprimir_string);

    Lista<string> camino_minimo = grafo.obtener_camino_minimo("V1","V4");

    cout<<endl;
    camino_minimo.imprimir(imprimir_string);

    cout<<endl<<"El peso es: "<<grafo.obtener_peso_minimo("V1","V4")<<endl;

    return 0;
}
