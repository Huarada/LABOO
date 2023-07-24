#include "Agendador.h"
#include "Chat.h"
#include "Datagrama.h"
#include "Evento.h"
#include "Fila.h"
#include "FilaComPrioridade.h"
#include "Hospedeiro.h"
#include "No.h"
#include "PersistenciaDeRede.h"
#include "Rede.h"
#include "Roteador.h"
#include "RoteadorComQoS.h"
#include "Segmento.h"
#include "TabelaDeRepasse.h"

using namespace std;
#include <string>
#include <iostream>
#include <stdexcept>

int main() {
    /* FALTANDO:
        - ROTEADOR
            * Arrumar as impressoes de saida do metodo processar
        - AGENDADOR
            * processar (roteador/hospedeiro falta criar evento e adicionar aos eventos agendados)
        - REDE
            * getHospedeiros
        - PERSISTENCIA DA REDE
            * lendo mais que uma vez
    */

    /* -----------------------------------------------------------
    -------------------------- INTERFACE -------------------------
    ----------------------------------------------------------- */
    string arquivo;
    int instanteInicial, opcao, enderecoHospedeiro, portaChat, passarTempo;

    cout << "Nome do arquivo: ";
    cin >> arquivo;
    cout << "Instante inicial: ";
    cin >> instanteInicial;
    cout << endl;

    try {
        PersistenciaDeRede *rede1 = new PersistenciaDeRede(arquivo);
        //Rede *redePersistida = new Rede();
        Rede* redePersistida = rede1->carregar();
        cout << redePersistida << endl;
        cout << "------------- REDE CARREGADA -------------" << endl << endl; // TESTE
        Agendador *agenda = new Agendador(instanteInicial, redePersistida, 10);

        cout << "Simulador de Rede" << endl << "1) Enviar uma mensagem" << endl << "2) Passar tempo" << endl << "0) Sair" << endl << "Escolha uma opcao: ";
        cin >> opcao;
        cout << endl;
        if (opcao == 1 || opcao == 2) {
            do {
                if (opcao == 1) {
                    cout << redePersistida->getNo(2) << endl; // TESTE
                    redePersistida->imprimir(); // TESTE

                    list<Hospedeiro*>::iterator hosp = redePersistida->getHospedeiros()->begin();
                    cout << "testando iterador" << endl;
                    while (hosp != redePersistida->getHospedeiros()->end()) {
                        cout << "Hospedeiro: " << (*hosp) << endl;
                        for (unsigned int i = 0; i < (*hosp)->getChats()->size(); i++) {
                            cout << "\tChats: ";
                        }
                    }
                    /*
                    for (unsigned int i = 0; i < redePersistida->getHospedeiros()->size(); i++) {
                        cout << "Hospedeiro: "; //redePersistida->getHospedeiros();
                        for (unsigned int j = 0; j < redePersistida->getHospedeiros()->size(); j++) {
                            cout << "\tChat: "; //getChats;
                        }
                    }
                    */
                    cout << "Endereco do hospedeiro: ";
                    cin >> enderecoHospedeiro;
                    cout << "Porta do chat: ";
                    cin >> portaChat;
                    cout << "Conteudo: ";
                    cout << endl;
                }

                else if (opcao == 2) {
                    cout << "Quantidade de tempo: ";
                    cin >> passarTempo;
                    for (int i = 1; i <= passarTempo; i++) {
                        cout << "Instante " << i << endl << "---" << endl;
                        agenda->processar();
                    }
                }
                cout << endl;
                cout << "Simulador de Rede" << endl << "1) Enviar uma mensagem" << endl << "2) Passar tempo" << endl << "0) Sair" << endl << "Escolha uma opcao: ";
                cin >> opcao;
                cout << endl;

            } while (opcao == 1 || opcao == 2);
        }
    } catch (invalid_argument *ia) {
        cout << ia->what();
        delete ia;
    } catch (logic_error *le) {
        cout << le->what();
        delete le;
    } catch (overflow_error *oe) {
        cout << oe->what();
        delete oe;
    }

    return 0;
}
