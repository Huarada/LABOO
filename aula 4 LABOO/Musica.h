#ifndef MUSICA_H
#define MUSICA_H
/*
 * Coloque a definicao da classe aqui. Use as diretivas adequadas e
 * inclua os arquivos e/ou bibliotecas necessarios para a classe.
 *
 *  Os atributos devem ser acessiveis somente internamente ao escopo
 *  da classe
*/


// Faca os includes necessarios
#include <string>

using namespace std;

class Musica {
private:
    string nome;
    int duracao;
    int quantidadeDeAvalicoes = 0;
    int somaDasAvaliacoes = 0;

public:
    void avaliar(int nota);
    double getMedia();

    void imprimir();


    void setNome(string nome);
    void setDuracao (int duracao);

    string getNome();
    int getDuracao();

};
#endif // MUSICA_H
