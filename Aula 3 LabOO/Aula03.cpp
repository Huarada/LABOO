#include <iostream>

// Faca os includes necessarios

using namespace std;

class Musica {
public:
    string nome;
    int duracao;
    int quantidadeDeAvaliacoes = 0;
    int somaDasAvaliacoes = 0;

    void avaliar(int valor);
    double getMedia();

    void imprimir();
};

/** Implementar metodos da classe Musica **/

void Musica::avaliar (int valor){
     if (valor == NULL){
        somaDasAvaliacoes = 0;
        quantidadeDeAvaliacoes = 1;

     }
     else{
     somaDasAvaliacoes = somaDasAvaliacoes + valor;
     quantidadeDeAvaliacoes = quantidadeDeAvaliacoes + 1;
     }

};

double Musica::getMedia() {



  double media = ((double) somaDasAvaliacoes)/ quantidadeDeAvaliacoes;

  return media;

};

void Musica::imprimir (){


  cout << nome << " - " << duracao << " segundos" << " - " << getMedia() << endl;

};


class Playlist {
public:
    string nome;
    Musica* m1 = NULL;
    Musica* m2 = NULL;

    int getDuracao();
    bool adicionar(Musica* m);
};

/** Implementar metodos da classe Playlist **/

int Playlist::getDuracao() {
   int temporizador = 0 ;

   if (m1 == NULL){

      if ( m2 == NULL ){
        return 0;
      }
      else {
        temporizador =  m2 -> duracao;
      }

   }
   else if (m2 ==NULL ){
        temporizador = m1 -> duracao;
   }
   else {
    temporizador = m1 -> duracao + m2 -> duracao;
   }

   return temporizador;
};


bool Playlist::adicionar (Musica* m){


   if (m == m1 || m == m2){
    return false ;
   }

   else if ( m1 == NULL ){
       m1 = m;
       return true;

   }
   else if (m2 == NULL ){
      m2 = m;
      return true;
   }

   else  return false ;


};



/** Implementar a funcao teste **/
void teste() {
    // IMPLEMENTE seguindo o enunciado
    Musica *roses = new Musica;

    roses -> nome = "Roses";
    roses -> duracao = 180;

    roses  -> avaliar (5) ;
    roses  -> avaliar (4) ;
    roses  -> avaliar (4) ;

    roses -> imprimir();



    Musica *rodaviva = new Musica ;

    rodaviva -> nome = "Roda-Viva";
    rodaviva -> duracao = 233;

    rodaviva -> avaliar(5) ;
    rodaviva -> avaliar(3) ;
    rodaviva -> avaliar(1) ;

    rodaviva -> imprimir();


    Playlist  *play1 = new Playlist;

    play1 -> adicionar (roses);
    play1 -> adicionar(rodaviva);

    cout << play1 -> getDuracao() << endl;




}


/** COMENTE a funcao main() ANTES DE ENVIAR AO JUDGE! **/
/*
int main() {
  teste();




    return 0;
}
*/
