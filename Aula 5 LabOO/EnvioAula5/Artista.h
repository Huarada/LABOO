#ifndef ARTISTA_H
#define ARTISTA_H

#include <string>

#include "Musica.h"

using namespace std;

class Artista {
private:
    int quantidadeMaxima;
    string nome;
    Musica** musicas;
    int quantidade;
public:
    Artista(int quantidadeMaxima, string nome);
    ~Artista();

    Musica** getMusicas() const;
    int getQuantidadeMusicas() const;
    int getQuantidadeMaximaMusicas() const;
    string getNome() const;

    bool adicionarMusica(Musica* musica);

    void imprimir();
};

#endif
