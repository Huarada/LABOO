#include "Fila.h"

Fila::Fila(int tamanho) : tamanho(tamanho), quantidade(0), filaAtual(new Datagrama*[tamanho]) {
    if (tamanho <= 0) throw new invalid_argument("Tamanho invalido da fila");
}

Fila::~Fila() {
    for (int i = 0; i < tamanho; i++) delete filaAtual[i];
    delete[] filaAtual;
    // cout << "Fila deletada" << endl;
}

void Fila::enqueue(Datagrama* d) {
    if (quantidade >= tamanho) throw new overflow_error("Overflow da fila");
    filaAtual[quantidade] = d;
    quantidade++;
}

Datagrama* Fila::dequeue() {
    if (quantidade <= 0) throw new underflow_error("Underflow");
    Datagrama* armazena = filaAtual[0];
    for (int i = 0; i < tamanho-1; i++) {
        filaAtual[i] = filaAtual[i+1];
        delete filaAtual[i+1];
    }
    quantidade--;
    return armazena;
}

bool Fila::isEmpty() {
    if (quantidade == 0) return true;
    return false;
}

int Fila::getSize() {
    return quantidade;
}

void Fila::imprimir() {
}
