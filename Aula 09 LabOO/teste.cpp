// Faca os includes necessarios
#include <iostream>
#include <stdexcept>
#include <string>

#include "Playlist.h"
#include "Musica.h"
#include "SemAvaliacao.h"
using namespace std;
void teste() {
    // IMPLEMENTE seguindo o enunciado


/* // Implementacao 1

    try {

    Playlist *p1 = new Playlist("Favoritos", 2) ;
    }
     catch (invalid_argument *a){
     cout << a -> what() << endl;
     delete a;
    }


    try {
      Playlist *p2 = new Playlist("", 4); }

      catch ( invalid_argument *b) {
          cout << b -> what() << endl;
          delete b;
        }

   Playlist *play1 = new Playlist("Favoritos", 2);
   Musica *m1 = new Musica(343, "Tio Macaco");
   Musica *m2 = new Musica(645, "Lingus");
   Musica *m3 = new Musica(372, "Kite");

   play1 ->adicionar(m1);

   try{
      play1 ->adicionar(m1);
   }
   catch (invalid_argument *c) {
     cout << c -> what() << endl;
     delete c;
   }

   try {
      play1 ->adicionar(m2);
      play1 ->adicionar(m3);
   }
    catch(overflow_error *d){
      cout << d -> what() << endl;
      delete d;
    }




 // IMPLEMENTACAO 2
/*
 Musica *m4 = new Musica(343, "Tio Macaco");
 try{
  m4 ->getMedia();} catch (SemAvaliacao *e){

  cout << e -> what() << endl;
  delete e;



 }

*/

//Implementacao 3

Playlist *p3 = new Playlist("Favoritos", 3);

Musica *m1 = new Musica(343,"Tio Macaco");
m1->avaliar(3);
m1->avaliar(2);

Musica *m2 = new Musica(645,"Lingus");
m2 ->avaliar(4);
m2 ->avaliar(4);
m2 ->avaliar(5);


Musica *m3 = new Musica(372,"Kite");

p3 ->adicionar(m1);

p3 ->adicionar(m2);

p3 ->adicionar(m3);


cout<< p3->getNome() <<"-" << p3->getAvaliacaoDasMusicas()<< endl;



}
/*
int main() {
    teste();
    return 0;
}

*/
