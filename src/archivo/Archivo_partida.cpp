#include "Archivo_partida.h"

Archivo_partida::Archivo_partida(const string nombre_fichero):Archivo(nombre_fichero)
{   
    mapa_guardado = nullptr;
}

Archivo_partida::Archivo_partida()
{
    mapa_guardado = nullptr;
}

Tablero* Archivo_partida::obtener_datos_de_partida(){

           

    return mapa_guardado;            
}

void Archivo_partida::guardar_partida(Jugador* jugador1, Jugador* jugador2, Lista<Objeto*> objetos){

    ofstream archivo;
    archivo.open("datos_partida.txt", ios::out);
    
    if(archivo.fail()){
        cout << endl << "No se pudo generar Archivo..." << endl;
        exit(1);
    }else{
        
        string contenido_j1 = obtener_contenido_datos_jugador(jugador1, true);
        string contenido_j2 = obtener_contenido_datos_jugador(jugador2, false);
        string contenido_obj = obtener_contenido_objetos(objetos);

        archivo << contenido_j1+SALTO_LINEA+contenido_j2;
        archivo << SALTO_LINEA+contenido_obj;  

        cout << endl << "Archivo generado con exito..." << endl;
    }

    archivo.close();
    
    remove("partida.txt");
    rename("datos_partida.txt", "partida.txt");
}

string Archivo_partida::obtener_contenido_datos_jugador(Jugador* jugador, bool guardo_el_juego)
{
    contenido_jugador = "";
    
    Lista<Objeto*> datos_personajes;
    datos_personajes=jugador->obtener_datos_personajes();

    if(guardo_el_juego){
        contenido_jugador+=to_string(jugador->obtener_numero_jugador());
        contenido_jugador+=SALTO_LINEA;    
    }

    contenido_jugador+=jugador->obtener_bando()+ESPACIO;
    contenido_jugador+=to_string(datos_personajes.obtener_tamano());
    
    int index = 0;

    while(index < datos_personajes.obtener_tamano()){
        Ser* ente = (Ser*)datos_personajes[index];
        int tipo_pj = buscar_dato(NOMBRES_CHAR,MAX_NOMBRES, ente->obtener_nombre());
        string nombre_pj = NOMBRES_STRING[tipo_pj];
        contenido_jugador+=SALTO_LINEA+nombre_pj+ESPACIO+ente->obtener_ID()+ESPACIO;
        grabar_estatus(ente);
        grabar_posicion(ente);        
        grabar_objetos(ente);
        index++;
    }   

    return contenido_jugador;
}

string Archivo_partida::obtener_contenido_objetos(Lista<Objeto*> objetos)
{
    string contenido_obj="";
    contenido_obj+=ITEMS+ESPACIO+to_string(objetos.obtener_tamano());
    int index = 0;
    while(index < objetos.obtener_tamano())
    {
        Elemento* objeto = (Elemento*)objetos[index];
        int tipo_obj = buscar_dato(NOMBRES_CHAR,MAX_NOMBRES, objeto->obtener_nombre());
        contenido_obj+=SALTO_LINEA+NOMBRES_STRING[tipo_obj]+ESPACIO;
        contenido_obj+=objeto->obtener_ID()+ESPACIO;
        contenido_obj+=to_string(objeto->obtener_cantidad())+ESPACIO;
        contenido_obj+=to_string(objeto->obtener_casilla()->obtener_fila())+ESPACIO;
        contenido_obj+=to_string(objeto->obtener_casilla()->obtener_columna());
        index++;
    }
    return contenido_obj;
}

void Archivo_partida::grabar_estatus(Ser* ente)
{
    contenido_jugador+=to_string(ente->devolver_armadura())+ESPACIO;
    contenido_jugador+=to_string(ente->devolver_fuerza())+ESPACIO;
    contenido_jugador+=to_string(ente->devolver_vida())+ESPACIO;
    contenido_jugador+=to_string(ente->devolver_energia())+ESPACIO;
}

void Archivo_partida::grabar_posicion(Ser* ente)
{
    contenido_jugador+=to_string(ente->obtener_casilla()->obtener_fila())+ESPACIO;
    contenido_jugador+=to_string(ente->obtener_casilla()->obtener_columna())+ESPACIO;
}

void Archivo_partida::grabar_objetos(Ser* ente)
{
    int index = 0;
    string agua="0", cruz="0", estaca="0", escopeta="0", bala="0";
    string cant_objetos="";
    while(index < ente->obtener_inventario().obtener_tamano()){
        Elemento* objeto = (Elemento*)ente->obtener_inventario()[index];
        int tipo_obj = buscar_dato(NOMBRES_CHAR,MAX_NOMBRES, objeto->obtener_nombre());
        grabar_cantidad(objeto, tipo_obj, agua, cruz, estaca, escopeta, bala);
        index++;
    }
    cant_objetos+=agua+ESPACIO+cruz+ESPACIO+estaca+ESPACIO+escopeta+ESPACIO+bala;
    contenido_jugador+=cant_objetos;
}

void Archivo_partida::grabar_cantidad(Elemento* objeto, int tipo, string &agua, string &cruz, string &estaca, string &escopeta,string &bala)
{
    switch (tipo)
    {
        case AGUA: agua=to_string(objeto->obtener_cantidad()) ; break;
    
        case CRUZ: cruz=to_string(objeto->obtener_cantidad()) ; break;

        case ESTACA: estaca=to_string(objeto->obtener_cantidad()) ; break;

        case ESCOPETA: escopeta=to_string(objeto->obtener_cantidad()) ; break;

        case BALA: bala=to_string(objeto->obtener_cantidad()) ; break;
            
        default: break;
    }
}