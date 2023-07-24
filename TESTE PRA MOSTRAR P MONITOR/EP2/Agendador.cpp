#include "Agendador.h"

Agendador::Agendador(int instanteInicial, Rede* rede, int tamanho)
    : instanteInicial(instanteInicial), rede(rede), tamanho(tamanho) {
    eventosAgendados = new Evento*[tamanho];
    quantidadeDeEventos = 0;
    instanteAtual = instanteInicial;
    for (int i = 0; i < quantidadeDeEventos; i++) { // TESTE
        eventosAgendados[i] = NULL;
    }
}

Agendador::~Agendador() {
    for (int i = 0; i < tamanho; i++) delete eventosAgendados[i];
    delete[] eventosAgendados;
}

bool Agendador::agendar(int instante, No* n, Datagrama* d) {
    Evento *e = new Evento(instante, n, d);
    if (quantidadeDeEventos >= tamanho) return false;
    for (int i = 0; i < quantidadeDeEventos; i++) {
        if (eventosAgendados[i] == NULL) {
            eventosAgendados[i] = e;
            quantidadeDeEventos++;
            return true;
        }
    }
    /*
    eventosAgendados[quantidadeDeEventos] = e;
    quantidadeDeEventos++;
    return true;
    */
}

void Agendador::processar() {
    // 1 - EVENTOS NO INSTANTE RECEBIDOS PELOS ROTEADORES
    for (int i = 0; i < tamanho; i++) {
        if (eventosAgendados[i]->getInstante() == instanteAtual) {
            list<No*>::iterator a = find(rede->getNos()->begin(), rede->getNos()->end(), eventosAgendados[i]->getDestino());
            (*a)->receber(eventosAgendados[i]->getDatagrama());
            quantidadeDeEventos--;
            delete eventosAgendados[i];
            eventosAgendados[i] = NULL; // TESTE
        }
    }
    // 2 - CHAMANDO PROCESSAR DE TODOS OS ROTEADORES E HOSPEDEIROS
    list<No*>::iterator e = rede->getNos()->begin();
    while (e != rede->getNos()->end()) {
        Hospedeiro *h1 = dynamic_cast<Hospedeiro*>(*e);
        Roteador *r1 = dynamic_cast<Roteador*>(*e);
        if (h1 != NULL && r1 == NULL) {
            Evento *eh1 = h1->processar(instanteAtual);
            agendar(eh1->getInstante(), eh1->getDestino(), eh1->getDatagrama());
        } else if (r1 != NULL && h1 == NULL) {
            Evento *er1 = r1->processar(instanteAtual);
            agendar(er1->getInstante(), er1->getDestino(), er1->getDatagrama());
        }
        e++;
    }
    // 3 - O TEMPO PASSOU
    instanteAtual++;
}

int Agendador::getInstante() {
    return instanteAtual;
}
