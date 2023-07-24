#ifndef ARTISTA_H
#define  ARTISTA_H

#include <string>

#include "Musica.h"

using namespace std;

class Artista {
private:
    int quantidadeMaxima, quantidadeDeMusicas;
    string nome;
    Musica** musicas;
public:
    Artista(int quantidadeMaxima, string nome);
    virtual ~Artista();

    Musica** getMusicas();
    int getQuantidadeDeMusicas();
    int getQuantidadeMaxima();

    string getNome();

    virtual double getNota();

    bool adicionarMusica(Musica* musica);

    virtual void imprimir() = 0;
};

#endif /* ARTISTA_H */
