#ifndef USUARIO_H
#define USUARIO_H

#include "Artista.h"

class Usuario {
private:
    string login;
    int maximoFavoritos;
    Artista** favoritos;
    int quantidadeDeFavoritos = 0;
public:
    Usuario(string login, int maximoFavoritos);
    virtual ~Usuario();

    bool adicionar(Artista* favorito);
    Artista** getFavoritos();
    int getQuantidadeDeFavoritos();
    string getLogin();
};

#endif // USUARIO_H
