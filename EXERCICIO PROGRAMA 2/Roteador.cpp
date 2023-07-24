
#include "Roteador.h"
#include <iostream>
using namespace std;
Roteador::Roteador(int endereco) : No(endereco){

tabela = new TabelaDeRepasse(TAMANHO_TABELA);
}

Roteador::~Roteador(){

delete[] tabela;
delete[] fila;

}

Roteador::Roteador(int endereco, Fila* fila): No( endereco,  fila){

}


void Roteador::mapear(int endereco,No* adjacente, int atraso){

tabela ->mapear(endereco,adjacente,atraso);

}

void Roteador::setPadrao(No* padrao,int atraso){

tabela->setPadrao(padrao,atraso);

}


Evento* Roteador::processar(int instante){
if (fila->isEmpty()) return NULL;
    cout << "Roteador " << endereco << endl;

    Datagrama* removido = fila->dequeue(); // Armazena o datagrama retornado pelo dequeue

    // Consultando a tabela de repasse
    int atraso;
    No* proxRot = tabela->getProximoSalto(removido->getDestino(), atraso);

    if (proxRot->getEndereco() == endereco) { // Chegou certo
        cout << "\tRecebido: " << removido->getSegmento()->getDado() << endl;
        delete removido;
        return NULL;
    }
    if (proxRot == NULL) { // Tabela de repasse retorna NULL
        cout << "\tSem proximo: Origem: " << removido->getOrigem() << ", Destino: " << removido->getDestino() << ", " << removido->getSegmento()->getDado() << endl;
        delete removido;
        return NULL;
    }
    else if (proxRot != NULL) { // Tabela de repasse retorna roteador destino e atraso
        cout << "\tRepassado para " << proxRot->getEndereco() << " (instante " << instante + atraso << "): ";
        cout << "Origem: " << removido->getOrigem() << ", Destino: " << removido->getDestino() << ", " << removido->getSegmento()->getDado() << endl;
        Evento* novo = new Evento(instante + atraso, proxRot, removido);
        return novo;

}
}






