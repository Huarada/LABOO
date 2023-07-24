/*
 * Faca os includes e coloque a implementacao dos metodos aqui!
*/
#include "Musica.h"
#include <iostream>

using namespace std;
void Musica::avaliar(int nota) {
    somaDasAvaliacoes += nota;
    quantidadeDeAvalicoes++;
}

double Musica::getMedia() {
    return ((double)somaDasAvaliacoes)/quantidadeDeAvalicoes;
}

void Musica::imprimir() {
    cout << nome << " - " << duracao << " segundos - " << this->getMedia()  << " avaliacao" << endl;
}


void Musica::setNome(string nome){
this -> nome = nome;


}


void Musica::setDuracao (int duracao){
this -> duracao = duracao;

}


string Musica::getNome(){

return nome;

}


int Musica::getDuracao(){

return duracao;


}
