#include "Agendador.h"

Agendador::Agendador(int instanteInicial, Rede* rede, int tamanho)
    : instanteInicial(instanteInicial), rede(rede), tamanho(tamanho) {
    eventosAgendados = new Evento*[tamanho];
    quantidadeDeEventos = 0;
    instanteAtual = instanteInicial;
}

Agendador::~Agendador() {
    for (int i = 0; i < tamanho; i++) delete eventosAgendados[i];
    delete[] eventosAgendados;
}

bool Agendador::agendar(int instante, No* n, Datagrama* d) {
    Evento *e = new Evento(instante, n, d);
    if (quantidadeDeEventos >= tamanho) return false;
    eventosAgendados[quantidadeDeEventos] = e;
    quantidadeDeEventos++;
    return true;
}

void Agendador::processar() {
    // 1
    for (int i = 0; i < tamanho; i++) {
        if (eventosAgendados[i]->getInstante() == instanteAtual) {
            list<No*>::iterator a = find(rede->getNos()->begin(), rede->getNos()->end(), eventosAgendados[i]->getDestino());
            (*a)->receber(eventosAgendados[i]->getDatagrama());
            quantidadeDeEventos--;
            delete eventosAgendados[i];
        }
    }
    // 2
    for (int i = 0; i < rede->getNos()->size(); i++) {
        //rede->getNos()[i]->processar()
    }
    // 3
    instanteAtual++;
}

int Agendador::getInstante() {
    return instanteAtual;
}
