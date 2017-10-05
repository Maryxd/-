#ifndef ENLAZADA_H
#define ENLAZADA_H
#include "Nodo.h"
#include "rmRef_H.h"
#include <cstddef>

using namespace std;

class Lista
{
    public:
        Lista();
        virtual ~Lista();
        int getSize();
        int getPos();
        void goToStart();
        void goToEnd();
        void next();
        void insert(rmRef_H* element); //inserta un elemento en la posición curr
        rmRef_H remove();
        void print();
        void clear();
        void reverse();
        void move(int pos);
        rmRef_H* getValue(int pos);
        void eliminarElemento(int pos);

    protected:
        Nodo* first; //Head
        Nodo* last; //Tail
        Nodo* curr; //Actual
        int size;
        int pos;
};

#endif // ENLAZADA_H
