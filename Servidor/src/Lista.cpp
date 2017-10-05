#include "Lista.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
using namespace std;
Lista::Lista()
{
    ///Constructor
    first = new Nodo();
    last = first;
    curr = first;
    size = 0;
}

Lista::~Lista()
{
    ///Destructor
    clear();
}

int Lista::getSize()
{
    ///Retorna el tamaño de la lista
    return size;
}

int Lista::getPos()
{
    ///Retorna la posicion actual de la lista
    return pos;
}

void Lista::goToStart()
{
    ///Se mueve al inicio de la lista
    curr = first;
}

void Lista::goToEnd()
{
    ///Se mueve al final de la lista
    curr = last;
}

void Lista::next()
{
    ///Moverse a la siguiente posicion
    curr = curr->getNext();
    pos++;
}

void Lista::insert(rmRef_H* element)
{
    ///Inserta un elemento
    Nodo* newNode = new Nodo(element, NULL);
    newNode->setNext(first);
    first=newNode;
    size++;
}




void Lista::print()
{
    ///Imprime la lista
    goToStart();

    for(int i=0; i<size; i++)
    {
        curr = curr->getNext();
        cout << curr->getValue()->valor << " ";
    }

    cout << endl;
}

void Lista::clear()
{
    ///Limpia la lista
    goToStart();

    for(int i=0; i<size; i++)
    {
        Nodo* temp = curr;
        next();
        delete temp;
    }

    first = new Nodo();
    last = first;
    curr = first;
    size = 0;
    pos = 0;
}



void Lista::move(int pos)
{
    ///Mueve curr a cualquier posicion
    goToStart();
    this->pos = pos;

    if(pos>size)
    {
        throw runtime_error("La posicion esta fuera de la lista");
    }

    for(int i=0; i!=pos; i++)
    {
        next();
    }
}

rmRef_H* Lista::getValue(int pos)
{
    ///Retorna el valor del elemento
    move(pos);
    return curr->getValue();
}


void Lista::eliminarElemento(int pos){
    cout<< "GGGGG" << endl;
    Nodo* temp;
    if (pos==0){
        first=first->getNext();
        cout<< "JOOOJ" << endl;
        size--;

    }

    if (pos==size-1){
        cout<< "JPPPPJ" << endl;
        move(pos-1);
        curr->setNext(NULL);
        size--;

    }

    if(pos>0 & pos<size){
    cout<< "JJJJ" << endl;
        move(pos-1);
        temp=curr->getNext();
        curr->setNext(temp->getNext());
        size--;
    }

}
