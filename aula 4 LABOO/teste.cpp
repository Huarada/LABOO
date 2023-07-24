#include "Musica.h"
#include <iostream>
#include <string>
#include "Playlist.h"




/**
 * Implementar a funcao teste
**/
void teste() {
    // IMPLEMENTE seguindo o enunciado
    Musica *roses = new Musica;
    roses -> setNome("Roses");
    roses -> setDuracao(180);

    roses -> avaliar(3);
    roses -> avaliar(3);
    roses -> avaliar(1);





    Musica *over = new Musica;
    over -> setNome("Overdue");
    over -> setDuracao(210);

    over-> avaliar(1);
    over-> avaliar(5);
    over-> avaliar(4);

    Playlist *estrangeiras = new Playlist;
    estrangeiras -> setNome ("Estrangeiras");
    estrangeiras -> adicionar(roses);
    estrangeiras -> adicionar (over);

    estrangeiras -> imprimir();
}



  int main() {
    teste();
    return 0;
}

