#include "Nodo.h"
#include <cstddef>
using namespace std;

Nodo::Nodo(rmRef_H* value, Nodo* next)
{
    ///Constructor
    this->value = value;
    this->next = next;
}

Nodo::Nodo(Nodo* next)
{
    ///Constructor
    this->next = next;
}

Nodo::~Nodo()
{
    ///Destructor
    //dtor
}

rmRef_H* Nodo::getValue()
{
    ///Retorna el valor del nodo actual
    return value;
}

Nodo* Nodo::getNext()
{
    ///Apunta al siguiente nodo
    return next;
}

void Nodo::setNext(Nodo* nodo)
{
    ///Apunta al nuevo nodo
    next = nodo;
}
