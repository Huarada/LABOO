#include <iostream>
#include <stdexcept>
#include "Artista.h"
#include <list>
#include <algorithm>
using namespace std;
Artista::Artista(string nome):  nome(nome)
    {
    if (nome.empty())
        throw new invalid_argument("Artista Com Nome Vazio");

    musicas = new list <Musica*>();
}

Artista::~Artista() {
    cout << "Artista com " << musicas->size() << " musica(s) destruido" << endl;

    delete[] musicas;
}

list<Musica*>* Artista::getMusicas() {
    return musicas;
}





string Artista::getNome() const {
    return nome;
}

double Artista::getNota() const {
    double soma = 0;
    list<Musica*>::iterator a = musicas->begin();
    while(a != musicas->end()){

        soma += (*a)->getMedia();
        a++;}
    return soma / musicas->size();
}

void Artista::adicionarMusica(Musica* musica) {

    if (musica == nullptr)
        throw new invalid_argument("Ponteiro de Musica invalido!");

    if (temMusica(musica))
        throw new invalid_argument("Musica repetida adicionada ao Artista!");

    musicas->push_back(musica);
}

void Artista::imprimir() {
    cout << "Artista " << getNome() << " - nota " << getNota() << endl;
    list <Musica*> :: iterator j = musicas->begin();
    while( j != musicas->end()){
        cout << "\t";
       (*j)->imprimir();
       j++;
    }
}

bool Artista::temMusica(Musica *m) const {
    list <Musica*>::iterator valor;
    valor= std::find(musicas->begin(),musicas->end(), m);

        if (valor != musicas->end())
            return true;


    return false;
}
