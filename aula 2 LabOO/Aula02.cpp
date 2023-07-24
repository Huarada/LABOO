// Use os includes necessarios.
#include <string>
#include <iostream>
using namespace std;

// Exercicio 1
/*
string* encontrarMusica(int duracoes[], string estilos[], string nomes[],
                        int quantidade, string estilo, int duracao) {

    string *name;

    name = NULL ;
    int i = 0;

    while ( i < quantidade) {
        if (estilo == estilos[i] && duracao == duracoes[i]) {
            name = &nomes[i];
            return name;
        }
        i++;

    }

    return name;


    // Implemente a funcao
}
*/
// Exercicio 2

int calcularEstatisticas(int duracoes[], int quantidade, int& minimo,
                         int* maximo) {
    int maxtemp = duracoes[0];
    int mintemp = duracoes[0];
    int i = 0;
    int soma = 0;
    int j = 0;

    if (quantidade == 0){
        *maximo = 0;
        minimo = 0;
        soma = 0;
    }
    else {
        while ( i < quantidade) {
            if ( maxtemp < duracoes[i]){
                maxtemp = duracoes [i]; // calculo do maximo
            }

            if ( mintemp > duracoes[i]){
                mintemp = duracoes[i];
            }
            i++;


       *maximo  = maxtemp;
       minimo = mintemp;

    }


    while (j < quantidade) {
        soma = soma + duracoes[j];
        j++;
    }

    }

    // Implemente a funcao
    return soma;
}


////////////////////////////////////////////
// REMOVA A MAIN ANTES DE ENVIAR AO JUDGE //
////////////////////////////////////////////
/*
int main() {
    // Teste da funcao Encontar Musica EX 1




   int duracoes[4] = {1,78,-89,55};
   int quantidade = 4;
   int minimo;
   int* maximo;
    cout <<calcularEstatisticas( duracoes, quantidade,  minimo,
                         maximo) <<endl;
   cout << *maximo << endl;
   cout << minimo;

    return 0;

}
*/
