#include <iostream>

#include "Artista.h"

// IMPLEMENTE O CONSTRUTOR E O DESTRUTOR
Artista::~Artista() {
    cout << this->nome <<" com " << quantidade << "  musica(s) destruido" <<endl;
}
Artista:: Artista(int quantidadeMaxima, string nome) {

    //  Musica **musicas = new Musica*[quantidadeMaxima];
        this->musicas = new Musica*[quantidadeMaxima];
        this->musicas = musicas;
        this->nome = nome;
        this->quantidadeMaxima = quantidadeMaxima;
        this->quantidade =0;


}

Musica** Artista::getMusicas() const {
    return musicas;
}

int Artista::getQuantidadeMusicas() const {
    return quantidade;
}

int Artista::getQuantidadeMaximaMusicas() const {
    return quantidadeMaxima;
}

string Artista::getNome() const {
    return nome;
}

bool Artista::adicionarMusica(Musica* musica) {
    if (quantidade >= quantidadeMaxima)
        return false;

    musicas[quantidade++] = musica;
    return true;
}

void Artista::imprimir() {
    cout << getNome() << endl;
    for(int i = 0; i < quantidade; i++) musicas[i]->imprimir();
}
