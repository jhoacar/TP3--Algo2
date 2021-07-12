#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include "../../constantes/Constantes.h"

//Pre: Dos datos a comparar, con sobrecargas de los operadores "<,>,=="
//Post: Compara y devuelve PEQUENO si A es menor que B, GRANDE si A es mayor que B e IGUAL caso contrario
template<class Dato>
int comparacion(Dato A, Dato B){
    if(A==B)
        return IGUAL;
    else if(A>B)
        return GRANDE;
    else
        return PEQUENO;
}

/*
PRE: Dos datos cargados
POST: Intercambia el valor de ambos datos
*/
template <class Dato>
void swap_datos(Dato &A, Dato &B){

  Dato tmp = A;
  
  A = B;
  
  B = tmp;
}

template <class Dato>
class Lista
{
	  Nodo<Dato> *inicio;
		Nodo<Dato> *fin;
    Nodo<Dato> *actual;
		unsigned long tamano;
    
    //Pre: Esta lista actual previamente vacia y una lista por parametro con la informacion a copiar 
    //Post: Carga toda la informacion de la lista del parametro a esta lista actual 
    void copiar_todo(const Lista &list);
    
    //Pre: Lista con datos previamente, para ser eliminados.
    //Post: Elimina toda la informacion de la lista, liberando toda la memoria reservada
    void borrar_todo();

    //Pre: Un indice a buscar en la lista
    //Post: Devuelve el nodo que se encuentra en ese indice de la lista
		Nodo<Dato>* buscar_nodo(const int index) const;
    
    
	public:
		
    //Pre: Constructor por defecto
    //Post: Crea desde cero a una lista vacia
    Lista();
    
    //Pre: Una lista previamente cargada con informacion
    //Post: Constructor de copia que crea una lista con toda la informacion de la lista del parametro
    Lista(const Lista &lista);

    //Pre: Un vector cargado previamente con informacion
    //Post: Constructor de copia que crea una lista con toda la informacion del vector del parametro
    Lista(Dato *datos, int tope);
    
    //Pre: 
    //Post: Elimina toda la lista
    ~Lista();
		
    //Pre: Una funcion que permita imprimir el tipo de dato de la lista
    //Post: Recorre cada dato de la lista y la imprime con la funcion que fue ofrecida
    void imprimir(void (*imprimir_data)(const Dato data));
    
    //Pre: Un dato a cargar a la lista
    //Post: Agrega al final de la lista el dato por parametro
    void agregar(Dato data);

    //Pre: Un dato a cargar a la lista
    //Post: Devuelve un puntero con la referencia de la lista con dicho dato agregado al final
    Lista<Dato>* expulsar(Dato data);
    
    //Pre: Un indice a eliminar de la lista
    //Post: Devuelve verdadero si fue eliminado de la lista, falso caso contrario
    bool borrar(const int index);
    
    //Pre: 
    //Post: Devuelve el tamano de la lista
		int obtener_tamano() const;
		
    //Pre: Un indice a evaluar si esta en el rango valido
    //Post: Devuelve verdadero si puede estar en la lista, falso caso contrario
    bool es_valido(const int index) const;
    
    //Pre: Un dato a evaluar su existencia, y una funcion para la comparacion de dos tipos de datos
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Devuelve verdadero si se encontro en la lista dicho dato
    bool existe(Dato data, int (*compare)(Dato A , Dato B) = comparacion) const;
    
    //Pre: El comienzo de la busqueda (puede ser desde el origen: 0), el dato a buscar y una funcion donde me compara dos datos
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Devuelve la posicion donde encontro dicho dato buscandolo desde el indice de comienzo
    int buscar_dato(int inicio_busqueda,const Dato data, int (*compare)(Dato A, Dato B) = comparacion) const;
    
    //Pre: El dato a buscar y una funcion donde me compara dos Datos A y B si son iguales
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Devuelve una lista de indices donde se encontro dicho dato
    Lista<int> buscar_todo_dato(const Dato data, int (*compare)(Dato A, Dato B) = comparacion) const;
    
    //Pre: El comienzo de la busqueda (puede ser desde el origen: 0), y una funcion de filtro
    //Esta funcion debe devolver un booleano que represente si pasa el filtro o no
    //Post: Devuelve una sublista de datos, con aquellos que fueron verdadero con la funcion del parametro
    Lista<Dato> filtrar_datos(int inicio_busqueda, bool (*filtro)(Dato A)) const;
    
    //Pre: Un indice a buscar en la lista
    //Post: Devuelve una referencia del dato que se encuentra en dicha posicion
	  Dato& operator[](const int index) const;
    
    //Pre: Una lista con la informacion a cargar
    //Post: Elimina la informacion que se encontraba antes y copia toda la informacion de la lista del parametro
	  void operator=(Lista list);
    
    //Pre: Una lista a unir
    //Post: Devuelve un puntero de una nueva lista con la union de ambas
    Lista<Dato>* operator+(Lista list);
    
    //Pre: Una funcion que permita comparar dos datos
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Ordena de menor a mayor de acuerdo a la funcion del parametro
    void ordenar(int (*compare)(const Dato a, const Dato b) = comparacion);
    
    //Pre: Esta lista, previamente ordenada y una funcion para la comparacion de datos
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Elimina todas aquellas ocurrencias repetidas de la lista con la comparacion que se pida   
    void limpiar(int (*compare)(const Dato a, const Dato b) = comparacion);

    //Pre: Dos posiciones de la lista
    //Post: Intercambia sus datos en la lista
    void swap(const int index_a, const int index_b);

    //Pre: Una lista para unir
    //Post: Une esta lista con la del parametro, modificandose
    void operator+=(Lista list);

    //Pre: Una lista para unir
    //Post: Devuelve la union de esta lista con la del parametro, sin modificarla
    Lista* obtener_union(Lista &lista);
		
    //Pre:
    //Post: Revierte el orden de esta lista, donde el ultimo se encontrara en el primero
    void revertir();

    //Pre:
    //Post: Devuelve un puntero con esta lista revertida, sin modificarla
    Lista *obtener_revertir();

    //Pre: Recibe una lista con la informacion y una funcion de comparacion entre dos datos 
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Se hace un mezclar entre las dos, modificando la original, que tiene que quedar ordenada  y  sin  elementos  repetidos.
    void mezclar(Lista &list, int (*compare)(const Dato A, const Dato B) = comparacion);

    //Pre: Un dato a eliminar de la lista y una funcion de comparacion entre dos datos
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Elimina la primera ocurrencia del dato si lo encontro en la lista, devolviendo verdadero si lo borra, falso caso contrario
    bool borrar_dato(const Dato data, int (*compare)(Dato A, Dato B) = comparacion);

    //Pre: Un dato a eliminar de la lista, la cantidad para borrar de dicho dato y una funcion de comparacion entre dos datos
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Elimina la cantidad de ocurrencias del dato encontrados en la lista, devolviendo la cantidad borradas
    int borrar_cantidad_dato(const Dato data, int cantidad, int (*compare)(Dato A, Dato B) = comparacion);

    //Pre: Un dato a eliminar de la lista y una funcion con el criterio de comparacion entre dos datos
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Elimina todas las ocurrencias que encuentra del dato en la lista, devolviendo la cantidad que fueron eliminados
    int borrar_toda_occurrencia(const Dato data, int (*compare)(Dato A, Dato B) = comparacion);

    //Pre: Un dato a buscar y una funcion con su criterio de comparacion entre dos datos
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Devuelve la cantidad que exista de dicho dato en la lista o -1 en caso contrario
    int obtener_cantidad_dato(const Dato data, int (*compare)(Dato A, Dato B) = comparacion);


    //Pre: Una lista cargada y una funcion que me permita comparar dos datos
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Retorna una nueva lista con los datos de esta lista que no esta con la del parametro
    Lista* obtener_diferencia(Lista list , int (*compare)(Dato A, Dato B) = comparacion);

    //Pre:
    //Post: Pone el puntero a la primera posición o apuntando a NULL
    void reiniciar(void);
    
    //Pre:
    //Post: Devuelve verdadero si el nodo actual no apunta a NULL, falso de lo contrario
    bool existe_siguiente(void) const;
    
    //Pre: hay_siguiente tiene que haber devuelto verdadero previamente
    //Post: Devuelve el dato actual y avanza
    Dato siguiente_dato(void);

    //Pre: Una lista a analizar y una funcion con el criterio de comparacion
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Devuelve verdadero si encuentra alguna coincidencia de un dato con la lista del parametro, falso caso contrario
    bool existe_alguno(Lista &lista, int(*compare)(Dato A, Dato B) = comparacion);

    //Pre: Una lista a analizar y una funcion con el criterio de comparacion
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Devuelve verdadero si encuentra toda coincidencia de los datos con la lista del parametro, falso caso contrario
    bool existen_todos(Lista &lista, int(*compare)(Dato A, Dato B) = comparacion);
  
    //Pre: Una funcion de comparacion de datos 
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo 
    //Post: Devuelve el menor elemento de la lista por dicha funcion
    Dato minimo(int(*compare)(Dato A, Dato B) = comparacion);

    //Pre: Una funcion de comparacion de datos
    //Esta funcion debe devolver un numero entero que representa
    // 0 : son iguales
    // 1 : si el primer argumento es mayor al segundo
    // -1: si el primer argumento es menor al segundo  IGUAL, GRANDE o PEQUENO
    //Post: Devuelve el mayor elemento de la lista por dicha funcion
    Dato maximo(int(*compare)(Dato A, Dato B) = comparacion);

};

template <class Dato>
Lista<Dato>::Lista(){
  this->inicio = new Nodo<Dato>();
  this->fin=this->inicio;
  this->actual=this->inicio;
  this->tamano=0;
}

template <class Dato>
Lista<Dato>::Lista(Dato *datos, int tope){
  this->inicio = new Nodo<Dato>();
  this->fin=this->inicio;
  this->actual=this->inicio;
  this->tamano=0;
  Dato *final = datos + tope;
  while(datos < final){
    agregar(*datos);
    datos++;
  }
}

template <class Dato>
Lista<Dato>::Lista(const Lista &lista){
  copiar_todo(lista);
}

template <class Dato>
Lista<Dato>::~Lista(){
  borrar_todo();
}

template <class Dato>
void Lista<Dato>::imprimir(void (*imprimir_data)(const Dato dato)){
  Nodo<Dato> *nodo = inicio;
  for(int i=0 ; i < (int)tamano  ; i++){
      imprimir_data(*nodo->dato);
      nodo = nodo->siguiente;
  }
}

template <class Dato>
void Lista<Dato>::copiar_todo(const Lista &lista){
  this->inicio = new Nodo<Dato>();
  this->fin=this->inicio;
  this->actual=this->inicio;
  this->tamano=0;
  for(int i=0 ; i< lista.obtener_tamano(); i++)
    agregar(lista[i]);
}

template <class Dato>
void Lista<Dato>::agregar(Dato dato){
  *(fin->dato)=dato;
  fin->siguiente = new Nodo<Dato>();
  fin=fin->siguiente;
  tamano+=1;
}

template <class Dato>
Lista<Dato>* Lista<Dato>::expulsar(Dato dato){
  agregar(dato);
  return this;
}

template <class Dato>
void Lista<Dato>::borrar_todo(){
  Nodo<Dato> *tmp;
  while( inicio!=nullptr ){
    tmp = inicio;
    inicio = inicio->siguiente;
    delete tmp;
  }
}

template <class Dato>
bool Lista<Dato>::borrar(const int index){

  Nodo<Dato> *borrar_node = buscar_nodo(index);
  
  if(borrar_node == nullptr) //Si no se encuentra en la lista no se eliminimoa
    return false;
  
  Nodo<Dato> *before = buscar_nodo(index-1);

  if(before==nullptr) // Si no tiene antecesor entonces se encuentra en el inicio
    inicio = borrar_node->siguiente; //Se referencia al que sigue
  else if(borrar_node->siguiente == nullptr){// Si en el que sigue no hay nada, se encuentra al final
    fin = before;
    fin->siguiente=nullptr;
  }
  else //Se deja de referenciar 
    before->siguiente = borrar_node->siguiente;

  delete borrar_node;
  
  tamano--;
  return true;
}

template <class Dato>
int Lista<Dato>::obtener_tamano() const{
  return (int)tamano;
}

template <class Dato>
bool Lista<Dato>::es_valido(const int index) const{
  return index>=0 && index<= (int) tamano;
}

template <class Dato>
bool Lista<Dato>::existe(Dato dato,int (*compare)(Dato A , Dato B)) const{
  return buscar_dato(0,dato,compare) != NO_ENCONTRADO;
}


template <class Dato>
Nodo<Dato>* Lista<Dato>::buscar_nodo(const int index) const{
  
  if(!es_valido(index))
    return nullptr;

  Nodo<Dato> *nodo = inicio;
  for(int i=0 ; i < index  ; i++)
    nodo = nodo->siguiente; 	
  
  return nodo;
}

template <class Dato>
int Lista<Dato>::buscar_dato(int inicio_busqueda,const Dato dato, int (*compare)(Dato A,Dato B)) const{

  Nodo<Dato> *nodo = buscar_nodo(inicio_busqueda);
  
  if(nodo==nullptr)
    return NO_ENCONTRADO;

  bool found = compare(*(nodo->dato) , dato) == IGUAL;

  while(inicio_busqueda < (int) tamano && !found){
    nodo = nodo->siguiente;
    if(nodo!=nullptr && inicio_busqueda < (int) tamano-1)
      found = compare(*(nodo->dato) , dato) == IGUAL;
    inicio_busqueda++;
  } 	
  return found ? inicio_busqueda : NO_ENCONTRADO;
}

template <class Dato>
Lista<int> Lista<Dato>::buscar_todo_dato(const Dato dato,int (*compare)(Dato A,Dato B)) const{

  int inicio = -1;
  Lista<int> indices;
  do{
      inicio = buscar_dato(inicio+1,dato,compare);
      if(inicio!=NO_ENCONTRADO)
        indices.agregar(inicio);
    }while(inicio!= NO_ENCONTRADO);

  return indices;
}

template <class Dato>
Lista<Dato> Lista<Dato>::filtrar_datos(int inicio_busqueda,bool (*filtro)(Dato A)) const{

  Lista<Dato> encontrados;

  Nodo<Dato> *nodo = buscar_nodo(inicio_busqueda);
  
  if(nodo==nullptr)
    return encontrados;

  while(inicio_busqueda < (int) tamano ){

    if(nodo != nullptr && inicio_busqueda < (int) tamano-1 && filtro(*(nodo->dato) ) )
      encontrados.agregar(*(nodo->dato));
    nodo = nodo->siguiente;  
    inicio_busqueda++;
  } 	
  return encontrados;
}

template <class Dato>
Dato& Lista<Dato>::operator[](const int index) const{
  Nodo<Dato> *nodo = buscar_nodo(index);
  return *(nodo->dato);
}

template <class Dato>
void Lista<Dato>::operator=(Lista lista){
  borrar_todo();
  copiar_todo(lista);
}
 
template <class Dato>
Lista<Dato>* Lista<Dato>::operator+(Lista lista){
  Lista<Dato> *nueva = new Lista<Dato>(*this);
  (*nueva)+=lista;
  return nueva;
}

template <class Dato>
void Lista<Dato>::ordenar(int (*compare)(const Dato a, const Dato b)){
    Lista *ordenared_list = selection_ordenar(*this,compare);
    //selection_ordenar
    //quick_ordenar (Desbordamiento de memoria)
    *this=*ordenared_list;
    delete ordenared_list;
}

template <class Dato>
void Lista<Dato>::limpiar(int (*compare)(const Dato a, const Dato b)){
  
  ordenar(compare);
  Lista nueva;
  while(existe_siguiente()){
    Dato dato = siguiente_dato();
    if(compare(dato,*(actual->dato))!=IGUAL) 
      nueva.agregar(dato);
  }  
  *this=nueva;
}

//Complejidad O(index_a + index_b)
template <class Dato>
void Lista<Dato>::swap(const int index_a, const int index_b){
  
  if(index_a == index_b) //Mejora el rfinimiento de hacer busquedas innecesarias
    return;
  
  Nodo<Dato> *node_a = buscar_nodo(index_a);
  Nodo<Dato> *node_b = buscar_nodo(index_b); 

  if(node_a == nullptr || node_b == nullptr)
    return;

  swap_datos( *(node_a->dato), *(node_b->dato) );

}


template <class Dato>
void Lista<Dato>::operator+=(Lista lista){
  lista.reiniciar();
  for( int i=0; i<lista.obtener_tamano(); i++)
    agregar(lista.siguiente_dato());
  lista.reiniciar();
}

template <class Dato>
Lista<Dato>* Lista<Dato>::obtener_union(Lista &lista){
  Lista *nueva = new Lista(*this);
  *nueva+=lista;
  return nueva;
}

//Complejidad O( tamano/2:"ciclo for" + (tamano^2)/2:"swaps") = O(tamano^2)
template <class Dato>
void Lista<Dato>::revertir(){

  int middle = int(tamano/2) - (((int)tamano % 2) == 0 );
  
  for(int i = 0 ; i<= middle ; i++)
    swap( i , (int)tamano - i - 1 );
}

template <class Dato>
Lista<Dato>* Lista<Dato>::obtener_revertir(){
  Lista *nueva = new Lista(*this);
  nueva->revertir();
  return nueva;
}

template <class Dato>
void Lista<Dato>::mezclar(Lista &list, int (*compare)(const Dato A, const Dato B)){
  (*this)+=list;
  ordenar(compare);
  limpiar(compare);
}

template <class Dato>
bool Lista<Dato>::borrar_dato(const Dato dato, int (*compare)(Dato A, Dato B)){
  return borrar(buscar_dato(0,dato,compare));
}

template <class Dato>
int Lista<Dato>::borrar_cantidad_dato(const Dato dato, int cantidad ,int (*compare)(Dato A, Dato B)){
  int borrados=0;
  Lista<int> indices = buscar_todo_dato(0,dato,compare);
  for(int i=0 ; i < minimo( cantidad, indices.obtener_tamano() ) ; i++ )
    borrados += borrar(indices[i]);
  return borrados;
}

template <class Dato>
int Lista<Dato>::borrar_toda_occurrencia(const Dato dato, int (*compare)(Dato A, Dato B)){
  int borrados = 0;
  Lista<int> indices = buscar_todo_dato(dato,compare);
  for(int i=0;i<indices.obtener_tamano(); i++)
    borrados += borrar(indices[i]);
  return borrados;
}
template <class Dato>
int Lista<Dato>::obtener_cantidad_dato(const Dato dato, int (*compare)(Dato A, Dato B)){
  
  int inicio = -1, encontrados = NO_ENCONTRADO;
  
  do{
    inicio = buscar_dato(inicio+1,dato,compare);
    encontrados++;
  }while(inicio!= NO_ENCONTRADO);

  return encontrados;
}

template <class Dato>
Lista<Dato>* Lista<Dato>::obtener_diferencia(const Lista<Dato> lista, int (*compare)(Dato A, Dato B)){
  Lista *nueva = new Lista();
  while(existe_siguiente()){
    Dato dato = siguiente_dato();
    if( !lista.existe(dato, compare ) )
      nueva->agregar(dato);
  }
  reiniciar();
  return nueva;
}

template <class Dato>
void Lista<Dato>::reiniciar(void){
  actual=inicio;
}

template <class Dato>
bool Lista<Dato>::existe_siguiente(void) const {
    return actual->siguiente!=nullptr;
}

template <class Dato>
Dato Lista<Dato>::siguiente_dato(void){
  Dato *dato = actual->dato;
  actual=actual->siguiente;
  return *dato;
}

template <class Dato>
bool Lista<Dato>::existe_alguno(Lista<Dato> &lista , int(*compare)(Dato A, Dato B)){
  bool found = false;
  while(lista.existe_siguiente() && !found)
    found = existe(lista.siguiente_dato(),compare);
  lista.reiniciar();
  return found;
}

template <class Dato>
bool Lista<Dato>::existen_todos(Lista<Dato> &lista , int(*compare)(Dato A, Dato B)){
  int cantidad = 0;
  while(lista.existe_siguiente())
    cantidad+=(int)existe(lista.siguiente_dato(),compare);
  lista.reiniciar();
  return cantidad == lista.obtener_tamano();
}

template <class Dato>
Dato Lista<Dato>::minimo(int (*compare)(Dato A,Dato B)){
  Dato minimo,dato;
  if(existe_siguiente())
    minimo = siguiente_dato();
  while(existe_siguiente()){
    dato = siguiente_dato();
    if(compare(dato,minimo)==PEQUENO)
      minimo = dato;
  }
  reiniciar();
  return minimo;
}

template <class Dato>
Dato Lista<Dato>::maximo(int (*compare)(Dato A,Dato B)){
  Dato maximo,dato;
  if(existe_siguiente())
    maximo = siguiente_dato();
  while(existe_siguiente()){
    dato = siguiente_dato();
    if(compare(dato,maximo)==GRANDE)
      maximo = dato;
  }
  reiniciar();
  return maximo;
}

template <class Dato>
Lista<Dato>* selection_ordenar(Lista<Dato> &list,int (*compare)(const Dato a, const Dato b)){
      Lista<Dato> *nueva = new Lista<Dato>(list);
      for(int i = 0; i < nueva->obtener_tamano(); i++){
        Dato minimo = (*nueva)[i];
        int minimo_index = i;
        for(int j = i+1 ; j < nueva->obtener_tamano() ; j++ ){
          if( compare( (*nueva)[j] , minimo ) == PEQUENO ){
            minimo = (*nueva)[j];
            minimo_index = j;
          }
        }
        nueva->swap(i,minimo_index);
      }
      return nueva;
}

template <class Dato>
Lista<Dato>* quick_ordenar(Lista<Dato> &list,int (*compare)(const Dato a, const Dato b)){
    if(list.obtener_tamano()==0)
      return new Lista<Dato>();
    Lista<Dato> left;
    Lista<Dato> right;
    Dato pivot = list[0];

    for(int i=1;i<list.obtener_tamano();i++){
        if(compare(list[i],pivot)==PEQUENO)
          left.agregar(list[i]);
        else
          right.agregar(list[i]);
    }
  return *(quick_ordenar(left,compare)->expulsar(pivot))+*quick_ordenar(right,compare);
}


#endif
