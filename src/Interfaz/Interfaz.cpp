#include "Interfaz.h"

bool tiene_vida(Objeto* objeto){
    if(objeto!=nullptr && !es_elemento(objeto))
        return ((Ser*)objeto)->obtener_vida()>0;
    else
        return false;
}


Interfaz::Interfaz() {
    this->turnos = 0;
}
void Interfaz::avanzar_turno() {
    this ->turnos++;
}
int Interfaz::devolver_turno() {
    return this -> turnos;
}
void Interfaz::desplegar_menu_principal() {
    limpiar_pantalla();

    gotoxy(0, 0);

    // estps numeros los saque de probar varias veces y ver como encuadraba bien
    int empieza_x = 3;
    int empieza_y = 35;
    int primera_opcion = 3;
    int ultima_opcion = 5;

    Coordenada eleccion;

    cout << "BIENVENIDO AL JUEGO DE NOSFERATU" << endl;
    cout << endl;
    cout << "----------- Jugar -----------" << endl;
    cout << "----------- Creditos -----------" << endl;
    cout << "----------- Salir -----------" << endl;

    eleccion = this ->elegir_opcion(empieza_x, empieza_y, primera_opcion, ultima_opcion);
    cout << eleccion.obtener_fila() << endl;

    switch(eleccion.obtener_fila()){
        case OPCION_1:
            this -> jugar();
            break;

        case OPCION_2:
            gotoxy(0, ultima_opcion + ESPACIO);
            this ->creditos();
            break;

        case OPCION_3:
            gotoxy(0, ultima_opcion + ESPACIO);
            this ->salir();
            break;

        default:
            gotoxy(0, ultima_opcion + ESPACIO);
            cout << "Implemetar si se equivoca de opcion" << endl;
    }
}

void Interfaz::salir() {
    cout << "GRACIAS POR JUGAR, ESPERO VUELVAS PRONTO!" << endl;
}

void Interfaz::creditos() {
    cout << "Este juego fue creado por:" << endl;
    cout << "Jhoan Carrero" << endl;
    cout << "Nicolas Porcel "<< endl;
    cout << "Franco Mazzaro" << endl;
    cout << "Agustin Sanchez" << endl;
    cout << "Alejandro Toledo" << endl;
    pausa();

    this ->desplegar_menu_principal();
}

int Interfaz::desplegar_menu_secundario(Tablero* mapa, Lista<Objeto*> lista_humanos, Lista<Objeto*> lista_mounstruos) {
    limpiar_pantalla();

    gotoxy(0, 0);

    int empieza_x = 1;
    int empieza_y = 58;
    int primera_opcion = 1;
    int ultima_opcion = 7;

    Coordenada eleccion;

    cout << "> Buscar por ID un personaje u objeto en particular" << endl;
    cout << "> Mostrar tablero" << endl;
    cout << "> Mostrar cantidad de integrantes de un bando" << endl;
    cout << "> Seleccionar bando" << endl;
    cout << "> Agregar un objeto al tablero" << endl;
    cout << "> Eliminar objeto del tablero" << endl;
    cout << "> Salir" << endl;

    eleccion = this ->elegir_opcion(empieza_x, empieza_y, primera_opcion, ultima_opcion);

    gotoxy(0, ultima_opcion + ESPACIO);

    switch(eleccion.obtener_fila()){
        case OPCION_1:
            this ->busqueda_objeto(mapa);
            break;

        case OPCION_2:
            this ->mostrar_tablero(mapa);
            break;

        case OPCION_3:
            this -> cantidad_integrantes(lista_humanos, lista_mounstruos);
            break;

        case OPCION_4:
            break;

        case OPCION_5:
            this ->agregar_objeto(mapa, lista_humanos, lista_mounstruos);
            break;

        case OPCION_6:
            this ->eliminar_objeto(mapa);
            break;

        case OPCION_7:
            break;

        default:
            gotoxy(0, ultima_opcion + ESPACIO);
            cout << "Implementar si se equivoca de opcion" << endl;
    }
    return eleccion.obtener_fila();
}

Coordenada Interfaz::elegir_opcion(int empieza_menu_x, int empieza_menu_y, int primera_opcion, int ultima_opcion) {
    char tecla=0;
    Coordenada posicion={empieza_menu_x, empieza_menu_y};

    while(tecla!=' '){

        gotoxy(posicion);
        tecla = caracter_mayuscula((char)tecla_pulsada());
        switch(tecla){
            case ARRIBA:
                gotoxy(posicion);
                mover_arriba_menu(posicion, primera_opcion, ultima_opcion);
                break;

            case ABAJO:
                gotoxy(posicion);
                mover_abajo_menu(posicion, primera_opcion, ultima_opcion);
                break;
        }
    }

    posicion = {(posicion.obtener_fila() - primera_opcion +1), posicion.obtener_columna()}; //esto lo haga para que me de el numero de la opcion real

    return posicion;

}

Lista<Objeto*> Interfaz::extraer_humanos(Lista<Objeto*> lista_objetos) {
    Lista<Objeto*> solo_humanos = lista_objetos.filtrar_datos(0, es_tipo_humano);

    return  solo_humanos;
}

Lista<Objeto*> Interfaz::extraer_mounstruos(Lista<Objeto *> lista_objetos) {
    Lista<Objeto*> solo_mounstruos = lista_objetos.filtrar_datos(0, es_tipo_monstruo);

    return  solo_mounstruos;
}

void Interfaz::jugar(){
    int eleccion = 0;

    Lista<Objeto*> lista_objetos;
    Lista<Objeto*> lista_humanos;
    Lista<Objeto*> lista_mounstruos;
    Tablero* mapa = nullptr;

    Archivo_tablero lectura_tablero(FICHERO_TABLERO);

    mapa = lectura_tablero.obtener_tablero();


    Archivo_objetos lectura_objetos(FICHERO_OBJETOS, mapa);

    lista_objetos = lectura_objetos.obtener_lista_objetos();

    lista_humanos = this -> extraer_humanos(lista_objetos);

    lista_mounstruos = this ->extraer_mounstruos(lista_objetos);

    while (eleccion != OPCION_7){
        eleccion = this -> desplegar_menu_secundario(mapa, lista_humanos, lista_mounstruos);
        if (eleccion == OPCION_4)
            this -> guerra(mapa);
    }
    this ->salir();
}

void Interfaz::asignar_bando(Jugador &jugador_1, Jugador &jugador_2) {
    srand(time_t(((unsigned int)0)));
    int bando = obtener_numero_aleatorio(1, 2);

    limpiar_pantalla();

    gotoxy(0, 0);


    int empieza_x = 2;
    int empieza_y = 14;
    int primera_opcion = 2;
    int ultima_opcion = 3;

    Coordenada eleccion;
    cout << "Elije jugador " << bando << endl;
    cout << "> Humanos" << endl;
    cout << "> Mounstros" << endl;

    eleccion = elegir_opcion(empieza_x, empieza_y, primera_opcion, ultima_opcion);

    switch (eleccion.obtener_fila()) {
        case OPCION_1:
            gotoxy(0, ultima_opcion + ESPACIO);
            cout << "EL jugador "<< bando << " ha elegido los humanos" << endl;

            pausa();

            if (bando == 1){
                jugador_1.asignar_bando("Humanos");
                jugador_2.asignar_bando("Mounstruos");
            }
            else{
                jugador_1.asignar_bando("Mounstruos");
                jugador_2.asignar_bando("Humanos");
            }

            break;

        case OPCION_2:
            gotoxy(0, ultima_opcion + ESPACIO);
            cout << "EL jugador " << bando << " ha elegido los mounstruos" << endl;

            pausa();

            if (bando == 1){
                jugador_1.asignar_bando("Mounstruos");
                jugador_2.asignar_bando("Humanos");
            }
            else{
                jugador_1.asignar_bando("Humanos");
                jugador_2.asignar_bando("Mounstruos");
            }

            break;
    }

    limpiar_pantalla();
    gotoxy(0, 0);

    cout << "El bando del jugador 1 es: " << jugador_1.obtener_bando() << endl;
    cout << "El bando del jugador 2 es: " << jugador_2.obtener_bando() << endl;

    pausa();
}

int Interfaz::movimiento() {
    Coordenada eleccion;

    limpiar_pantalla();
    gotoxy(0, 0);

    int empieza_x = 2;
    int empieza_y = 14;
    int primera_opcion = 2;
    int ultima_opcion = 5;

    cout << "Movimientos:  " << endl;
    cout << "> Defenderse" << endl;
    cout << "> Atacar" << endl;
    cout << "> Moverse" << endl;
    cout << "> Pasar opcion" << endl;

    eleccion = elegir_opcion(empieza_x, empieza_y, primera_opcion, ultima_opcion);
    return eleccion.obtener_fila();
}

Coordenada Interfaz::eleccion_coordenada() {
    int x,y;
    Coordenada posicion;

    cout << "Ingrese coordenada" << endl;
    cout << "X: ";

    cin >> x;
    cout << endl;

    cout << "Y: ";
    cin >> y;
    posicion = {x, y};
    return posicion;
}

int Interfaz::eleccion_arma() {
    limpiar_pantalla();

    gotoxy(0, 0);

    int nombre = 0;

    int empieza_x = 2;
    int empieza_y = 11;
    int primera_opcion = 2;
    int ultima_opcion = 4;

    Coordenada eleccion;

    cout << "Eligi el arma: " << endl;
    cout << "> Escopeta" << endl;
    cout << "> Agua bendita" << endl;
    cout << "> Estaca" << endl;

    eleccion = elegir_opcion(empieza_x, empieza_y, primera_opcion, ultima_opcion);
    switch (eleccion.obtener_fila()) {
        case OPCION_1:
            nombre = 11;
            break;
        case OPCION_2:
            nombre = 7;
            break;
        case OPCION_3:
            nombre = 10;
            break;
    }

    return NOMBRES_CHAR[nombre];
}

void Interfaz::ataque_humano(Objeto *personaje, Tablero* mapa) {
    
    limpiar_pantalla();

    gotoxy(0, 0);

    Coordenada posicion_ataque = this -> eleccion_coordenada();

    if(!mapa->es_valida(posicion_ataque)){
        cout << "No podes atacar porque ingresaste una coordenada fuera del rango" << endl;
        pausa();
        return;
    }


    int valida = ((Humano*)personaje)->se_puede_atacar(posicion_ataque, mapa, NOMBRES_CHAR[ESCOPETA]);
    if (personaje->obtener_nombre() == NOMBRES_CHAR[HUMANO])
        if(valida == NO_ENERGIA || valida == NO_RANGO || valida == NO_ARMA_OBJETO){
            if(valida == NO_ENERGIA)
                cout << "No podes atacar porque no hay energia suficiente" << endl;
            else if (valida == NO_RANGO)
                cout << "No podes atacar porque no hay un mounstruo en tu rango" << endl;
            else
                cout << "No tiene escopeta" << endl;
        }
        else{
            ((Humano*)personaje) ->atacar(posicion_ataque, mapa, NOMBRES_CHAR[ESCOPETA]);
            cout << "Se ataco correctamente" << endl;
        }


    else if (personaje->obtener_nombre() == NOMBRES_CHAR[HUMANO_CAZADOR]){
        char arma = this -> eleccion_objeto();
        int valida = ((Cazador*)personaje)->se_puede_atacar(posicion_ataque, mapa, arma);
        if(valida == NO_ENERGIA || valida == NO_RANGO || valida == NO_ARMA_OBJETO)
            if(valida == NO_ENERGIA)
                cout << "No podes atacar porque no hay energia suficiente" << endl;
            else if (valida == NO_RANGO)
                cout << "No podes atacar porque no hay un mounstruo en tu rango" << endl;
            else
                cout << "No tenes esa arma para atacar" << endl;
        else{
            ((Humano*)personaje) ->atacar(posicion_ataque, mapa, arma);
            cout << "Se ataco correctamente" << endl;
        }
    }

    else if (personaje->obtener_nombre() == NOMBRES_CHAR[VANESA]){
        char arma = this -> eleccion_objeto();
        int valida = ((Vanessa*)personaje)->se_puede_atacar(posicion_ataque, mapa, arma);
        if(valida == NO_ENERGIA || valida == NO_RANGO || valida == NO_ARMA_OBJETO){
            if(valida == NO_ENERGIA)
                cout << "No podes atacar porque no hay energia suficiente" << endl;
            else if (valida == NO_RANGO)
                cout << "No podes atacar porque no hay un mounstruo en tu rango" << endl;
            else
                cout << "No tenes esa arma para atacar" << endl;
        }
        else{
            ((Vanessa*)personaje) ->atacar(posicion_ataque, mapa, arma);
            cout << "Se ataco correctamente" << endl;
            }
    }
    pausa();
}

void Interfaz::ataque_mounstruo(Objeto *personaje, Tablero *mapa) {
    limpiar_pantalla();

    gotoxy(0, 0);

    Coordenada posicion_ataque = this -> eleccion_coordenada();

    if(!mapa->es_valida(posicion_ataque)){
        cout << "No podes atacar porque ingresaste una coordenada fuera del rango" << endl;
        pausa();
        return;
    }

    int valida = ((Vampiro*)personaje)->se_puede_atacar(posicion_ataque, mapa);
    if (personaje->obtener_nombre() == NOMBRES_CHAR[VAMPIRO])
        if(valida == NO_ENERGIA_MOUNSTRUO || valida == NO_RANGO_MOUNSTRUO){
            if(valida == NO_ENERGIA_MOUNSTRUO)
                cout << "No podes atacar porque no hay energia suficiente" << endl;
            else
                cout << "No podes atacar porque no hay un mounstruo en tu rango" << endl;
        }
        else{
            ((Vampiro*)personaje) ->atacar(posicion_ataque, mapa);
            cout << "Se ataco correctamente" << endl;
        }

    else if (personaje->obtener_nombre() == NOMBRES_CHAR[VAMPIRELLA]){
        int valida = ((Vampirella*)personaje)->se_puede_atacar(posicion_ataque, mapa);
        if(valida == NO_ENERGIA_MOUNSTRUO || valida == NO_RANGO_MOUNSTRUO)
            if(valida == NO_ENERGIA_MOUNSTRUO)
                cout << "No podes atacar porque no hay energia suficiente" << endl;
            else
                cout << "No podes atacar porque no hay un mounstruo en tu rango" << endl;

        else{
            ((Vampirella*)personaje) ->atacar(posicion_ataque, mapa);
            cout << "Se ataco correctamente" << endl;
        }
    }

    else if (personaje->obtener_nombre() == NOMBRES_CHAR[NOSFERATU]){
        int valida = ((Nosferatu*)personaje)->se_puede_atacar(posicion_ataque, mapa);
        if(valida == NO_ENERGIA_MOUNSTRUO || valida == NO_RANGO_MOUNSTRUO)
            if(valida == NO_ENERGIA_MOUNSTRUO)
                cout << "No podes atacar porque no hay energia suficiente" << endl;
            else
                cout << "No podes atacar porque no hay un humano en tu rango" << endl;
        else{
            ((Nosferatu*)personaje) ->atacar(posicion_ataque, mapa);
            cout << "Se ataco correctamente" << endl;
            }

    }

    else if (personaje->obtener_nombre() == NOMBRES_CHAR[ZOMBIE]){
        int valida = ((Zombie*)personaje)->se_puede_atacar(posicion_ataque, mapa);
        if(valida == NO_ENERGIA_MOUNSTRUO || valida == NO_RANGO_MOUNSTRUO){
            if(valida == NO_ENERGIA_MOUNSTRUO)
                cout << "No podes atacar porque no hay energia suficiente" << endl;
            else
                cout << "No podes atacar porque no hay un Humano en tu rango" << endl;
        }
        else{
            ((Zombie*)personaje) ->atacar(posicion_ataque, mapa);
            cout << "Se ataco correctamente" << endl;
            }
    }
    pausa();
}

int Interfaz::eleccion_defensa_humano() {
    limpiar_pantalla();

    gotoxy(0, 0);

    int opcion = 0;

    int empieza_x = 2;
    int empieza_y = 11;
    int primera_opcion = 2;
    int ultima_opcion = 3;

    Coordenada eleccion;

    cout << "Eligi entre: " << endl;
    cout << "> Subir un punto de armadura" << endl;
    cout << "> Regenerar toda la energia" << endl;

    eleccion = elegir_opcion(empieza_x, empieza_y, primera_opcion, ultima_opcion);

    switch (eleccion.obtener_fila()) {
        case OPCION_1:
            opcion = OPCION_AUMENTAR_ARMADURA;
            break;
        case OPCION_2:
            opcion = OPCION_REGENERAR_ENERGIA;
            break;
    }

    return opcion;
}

int Interfaz::eleccion_defensa_cazador() {
    limpiar_pantalla();

    gotoxy(0, 0);

    int opcion = 0;

    int empieza_x = 2;
    int empieza_y = 11;
    int primera_opcion = 2;
    int ultima_opcion = 3;

    Coordenada eleccion;

    cout << "Eligi entre: " << endl;
    cout << "> Aumentar vida propia" << endl;
    cout << "> Aumentar vida aliados" << endl;

    eleccion = elegir_opcion(empieza_x, empieza_y, primera_opcion, ultima_opcion);

    switch (eleccion.obtener_fila()) {
        case OPCION_1:
            opcion = OPCION_CURARSE_VIDA;
            break;
        case OPCION_2:
            opcion = OPCION_CURAR_ALIADOS;
            break;
    }

    return opcion;
}


void Interfaz::defensa_humano(Objeto *personaje, Tablero *mapa){
    if (personaje->obtener_nombre() == NOMBRES_CHAR[HUMANO]){
        if(((Humano*)personaje)->tiene_agua_bendita()){
            int opcion_humano_simple = this ->eleccion_defensa_humano();
            ((Humano*)personaje)->defender(mapa, opcion_humano_simple);
        }
    }
    if (personaje->obtener_nombre() == NOMBRES_CHAR[HUMANO_CAZADOR]){
        if(((Cazador*)personaje)->tiene_agua_bendita()){
            int opcion_cazador = this ->eleccion_defensa_humano();
            ((Cazador*)personaje)->defender(mapa, opcion_cazador);
        }
    }
    else
        ((Vanessa*)personaje)->defender(mapa);
}

void Interfaz::defensa_mounstruo(Objeto *personaje, Tablero *mapa) {

    if (personaje->obtener_nombre() == NOMBRES_CHAR[VAMPIRO])
        ((Vampiro*)personaje)->defender(mapa);
    else if (personaje->obtener_nombre() == NOMBRES_CHAR[VAMPIRELLA])
        ((Vampirella*)personaje)->defender(mapa);
    else if (personaje->obtener_nombre() == NOMBRES_CHAR[NOSFERATU])
        ((Nosferatu*)personaje)->defender(mapa);
    else if (personaje->obtener_nombre() == NOMBRES_CHAR[ZOMBIE])
        ((Zombie*)personaje)->defender(mapa);

}

void Interfaz::eleccion_movimiento_objeto(int eleccion, Objeto* personaje, Tablero* mapa) {
    switch (eleccion) {
        case OPCION_1:
            if (es_tipo_humano(personaje))
                this ->defensa_humano(personaje, mapa);
            else
                this ->defensa_mounstruo(personaje, mapa);
            break;

        case OPCION_2:
            if (es_tipo_humano(personaje))
                this ->ataque_humano(personaje, mapa);
            else
                this ->ataque_mounstruo(personaje, mapa);
            break;
        case OPCION_3:
                this ->mover(personaje,mapa);
            break;

    }
}

void Interfaz::mover(Objeto* personaje, Tablero* mapa){

    Coordenada destino = POSICION_INVALIDA;
    
    while(!mapa->es_valida(destino)){
        limpiar_pantalla();
        cout<<"Hacia donde quieres mover el personaje "<<convertir_nombre(personaje->obtener_nombre())<<endl;
        cout<<"El tablero tiene dimensiones filas = "<<mapa->obtener_filas()<<" y columnas = "<<mapa->obtener_columnas()<<endl;
    
        destino = eleccion_coordenada();
        if(!mapa->es_valida(destino)){
            cout<<"Ingresaste una coordenada erronea, vuelve a ingresarla: "<<endl;
            pausa();
        }
    }

    cout<<"Comienza simulacion de camino minimo"<<endl;
    pausa();

    simulacion_camino_minimo(destino,personaje,mapa);
}

void Interfaz::simulacion_camino_minimo(Coordenada destino,Objeto* personaje, Tablero* mapa){

    limpiar_pantalla();
    mapa->mostrar_tablero();
    
    int tipo;
    if(personaje->obtener_nombre()==NOMBRES_CHAR[ZOMBIE])
        tipo = TIPO_ZOMBIE;
    else if(personaje->obtener_nombre()==NOMBRES_CHAR[HUMANO])
        tipo = TIPO_HUMANO;
    else if(personaje->obtener_nombre()==NOMBRES_CHAR[HUMANO_CAZADOR] || personaje->obtener_nombre()==NOMBRES_CHAR[VANESA] )
        tipo = TIPO_CAZADOR;
    else
        tipo = TIPO_VAMPIRO;

    Lista<Casilla*> camino_minimo = mapa->obtener_camino_minimo(personaje->obtener_posicion(),destino,tipo);

    Coordenada incremento = {1,1};

    gotoxy(personaje->obtener_posicion()+incremento);
    cout<<personaje->obtener_nombre();

    Casilla *anterior = personaje->obtener_casilla();
    
    cursor(false);

    while(camino_minimo.existe_siguiente()){

        demorar(1);
        
        gotoxy(personaje->obtener_posicion()+incremento);
        color(anterior->obtener_color());
        cout<<" ";
        color(RESET);


        anterior->eliminar_objeto(personaje->obtener_nombre()); 
        Casilla *casilla_nueva = camino_minimo.siguiente_dato();
        personaje->asignar_casilla( casilla_nueva );
        ((Ser*)personaje)->encuentro_con_elemento();
        casilla_nueva->agregar_objeto(personaje);

        gotoxy(personaje->obtener_posicion()+incremento);
        cout<<personaje->obtener_nombre();

        anterior = casilla_nueva; 
        
    }

    cursor(true);

    gotoxy(1,10);
    pausa();
}





bool Interfaz::turno_jugador(Tablero* mapa, string bando) {
    int eleccion = 0;

    if (bando == "humanos"){

        Lista<Objeto*> humanos;
        humanos = mapa ->obtener_objetos().filtrar_datos(0, es_tipo_humano);
        while (humanos.existe_siguiente()){
            Objeto* humano = humanos.siguiente_dato();
            limpiar_pantalla();
            cout<<"Opcion para el personaje: "<<convertir_nombre(humano->obtener_nombre())<<endl;
            pausa();
            eleccion = this ->movimiento();
            this ->eleccion_movimiento_objeto(eleccion, humano, mapa);
        }
        return hay_personajes_con_vida(mapa->obtener_objetos().filtrar_datos(0,es_tipo_monstruo));
    }
    else{
        Lista<Objeto*> mounstruos;
        mounstruos = mapa ->obtener_objetos().filtrar_datos(0, es_tipo_monstruo);
        while (mounstruos.existe_siguiente()){
            Objeto* mounstruo = mounstruos.siguiente_dato();
            limpiar_pantalla();
            cout<<"Opcion para el personaje: "<<convertir_nombre(mounstruo->obtener_nombre())<<endl;
            pausa();
            eleccion = this ->movimiento();
            this ->eleccion_movimiento_objeto(eleccion, mounstruo, mapa);
        }
        return hay_personajes_con_vida(mapa->obtener_objetos().filtrar_datos(0,es_tipo_humano));
    }
}


bool Interfaz::hay_personajes_con_vida(Lista<Objeto*> personajes){
    return personajes.filtrar_datos(0,tiene_vida).obtener_tamano()>0;   
}


void Interfaz::guerra(Tablero* mapa) {
    //aca se llevara a cabo la simulacion del juego con la creacion de los bandos
    bool juego_finalizado = false;

    Jugador jugador_1, jugador_2;
    jugador_1.asignar_numero(1);
    jugador_2.asignar_numero(2);
    this ->asignar_bando(jugador_1, jugador_2);

    int comienza = obtener_numero_aleatorio(1, 2);

    if (comienza == 1){
        while(!juego_finalizado){
            this -> turnos++;
            if (turnos%2 == 0)
                juego_finalizado = this -> turno_jugador(mapa, jugador_2.obtener_bando());
            else{
                //primero
                juego_finalizado = this -> turno_jugador(mapa, jugador_1.obtener_bando());
            }
        }
    }
    else{
        while(!juego_finalizado){
            this -> turnos++;
            if (turnos%2 == 0)
                juego_finalizado = this -> turno_jugador(mapa, jugador_1.obtener_bando());
            else{
                //primero
                juego_finalizado = this -> turno_jugador(mapa, jugador_2.obtener_bando());
            }
        }
    }
}

char Interfaz::eleccion_objeto() {
    limpiar_pantalla();

    gotoxy(0, 0);

    int empieza_x = 1;
    int empieza_y = 17;
    int primera_opcion = 1;
    int ultima_opcion = 12;

    int nombre = 0;
    Coordenada eleccion;

    cout << "> Humano" << endl;
    cout << "> Humano cazador" << endl;
    cout << "> Vanesa" << endl;
    cout << "> Vampiro" << endl;
    cout << "> Vampirella" << endl;
    cout << "> Nosferatu" << endl;
    cout << "> Zombie" << endl;
    cout << "> Agua" << endl;
    cout << "> Bala" << endl;
    cout << "> Cruz" << endl;
    cout << "> Estaca" << endl;
    cout << "> Escopeta" << endl;

    eleccion = elegir_opcion(empieza_x, empieza_y, primera_opcion, ultima_opcion);
    nombre = eleccion.obtener_fila() - 1; //El -1 es porque el enum de objetos empieza de 0

    return NOMBRES_CHAR[nombre];

}

Coordenada Interfaz::eleccion_casilla(Tablero *mapa) {
    limpiar_pantalla();

    gotoxy(0, 0);

    Coordenada posicion;
    int posicion_x = 0, posicion_y = 0;

    cout << "Recorda que las medidas del tablero son: " << "Ancho: " << mapa->obtener_filas() << " y Largo: " <<  mapa->obtener_columnas() << endl;
    cout << "X: ";

    cin >> posicion_x;
    cout << endl;

    while (posicion_x > mapa->obtener_columnas()){
        cout << "La posicion que ingreso es invalida, ingrese otra: ";
        cin >> posicion_x;
    }

    cout << "Y: ";

    cin >> posicion_y;
    cout << endl;

    while (posicion_y > mapa->obtener_filas()){
        cout << "La posicion que ingreso es invalida, ingrese otra: ";
        cin >> posicion_y;
    }

    posicion = {posicion_x, posicion_y};

    return  posicion;
}

bool Interfaz::validar_id(int id, Lista<Objeto *> lista_humanos, Lista<Objeto *> lista_mounstruos) {
    bool valido = true;
    while (lista_humanos.existe_siguiente())
        if(lista_humanos.siguiente_dato()->obtener_ID() == to_string(id))
            valido = false;

    while (lista_mounstruos.existe_siguiente())
        if(lista_mounstruos.siguiente_dato()->obtener_ID() == to_string(id))
            valido = false;

    return valido;
}

string Interfaz::ingresar_id(int tope_inferior, int tope_superior, Lista<Objeto*> lista_humanos, Lista<Objeto*> lista_mounstruos) {
    limpiar_pantalla();
    gotoxy(0, 0);

    if(tope_inferior == tope_superior){

        Objeto *objeto_unico = new Agua();
        
        if(to_string(tope_inferior)==ID_Nosferatu ){
            objeto_unico->asignar_nombre(NOMBRES_CHAR[NOSFERATU]);
            if(lista_mounstruos.existe(objeto_unico,comparacion_por_nombre))
                return "";
        }
        if(to_string(tope_inferior)==ID_Vampirella ){
            objeto_unico->asignar_nombre(NOMBRES_CHAR[VAMPIRELLA]);
            if(lista_mounstruos.existe(objeto_unico,comparacion_por_nombre))
                return "";
        }
        if(to_string(tope_inferior)==ID_Vanesa ){
            objeto_unico->asignar_nombre(NOMBRES_CHAR[VANESA]);
            if(lista_humanos.existe(objeto_unico,comparacion_por_nombre))
                return "";
        }
        delete objeto_unico;
    }
        
    
    int id = 0;
    cout << "Ingrese el id, entre los valores: " << tope_inferior << " y " << tope_superior << endl;
    cout << "id: ";
    cin >> id;
    cout << endl;
    while (id > tope_superior || id < tope_inferior || !this ->validar_id(id, lista_humanos, lista_mounstruos)){
        cout << "El numero de id es invalido, ingrese otro: ";
        cin >> id;
    }

    return to_string(id);
}

string Interfaz::eleccion_id(char tipo, Lista<Objeto*> lista_humanos, Lista<Objeto*> lista_mounstruos) {
    string id = "";
    int tipo_objeto = char_a_int(tipo);
    switch (tipo_objeto) {
        case AGUA:          id = this ->ingresar_id(convertir_entero(ID_minimo_agua), convertir_entero(ID_maximo_agua), lista_humanos, lista_mounstruos); break;

        case BALA:          id = this ->ingresar_id(convertir_entero(ID_minimo_balas), convertir_entero(ID_maximo_balas), lista_humanos, lista_mounstruos); break;

        case CRUZ:          id = this ->ingresar_id(convertir_entero(ID_minimo_cruces), convertir_entero(ID_maximo_cruces), lista_humanos, lista_mounstruos); break;

        case ESTACA:          id = this ->ingresar_id(convertir_entero(ID_minimo_estacas), convertir_entero(ID_maximo_estacas), lista_humanos, lista_mounstruos); break;

        case ESCOPETA:          id = this ->ingresar_id(convertir_entero(ID_minimo_escopetas), convertir_entero(ID_maximo_escopetas), lista_humanos, lista_mounstruos); break;

        case HUMANO:          id = this ->ingresar_id(convertir_entero(ID_minimo_humano_simple), convertir_entero(ID_maximo_humano_simple), lista_humanos, lista_mounstruos); break;

        case HUMANO_CAZADOR:          id = this ->ingresar_id(convertir_entero(ID_minimo_cazador), convertir_entero(ID_maximo_cazador), lista_humanos, lista_mounstruos); break;

        case VANESA:          id = this ->ingresar_id(convertir_entero(ID_Vanesa), convertir_entero(ID_Vanesa), lista_humanos, lista_mounstruos); break;

        case VAMPIRO:          id = this ->ingresar_id(convertir_entero(ID_minimo_vampiro_simple), convertir_entero(ID_maximo_vampiro_simple), lista_humanos, lista_mounstruos); break;

        case VAMPIRELLA:          id = this ->ingresar_id(convertir_entero(ID_Vampirella), convertir_entero(ID_Vampirella), lista_humanos, lista_mounstruos); break;

        case NOSFERATU:          id = this ->ingresar_id(convertir_entero(ID_Nosferatu), convertir_entero(ID_Nosferatu), lista_humanos, lista_mounstruos); break;

        case ZOMBIE:             id = this ->ingresar_id(convertir_entero(ID_minimo_zombie), convertir_entero(ID_maximo_zombie), lista_humanos, lista_mounstruos); break;

    }

    return id;
}

int Interfaz::char_a_int(char tipo) {
    for (size_t i = 0; i < MAX_NOMBRES; i++)
        if (NOMBRES_CHAR[i] == tipo)
            return (int)i;
    return 0;
}

int Interfaz::eleccion_cantidad() {
    int cantidad = 0;

    cout << "Ingresa la cantidad del objeto: ";
    cin >> cantidad;

    return cantidad;
}

void Interfaz::crear_objeto_y_guardarlo(int tipo_objeto, char tipo, Tablero* mapa, int cantidad, string id, Objeto* objeto, Coordenada posicion) {
    tipo_objeto = this -> char_a_int(tipo);

    objeto = crear_objeto(tipo_objeto, tipo, mapa->obtener_casilla(posicion), cantidad, id);

    if (mapa ->obtener_casilla(posicion) != nullptr){
        cout << "No es null" << endl;
        mapa ->obtener_casilla(posicion) ->agregar_objeto(objeto); //guardado en el mapa
        cout << "hola" << endl;
    }
}

void Interfaz::agregar_objeto(Tablero *mapa, Lista<Objeto*> lista_humanos, Lista<Objeto*> lista_mounstruos) {
    Objeto* objeto = nullptr;
    char tipo = this -> eleccion_objeto();
    int tipo_objeto = 0;
    int cantidad = 0;

    if(es_elemento(tipo))
        cantidad = this -> eleccion_cantidad();

    string id = this ->eleccion_id(tipo, lista_humanos, lista_mounstruos);

    if(id.length()==0){
        cout<<"No se pudo agregar porque es un personaje unico y ya se encuentra en el tablero"<<endl;
        pausa();
        return;
    }
    
    Coordenada posicion = this ->eleccion_casilla(mapa);

    this ->crear_objeto_y_guardarlo(tipo_objeto, tipo, mapa, cantidad, id, objeto, posicion);

    cout << "El objeto se aniadio con exito" << endl;

    pausa();
}

void Interfaz::eliminar_objeto(Tablero* mapa){
    Coordenada posicion = this ->eleccion_casilla(mapa);
    char nombre_objeto = this -> eleccion_objeto();

    limpiar_pantalla();
    gotoxy(0, 0);

    if (mapa ->eliminar_objeto(posicion, nombre_objeto))
        cout << "El objeto se elimino con exito" << endl;
    else
        cout << "No se pudo eliminar el objeto" << endl;

    pausa();
}

void Interfaz::cantidad_integrantes(Lista<Objeto*> lista_humanos, Lista<Objeto*> lista_mounstruos) {
    limpiar_pantalla();

    gotoxy(0, 0);


    int empieza_x = 1;
    int empieza_y = 14;
    int primera_opcion = 1;
    int ultima_opcion = 2;

    Coordenada eleccion;

    cout << "> Humanos" << endl;
    cout << "> Mounstros" << endl;

    eleccion = elegir_opcion(empieza_x, empieza_y, primera_opcion, ultima_opcion);

    switch (eleccion.obtener_fila()) {
        case OPCION_1:
            gotoxy(0, ultima_opcion + ESPACIO);
            cout << "La cantidad de integrantes del bando de Humanos es: " << lista_humanos.obtener_tamano() << endl;
            break;

        case OPCION_2:
            gotoxy(0, ultima_opcion + ESPACIO);
            cout << "La cantidad de integrantes del bando de Humanos es: " << lista_mounstruos.obtener_tamano() << endl;
            break;
    }

    pausa();

}

void Interfaz::busqueda_objeto(Tablero* mapa) {
    Objeto* objeto_buscado;
    string ID;

    cout << "Ingrese el ID del objeto a buscar: ";
    cin >> ID;

    objeto_buscado = mapa->obtener_objeto_id(ID);

    if (objeto_buscado != nullptr)
        objeto_buscado ->mostrar();
    else
        cout << "Lo siento, el ID que ingreso no esta asociado a ningun objeto" << endl;

    pausa();

}

void Interfaz::mostrar_tablero(Tablero* mapa) {
    mapa ->mostrar_tablero();
    pausa();

}