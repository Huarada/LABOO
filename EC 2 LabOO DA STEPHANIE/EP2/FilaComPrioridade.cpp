#include "FilaComPrioridade.h"

FilaComPrioridade::FilaComPrioridade(int tamanho) : Fila (tamanho), ultimoPrioritario(0) {
    if (tamanho <= 0) throw new invalid_argument("Tamanho invalido da fila com prioridade");
}

FilaComPrioridade::~FilaComPrioridade() {
    for (int i = 0; i < tamanho; i++) delete filaAtual[i];
    delete[] filaAtual;
}

void FilaComPrioridade::enqueue(Datagrama* d, bool prioritario) {
    if (quantidade >= tamanho) throw new overflow_error("Overflow da fila com prioridade");

    if (prioritario) {
        for (int i = quantidade; i > ultimoPrioritario; i--) filaAtual[i+1] = filaAtual[i];
        filaAtual[ultimoPrioritario] = d;
        ultimoPrioritario++;
        quantidade++;
    }
    else {
        enqueue(d);
    }
}
