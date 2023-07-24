#ifndef SEGMENTO_H
#define SEGMENTO_H

using namespace std;
#include <string>
#include <iostream>

class Segmento {
public:
    Segmento(int portaDeOrigem, int portaDeDestino, string dado);
    virtual ~Segmento();

    virtual int getPortaDeOrigem();
    virtual int getPortaDeDestino();
    virtual string getDado();

    virtual void imprimir();

protected:

private:
    int portaDeOrigem, portaDeDestino;
    string dado;
};

#endif // SEGMENTO_H
