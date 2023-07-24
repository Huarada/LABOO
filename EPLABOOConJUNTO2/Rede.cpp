#include <iostream>
#include <string>
using namespace std;
#include "Rede.h"

Rede::Rede(int tamanho) {
    quantidade = 0;
    this->tamanho = tamanho;
    vetorRedes = new Roteador*[tamanho];
}

Rede::~Rede() {
    for (int i = 0; i < quantidade; i++) delete vetorRedes[i];
    delete[] vetorRedes;
    cout << "Rede destruida" << endl;
}

bool Rede::adicionar(Roteador* r) {
    if (quantidade >= tamanho) return false;  // VETOR CHEIO
    for (int i = 0; i < quantidade; i++) {
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
