#ifndef ROTEADORCOMQOS_H
#define ROTEADORCOMQOS_H

#include "Roteador.h"
#include "FilaComPrioridade.h"
#include <vector>

using namespace std;

class RoteadorComQoS : public Roteador {
public:
    RoteadorComQoS(int endereco);
    virtual ~RoteadorComQoS();

    virtual void priorizar(int destino);
    virtual vector<int>* getDestinosPriorizados();

    void receber(Datagrama* d);
protected:

private:
    FilaComPrioridade* filaPrioridade;
    vector<int>* prioritarios;
};

#endif // ROTEADORCOMQOS_H
