#include "Rede.h"

Rede::Rede(int tamanho) {
    this->tamanho = tamanho;
    vetorRedes = new Roteador*[tamanho];
    quantidade = 0;
}

Rede::~Rede() {
    for (int i = 0; i < tamanho; i++) delete vetorRedes[i];
    delete[] vetorRedes;
}

bool Rede::adicionar(Roteador* r) {
    if (vetorRedes[tamanho] != NULL) return false; // VETOR CHEIO
    for (int i = 0; i < tamanho; i++) {
        if (vetorRedes[i] == r) return false; // TEM IGUAL
    }
    vetorRedes[quantidade] = r;
    quantidade += 1;
    return true;
}

Roteador* Rede::getRoteador(int endereco) {
    for (int i = 0; i < quantidade; i++) {
        if (vetorRedes[i]->getEndereco() == endereco) return vetorRedes[i];
    }
    return NULL;
}

Roteador** Rede::getRoteadores() {
    return vetorRedes;
}

int Rede::getQuantidade() {
    return quantidade;
}

void Rede::imprimir() {
}
