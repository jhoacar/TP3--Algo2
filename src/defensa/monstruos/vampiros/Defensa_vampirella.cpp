#include "Defensa_vampirella.h"

Defensa_vampirella::Defensa_vampirella(Vampirella *personaje):Defensa_vampiro(personaje){

}
void Defensa_vampirella::defender(Tablero *tablero, int opcion){
    
    personaje->asignar_energia(personaje->obtener_energia()-5);

    ((Monstruo*)personaje)->ocultar();
}