#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
using namespace std;

#include "Lista.h"
#include "Floyd.h"

template <class Dato>
class Grafo {

private:
    
    int ** matriz_adyacencia;
    Lista<Dato>  * vertices;
    Floyd<Dato> * floyd;

    //Pre: Tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //Post: Retorna una lista con los datos que debe seguir desde el origen hasta el destino
    Lista<Dato> camino_minimo(int origen, int destino);

    //Post: Agranda dinamicamente la matriz de adyacencia
    void agrandar_matriz_adyacencia();

    //Pre: La matriz que se le envie ya debe tener memoria reservada
    //Post: Copia la matriz de adyacencia en la nueva matriz
    void copiar_matriz_adyacente(int** nueva_adyacente);

    //Post: Inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializar_nuevo_vertice(int** nueva_adyacente);

    //Post: Libera la memoria de la matriz de adyacencia
    void liberar_matriz_adyacencia();

    //Post: Imprime por pantalla la matriz de adyacencia
    void mostrar_matriz_adyacencia();

public:

    Grafo();

    ~Grafo();

    //Pre: Un tipo de dato cargado
    //Post: Agrega un nuevo vertice al grafo
    void agregar_vertice(Dato nuevo_vertice);

    //Pre: Un dato de origen y un dato del destino y una funcion de comparacion dicho tipo de dato
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Devuelve una lista con los datos del camino desde el origen hasta el destino
    Lista<Dato> obtener_camino_minimo(Dato origen, Dato destino, int (*compare)(Dato A, Dato B)=comparacion);

    //Pre: Un dato de origen y un dato del destino y una funcion de comparacion dicho tipo de dato
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Devuelve un entero con el peso minimo del camino desde el origen al destino
    int obtener_peso_minimo(Dato origen, Dato destino, int (*compare)(Dato A, Dato B)=comparacion);

    //Pre: El peso es un valor positivo
    //Post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregar_camino(Dato origen, Dato destino, int peso);

    //Pre: Una funcion que me permita imprimir cada vertice
    //Post: imprime por pantalla el grafo
    void mostrar_grafo(void (*imprimir)(Dato dato));

    //Post: Calcula la matrices que requiere el metodo de floyd para funcionar
    void calcular_matrices_Floyd();
};

template <class Dato>
Grafo<Dato>::Grafo() {
    matriz_adyacencia = nullptr;
    vertices = new Lista<Dato>();
    floyd = new Floyd<Dato>(vertices);
}

template <class Dato>
void Grafo<Dato>::agregar_vertice(Dato nuevo_vertice) {
    agrandar_matriz_adyacencia();
    vertices->agregar(nuevo_vertice);
}


template <class Dato>
void Grafo<Dato>::mostrar_grafo(void (*imprimir)(Dato dato)) {
    vertices->imprimir(imprimir);
    cout<<endl;
    mostrar_matriz_adyacencia();
    floyd->mostrar_matriz_camino(imprimir);
    floyd->mostrar_matriz_pesos();
}

template <class Dato>
void Grafo<Dato>::agregar_camino(Dato origen, Dato destino, int peso) {

    int posicion_origen = vertices->buscar_dato(0,origen);
    int posicion_destino = vertices->buscar_dato(0,destino);

    if(posicion_destino!= NO_ENCONTRADO && posicion_origen != NO_ENCONTRADO) {
        matriz_adyacencia[posicion_origen][posicion_destino] = peso;
        matriz_adyacencia[posicion_destino][posicion_origen] = peso;
    }
}
template <class Dato>
Lista<Dato> Grafo<Dato>::obtener_camino_minimo(Dato origen, Dato destino, int (*compare)(Dato A , Dato B)) {
    
    int posicion_origen = vertices->buscar_dato(0,origen);
    int posicion_destino = vertices->buscar_dato(0,destino);

    Lista<Dato> camino;

    camino.agregar(origen);

    if(posicion_origen!=NO_ENCONTRADO && posicion_destino!=NO_ENCONTRADO)
        camino+=camino_minimo(posicion_origen, posicion_destino);
        
    return camino;
}
template <class Dato>
int Grafo<Dato>::obtener_peso_minimo(Dato origen, Dato destino, int (*compare)(Dato A , Dato B)) {
    
    int posicion_origen = vertices->buscar_dato(0,origen);
    int posicion_destino = vertices->buscar_dato(0,destino);

    if(posicion_origen==NO_ENCONTRADO || posicion_destino==NO_ENCONTRADO)
        return NO_ENCONTRADO;
    else
        return floyd->peso_minimo(posicion_origen,posicion_destino);
}
template <class Dato>
void Grafo<Dato>::agrandar_matriz_adyacencia() {
    
    int** matriz_auxiliar;
    int nueva_cantidad_vertices = vertices->obtener_tamano() + 1;

    matriz_auxiliar = new int*[nueva_cantidad_vertices];
    for(int i = 0; i < nueva_cantidad_vertices; i++){
        matriz_auxiliar[i] = new int[nueva_cantidad_vertices];
    }

    copiar_matriz_adyacente(matriz_auxiliar);
    inicializar_nuevo_vertice(matriz_auxiliar);
    liberar_matriz_adyacencia();
    matriz_adyacencia = matriz_auxiliar;

}
template <class Dato>
void Grafo<Dato>::copiar_matriz_adyacente(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_tamano(); i++){
        for(int j = 0; j < vertices -> obtener_tamano(); j++){
            nueva_adyacente[i][j] = matriz_adyacencia[i][j];
        }
    }
}
template <class Dato>
void Grafo<Dato>::inicializar_nuevo_vertice(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_tamano(); i++){
        nueva_adyacente[vertices -> obtener_tamano()][i] = INFINITO;
        nueva_adyacente[i][vertices -> obtener_tamano()] = INFINITO;
    }
    nueva_adyacente[vertices -> obtener_tamano()][vertices -> obtener_tamano()] = 0;
}
template <class Dato>
void Grafo<Dato>::liberar_matriz_adyacencia() {
    for(int i = 0; i < vertices -> obtener_tamano(); i++){
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
}
template <class Dato>
Grafo<Dato>::~Grafo() {
    liberar_matriz_adyacencia();
    matriz_adyacencia = nullptr;
    delete vertices;
}

template <class Dato>
void Grafo<Dato>::mostrar_matriz_adyacencia() {
    
    cout << "Matriz de adyacencia:" << endl;

    for(int i = 0; i < vertices -> obtener_tamano(); i++){
        for(int j = 0; j < vertices -> obtener_tamano() * 2; j++) {
            if(j == vertices -> obtener_tamano() * 2 - 1){
                cout << endl;
            } else if(j % 2 == 0){
                if(matriz_adyacencia[i][j/2] == INFINITO){
                    cout <<" "<<(char)157<<" "; //"∞-";
                } else {
                    cout << " "<<matriz_adyacencia[i][j/2]<<" ";
                }
            } else{
                cout << " | ";
            }
        }
    }
    cout << endl;
}
template <class Dato>
void Grafo<Dato>::calcular_matrices_Floyd() {
    floyd -> calcular_matrices(matriz_adyacencia);
}

template <class Dato>
Lista<Dato> Grafo<Dato>::camino_minimo(int origen, int destino) {
    return floyd->camino_minimo(origen,destino);
}


#endif //GRAFO_H
