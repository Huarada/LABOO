#ifndef PASSAPORTE_H
#define PASSAPORTE_H

#include <string>
#include "Vacina.h"
#include <vector>
using namespace std;

// NAO ALTERE
#define MAXIMO_VACINAS 3

class Passaporte{
public:
    Passaporte(string nome);
    virtual ~Passaporte();
    virtual string getNome();
    virtual bool aplicaVacina(Vacina* v, int dataAplicacao);
    virtual Vacina** getVacinas();
    virtual int* getDataAplicacoes();
    virtual int getQuantidadeVacinas();
    virtual void imprimir();
private:
    string nome;
    int quantidade = 0;
    vector<Vacina*>* vacinas;
    vector<int>* aplicacoes;
};

#endif // PASSAPORTE_H
