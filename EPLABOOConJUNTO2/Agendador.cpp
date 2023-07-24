#include "Agendador.h"

Agendador::Agendador(int instanteInicial, Rede* rede, int tamanho) {
    this->instanteInicial = instanteInicial;
    this->rede = rede;
    this->tamanho = tamanho;
    instanteAtual = instanteInicial;
    eventosAgendados = new Evento*[tamanho];
    quantidade = 0;
}

Agendador::~Agendador() {
    for (int i = 0; i < tamanho; i++) delete eventosAgendados[i];
    delete[] eventosAgendados;
}

bool Agendador::agendar(int instante, Roteador* r, Datagrama* d) {
    if (quantidade >= tamanho) return false;
    Evento* novo = new Evento(instante, r, d);
    eventosAgendados[quantidade] = novo;
    quantidade += 1;
    return true;
}

void Agendador::processar() {
    for (int i = 0; i < quantidade; i++) {
        if (eventosAgendados[i]->getInstante() == instanteAtual) {
            eventosAgendados[i]->getDestino()->receber(eventosAgendados[i]->getDatagrama());

            for(int j = i;j < quantidade -1; j++){
                eventosAgendados[j] = eventosAgendados[j+1];
            }

            quantidade -= 1;
            delete eventosAgendados[i];
        }
    }
    for (int i = 0; i < rede->getQuantidade()-1; i++) {
        if(rede->getRoteadores()[i]->processar(instanteAtual) != NULL){
        eventosAgendados[quantidade -1]= rede->getRoteadores()[i]->processar(instanteAtual);
        quantidade = quantidade + 1;
        }

    }
    instanteAtual += 1;
}

int Agendador::getInstante() {
    return instanteInicial;
}
