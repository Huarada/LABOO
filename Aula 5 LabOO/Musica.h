
#ifndef MUSICA_H
#define MUSICA_H

#include <string>

using namespace std;

class Musica {
public:
    Musica(int duracao, string nome);
    ~Musica();

    string getNome();
    int getDuracao();

    void imprimir();
private:
    int duracao;
    string nome;
};

#endif
