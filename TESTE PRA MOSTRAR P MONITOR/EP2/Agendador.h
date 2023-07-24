#ifndef AGENDADOR_H
#define AGENDADOR_H

#include "Rede.h"
#include "No.h"
#include "Datagrama.h"
#include <list>
#include <algorithm>

class Agendador{
public:
    Agendador(int instanteInicial, Rede* rede, int tamanho);
    virtual ~Agendador();

    virtual bool agendar(int instante, No* n, Datagrama* d);
    virtual void processar();
    virtual int getInstante();

protected:

private:
    int instanteInicial, tamanho, instanteAtual, quantidadeDeEventos;
    Rede* rede;
    Evento** eventosAgendados;
};

#endif // AGENDADOR_H
