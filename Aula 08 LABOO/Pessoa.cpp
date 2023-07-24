#include "Pessoa.h"
#include <iostream>

//Implemente aqui os metodos necessarios


Pessoa::Pessoa(int quantidadeMaxima, string nome): Artista(quantidadeMaxima,nome){

this -> quantidadeMaxima = quantidadeMaxima;
this -> nome = nome;

}
Pessoa:: ~Pessoa(){

}


void Pessoa::imprimir(){
    cout << "- " << getNome() << endl;
    for (int i = 0; i < getQuantidadeDeMusicas(); i++) {
        cout << "\t";
        Artista::getMusicas()[i]->imprimir();
    }
}
