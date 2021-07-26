#include "Archivo_partida.h"

Archivo_partida::Archivo_partida(const string nombre_fichero):Archivo(nombre_fichero){   }

void Archivo_partida::cargar_datos_de_partida(Tablero* tablero, Jugador* jugador1, Jugador* jugador2){

    if(contenido.length()==0||tablero==nullptr)
        return;

    Lista<string> lineas = dividir_texto(contenido,'\n');
    
    int guardo_partida = convertir_entero(lineas[0]);
    
    if(guardo_partida == 1){
        cargar_jugadores(tablero, jugador1, jugador2, lineas);
    }else{
        cargar_jugadores(tablero,jugador2, jugador1, lineas);
    }

    tablero->cargar_lista_objetos(objetos.obtener_valores());
}

void Archivo_partida::cargar_jugadores(Tablero* tablero, Jugador* jugador1, Jugador* jugador2, Lista<string> &lineas)
{
    int num_jugador = convertir_entero(lineas[0]);
    jugador1->asignar_numero(num_jugador);
    
    Lista<string> datos = dividir_texto(lineas[1], ' ');
    
    jugador1->asignar_bando(datos[0]);
    int cantidad_pj = convertir_entero(datos[1]);
    
    Lista<Objeto*> personajes_j1;
    
    int iterator = 2;
    
    int max = iterator+cantidad_pj;
    while(iterator < max){
        datos=dividir_texto(lineas[iterator], ' ');
        personajes_j1.agregar(cargar_personaje(tablero, datos));
        iterator++;
    }
    jugador1->guardar_personajes_de_jugador(personajes_j1);
    
    Lista<Objeto*> personajes_j2;
    
    if(num_jugador == 1) jugador2->asignar_numero(2);
    else jugador2->asignar_numero(1);
    
    datos=dividir_texto(lineas[iterator], ' ');
    iterator++;
    
    cantidad_pj = convertir_entero(datos[1]);
    jugador2->asignar_bando(datos[0]);
    

    max = iterator+cantidad_pj;
    while(iterator < max){
        datos=dividir_texto(lineas[iterator], ' ');
        personajes_j2.agregar(cargar_personaje(tablero, datos));
        iterator++;
    }
    jugador2->guardar_personajes_de_jugador(personajes_j2);
    
    datos=dividir_texto(lineas[iterator], ' ');
    iterator++;
    
    int cantidad_obj = convertir_entero(datos[1]);
    
    max = iterator+cantidad_obj;
    while(iterator < max){
        datos=dividir_texto(lineas[iterator], ' ');
        cargar_elemento(tablero, datos);
        iterator++;
    }
}

void Archivo_partida::cargar_elemento(Tablero* tablero, Lista<string> &datos)
{   
    Coordenada posicion_objeto(convertir_entero(datos[3])-1, convertir_entero(datos[4])-1);
    string ID = datos[1];
    string nombre_objeto = datos[0];
    int cantidad = convertir_entero(datos[2]);
		
    int tipo_objeto = 	buscar_dato(NOMBRES_STRING,MAX_NOMBRES,nombre_objeto);
    char nombre = tipo_objeto!=NO_ENCONTRADO ? NOMBRES_CHAR[tipo_objeto] : 0;
    Casilla *casilla = tablero->obtener_casilla(posicion_objeto);
    
	Objeto *elemento = crear_objeto(tipo_objeto,nombre,casilla, cantidad, ID);
    
	objetos[ID] = elemento;
    
}

Objeto* Archivo_partida::cargar_personaje(Tablero* tablero, Lista<string> &datos)
{
    string nombre_objeto = datos[0];
    if(datos[1] == "CV"){
        nombre_objeto+=ESPACIO+datos[1];
        datos.borrar(1);
    }

    Coordenada posicion_objeto(convertir_entero(datos[6])-1, convertir_entero(datos[7])-1);
    
    string ID = datos[1];
	
    int tipo_objeto = 	buscar_dato(NOMBRES_STRING,MAX_NOMBRES,nombre_objeto);
    char nombre = tipo_objeto!=NO_ENCONTRADO ? NOMBRES_CHAR[tipo_objeto] : 0;
    
    Casilla *casilla = tablero->obtener_casilla(posicion_objeto);

	Objeto *personaje = crear_objeto(tipo_objeto,nombre,casilla, 1, ID);

	((Ser*)personaje)->asignar_armadura(convertir_entero(datos[2]));
    ((Ser*)personaje)->asignar_fuerza(convertir_entero(datos[3]));
    ((Ser*)personaje)->asignar_vida(convertir_entero(datos[4]));
    ((Ser*)personaje)->asignar_energia(convertir_entero(datos[5]));

	objetos[ID] = personaje;
    
    return personaje;
}

Objeto* Archivo_partida::crear_objeto(const int tipo_objeto,const char nombre,Casilla *casilla, int cantidad, string ID){

	Objeto* objeto = nullptr;

	switch(tipo_objeto) {

		case AGUA: 			objeto = new Agua(casilla,nombre,cantidad,ID); break;

		case BALA: 			objeto = new Bala(casilla,nombre,cantidad,ID); break;

		case CRUZ: 			objeto = new Cruz(casilla,nombre,cantidad,ID); break;

		case ESTACA: 		objeto = new Estaca(casilla,nombre,cantidad, ID); break;

		case ESCOPETA: 		objeto = new Escopeta(casilla,nombre,cantidad, ID); break;

		case HUMANO: 		objeto = new Humano(casilla,nombre,ID); break;

		case HUMANO_CAZADOR:objeto = new Cazador(casilla,nombre,ID); break;

		case VANESA: 		objeto = new Vanessa(casilla,nombre,ID); break;

		case VAMPIRO: 		objeto = new Vampiro(casilla,nombre,ID); break;

		case VAMPIRELLA: 	objeto = new Vampirella(casilla,nombre,ID); break;

		case NOSFERATU: 	objeto = new Nosferatu(casilla,nombre,ID); break;

		case ZOMBIE: 		objeto = new Zombie(casilla,nombre,ID); break;	

		default: 			cout<<"No se ha encontrado el objeto de nombre: "<<nombre<<endl; break;
	}

	return objeto;
}

void Archivo_partida::guardar_partida(Jugador* jugador1, Jugador* jugador2, Lista<Objeto*> &objetos){

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

string Archivo_partida::obtener_contenido_objetos(Lista<Objeto*> &objetos)
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