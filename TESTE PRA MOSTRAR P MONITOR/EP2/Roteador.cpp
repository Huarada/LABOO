#include "Roteador.h"

Roteador::Roteador(int endereco)
    : No(endereco), tabela(new TabelaDeRepasse(TAMANHO_TABELA)) {}

Roteador::Roteador(int endereco, Fila* fila)
    : No(endereco, fila), tabela(new TabelaDeRepasse(TAMANHO_TABELA)) {}

Roteador::~Roteador() {
    delete tabela;
}

void Roteador::mapear(int endereco, No* adjacente, int atraso) {
    tabela->mapear(endereco, adjacente, atraso);
}

void Roteador::setPadrao(No* padrao, int atraso) {
    tabela->setPadrao(padrao, atraso);
}

Evento* Roteador::processar(int instante) {
    if (fila->isEmpty()) return NULL;
    cout << "Roteador " << endereco << endl;
    Datagrama* removido = fila->dequeue();

    // ARRUMAR AS IMPRESSOES
    // 1 - destino do datagrama eh esse roteador
    if (removido->getDestino() == endereco) {
        cout << "\tRecebido: " << removido->getSegmento()->getDado() << endl;
        delete removido;
        return NULL;
    }
    // 2 - destino nao eh esse roteador
    else {
        int atraso;
        No* proximo = tabela->getProximoSalto(removido->getDestino(), atraso);
        cout << "\tRepassado para " << proximo->getEndereco() << " (instante " << instante + atraso << "): ";
        cout << "Origem: " << removido->getOrigem() << ", Destino: " << removido->getDestino() << ", " << removido->getSegmento()->getDado() << endl;
        Evento *novo = new Evento(instante + atraso, proximo, removido);
        return novo;
    }
}
