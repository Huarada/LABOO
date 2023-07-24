// Faca os includes necessarios
#include <iostream>
#include    "Musica.h"
#include    "Artista.h"
void teste() {

    // IMPLEMENTE seguindo o enunciado
        Musica *musica0 = new Musica(162, "Tiro ao alvaro");


        Musica  *musica1 = new Musica(162, "Triste");

        Musica  *musica2 = new Musica(214, "Aguas de marco");

        Musica  *musica3= new Musica(228, "Bala com bala");

        Artista *artista =new Artista(23,"Elis Regina");


        artista->adicionarMusica(musica0 );
        artista->adicionarMusica(musica1 );
        artista->adicionarMusica(musica2 );
        artista->adicionarMusica(musica3 );





      delete artista;
}
/*
int main() {
    teste();
    return 0;
}

*/
