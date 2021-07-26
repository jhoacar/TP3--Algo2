#include "Defensa_vampirella.h"


Defensa_vampirella::Defensa_vampirella(Vampirella *personaje):Defensa_vampiro(personaje){
}


void Defensa_vampirella::defender() {

    personaje ->regenerar_vida_defensa(20);
    ((Vampirella* )personaje) -> convertir_en_murcielago();

}