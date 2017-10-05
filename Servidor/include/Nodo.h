#ifndef NODO_H
#define NODO_H
#include <cstddef> //Para que funcione el Null
#include "rmRef_H.h"

using namespace std;

class Nodo
{
    public:
        Nodo(rmRef_H* value, Nodo* next=NULL);
        Nodo(Nodo* next=NULL);
        virtual ~Nodo();
        rmRef_H* getValue();
        Nodo* getNext();
        void setNext(Nodo* nodo);

    private:
        rmRef_H* value;
        Nodo* next; //Apunta a una instancia de la clase Nodo
};

#endif // NODo_H
