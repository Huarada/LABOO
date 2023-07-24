#include <iostream>
#include <stdexcept>

#include "Playlist.h"
#include "SemAvaliacao.h"
Playlist::Playlist(string nome, int maximoValor)
    : nome(nome), maximoValor(maximoValor) {
    if (maximoValor <= 1 || nome == "" ) throw new invalid_argument ("maximoValor invalido");
    musicas = new Musica*[maximoValor];
}

Playlist::~Playlist() {
    delete[] musicas;
}

string Playlist::getNome() {
    return nome;
}

int Playlist::getDuracao() {
    int duracao = 0;
    for (int i = 0; i < quantidadeDeMusicas; i++)
        duracao += musicas[i]->getDuracao();

    return duracao;
}

int Playlist::getQuantidadeDeMusicas() const {
    return quantidadeDeMusicas;
}

Musica **Playlist::getMusicas() {
    return musicas;
}

void Playlist::adicionar(Musica *m) {
    if (quantidadeDeMusicas >= maximoValor) throw new overflow_error ("musicas estourou");


    if (m == nullptr) throw new invalid_argument ("Nulo");


    if (temMusica(m)) throw new invalid_argument (  getNome() + std::string(" ja adicionado"));


    musicas[quantidadeDeMusicas++] = m;

}

double Playlist::getAvaliacaoDasMusicas() const {
    /* IMPLEMENTAR METODO */
    double somadasnotas = 0;
    int notasconsideradas = getQuantidadeDeMusicas();

    for (int i = 0; i <getQuantidadeDeMusicas(); i++){
    int protect = 0;

    try { musicas[i]->getMedia() ; }
    catch(SemAvaliacao *f){
    protect = 1;
    notasconsideradas--;
    delete f;
    }
    if (protect == 0 ){
      somadasnotas = somadasnotas + musicas[i] ->getMedia();


    }
    }

   if (quantidadeDeMusicas == 0 || somadasnotas == 0 )
    return .0;

    else return somadasnotas/notasconsideradas;
}

void Playlist::imprimir() {
    cout << nome << endl;
    for (int i = 0; i < quantidadeDeMusicas; i++) {
        cout << "\t";
        musicas[i]->imprimir();
    }
}

bool Playlist::temMusica(Musica *m) const {
    for (int i = 0; i < quantidadeDeMusicas; i++)
        if (musicas[i] == m)
            return true;

    return false;
}
