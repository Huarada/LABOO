#ifndef MUSICA_H
#define  MUSICA_H

#include <string>

using namespace std;

class Musica {
public:
    Musica(int duracao, string nome);
    Musica(int duracao, string nome, int quantidadeDeAvaliacoes, int somaDasAvaliacoes);
    ~Musica();

    void avaliar(int nota);
    void imprimir();
    double getMedia();

    string getNome();
    int getDuracao();

    int getQuantidadeAvaliacoes();
    int getSomaDasAvaliacoes();
private:
    int duracao;
    string nome;
    int quantidadeDeAvalicoes = 0;
    int somaDasAvaliacoes = 0;
};

#endif /* MUSICA_H */
