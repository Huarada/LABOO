#ifndef ARTISTA_H
#define ARTISTA_H
#include <string>
#include "Musica.h"

using namespace std;

class Artista {
protected:
    int quantidadeMaxima;
    string nome;
private:
    Musica** musicas;
    int quantidadeDeMusicas;

    int getIndice(Musica* musica);
public:
    Artista(int quantidadeMaxima, string nome);
    virtual ~Artista();

    Musica** getMusicas() const;
    int getQuantidadeDeMusicas() const;
    int getQuantidadeMaximaMusicas() const;
    string getNome() const;

    bool adicionarMusica(Musica* musica);

    void imprimir();
};

#endif // ARTISTA_H
