#include <iostream>
using namespace std;

#include "../src/funcionalidades/tda/Grafo.h"
#include "../src/objetos/Coordenada.h"

void imprimir_coordenada(Coordenada coord){
    cout<<" ( "<<coord.obtener_x()<<" , "<<coord.obtener_y()<<" ) \t";
}


int main() {

    Grafo<Coordenada> grafo;

    grafo.agregar_vertice({0,0});
    grafo.agregar_vertice({1,0});
    grafo.agregar_vertice({0,1});
    grafo.agregar_vertice({1,1});
    //grafo.agregar_vertice({1,2});
    //grafo.agregar_vertice({2,2});
    //grafo.agregar_vertice({2,1});
    //grafo.agregar_vertice({2,2});
    //grafo.agregar_vertice({2,0});
    //grafo.agregar_vertice({0,2});

    //grafo.agregar_camino({0,0},{1,0},2);
    //grafo.agregar_camino({1,0},{2,0},1);
    //grafo.agregar_camino({2,0},{2,2},3);
    
    //grafo.agregar_camino({0,0},{0,1},3);
    //grafo.agregar_camino({0,1},{1,1},4);
    //grafo.agregar_camino({1,1},{2,2},3);

    grafo.calcular_matrices_Floyd();
    
    grafo.mostrar_grafo(imprimir_coordenada);

    Lista<Coordenada> camino_minimo = grafo.obtener_camino_minimo({0,0},{2,2});

    camino_minimo.imprimir(imprimir_coordenada);

    cout<<"El peso es: "<<grafo.obtener_peso_minimo({0,0},{2,2})<<endl;

    return 0;
}
