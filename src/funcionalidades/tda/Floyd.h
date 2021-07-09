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

    //pre: requiere una matriz de adyacencia bien cargada
    //post: crea la matriz costo inicializandola con los valores de la matriz de adyacencia
    int ** crear_matriz_costos(int ** matriz_adyacencia);

    //post: crea una matriz de caminos
    int ** crear_matriz_caminos();

   //post: libera la memoria de las matrices de costos y caminos
    void liberar_matrices();

    void actualizar_matrices();
public:
    Floyd(Lista<Dato> *vertices);

    //post: libera la memoria pedida
    ~Floyd();

    //post:calcula las matrices de costos y caminos.
    void calcular_matrices(int ** matriz_adyacencia);

    //post: muestra el camino minimo entre el origen y el destino imprimiendo los vertices a visitar y su costo final
    Lista<Dato> camino_minimo(int origen, int destino);

    int peso_minimo(int origen,int destino);

    void mostrar_matriz_camino(void (*imprimir)(Dato dato));
    
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

void imprimir_coord(Coordenada c){
    cout<<"("<<c.obtener_x()<<","<<c.obtener_y()<<")"<<endl;
}

template<class Dato>
void Floyd<Dato>::actualizar_matrices(){
    //Algoritmo, Recorro una cruz desde cada posicion de la diagonal principal luego obtengo el vertice de interseccion de cada coordenada de la cruz
    //Verfico si el peso que tiene esa interseccion es mayor a la suma que tiene en esa cruz 
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                matriz_costos[i][j] = min(matriz_costos[i][j], matriz_costos[i][k] + matriz_costos[k][j]);
    
    for(int i = 0 ; i < cantidad_vertices; i++){
        Lista<Coordenada> cruz = obtener_cruz({i,i},cantidad_vertices,{0,0},{cantidad_vertices,cantidad_vertices});
        for(int i = 0 ; i < cruz.obtener_tamano(); i++){

        }
        
        
        cout<<endl;
        cruz.imprimir(imprimir_coord);
        cout<<endl;
        pausa();
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
        camino_minimo.agregar((*vertices)[origen+1]);
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
void Floyd<Dato>::mostrar_matriz_camino(void (*imprimir)(Dato dato)){
    cout << " Matriz de caminos:" << endl;
    for(int i=0; i< cantidad_vertices; i++){
        for(int j=0; j<cantidad_vertices; j++)
            cout<<" "<<matriz_caminos[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0; i< cantidad_vertices; i++){
        for(int j=0; j<cantidad_vertices; j++)
            imprimir((*vertices)[matriz_caminos[i][j]]);
        cout<<endl;
    }
}

template<class Dato>
void Floyd<Dato>::mostrar_matriz_pesos(){
    cout << " Matriz de pesos:" << endl;
    for(int i=0; i< cantidad_vertices; i++){
        for(int j=0; j<cantidad_vertices; j++)
            cout<<" "<<matriz_costos[i][j]<<" ";
        cout<<endl;
    }
}


#endif //GRAFOS_FLOYD_H
