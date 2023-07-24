#include "TabelaDeRepasse.h"

TabelaDeRepasse::TabelaDeRepasse(int tamanho)
    : tamanho(tamanho), padraoAtual(NULL), atrasoPadrao(0), quantidade(0),
    enderecos(new int[tamanho]), adjacentes(new No*[tamanho]), atrasos(new int[tamanho]) {

    if (tamanho <= 0) throw new invalid_argument("Tamanho da tabela invalido");
}

TabelaDeRepasse::~TabelaDeRepasse() {
    delete[] enderecos;
    delete[] adjacentes;
    delete[] atrasos;
}

void TabelaDeRepasse::mapear(int endereco, No* adjacente, int atraso) {
    if (quantidade >= tamanho) throw new overflow_error("Quantidade de enderecos da tabela estourou");
    for (int i = 0; i < tamanho; i++) {
        if (endereco == enderecos[i]) throw new invalid_argument("Ja tem endereco na tabela");
    }
    enderecos[quantidade] = endereco;
    adjacentes[quantidade] = adjacente;
    atrasos[quantidade] = atraso;
    quantidade++;
}

No** TabelaDeRepasse::getAdjacentes() {
    return adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
    return quantidade;
}

void TabelaDeRepasse::setPadrao(No* padrao, int atraso) {
    padraoAtual = padrao;
    atrasoPadrao = atraso;
}

No* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso) {
    for (int i = 0; i < quantidade; i++) {
        if (endereco == enderecos[i]) {
            atraso = atrasos[i];
            return adjacentes[i];
        }
    }
    atraso = atrasoPadrao;
    return padraoAtual;
}

void TabelaDeRepasse::imprimir() {

}
