#ifndef PERSISTENCIADEREDE_H
#define PERSISTENCIADEREDE_H

#include <string>
#include <fstream>
#include <stdexcept>

#include "Rede.h"
#include "Roteador.h"
#include "RoteadorComQoS.h"

class PersistenciaDeRede {
public:
    PersistenciaDeRede(string arquivo);
    virtual ~PersistenciaDeRede();

    virtual Rede* carregar();

private:
    ifstream leitura;
    ofstream escrita;
    string arquivo;

    string qualRoteador;
    int endereco;
    int qtdRoteadores, qtdDestinosPriorizados, destino; // ROTEADORES
    int qtdHospedeiros, gateway, atraso, qtdChats; // HOSPEDEIROS
    int porta, enderecoDestino, portaDestino; // CHATS
    int rotTabela, rotPadrao, atrasoPadrao, qtdMapeamentos; // MAPEAMENTO
    int tabelaDestino, tabelaAdjacente, tabelaAtraso; // MAPEAMENTO
};

#endif // PERSISTENCIADEREDE_H
