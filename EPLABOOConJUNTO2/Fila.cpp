#include "Fila.h"

Fila::Fila(int tamanho) {
    this->tamanho = tamanho;
    tamanhoFila = 0;
    vetorFila = new Datagrama*[tamanho];
}

Fila::~Fila() {
    for (int i = 0; i < tamanhoFila; i++) delete vetorFila[i];
    delete[] vetorFila;
    cout << "Fila deletada" << endl;
}

bool Fila::enqueue(Datagrama* d) {
    if (tamanhoFila >= tamanho) return false; // OVERFLOW
    vetorFila[tamanhoFila] = d;
    tamanhoFila += 1;
    return true;
}

Datagrama* Fila::dequeue() {
    if (tamanhoFila <= 0) return NULL; // UNDERFLOW

    Datagrama* armazena1 = vetorFila[0];
    for (int i = 0; i < tamanho-1; i++) {
        vetorFila[i] = vetorFila[i+1]; // Reorganiza a fila
    }
    vetorFila[tamanho] = NULL;
    tamanhoFila -= 1;
    return armazena1;
}

bool Fila::isEmpty() {
    if (tamanhoFila == 0) return true;
    return false;
}

int Fila::getSize() {
    return tamanhoFila;
}

void Fila::imprimir() {
}
