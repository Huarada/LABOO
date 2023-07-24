#include "TabelaDeRepasse.h"

TabelaDeRepasse::TabelaDeRepasse(int tamanho) {
    this->tamanho = tamanho;
    quantidade = 0;
    roteadoresAdjacentes = new Roteador*[tamanho];
    enderecosDestino = new int[tamanho];
    atrasos = new int[tamanho];
}

TabelaDeRepasse::~TabelaDeRepasse() {
}

bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente, int atraso) {
    if (quantidade >= tamanho) return false; // VETOR CHEIO
    for (int i = 0; i < quantidade; i++) {
        if (enderecosDestino[i] == endereco) return false; // JA TEM ENDERECO NA TABELA
    }
    enderecosDestino[quantidade] = endereco;
    roteadoresAdjacentes[quantidade] = adjacente;
    atrasos[quantidade] = atraso;
    quantidade += 1;
    return true;
}

Roteador** TabelaDeRepasse::getAdjacentes() {
    return roteadoresAdjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
    return quantidade;
}

void TabelaDeRepasse::setPadrao(Roteador* padrao, int atraso) {
    this->padrao = padrao;
    padraoAtraso = atraso;
}

Roteador* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso) {
    for (int i = 0; i < quantidade; i++) {
        if (enderecosDestino[i] == endereco) {
            atraso = atrasos[i];
            return roteadoresAdjacentes[i];
        }
    }
    if (padrao == NULL) {
        atraso = 0;
        return NULL;
    }
    atraso = padraoAtraso;
    return padrao;
}

void TabelaDeRepasse::imprimir() {
}

