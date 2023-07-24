#ifndef BANDA_H
#define BANDA_H
#include "Artista.h"
#include <string>
// Adicione aqui as diretivas de compilacao necessarias

class Banda:public Artista {
private:
    // Adicione aqui os atributos necessarios
    int numeroDeMembros;

    int quantidadeMaxima;
    string nome;


public:
    Banda(int numeroDeMembros, int quantidadeMaxima,string nome) ;
    ~Banda();

    int getNumeroDeMembros();

    void imprimir();
};

#endif // BANDA_H
