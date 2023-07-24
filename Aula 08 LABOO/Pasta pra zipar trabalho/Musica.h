#ifndef MUSICA_H
#define  MUSICA_H

#include <string>

using namespace std;

class Musica {
public:
    Musica(int duracao, string nome);
    ~Musica();

    string getNome();
    int getDuracao();

    void avaliar(int nota);
    double getMedia();

    void imprimir();
private:
    int duracao;
    string nome;
    int quantidadeDeAvalicoes = 0;
    int somaDasAvaliacoes = 0;
};

#endif /* MUSICA_H */