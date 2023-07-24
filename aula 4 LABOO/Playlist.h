/*
 * Faca os includes e coloque a implementacao dos metodos aqui!
*/
#include <string>
#include "Musica.h"
#define NUMERO_MAXIMO_VALORES 10
using namespace std;
class Playlist {
/*  Os atributos devem ser acessiveis somente internamente ao escopo
 *  da classe
*/

/*
 * Os metodos podem ser acessados de fora do escopo da classe
*/
private:
    string nome;
    Musica *musicas[NUMERO_MAXIMO_VALORES];
    int quantidade = 0;
    int duracao = 0;
public:
    int getDuracaoTotal();
    bool adicionar(Musica* m);

    void setNome(string nome);
    string getNome();
    int getQuantidade();

    void imprimir();
};
