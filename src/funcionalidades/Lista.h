#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

const int SMALLER = -1;
const int BIGGER = 1;
const int EQUALS = 0;
const int DONT_FOUND = -1;

//Pre: Dos datos a comparar, con sobrecargas de los operadores "<,>,=="
//Post: Compara y devuelve SMALLER si A es menor que B, BIGGER si A es mayor que B y EQUALS caso contrario
template<class Dato>
int comparacion(Dato A, Dato B){
    if(A==B)
        return EQUALS;
    else if(A>B)
        return BIGGER;
    else
        return SMALLER;
}

template <class Dato>
class Lista
{
	  Nodo<Dato> *start;
		Nodo<Dato> *end;
    Nodo<Dato> *actual;
		unsigned long size;
    
    //Pre: Esta lista actual previamente vacia y una lista por parametro con la informacion a copiar 
    //Post: Carga toda la informacion de la lista del parametro a esta lista actual 
    void copiar_todo(const Lista &list);
    
    //Pre: Lista con datos previamente, para ser eliminimoados.
    //Post: Eliminimoa toda la informacion de la lista, liberando toda la memoria reservada
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
    //Post: Eliminimoa toda la lista
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
    
    //Pre: Un indice a eliminimoar de la lista
    //Post: Devuelve verdadero si fue eliminimoado de la lista, falso caso contrario
    bool borrar(const int index);
    
    //Pre: 
    //Post: Devuelve el tamano de la lista
		int obtener_tamano() const;
		
    //Pre: Un indice a evaluar si esta en el rango valido
    //Post: Devuelve verdadero si puede estar en la lista, falso caso contrario
    bool es_valido(const int index) const;
    
    //Pre: Un dato a evaluar su existencia
    //Post: Devuelve verdadero si se encontro en la lista dicho dato
    bool existe(Dato data, int (*compare)(Dato A , Dato B)) const;
    
    //Pre: El comienzo de la busqueda (puede ser desde el origen: 0), el dato a buscar y una funcion donde me compara dos Datos A y B si son iguales
    //Post: Devuelve la posicion donde encontro dicho dato buscandolo desde el indice de comienzo
    int buscar_dato(int start_search,const Dato data, int (*compare)(Dato A, Dato B)) const;
    
    //Pre: Un indice a buscar en la lista
    //Post: Devuelve una referencia del dato que se encuentra en dicha posicion
		Dato& operator[](const int index) const;
    
    //Pre: Una lista con la informacion a cargar
    //Post: Eliminimoa la informacion que se encontraba antes y copia la informacion de ahora de la lista
		void operator=(Lista &list);
    
    //Pre: Una lista a unir
    //Post: Devuelve un puntero con la lista de la union, eliminimoando la informacion de la lista del parametro
    Lista<Dato>* operator+(Lista &list);
    
    //Pre: Una funcion que permita comparar dos datos
    //Post: Ordena de menor a mayor de acuerdo a la funcion del parametro
    void ordenar(int (*compare)(const Dato a, const Dato b));
    
    //Pre: Esta lista, previamente ordenada y una funcion para la comparacion de datos
    //Post: Eliminimoa todas aquellas ocurrencias repetidas de la lista    
    void limpiar(int (*compare)(const Dato a, const Dato b));

    //Pre: Dos posiciones de la lista
    //Post: Intercambia sus datos en la lista
    void swap(const int index_a, const int index_b);

    //Pre: Una lista para unir
    //Post: Une esta lista con la del parametro, modificandose
    void operator+=(Lista &list);

    //Pre: Una lista para unir
    //Post: Devuelve la union de esta lista con la del parametro, sin modificar esta
    Lista* obtener_union(Lista &lista);
		
    //Pre:
    //Post: Revierte el orden de esta lista, donde el ultimo se encontrara en el primero
    void revertir();

    //Pre:
    //Post: Devuelve un puntero con esta lista revertida, sin modificar esta
    Lista *obtener_revertir();

    //Pre: Recibe una lista con la informacion y una funcion de comparacion entre dos datos (Este método devolvera -1 si A es menor que B; 1, si A es mayor que B; y 0 si son iguales.)
    //Post:se hace un mezclar entre las dos, modificando la original, que tiene que quedar ordenada  y  sin  elementos  repetidos.
    void mezclar(Lista &list, int (*compare)(const Dato A, const Dato B));

    //Pre: Un dato a eliminimoar de la lista y una funcion de comparacion entre dos datos A y B
    //Post: Eliminimoa el dato si lo encontro en la lista basandose en el criterio de la funcion de comparacion
    void borrar_data(const Dato data, int (*compare)(Dato A, Dato B));

    //Pre: Un dato a eliminimoar de la lista y una funcion con el criterio de comparacion entre dos Datos A y B
    //Post: Eliminimoa todos las ocurrencias que encuentra del dato en la lista
    void borrar_todo_occurrences(const Dato data, int (*compare)(Dato A, Dato B));

    //Pre: Una lista cargada y una funcion que me permita comparar dos Datos, A y B
    //Post: Retorna una nueva lista con los datos de esta lista que no esta con la del parametro
    Lista* obtener_diferencia(Lista list , int (*compare)(Dato A, Dato B) );

    //Pre:
    //Post: Pone el puntero a la primera posición o apuntando a NULL
    void reiniciar(void);
    
    //Pre:
    //Post: devuelve true si el actual no apunta a NULL, false de lo contrario
    bool existe_siguiente(void) const;
    
    //Pre: hay_siguiente tiene que haber devuelto true previamente
    //Post: devuelve el elemento actual y avanza
    Dato siguiente_dato(void);

    //Pre: Una lista a analizar y una funcion con el criterio de comparacion
    //Post: Devuelve verdadero si encuentra alguna coincidencia de un dato con la lista del parametro, falso caso contrario
    bool existe_alguno(Lista &lista, int(*compare)(Dato A, Dato B));

    //Pre: Una lista a analizar y una funcion con el criterio de comparacion
    //Post: Devuelve verdadero si encuentra toda coincidencia de los datos con la lista del parametro, falso caso contrario
    bool existen_todos(Lista &lista, int(*compare)(Dato A, Dato B));

    
    //Pre: Una funcion de comparacion de datos que devuelve EQUALS, BIGGER o SMALLER
    //Post: Devuelve el menor elemento de la lista por dicha funcion
    Dato minimo(int(*compare)(Dato A, Dato B));

    //Pre: Una funcion de comparacion de datos que devuelve EQUALS, BIGGER o SMALLER
    //Post: Devuelve el mayor elemento de la lista por dicha funcion
    Dato maximo(int(*compare)(Dato A, Dato B));
};

template <class Dato>
Lista<Dato>::Lista(){
  this->start = new Nodo<Dato>();
  this->end=this->start;
  this->actual=this->start;
  this->size=0;
}

template <class Dato>
Lista<Dato>::Lista(Dato *datos, int tope){
  this->start = new Nodo<Dato>();
  this->end=this->start;
  this->actual=this->start;
  this->size=0;
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
  Nodo<Dato> *nodo = start;
  for(int i=0 ; i < (int)size  ; i++){
      imprimir_data(*nodo->dato);
      nodo = nodo->siguiente;
  }
}

template <class Dato>
void Lista<Dato>::copiar_todo(const Lista &lista){
  this->start = new Nodo<Dato>();
  this->end=this->start;
  this->actual=this->start;
  this->size=0;
  for(int i=0 ; i< lista.obtener_tamano(); i++)
    agregar(lista[i]);
}

template <class Dato>
void Lista<Dato>::agregar(Dato dato){
  *(end->dato)=dato;
  end->siguiente = new Nodo<Dato>();
  end=end->siguiente;
  size+=1;
}

template <class Dato>
Lista<Dato>* Lista<Dato>::expulsar(Dato dato){
  agregar(dato);
  return this;
}

template <class Dato>
void Lista<Dato>::borrar_todo(){
  Nodo<Dato> *tmp;
  while( start!=nullptr ){
    tmp = start;
    start = start->siguiente;
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
    start = borrar_node->siguiente; //Se referencia al que sigue
  else if(borrar_node->siguiente == nullptr){// Si en el que sigue no hay nada, se encuentra al final
    end = before;
    end->siguiente=nullptr;
  }
  else //Se deja de referenciar 
    before->siguiente = borrar_node->siguiente;

  delete borrar_node;
  
  size--;
  return true;
}

template <class Dato>
int Lista<Dato>::obtener_tamano() const{
  return (int)size;
}

template <class Dato>
bool Lista<Dato>::es_valido(const int index) const{
  return index>=0 && index<= (int) size;
}

template <class Dato>
bool Lista<Dato>::existe(Dato dato,int (*compare)(Dato A , Dato B)) const{
  return buscar_dato(0,dato,compare) != DONT_FOUND;
}


template <class Dato>
Nodo<Dato>* Lista<Dato>::buscar_nodo(const int index) const{
  
  if(!es_valido(index))
    return nullptr;

  Nodo<Dato> *nodo = start;
  for(int i=0 ; i < index  ; i++)
    nodo = nodo->siguiente; 	
  
  return nodo;
}

template <class Dato>
int Lista<Dato>::buscar_dato(int start_search,const Dato dato, int (*compare)(Dato A,Dato B)) const{

  Nodo<Dato> *nodo = buscar_nodo(start_search);
  
  if(nodo==nullptr)
    return DONT_FOUND;

  bool found = compare(*(nodo->dato) , dato) == EQUALS;

  while(start_search < (int) size && !found){
    nodo = nodo->siguiente;
    if(nodo!=nullptr)
      found = compare(*(nodo->dato) , dato) == EQUALS;
    start_search++;
  } 	
  return found ? start_search : DONT_FOUND;
}

template <class Dato>
Dato& Lista<Dato>::operator[](const int index) const{
  Nodo<Dato> *nodo = buscar_nodo(index);
  return *(nodo->dato);
}

template <class Dato>
void Lista<Dato>::operator=(Lista &lista){
  borrar_todo();
  copiar_todo(lista);
}
 
template <class Dato>
Lista<Dato>* Lista<Dato>::operator+(Lista &lista){
  *this+=lista;
  lista.borrar_todo();
  return this;
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
  Lista nueva;
  while(existe_siguiente()){
    Dato dato = siguiente_dato();
    if(compare(dato,*(actual->dato))!=EQUALS) 
      nueva.agregar(dato);
  }  
  *this=nueva;
}

//Complejidad O(index_a + index_b)
template <class Dato>
void Lista<Dato>::swap(const int index_a, const int index_b){
  
  if(index_a == index_b) //Mejora el rendimiento de hacer busquedas innecesarias
    return;
  
  Nodo<Dato> *node_a = buscar_nodo(index_a);
  Nodo<Dato> *node_b = buscar_nodo(index_b); 

  if(node_a == nullptr || node_b == nullptr)
    return;

  swap_data( *(node_a->dato), *(node_b->dato) );

}


template <class Dato>
void Lista<Dato>::operator+=(Lista &lista){
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

//Complejidad O( SIZE/2:"ciclo for" + (SIZE^2)/2:"swaps") = O(SIZE^2)
template <class Dato>
void Lista<Dato>::revertir(){

  int middle = int(size/2) - (int)size % 2 == 0 ;
  
  for(int i = 0 ; i<= middle ; i++)
    swap( i , (int)size - i - 1 );
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
void Lista<Dato>::borrar_data(const Dato dato, int (*compare)(Dato A, Dato B)){
  borrar(buscar_dato(0,dato,compare));
}

template <class Dato>
void Lista<Dato>::borrar_todo_occurrences(const Dato dato, int (*compare)(Dato A, Dato B)){
  int start = 0;
  do{
    start = buscar_dato(start,dato,compare);
    borrar(start);
  }while(start!= DONT_FOUND);
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
  actual=start;
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
    if(compare(dato,minimo)==SMALLER)
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
    if(compare(dato,maximo)==BIGGER)
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
          if( compare( (*nueva)[j] , minimo ) == SMALLER ){
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
        if(compare(list[i],pivot)==SMALLER)
          left.agregar(list[i]);
        else
          right.agregar(list[i]);
    }
  return *(quick_ordenar(left,compare)->expulsar(pivot))+*quick_ordenar(right,compare);
}


#endif