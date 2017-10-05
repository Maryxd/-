#include "rmRef_H.h"
#include <cstddef> //Para utilizar el NULL

rmRef_H::rmRef_H()
{
}

rmRef_H::rmRef_H(int key, int value, int size_)
{
    llave=key;
    valor=value;
    tamano=size_;
    contador=0;
}


void rmRef_H::operator = (rmRef_H elemento2)
{
    llave=elemento2.llave; //falta guardar en la memoria distribuida
}

bool rmRef_H::operator == (rmRef_H elemento2)
{
    return llave==elemento2.llave;
}

bool rmRef_H::operator != (rmRef_H elemento2)
{
    return llave!=elemento2.llave;
}

rmRef_H::~rmRef_H()
{
    //dtor
}
