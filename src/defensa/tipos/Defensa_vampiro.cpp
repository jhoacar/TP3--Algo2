#include "Defensa_vampiro.h"


Defensa_vampiro::Defensa_vampiro(Vampiro *personaje):Defensa(personaje){
}


void Defensa_vampiro::defender() {

    personaje ->regenerar_vida_defensa(20);
    ((Vampiro* )personaje) ->ocultarse();

}
