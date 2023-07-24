#include "Banda.h"
#include <iostream>
#include <string>

using namespace std;
// Implemente aqui os metodos
Banda::~Banda() {
    cout << "Banda com  "<<numeroDeMembros << " membros destruida"<<endl;;
}

int Banda:: getNumeroDeMembros() {
    return  numeroDeMembros ;
}

void Banda::imprimir() {
    cout    <<getNome() << " - " << getNumeroDeMembros()<< "  membros destruida"<<endl;
}

Banda::Banda(int numeroDeMembros, int quantidadeMaxima,string nome) :Artista(quantidadeMaxima, nome) {
this->numeroDeMembros = numeroDeMembros;
}


