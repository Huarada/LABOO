#include <stdexcept>
#include <fstream>
#include <iostream>

#include "PersistenciaMusica.h"
using namespace std;

PersistenciaMusica::PersistenciaMusica(string arquivo) {
    this -> arquivo = arquivo;
    /* Implementar */
}

PersistenciaMusica::~PersistenciaMusica() {
    /* Implementar */
}

void PersistenciaMusica::inserir(Musica* m) {

    totalmusicas ++;
    ofstream output;
    output.open( arquivo, ios_base::app);

    output << m ->getNome() << endl;
    output << m ->getDuracao() << endl;
    output << m ->getQuantidadeAvaliacoes() << endl;
    output << m ->getSomaDasAvaliacoes() << endl;

    output.close();


    /* Implementar */
}



Musica** PersistenciaMusica::obter(int& quantidade){

   Musica** musicas = new Musica*[10];
    quantidade= 0;

    ifstream input ;

    input.open(arquivo);


    if (input.fail()){
        input.close();
        throw new invalid_argument("Erro de leitura");

    }




    input >> nometemp >> duracaotemp >> quantidadetemp >> somatemp; //Se falhar n entra no laco


     while (input){


     mustemp = new Musica(duracaotemp,nometemp,quantidadetemp,somatemp);
     musicas[quantidade] = mustemp;
     quantidade ++;

     input >> nometemp >> duracaotemp >> quantidadetemp >> somatemp;

     }

 if (!input.eof()){
 input.close();
throw new logic_error("Arquivo com formatacao inesperada");
   }

if( quantidade == 0 ){
    input.close();
    return NULL;
}


   input.close();

   return musicas;


}




