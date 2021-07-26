#include "Defensa_humano.h"



Defensa_humano::Defensa_humano(Humano *humano):Defensa(humano){
    
    cantidad_agua = 0;
    cantidad_cruces = 0;

    Lista<Objeto*> aguas_totales  = humano->obtener_inventario().filtrar_datos(0,es_agua);
    Lista<Objeto*> cruces_totales = humano->obtener_inventario().filtrar_datos(0,es_cruz);



}