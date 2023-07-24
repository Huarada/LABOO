#ifndef AGENDADOR_H
#define AGENDADOR_H

#include "Rede.h"
#include "Evento.h"

class Agendador {
public:
    Agendador(int instanteInicial, Rede* rede, int tamanho);
    ~Agendador();
    bool agendar(int instante, Roteador* r, Datagrama* d);
    void processar();
    int getInstante();

private:
    int instanteInicial, instanteAtual, tamanho, quantidade;
    Rede* rede;
    Evento** eventosAgendados;
};

#endif // AGENDADOR_H
