#include <algorithm>
#include <iostream>

#include "Banda.h"

Banda::Banda(int quantidadeMaxima, string nome)
    : Artista(quantidadeMaxima, nome), pessoas(new Pessoa*[quantidadeMaxima]) {}

Banda::~Banda(){}




bool Banda::adicionar(Pessoa *a) {
    if (quantidadeDePessoas >= getQuantidadeMaxima())
        return false;

    for (int i = 0; i < quantidadeDePessoas; i++)
        if (pessoas[i] == a)
            return false;

    pessoas[quantidadeDePessoas++] = a;
    return true;
}

double Banda::getNota() {
    double soma = 0;
    for (int i = 0; i < quantidadeDePessoas; i++)

          soma += pessoas[i]->Artista::getNota();

    return min(soma/quantidadeDePessoas + bonus, 5.);
}

Pessoa** Banda::getParticipantes(){
    return pessoas;
}


void Banda::setBonus(double valor){
Banda::bonus = valor;

}

double Banda::getBonus(){

return bonus;


}

double Banda::bonus = 0.1;






void Banda::imprimir() {
  cout << "Banda de " << quantidadeDePessoas << " membros" << endl;
}
