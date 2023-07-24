#ifndef ROTEADOR_H
#define ROTEADOR_H

#include "fila.h"
#include "evento.h"
#include "tabeladerepasse.h"

#define TAMANHO 10



class TabelaDeRepasse;
class Evento;

class Roteador{

public:

    Roteador(int endereco);
    ~Roteador();
    bool mapear(int endereco, Roteador* adjacente, int atraso);
    void setPadrao(Roteador* padrao, int atraso);
    int getEndereco();
    void receber(Datagrama* d);
    Evento* processar(int instante);
    void imprimir();

private:

int endereco_rot;
TabelaDeRepasse* tabela_rot;
Fila* fila_rot;
Datagrama* memoria_rot;
Evento* evento_rot;
int atraso_evento;
};

#endif  // ROTEADOR_H
