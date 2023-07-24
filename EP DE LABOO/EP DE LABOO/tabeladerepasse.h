#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H



#include "roteador.h"

class Roteador;

class TabelaDeRepasse {


public:

TabelaDeRepasse(int tamanho);

~TabelaDeRepasse();

bool mapear(int endereco, Roteador* adjacente, int atraso);

Roteador** getAdjacentes();

int getQuantidadeDeAdjacentes();

void setPadrao(Roteador* padrao, int atraso);

Roteador* getProximoSalto(int endereco, int& atraso);

void imprimir();


private:
int tamanho;

int* enderecos;

Roteador** adjacente;

int* atrasos;

int quantidade;


Roteador* padrao;
int atraso_padrao;

};

#endif  // TABELADEREPASSE_H

