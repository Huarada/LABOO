#ifndef USUARIO_H
#define USUARIO_H
// Inclua aqui as diretivas de compilacao necessarias
#include <string>
#include "Artista.h"
using namespace std;
class Usuario{
private:
    // Inclua aqui os atributos necessarios
   string login;
   int maximoFavoritos;
   Artista** artistas;
   int quantidadeDeFavoritos ;
public:
    Usuario(string login, int maximoFavoritos);
    ~Usuario();

    string getLogin();
    bool adicionar(Artista* favorito);
    Artista** getFavoritos();
    int getQuantidadeDeFavoritos();

    void imprimir();
};

#endif // USUARIO_H
