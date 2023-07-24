#include <iostream>
#include <stdexcept>

#include "Musica.h"
#include "SemAvaliacao.h"

Musica::Musica(int duracao, string nome) : duracao(duracao), nome(nome) {}

Musica::~Musica() {
    cout << "Musica " << getNome() << " destruida" << endl;
}

void Musica::avaliar(int nota){
    somaDasAvaliacoes += nota;
    quantidadeDeAvalicoes++;
}

double Musica::getMedia(){

    if (quantidadeDeAvalicoes == 0) throw new SemAvaliacao(getNome());
    return ((double)somaDasAvaliacoes)/quantidadeDeAvalicoes;
}

string Musica::getNome() {
    return nome;
}

int Musica::getDuracao() {
    return duracao;
}

void Musica::imprimir() {
    cout << "Musica " << getNome() << " com duracao " << getDuracao() << endl;
}
