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

protected:

private:
    int instanteInicial;
    int tamanho;
    int quantidade;
    Rede* rede;
    Evento** eventos;
};

#endif // AGENDADOR_H
