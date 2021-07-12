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


<<<<<<< HEAD
    for(int i = 0; i < filas ;i++){

        for(int j = 0; j < columnas ;j++)
            casillas[i][j] = nullptr;
=======
    for(int i=0; i < filas ;i++){
        for(int j=0; j < columnas ;j++){
            casillas[i][j]=nullptr;
            grafo.agregar_vertice({i,j});
        }
>>>>>>> 1a1fbf920d772274e7d223ce8c51d7a0df2eef63
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

    else if(posicion.obtener_x()<columnas/2 && posicion.obtener_y()<filas/2)
    
        return CARDINALES[NOROESTE];
    
    else if(posicion.obtener_x()>columnas/2 && posicion.obtener_y()>filas/2)
    
        return CARDINALES[SURESTE];
    
    else if(posicion.obtener_x()>=columnas/2 && posicion.obtener_y()<=filas/2)
    
        return CARDINALES[NORESTE];
    
    else
    
        return CARDINALES[SUROESTE];
}

bool Tablero::es_valida(Coordenada posicion){

    Coordenada limite( columnas , filas );

    return (posicion < limite);

}
void Tablero::cargar_objeto(Objeto *objeto){
    
    if(objeto){

        Coordenada posicion = objeto->obtener_casilla()->obtener_posicion();

<<<<<<< HEAD
        posicion -= 1; //Le resto una posicion para guardarla correctamente en el tablero arrancando en (0,0)
=======
        //Le resto una posicion para guardarla correctamente en el tablero arrancando en (0,0)
        int fila = posicion.obtener_y() - 1;
        int columna = posicion.obtener_x() - 1;
>>>>>>> 1a1fbf920d772274e7d223ce8c51d7a0df2eef63

        if(es_valida({fila,columna}) && casillas[ fila ][ columna ] != nullptr){

            objeto->asignar_cuadrante( obtener_cuadrante ( {fila,columna} ) );
    
            casillas[ fila ][ columna ]->agregar_objeto(objeto);
        }

    }    
}

void Tablero::cargar_lista_objetos(Lista<Objeto *>objeto){
    
    for(int i=0;i<objeto.obtener_tamano(); i++){
        cargar_objeto(objeto[i]);
    }
}


int Tablero::obtener_filas(){
    
    return this->filas;

}
int Tablero::obtener_columnas(){

    return this->columnas;

}

Casilla* Tablero::obtener_casilla(Coordenada posicion){
    
    int fila = posicion.obtener_y();
    int columna = posicion.obtener_x();

<<<<<<< HEAD
    posicion -= 1; //Le resto una posicion para eliminarlo correctamente en el tablero arrancando en (0,0)
=======
>>>>>>> 1a1fbf920d772274e7d223ce8c51d7a0df2eef63

    if(es_valida(posicion))
        return casillas[fila][columna];        
    else  
        return nullptr;
}

void Tablero::asignar_casilla(Casilla *casilla){

    if(casilla!=nullptr && es_valida(casilla->obtener_posicion())){

        int fila = casilla->obtener_posicion().obtener_y();
        int columna = casilla->obtener_posicion().obtener_x();

        casillas[fila][columna] = casilla;
    }
}

void Tablero::asignar_casillas( Lista<Casilla*> lista_casillas){

<<<<<<< HEAD
	for(int i = 0; i < filas ; i++){

        if(i == 0){
            cout << "    ";
            for(int j = 0; j < columnas; j++){
                
                if(j % (columnas/2) == 0 ){
                    color(ROJO);
                    cout << " | ";
                    color(RESET);
                }
                color(CYAN);
                cout << " " << (j+1) << " ";
                color(RESET);
            }

            cout << endl;
        }
=======
    for( int i=0; i< lista_casillas.obtener_tamano(); i++)
        asignar_casilla(lista_casillas[i]);
}

Lista<Casilla*> Tablero::obtener_lista_casillas(Lista<Coordenada> posiciones){
    
    Lista<Casilla*> lista_casillas;
    for(int i=0;i<posiciones.obtener_tamano(); i++)
        if(es_valida(posiciones[i]))
            lista_casillas.agregar(obtener_casilla(posiciones[i]));
>>>>>>> 1a1fbf920d772274e7d223ce8c51d7a0df2eef63

    return lista_casillas;
}

void Tablero::cargar_grafo(int tipo_personaje){

<<<<<<< HEAD
            for(int j = 0; j < columnas + 3 ; j++){
                
                color(ROJO);
                cout << " _ ";
                color(RESET);
            }

            cout << endl;
        }
		
        for(int j =- 1; j < columnas ; j++){

            if(j == -1){
                color(CYAN);
                cout << " " << (i < 9? " "+to_string(i+1) : to_string(i+1) ) << " ";
                color(RESET);
            }
            else{
                
                if(j % (columnas/2) == 0 ){
                    color(ROJO);
                    cout << " | ";
                    color(RESET);
                }    

                if(casillas[i][j]){
                    
                    color(AMARILLO);
                    //cout << " " << casillas[i][j]->obtener_nombre()<<" ";
                    color(RESET);
                    
                }
                else{
                    cout << " * ";
                }
            }
        }    
        color(ROJO);
        cout << " | " << endl;
        color(RESET);
	}

    for(int j = 0; j < columnas + 3 ; j++){

        color(ROJO);
        cout << " - ";
        color(RESET);
    }
    cout << endl;
=======
    for(int i=0; i< filas; i++){
        for(int j=0; j<columnas ; j++){

            Lista<Coordenada> adyacentes = obtener_cruz({i,j},1,{0,0},{filas,columnas});
        
            for(int k=0;k<adyacentes.obtener_tamano(); k++){

                int fila_adyacente    = adyacentes[k].obtener_y();
                int columna_adyacente = adyacentes[k].obtener_x();

                Casilla *casilla_adyacente = obtener_casilla(adyacentes[k]);

                int peso = casilla_adyacente!=nullptr ? casilla_adyacente->obtener_energia(tipo_personaje) : INFINITO;
                    
                grafo.agregar_camino({i,j},{fila_adyacente,columna_adyacente},peso);

            }
        }
    }

}

Lista<Casilla*> Tablero::obtener_camino_minimo(Coordenada origen, Coordenada destino, int tipo_personaje){

    cargar_grafo(tipo_personaje);
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
>>>>>>> 1a1fbf920d772274e7d223ce8c51d7a0df2eef63

    mostrar_leyenda();
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
