#include "rmlib.h"

ib::rmlib()
{
    //ctor
}

void rmlib::rm_delete(rmRef_H* handler)
{
    delete handler;
}

rmlib::~rmlib()
{
    //dtor
}
