#include <iostream>
#include <string>
using namespace std;

#include "Roteador.h"

Roteador::Roteador(int endereco) {
    tabela = new TabelaDeRepasse(TAMANHO); // CRIA UMA TABELA DE REPASSE COM TAMANHO "TAMANHO"
    fila = new Fila(TAMANHO);              // CRIA UMA FILA COM TAMANHO "TAMANHO"
    enderecoRoteador = endereco;
    quantidadeTabela = 0;
}

Roteador::~Roteador() {
    delete tabela;
    delete fila;
    cout << "Roteador destruido" << endl;
}

bool Roteador::mapear(int endereco, Roteador* adjacente, int atraso) {
    tabela->mapear(endereco, adjacente, atraso);
}

void Roteador::setPadrao(Roteador* padrao, int atraso) {
    tabela->setPadrao(padrao, atraso);
}

int Roteador::getEndereco() {
    return enderecoRoteador;
}

void Roteador::receber(Datagrama* d) {
    if (fila->getSize() >= TAMANHO) {
        cout << "\tFila em " << enderecoRoteador << " estourou" << endl;
    }
    else {
        fila->enqueue(d);
    }
}

Evento* Roteador::processar(int instante) {
    if (fila->isEmpty()) return NULL;
    cout << "Roteador " << enderecoRoteador << endl;

    Datagrama* removido = fila->dequeue(); // Armazena o datagrama retornado pelo dequeue

    // Consultando a tabela de repasse
    int atraso;
    Roteador* proxRot = tabela->getProximoSalto(removido->getDestino(), atraso);

    if (removido->getDestino() == enderecoRoteador) { // Mesmo endereco do roteador
        cout << "\tRecebido: " << removido->getDado() << endl;
        delete removido;
        return NULL;
    }
    if (proxRot == NULL) { // Tabela de repasse retorna NULL
        cout << "\tSem proximo: Origem: " << removido->getOrigem();
        cout << ", Destino: " << removido->getDestino() << ", " << removido->getDado() << endl;
        delete removido;
        return NULL;
    }
    else if (proxRot != NULL) { // Tabela de repasse retorna roteador e atraso
        cout << "\tRepassado para " << proxRot->getEndereco() << " (instante " << instante + atraso;
        cout << "): Origem: " << removido->getOrigem() << ", Destino: " << removido->getDestino();
        cout << ", " << removido->getDado() << endl;
        Evento* novo = new Evento(instante + atraso, proxRot, removido);
        return novo;
    }
}

void Roteador::imprimir() {
}
