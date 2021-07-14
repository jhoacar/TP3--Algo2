#include "../src/funcionalidades/Funciones.h"
#include "../src/funcionalidades/tda/Lista.h"
#include "../src/objetos/Objeto.h"
#include "../src/funcionalidades/Includes_Objetos.h"
#include "../src/mapa/Tablero.h"
#include <iostream>
using namespace std;

int comparacion_por_cuadrante(Objeto *A, Objeto *B){
    if(A->obtener_cuadrante()==B->obtener_cuadrante())
        return IGUAL;
    else if(A->obtener_cuadrante()>B->obtener_cuadrante())
        return GRANDE;
    else    
        return PEQUENO;
}

int comparacion_por_ID(Objeto *A, Objeto *B){
    if(A->obtener_ID()==B->obtener_ID())
        return IGUAL;
    else if(A->obtener_ID()>B->obtener_ID())
        return GRANDE;
    else    
        return PEQUENO;
}

int main(){

    Lista<Objeto *> objetos;
    Casilla *casilla = new Lago({1,2});
    Tablero tablero(10,10);

    objetos.agregar(new Humano(casilla,NOMBRES_CHAR[HUMANO],"043"));
    objetos.agregar(new Cazador(casilla,NOMBRES_CHAR[HUMANO_CAZADOR],"052"));
    objetos.agregar(new Agua(casilla,NOMBRES_CHAR[AGUA],20,"301"));
    objetos.agregar(new Estaca(casilla,NOMBRES_CHAR[ESTACA],1,"383"));
    objetos.agregar(new Vampiro(casilla,NOMBRES_CHAR[VAMPIRO],"257"));

    for(int i=0;i<tablero.obtener_filas();i++)
        for(int j=0;j<tablero.obtener_columnas();j++)
            tablero.asignar_casilla( {i,j} , new Lago({i,j}) );

    tablero.cargar_lista_objetos(objetos);

    Objeto *objeto_buscar = new Agua();

    objeto_buscar->asignar_cuadrante(CARDINALES[NOROESTE]);
    objeto_buscar->asignar_ID("052");

    Objeto *objeto_encontrado;

    int indice = objetos.buscar_dato(0,objeto_buscar,comparacion_por_cuadrante);

    if(indice!=NO_ENCONTRADO)
        objeto_encontrado = objetos[indice];
    
    cout<<"SE ENCONTRO EN EL CUADRANTE NOROESTE: ";
    cout<<obtener_nombre_del_objeto(objeto_encontrado->obtener_nombre())<<endl;

    indice = objetos.buscar_dato(0,objeto_buscar,comparacion_por_ID);

    if(indice!=NO_ENCONTRADO)
        objeto_encontrado = objetos[indice];
    
    cout<<"SE ENCONTRO CON ID: ";
    cout<<obtener_nombre_del_objeto(objeto_encontrado->obtener_nombre())<<endl;

    
    pausa();
}