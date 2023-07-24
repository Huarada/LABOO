#include <iostream>

#include "Usuario.h"

Usuario::Usuario(string login, int maximoFavoritos) : login(login), maximoFavoritos(maximoFavoritos) {
  favoritos = new Artista*[maximoFavoritos];
}

Usuario::~Usuario() {
  delete[] favoritos;
}

Artista** Usuario::getFavoritos() {
  return favoritos;
}

int Usuario::getQuantidadeDeFavoritos() {
  return quantidadeDeFavoritos;
}

string Usuario::getLogin() {
  return login;
}

bool Usuario::adicionar(Artista* favorito) {
  for (int i = 0; i < quantidadeDeFavoritos; i++)
    if (favoritos[i] == favorito)
      return false;
  if (quantidadeDeFavoritos >= maximoFavoritos)
    return false;
  favoritos[quantidadeDeFavoritos++] = favorito;
  return true;
}
