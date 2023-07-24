#include <iostream>

#include "Musica.h"

Musica::Musica(int duracao, string nome) : duracao(duracao), nome(nome){
}


Musica::~Musica(){
    cout << "Musica " << nome << " destruida" << endl;
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
