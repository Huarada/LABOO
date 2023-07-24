/*
 * Faca os includes e coloque a implementacao dos metodos aqui!
*/
#include "Playlist.h"
#include <string>
#include  <iostream>

using namespace std;

void Playlist::setNome(string nome){
    this -> nome = nome;
}

string Playlist::getNome(){
    return nome;
}




bool Playlist::adicionar(Musica* m){


quantidade++ ;
int i= 0;

if (quantidade > NUMERO_MAXIMO_VALORES ){
    return false;
}
else{

    while ( i < quantidade){
        if (musicas [i] -> getNome() = m ->getNome()){
            return false;
        }

    i++;
    }

}
musicas[quantidade -1 ] = m;

return true;


}


int Playlist::getQuantidade(){
  return quantidade;
}



int Playlist::getDuracaoTotal(){
  int j = 0;



    while(j < quantidade){

        duracao = duracao + musicas[j] -> getDuracao();
        j++;
    }



  return duracao;
}



void Playlist::imprimir(){
 int z = 0;

 cout << nome << " - " << this -> getDuracaoTotal() << " segundos no total"<<endl;

 while ( z <= quantidade){
    cout << musicas[z] -> getNome() << " - " << musicas[z] -> getDuracao() << " segundos - " << musicas[z] ->getMedia()  << " avaliacao" << endl;
  z++;
 }

}
