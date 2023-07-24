#include "Agendador.h"

Agendador::Agendador(int instanteInicial, Rede* rede, int tamanho) {
    this->instanteInicial = instanteInicial;
    this->rede = rede;
    this->tamanho = tamanho;
    eventos = new Evento*[tamanho];
    quantidade = 0;
}

Agendador::~Agendador() {
}

bool Agendador::agendar(int instante, Roteador* r, Datagrama* d) {
    if (eventos[tamanho] != NULL) return false;

    Evento* novo = new Evento(instante, r, d);
    eventos[quantidade] = novo;
    quantidade += 1;
    return true;
}

void Agendador::processar() {

}
