#include "Tablero.h"
#include <iostream>
#include "../funcionalidades/Funciones.h"

using namespace std;

Tablero::Tablero(){

    this->filas = 0;

    this->columnas = 0;

    casillas = nullptr;

}

Tablero::Tablero(int filas,int columnas)
{

    this->filas = filas;

    this->columnas = columnas;

    casillas = new Casilla**[filas];

    for(int i=0; i < filas; i++)
        casillas[i] = new Casilla*[columnas];


    for(int i=0; i < filas ;i++){
        for(int j=0; j < columnas ;j++){
            casillas[i][j]=nullptr;
            grafo.agregar_vertice({i,j});
        }
    }
}

Tablero::~Tablero()
{
    for(int i = 0; i < filas ; i++){

        for(int j = 0; j < columnas ; j++){

            if(casillas[i][j] != nullptr){

                delete casillas[i][j];

                casillas[i][j] = nullptr;

            }
        }
    }

    for(int i = 0 ; i < filas ;i++){
    
        delete[] casillas[i];
    
        casillas[i] = nullptr;
    
    }

    delete [] casillas;

    casillas = nullptr;
}

string Tablero::obtener_cuadrante(Coordenada posicion){
    
    if(!es_valida(posicion))
    
        return "";

    else if(posicion.obtener_fila()<columnas/2 && posicion.obtener_columna()<filas/2)
    
        return CARDINALES[NOROESTE];
    
    else if(posicion.obtener_fila()>columnas/2 && posicion.obtener_columna()>filas/2)
    
        return CARDINALES[SURESTE];
    
    else if(posicion.obtener_fila()>=columnas/2 && posicion.obtener_columna()<=filas/2)
    
        return CARDINALES[NORESTE];
    
    else
    
        return CARDINALES[SUROESTE];
}

bool Tablero::es_valida(Coordenada posicion){

    Coordenada limite( filas , columnas );

    return (posicion < limite);

}

bool Tablero::hay_casilla(Coordenada posicion){
    if(!es_valida(posicion))
        return false;

    return casillas[posicion.obtener_fila()][posicion.obtener_columna()] != nullptr;
}

void Tablero::cargar_objeto(Objeto *objeto){
    
    if(objeto==nullptr)
        return;

    Coordenada posicion = objeto->obtener_posicion();
    
    int fila = posicion.obtener_fila();
    int columna = posicion.obtener_columna();

    if(es_valida(posicion) && casillas[ fila ][ columna ] != nullptr){

        objeto->asignar_cuadrante( obtener_cuadrante ( posicion ) );

        casillas[ fila ][ columna ]->agregar_objeto(objeto);
    }
        
}

void Tablero::cargar_lista_objetos(Lista<Objeto*> objetos){
    objetos.reiniciar();
    while(objetos.existe_siguiente())
        cargar_objeto(objetos.siguiente_dato()); 
    objetos.reiniciar();
}


int Tablero::obtener_filas(){
    
    return this->filas;

}
int Tablero::obtener_columnas(){

    return this->columnas;

}

Casilla* Tablero::obtener_casilla(Coordenada posicion){
    
    int fila = posicion.obtener_fila();
    int columna = posicion.obtener_columna();

    if(es_valida(posicion))
        return casillas[fila][columna];        
    else  
        return nullptr;
}

Objeto* Tablero::obtener_objeto(Coordenada posicion, char nombre_objeto){
    
    int fila = posicion.obtener_fila();
    int columna = posicion.obtener_columna();

    if(!es_valida(posicion) || casillas[fila][columna]==nullptr)
        return nullptr;

    return casillas[fila][columna]->obtener_objeto(nombre_objeto); 
}

Lista<Objeto*> Tablero::obtener_objetos( char nombre_objeto){
    
    Lista<Objeto*> objetos;
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            if(hay_casilla({i,j}))
                objetos+=casillas[i][j]->obtener_objetos(nombre_objeto);
        }
    }
    return objetos;
}


void Tablero::asignar_casilla(Casilla *casilla){

    if(casilla!=nullptr && es_valida(casilla->obtener_posicion())){

        int fila = casilla->obtener_fila();
        int columna = casilla->obtener_columna();
        casilla->asignar_cuadrante(obtener_cuadrante({fila,columna}));
        casillas[fila][columna] = casilla;
    }
}

void Tablero::asignar_casillas( Lista<Casilla*> lista_casillas){

    lista_casillas.reiniciar();
    while(lista_casillas.existe_siguiente())
        asignar_casilla(lista_casillas.siguiente_dato());
    lista_casillas.reiniciar();
}

Lista<Casilla*> Tablero::obtener_lista_casillas(Lista<Coordenada> posiciones){
    
    Lista<Casilla*> lista_casillas;
    while(posiciones.existe_siguiente()){
        Coordenada posicion = posiciones.siguiente_dato();
        if(obtener_casilla(posicion)!= nullptr)
            lista_casillas.agregar(obtener_casilla(posicion));
    }

    return lista_casillas;
}

void Tablero::cargar_grafo(int tipo_personaje){

    for(int i=0; i< filas; i++){
        for(int j=0; j<columnas ; j++){

            Lista<Coordenada> adyacentes = obtener_cruz({i,j},1);
            
            while(adyacentes.existe_siguiente()){

                Coordenada adyacente = adyacentes.siguiente_dato();
                
                if(es_valida(adyacente)){

                    Casilla *casilla_adyacente = obtener_casilla(adyacente);

                    int peso = casilla_adyacente!=nullptr ? casilla_adyacente->obtener_energia(tipo_personaje) : INFINITO;
                
                    grafo.agregar_camino({i,j},adyacente,peso);
                }
            }
        }
    }
    grafo.calcular_matrices_Floyd();
}

Lista<Casilla*> Tablero::obtener_camino_minimo(Coordenada origen, Coordenada destino, int tipo_personaje){

    cargar_grafo(tipo_personaje); //Carga todas las aristas con los pesos correspondientes al tipo de personaje
    Lista<Coordenada> camino_minimo = grafo.obtener_camino_minimo(origen,destino);
    return obtener_lista_casillas(camino_minimo);
}

int Tablero::obtener_energia_total(Coordenada origen, Coordenada destino, int tipo_personaje){
    
    cargar_grafo(tipo_personaje);
    return grafo.obtener_peso_minimo(origen,destino);
}

bool Tablero::eliminar_objeto(Coordenada posicion,const char nombre_objeto){
    
    Casilla *casilla = obtener_casilla(posicion);

    if(casilla==nullptr)
        return false;

    return casilla->eliminar_objeto(nombre_objeto);   
}

bool Tablero::eliminar_objeto(Coordenada posicion,const string ID){
    
    Casilla *casilla = obtener_casilla(posicion);

    if(casilla==nullptr)
        return false;

    return casilla->eliminar_objeto(ID);   
}

void Tablero::mostrar_tablero(){

    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            if(hay_casilla({i,j})){
                color(casillas[i][j]->obtener_color());
                color(NEGRO);
                cout<<" ";
                //casillas[i][j]->obtener_tipo()<<" ";
                color(RESET);
            }
            else
            cout<<" * ";
        }
        color(RESET);
        cout<<endl;
    }
    /*
    cout<<endl<<endl;
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            if(hay_casilla({i,j})){
                cout<<endl<<"Casilla ("<<i<<","<<j<<"):"<<endl;
                casillas[i][j]->obtener_objetos().imprimir(imprimir_objeto);
            }
            else
            cout<<" NO HAY NINGUN OBJETO ACA ";
        }
    }
    cout<<endl<<endl;
     */
}


void Tablero::mostrar_leyenda(){

    cout << "\n\tCONVENCION USADA: " << endl;
    cout << "\n-*: vacio";
    cout << "\n- h: humaNOROESTE simple";
    cout << "\n- H: humaNOROESTE caza vampiros-zombis";
    cout << "\n- W: Vanesa";
    cout << "\n- z: zombi";
    cout << "\n- v: vampiro";
    cout << "\n- V: Vampirella"; 
    cout << "\n- N: NOROESTEsferatu ";
    cout << "\n- c: cruz ";
    cout << "\n- a: agua bendita ";
    cout << "\n- e: estaca ";
    cout << "\n- E: escopeta ";
    cout << "\n- b: balas" << endl;
}
