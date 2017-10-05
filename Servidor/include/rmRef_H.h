#ifndef RMREF_H_H
#define RMREF_H_H


class rmRef_H
{
    public:
        rmRef_H();
        rmRef_H(int key, int value, int size_);
        virtual ~rmRef_H();
        char llave;
        int valor;
        int tamano;
        int contador;
        char* ptr;
        void operator = (rmRef_H elemento2);
        bool operator == (rmRef_H elemento2);
        bool operator != (rmRef_H elemento2);
    protected:
    private:
};

#endif // RMREF_H_H
