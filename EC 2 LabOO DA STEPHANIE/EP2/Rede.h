#ifndef REDE_H
#define REDE_H

#include "No.h"
#include "Hospedeiro.h"
#include <list>
#include <algorithm>

using namespace std;

class Rede {
public:
    Rede();
    virtual ~Rede();

    virtual void adicionar(No* n);
    virtual No* getNo(int endereco);
    virtual list<No*>* getNos();
    virtual list<Hospedeiro*>* getHospedeiros();

    virtual void imprimir();

protected:

private:
    list<No*>* nos;
    list<Hospedeiro*>* hospedeiros;
};

#endif // REDE_H
