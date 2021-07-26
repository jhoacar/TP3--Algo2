#include "Defensa.h"
#include "../objetos/seres/Ser.h"

Defensa::Defensa(Ser *personaje){
    this -> personaje = personaje;
}
Defensa::~Defensa(){
}

bool Defensa::validar_energia(int minimo) {

    bool energia_suficiente = false;
    int energia = personaje ->devolver_energia();

    if(energia >= minimo)
        energia_suficiente = true;

    return energia_suficiente;
}