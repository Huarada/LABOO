#include <iostream>
#include <stdexcept>
#include <vector>
#include "Playlist.h"

using namespace std;

Playlist::Playlist(string nome)
    : nome(nome) {

    musicvec = new vector <Musica *>();

    if (nome.empty())
        throw new invalid_argument("Playlist Com Nome Vazio");
}

Playlist::~Playlist() {
    delete[] musicvec;
}

string Playlist::getNome() {
    return nome;
}

int Playlist::getDuracao() {
    int duracao = 0;
    for (int i = 0; i < musicvec ->size(); i++)
        duracao +=(* musicvec)[i]->getDuracao();

    return duracao;
}



vector<Musica*>* Playlist::getMusicas() {
    return musicvec;
}

void Playlist::adicionar(Musica *m) {

    if (m == nullptr)
        throw new invalid_argument("Ponteiro de Musica invalido!");

    if (temMusica(m))
        throw new invalid_argument("Musica repetida adicionada à Playlist!");


    musicvec->push_back(m);





}

double Playlist::getAvaliacaoDasMusicas() const {
    double soma = 0;
    int numeroMusicas = 0;
    for (int i = 0; i < musicvec->size(); i++) {
        try {
            soma += (*musicvec)[i]->getMedia();
            numeroMusicas++;
        } catch (invalid_argument*) {}
    }

    return soma / numeroMusicas;
}

void Playlist::imprimir() {
    cout << "Playlist " << nome << " - duracao " << getDuracao() << " - media " << getAvaliacaoDasMusicas() << endl;
    for (int i = 0; i < musicvec->size(); i++) {
        cout << "\t";
        (*musicvec)[i]->imprimir();
    }
}

bool Playlist::temMusica(Musica *m) const {
    for (int i = 0; i < musicvec->size(); i++)
        if ((*musicvec)[i] == m)
            return true;

    return false;
}
