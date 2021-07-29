#include "Defensa_vampiro.h"

Defensa_vampiro::Defensa_vampiro(Vampiro *personaje):Defensa(personaje){

}
void Defensa_vampiro::defender(Tablero *tablero, int opcion){

    personaje->asignar_energia(personaje->obtener_energia()-4);

    ((Monstruo*)personaje)->ocultar();

    personaje->asignar_armadura(personaje->obtener_armadura()+1);
    
}