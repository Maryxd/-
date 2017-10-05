#include <iostream>
#include "rmlib.h"
#include "rmRef_H.h"

using namespace std;


int puerto;
int puerto2;

int main()
{

    cout<<"ingrese puerto1: ";
    cin>>puerto;
    cout<<"ingrese puerto2: ";
    cin>>puerto2;
    rm_init("127.0.0.1",puerto,"127.0.0.1",puerto2);

    return 0;
}
