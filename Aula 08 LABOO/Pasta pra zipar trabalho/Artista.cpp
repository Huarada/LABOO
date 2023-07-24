#include "Artista.h"
#include <iostream>

Artista::Artista(int quantidadeMaxima, string nome) : quantidadeMaxima(quantidadeMaxima), nome(nome){
    musicas = new Musica*[quantidadeMaxima];
    quantidadeDeMusicas = 0;
}

Artista::~Artista(){
}

Musica** Artista::getMusicas(){
    return musicas;
}

int Artista::getQuantidadeDeMusicas(){
    return quantidadeDeMusicas;
}

int Artista::getQuantidadeMaxima(){
    return quantidadeMaxima;
}

string Artista::getNome(){
    return nome;
}

double Artista::getNota(){
    double soma = 0;
    for(int i = 0; i < quantidadeDeMusicas; i++) soma += musicas[i]->getMedia();
    return (soma/quantidadeDeMusicas);
}

bool Artista::adicionarMusica(Musica* musica){
    if(quantidadeDeMusicas >= quantidadeMaxima) return false;
    for(int i = 0; i < quantidadeDeMusicas; i++){
        if(musicas[i] == musica) return false;
    }
    musicas[quantidadeDeMusicas++] = musica;
    return true;
}


