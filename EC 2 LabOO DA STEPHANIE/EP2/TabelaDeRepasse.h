#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "No.h"

class TabelaDeRepasse {
public:
    TabelaDeRepasse(int tamanho);
    virtual ~TabelaDeRepasse();

    virtual void mapear(int endereco, No* adjacente, int atraso);
    virtual No** getAdjacentes();
    virtual int getQuantidadeDeAdjacentes();

    virtual void setPadrao(No* padrao, int atraso);

    virtual No* getProximoSalto(int endereco, int& atraso);

    virtual void imprimir();

protected:

private:
    No* padraoAtual;
    No** adjacentes;
    int tamanho, atrasoPadrao, quantidade;
    int* enderecos;
    int* atrasos;
};

#endif // TABELADEREPASSE_H
