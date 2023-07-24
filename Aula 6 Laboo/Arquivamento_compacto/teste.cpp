// Faca os includes necessarios
#include "Artista.h"
#include "Banda.h"
#include "Musica.h"
#include "Usuario.h"
#include <iostream>
#include <string>

void teste() {

 /*
   Artista* artista =  new Banda ( 20 , 5 ,"Snarky Puppy"  );
   Musica*  musica =   new Musica(645, "Lingus");
   artista->adicionarMusica(musica);
   Musica*  musica1 =  new Musica(343, "Tio Macaco");
   artista->adicionarMusica(musica1);

   Banda* banda = static_cast<Banda*> (artista);
   banda->imprimir();

   delete artista;

*/

 /* Teste 2*/

        Artista* artista1 = new Artista (2,"Elis Regina");
        Musica* musica1  = new Musica(162 , "Tiro ao alvaro");
        artista1->adicionarMusica(musica1);

        Musica* musica2 = new Musica(162, "Triste" );
        artista1->adicionarMusica(musica2);


         Banda* banda1 = new Banda(20, 20, "Snarky Puppy" );

         Musica* musica3 = new Musica(645, "Lingus" );
         banda1->adicionarMusica(musica3);


         Musica*    musica4 = new Musica(343, "Tio Macaco" );
         banda1 ->adicionarMusica(musica4);


         Artista* temp = (Artista*) (banda1) ;

            Usuario* usuaria = new Usuario("MAE", 2 );
            usuaria->adicionar(artista1);
            usuaria->adicionar(temp);


            usuaria->imprimir();


           delete usuaria;
           delete artista1;
           delete temp;




}

/*
int main() {
    teste();

    return 0;
}
*/

