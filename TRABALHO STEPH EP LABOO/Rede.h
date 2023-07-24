#ifndef REDE_H
#define REDE_H

#include "Roteador.h"

class Rede {
public:
    Rede(int tamanho);
    ~Rede();
    bool adicionar(Roteador* r);
    Roteador* getRoteador(int endereco);
    Roteador** getRoteadores();
    int getQuantidade();
    void imprimir();

protected:

private:
    int tamanho;
    int quantidade;
    Roteador** vetorRedes;
};

#endif // REDE_H
