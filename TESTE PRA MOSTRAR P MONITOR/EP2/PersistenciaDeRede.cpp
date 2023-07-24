#include "PersistenciaDeRede.h"

PersistenciaDeRede::PersistenciaDeRede(string arquivo) {
    this->arquivo = arquivo;
}

PersistenciaDeRede::~PersistenciaDeRede() {}

Rede* PersistenciaDeRede::carregar() {
    Rede *redeCriada = new Rede();
    cout << "1 ------ Rede criada: " << redeCriada << " ------ 1" << endl;
    leitura.open(arquivo);

    if (leitura.fail()) { // ARQUIVO NAO ENCONTRADO
        leitura.close();
        throw new invalid_argument("Erro de leitura / Arquivo nao encontrado");
    }

    leitura >> qtdRoteadores; // PRIMEIRA LEITURA

    cout << "Quantidade de roteadores: " << qtdRoteadores << endl;                                     // TESTE ------

    while (leitura) { // ENQUANTO NAO FOR FAIL NEM BAD

        // LE OS ROTEADORES
        for (int i = 0; i < qtdRoteadores; i++) {
            leitura >> qualRoteador;
            if (qualRoteador == "r") {
                leitura >> endereco;
                Roteador *r1 = new Roteador(endereco);
                redeCriada->adicionar(r1);
                cout << "Adicionado roteador " << r1->getEndereco() << " (" << r1 << ")" << endl;               // TESTE ------
            }
            else if (qualRoteador == "q") {
                leitura >> endereco;
                RoteadorComQoS *rqos = new RoteadorComQoS(endereco);
                leitura >> qtdDestinosPriorizados;
                for (int i = 0; i < qtdDestinosPriorizados; i++) {
                    leitura >> destino;
                    rqos->priorizar(destino);
                }
                redeCriada->adicionar(rqos);
                cout << "Adicionado roteaQoS " << rqos->getEndereco() << " (" << rqos;                          // TESTE ------
                cout << ") com " << rqos->getDestinosPriorizados()->size() << " destino(s) priorizado(s)" << endl;  // TESTE ------
                cout << "\tDestino(s) priorizado(s): " << rqos->getDestinosPriorizados()->at(0);
                for (unsigned int i = 1; i < rqos->getDestinosPriorizados()->size(); i++) {
                    cout << ", " << rqos->getDestinosPriorizados()->at(i);
                }
                cout << endl;
            }
            else return NULL;
        }

        // LE OS HOSPEDEIROS
        leitura >> qtdHospedeiros;
        cout << endl << "Quantidade de hospedeiros: " << qtdHospedeiros << endl;
        for (int i = 0; i < qtdHospedeiros; i++) {
            leitura >> endereco >> gateway >> atraso >> qtdChats;
            Roteador* aux1 = dynamic_cast<Roteador*>(redeCriada->getNo(gateway));

            Hospedeiro *h1 = new Hospedeiro(endereco, aux1, atraso); // ERRO
            if (aux1 != NULL) {
                for (int i = 0; i < qtdChats; i++) {
                    leitura >> porta >> enderecoDestino >> portaDestino;
                    h1->adicionarChat(porta, enderecoDestino, portaDestino); // O METODO CRIA O CHAT
                }
            redeCriada->adicionar(h1);
            cout << "Adicionado hospedeiro " << h1->getEndereco() << " (" << h1 << "), com atraso " << atraso;  // TESTE ------
            cout << " e " << h1->getChats()->size() << " chat(s)" << endl;                                      // TESTE ------
            }
        }

        // TABELA DE REPASSE - MAPEAMENTO
        for (int i = 0; i < qtdRoteadores; i++) {
            leitura >> rotTabela >> rotPadrao >> atrasoPadrao >> qtdMapeamentos;

            Roteador* rotAux = dynamic_cast<Roteador*>(redeCriada->getNo(rotTabela));
            Roteador* rotAuxPadrao = dynamic_cast<Roteador*>(redeCriada->getNo(rotPadrao));

            if (rotAux != NULL) {
                cout << endl << "ROTEADOR " << rotAux->getEndereco() << " (" << rotAux << ")" << endl;                  // TESTE ------
                if (rotAuxPadrao != NULL) {
                    rotAux->setPadrao(rotAuxPadrao, atrasoPadrao);
                    cout << "\tPadrao definido: " << rotAuxPadrao->getEndereco() << " (" << rotAuxPadrao;               // TESTE ------
                    cout << "), " << atrasoPadrao << " de atraso, com " << qtdMapeamentos << " mapeamentos" << endl;    // TESTE ------
                }
            }
            cout << "\tMapeamento: " << endl;                                                                           // TESTE ------
            for (int i = 0; i < qtdMapeamentos; i++) { // MAPEAMENTO
                leitura >> tabelaDestino >> tabelaAdjacente >> tabelaAtraso;
                No* adjacente = redeCriada->getNo(tabelaAdjacente);
                rotAux->mapear(tabelaDestino, adjacente, tabelaAtraso);
                cout << "\t\tDestino " << tabelaDestino << ", adjacente " << adjacente->getEndereco();
                cout << ", atraso " << tabelaAtraso << endl;                                                    // TESTE ------
            }
        }

        cout << "2 ------ Rede criada: " << redeCriada << " ------ 2" << endl;
    }

    cout << "3 ------ Rede criada: " << redeCriada << "------ 3" << endl;
    cout << leitura.fail() << endl;

    if (!leitura.eof()) { // ERRO DE LEITURA - saiu do while sem chegar no fim do arquivo
        leitura.close();
        throw new logic_error("Arquivo com formatacao inesperada");
    }

    cout << "4 ------ Rede criada: " << redeCriada << "------ 4" << endl;
    leitura.close();
    return redeCriada;
}
