#ifndef DEFENSA_H
#define DEFENSA_H

class Ser;

class Defensa{

    protected:
        Ser *personaje;
    public:
        Defensa(Ser *personaje);
        ~Defensa();
        virtual void defender()=0;
};
#endif