#ifndef GRAFOS_FLOYD_H
#define GRAFOS_FLOYD_H
#include "../Funciones.h"

#include <iostream>
using namespace std;

template <class Dato>

class Floyd {
private:

    int ** matriz_costos;
    int ** matriz_caminos;
    int cantidad_vertices;
    Lista<Dato> *vertices;

    //Pre: Requiere una matriz de adyacencia bien cargada
    //Post: Crea la matriz costo inicializandola con los valores de la matriz de adyacencia
    int ** crear_matriz_costos(int ** matriz_adyacencia);

    //Post: crea una matriz de caminos
    int ** crear_matriz_caminos();

   //Post: libera la memoria de las matrices de costos y caminos
    void liberar_matrices();

    //Post: carga correctamente la informacion de los pesos minimos y caminos en las matrices de costos y caminos
    void actualizar_matrices();

public:
    //Pre: Una lista de vertices para cargar a las matrices
    //Post: Asigna los vertices de la clase al del parametro
    Floyd(Lista<Dato> *vertices);

    //Post: Libera la memoria pedida
    ~Floyd();

    //Pre: Una matriz de adyacencia bien cargada
    //Post: Calcula las matrices de costos y caminos.
    void calcular_matrices(int ** matriz_adyacencia);

    //Pre: Un origen y un destino representado por numeros enteros del vertice
    //Post: Devuelve una lista de datos con el camino desde el origen hasta el destino
    Lista<Dato> camino_minimo(int origen, int destino);

    //Pre: Un origen y un destino representado por numeros enteros del vertice
    //Post: Devuelve un entero con el peso minimo del camino desde el origen hasta el destino
    int peso_minimo(int origen,int destino);

    //Pre: Una funcion que me permita imprimir el dato del vertice
    //Post: Imprime cada elemento de la matriz de camino como con su correspondiente vertice
    void mostrar_matriz_camino();
    
    //Post: Muestra la matriz de pesos en consola
    void mostrar_matriz_pesos();
};

template<class Dato>
Floyd<Dato>::Floyd(Lista<Dato> *vertices) {
    this -> vertices = vertices;
}

template<class Dato>
Floyd<Dato>::~Floyd() {
    liberar_matrices();
}

template<class Dato>
int ** Floyd<Dato>::crear_matriz_caminos(){

    int ** caminos = new int*[cantidad_vertices];
    for(int i = 0; i < cantidad_vertices; i++){
        caminos[i] = new int[cantidad_vertices];
    }

    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices; j++) {
            caminos[i][j] = j;
        }
    }
    return caminos;
}

template<class Dato>
int ** Floyd<Dato>::crear_matriz_costos(int ** matriz_adyacencia){

    int ** costos = new int*[cantidad_vertices];
    for(int i = 0; i < cantidad_vertices; i++){
        costos[i] = new int[cantidad_vertices];
    }

    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices; j++){
            costos[i][j] = matriz_adyacencia[i][j];
        }
    }
    return costos;
}

template<class Dato>
void Floyd<Dato>::actualizar_matrices(){
    
    for (int k = 0; k < cantidad_vertices; k++){
        for (int i = 0; i < cantidad_vertices; i++){
            for (int j = 0; j < cantidad_vertices; j++){

                if ( matriz_costos[i][k] + matriz_costos[k][j] < matriz_costos[i][j]){
                    
                    matriz_costos[i][j] = matriz_costos[i][k]+matriz_costos[k][j];
                    matriz_caminos[i][j] = matriz_caminos[i][k];
                } 
            }
        }
    }
}

template<class Dato>
void Floyd<Dato>::calcular_matrices(int ** matriz_adyacencia) {

    cantidad_vertices = vertices->obtener_tamano();
    matriz_costos = crear_matriz_costos(matriz_adyacencia);
    matriz_caminos = crear_matriz_caminos();
    actualizar_matrices();
}

template<class Dato>
Lista<Dato> Floyd<Dato>::camino_minimo(int origen, int destino) {

    Lista<Dato> camino_minimo;
    do{
        origen = matriz_caminos[origen][destino];
        camino_minimo.agregar((*vertices)[origen]);
    }while(origen != destino);
    return camino_minimo;
}
template<class Dato>
int Floyd<Dato>::peso_minimo(int origen, int destino) {
    return matriz_costos[origen][destino];
}

template<class Dato>
void Floyd<Dato>::liberar_matrices() {

    if(matriz_costos != nullptr && matriz_caminos != nullptr){
        
        for(int i = 0; i < cantidad_vertices; i++){
            delete[] matriz_costos[i];
            delete[] matriz_caminos[i];
        }
        delete[] matriz_costos;
        delete[] matriz_caminos;

        matriz_costos = nullptr;
        matriz_caminos = nullptr;
    }
}


template<class Dato>
void Floyd<Dato>::mostrar_matriz_camino(){
    cout << " Matriz de caminos:" << endl;
    for(int i=0; i< cantidad_vertices; i++){
        for(int j=0; j<cantidad_vertices; j++)
            cout<<" "<<matriz_caminos[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

template<class Dato>
void Floyd<Dato>::mostrar_matriz_pesos(){
    cout << " Matriz de pesos:" << endl;
    for(int i=0; i< cantidad_vertices; i++){
        for(int j=0; j<cantidad_vertices; j++)
            if(matriz_costos[i][j]>=INFINITO)
                cout<<" "<<(char)157<<" ";
            else
                cout<<" "<<matriz_costos[i][j]<<" ";
        cout<<endl;
    }
}


#endif //GRAFOS_FLOYD_H
