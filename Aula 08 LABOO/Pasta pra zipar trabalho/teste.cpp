// Faca os includes necessarios
#include "Banda.h"
#include "UsuarioPessoa.h"
#include <iostream>

using namespace std;

void teste() {
    // IMPLEMENTE seguindo o enunciado

 //TESTE DO PRIMEIRO EXERCICIO

    Banda* band1 = new Banda(3,"Banda do Mar");
    Pessoa* pessoa1 = new Pessoa(3,"Marcelo Camelo");
    Pessoa* pessoa2 = new Pessoa(3,"Maria Luiza");

    band1 ->adicionar(pessoa1);
    band1 ->adicionar(pessoa2);
    band1 ->imprimir();



/* //TESTE DO SEGUNDO EXERCICIO

   UsuarioPessoa* UserP1 = new UsuarioPessoa("Tom Jobin","tom@usp.br",1,1);
    UserP1 ->Pessoa::imprimir();




/*  //TESTE DO TERCEIRO EXERCICIO


Pessoa * per1 = new Pessoa(1,"Tom Jobin");
Musica* song1 = new Musica(180, "Samba de uma nota so");
song1 ->avaliar(5);

per1 ->adicionarMusica(song1);

Pessoa* per2 = new Pessoa(1,"Elis Regina");
Musica* song2 = new Musica(214,"Aguas de marco");
song2 ->avaliar(4);
per2 ->adicionarMusica(song2);

Banda* band1 = new Banda(2,"Elis & Tom");

band1 ->adicionar(per1);

band1 ->adicionar(per2);



cout << band1 ->getNota() <<endl;

band1 ->setBonus(0.2);

cout << band1 ->getNota();

*/


}
/*
int main() {
    teste();
    return 0;
}
*/
