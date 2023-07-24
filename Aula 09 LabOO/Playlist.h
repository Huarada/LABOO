#ifndef PLAYLIST_H
#define  PLAYLIST_H

#include <string>

#include "Musica.h"

using namespace std;

class Playlist {
public:
    Playlist(string nome, int maximoValor);
    ~Playlist();

    string getNome();
    int getDuracao();

    int getQuantidadeDeMusicas() const;

    Musica **getMusicas();

    void adicionar(Musica *m);

    double getAvaliacaoDasMusicas() const;

    void imprimir();
private:
    bool temMusica(Musica *m) const;

    string nome;
    int maximoValor;
    Musica **musicas;
    int quantidadeDeMusicas = 0;
};

#endif /* PLAYLIST_H */
