#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include "Artista.h"

// Inclua aqui as diretivas de compilacao necessarias

using namespace std;

class Pessoa : public Artista{
private:
    // Inclua aqui os atributos necessarios

    int quantidadeMaxima;
    string nome;
public:
    Pessoa(int quantidadeMaxima, string nome);
    virtual ~Pessoa();
    virtual void imprimir();
};

#endif // PESSOA_H
