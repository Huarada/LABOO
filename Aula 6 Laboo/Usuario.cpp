#include "Usuario.h"
#include <iostream>
#include "Artista.h"
using namespace std;

// Implemente aqui os metodos necessarios

// Metodos ja implementados



void Usuario::imprimir() {
  cout << "Usuario(a) " << this->getLogin()  << " com " << this->getQuantidadeDeFavoritos() << " favoritos:" << endl;
  for (int i = 0; i < this->getQuantidadeDeFavoritos(); i++) {
    cout << "Favorito " << i + 1 << ": ";
    this->getFavoritos()[i]->imprimir();
    cout << "\n";
  }
}

Usuario::Usuario( string login, int maximoFavoritos)  {
    this -> login = login;
    this -> maximoFavoritos = maximoFavoritos;
    artistas = new Artista*[maximoFavoritos];

}

string Usuario::getLogin(){

 return login;
}


Artista** Usuario::getFavoritos(){


return artistas;

}




bool Usuario::adicionar(Artista* favorito){
    int z = 0;

    while (quantidadeDeFavoritos < maximoFavoritos && z <= quantidadeDeFavoritos ){
        if ( artistas[z] == favorito){
            return false;
        }
        z = z + 1;
    }


    if ( quantidadeDeFavoritos >= maximoFavoritos){

        return false; }

    else {


    artistas[quantidadeDeFavoritos] = favorito;
    quantidadeDeFavoritos = quantidadeDeFavoritos + 1;
    return true;

    }


}





int Usuario::getQuantidadeDeFavoritos(){


return quantidadeDeFavoritos;

}




Usuario::~Usuario(){

for(int j = 0; j < getQuantidadeDeFavoritos(); j++) delete artistas[j];
delete[] artistas;




}
