//FACA OS INCLUDES NECESARIOS
#include <iostream>
using namespace std;
//IMPLEMENTE AS FUNCOES
// EXERCICIO 1
/*
int calcularNota(int numeroDeReproducoes, int quantidadeDePositivos, int quantidadeDeUsuariosQueOuviram) {

    double porcento = ((double) quantidadeDePositivos) / quantidadeDeUsuariosQueOuviram ;
    int nota ;

    if ( numeroDeReproducoes >= 1000000 )
        nota = 5;

        else if (numeroDeReproducoes >= 100000 || porcento >= 0.5)
            nota = 4;

        else if (numeroDeReproducoes >= 10000 || porcento >= 0.35)
            nota = 3;

        else if (numeroDeReproducoes >= 1000 || porcento >= 0.2)
            nota = 2 ;

        else if (numeroDeReproducoes >= 100 || porcento >= 0.15)
            nota = 1;

        else nota = 0 ;

    return nota;


}
*/
// EXERCICIO 2

int calcularTempoTotal(int nota, int notas[], int duracoes[], int quantidade) {
 int tempo = 0;
    int i = 0 ;

    while (i < quantidade) {
        if (notas[i] == nota){
           tempo = tempo + duracoes [i];
        }

        i++;
    }

    return tempo;
}


// EXERCICIO 3
/*
bool temRepetido(string artistas[], int quantidade) {

    bool repete;
    string compara;
    int i =0;
    int j = 0;
    int z = 0;

    while  (i < quantidade) {
        compara = artistas [i];
        j = 0 ;
        z = 0 ;
        while (j < quantidade){

           if (compara == artistas [j])
               z ++ ;

           if (z == 2)

               return  true;



        }
    }
    return false ;





}

*/
/* COMENTE A MAIN PARA SUBMETER */

int main() {

    cout << calcularTempoTotal(4,{4, 5, 4},{5, 3, 4},3)  ;
    return 0;
}

