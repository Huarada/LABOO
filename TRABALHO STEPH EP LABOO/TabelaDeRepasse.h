#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "Roteador.h"

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

protected:

private:
    int tamanho;
    int quantidade;

    Roteador** adjacentes;
    int* enderecos;
    int* atrasos;

    Roteador *padrao;
    int padraoAtraso;
};

#endif // TABELADEREPASSE_H
