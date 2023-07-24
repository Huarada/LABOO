#include <iostream>
#include "Artista.h"

Artista::Artista(int quantidadeMaxima, string nome) : quantidadeMaxima(quantidadeMaxima), nome(nome) {
    musicas = new Musica*[quantidadeMaxima];
    quantidadeDeMusicas = 0;
}

Artista::~Artista() {
    cout << "Artista com " << quantidadeDeMusicas << " musica(s) destruido" << endl;
    for(int i = 0; i < quantidadeDeMusicas; i++) delete musicas[i];
    delete[] musicas;
}

Musica** Artista::getMusicas() const {
    return musicas;
}

int Artista::getQuantidadeDeMusicas() const {
    return quantidadeDeMusicas;
}

int Artista::getQuantidadeMaximaMusicas() const {
    return quantidadeMaxima;
}

string Artista::getNome() const {
    return nome;
}

bool Artista::adicionarMusica(Musica* musica) {
    if (quantidadeDeMusicas >= quantidadeMaxima)
        return false;

    musicas[quantidadeDeMusicas++] = musica;
    return true;
}

void Artista::imprimir() {
    cout << getNome() << endl;
    for (int i = 0; i < quantidadeDeMusicas; i++) {
        cout << "\t";
        musicas[i]->imprimir();
    }
}
