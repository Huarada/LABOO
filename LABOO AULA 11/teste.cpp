// Faca os includes necessarios
#include "Playlist.h"
#include <string>
#include "Artista.h"
#include <iostream>
#include <vector>
#include "Musica.h"
using namespace std;
void teste() {
    // IMPLEMENTE seguindo o enunciado
    Playlist* fav = new Playlist("Favoritos");
    Artista* tom = new Artista("Tom Jobim");


    Musica* agua = new Musica(214,"Aguas de marco");
    agua->avaliar(5);
    agua->avaliar(4);
    agua->avaliar(5);


    tom->adicionarMusica(agua);



    fav->adicionar(agua);




    Musica* ninguem = new Musica(168,"Mais ninguem");
    ninguem->avaliar(3);
    ninguem->avaliar(3);

    fav->adicionar(ninguem);



    Musica *samba = new Musica(180,"Samba de uma nota so");
    samba->avaliar(5);
    samba->avaliar(3);

    tom->adicionarMusica(samba);

    fav->imprimir();
    tom->imprimir();








}
/*
int main() {
    teste();
    return 0;
}
*/
