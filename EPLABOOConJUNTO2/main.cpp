#include "Datagrama.h"
#include "Fila.h"
#include "TabelaDeRepasse.h"
#include "Evento.h"
#include "Roteador.h"
#include "Rede.h"
#include "Agendador.h"

#include <string>
#include <iostream>
using namespace std;
// /*



int main() {
    Datagrama *d1 = new Datagrama(1, 2, "Oi");
    Fila *f1 = new Fila(2);
    f1->enqueue(d1);
    Roteador *r1 = new Roteador(1);
    Roteador *r2 = new Roteador(2);
    Roteador *r3 = new Roteador(3);
    Roteador *r4 = new Roteador(4);
    Roteador *r5 = new Roteador(5);
    Roteador *r6 = new Roteador(6);
    Roteador *r7 = new Roteador(7);
    Rede *rede1 = new Rede(6);
    cout << rede1->adicionar(r1);
    cout << rede1->adicionar(r2);
    cout << rede1->adicionar(r3);
    cout << rede1->adicionar(r4);
    cout << rede1->adicionar(r5);
    cout << rede1->adicionar(r5);
    cout << rede1->adicionar(r6);
    cout << rede1->adicionar(r7);
    delete f1;
















    //delete rede1;
    return 0;
}
// */
/*
int main() {
    // Criando roteadores, rede, fila e agendador
    Roteador *r1 = new Roteador(1);
    Roteador *r2 = new Roteador(2);
    Roteador *r3 = new Roteador(3);
    Roteador *r4 = new Roteador(4);
    Roteador *r5 = new Roteador(5);
    Roteador *r6 = new Roteador(6);
    Rede *rede1 = new Rede(6);
    Agendador *agenda1 = new Agendador(1, rede1, 10);

    // Ajustando a rede
    rede1->adicionar(r1);
    rede1->adicionar(r2);
    rede1->adicionar(r3);
    rede1->adicionar(r4);
    rede1->adicionar(r5);
    rede1->adicionar(r6);

    // Ajustando a tabela de repasse dos roteadores
    r1->mapear(2, r2, 2);
    r1->mapear(3, r3, 1);
    r2->mapear(1, r1, 2);
    r2->mapear(4, r4, 1);
    r3->mapear(1, r1, 1);
    r3->mapear(4, r4, 1);
    r3->mapear(5, r5, 2);
    r4->mapear(2, r2, 1);
    r4->mapear(3, r3, 1);
    r4->mapear(6, r6, 1);
    r5->mapear(3, r3, 2);
    r5->mapear(6, r6, 2);
    r6->mapear(4, r4, 1);
    r6->mapear(5, r5, 2);

    // Ajustando padrao
    r1->setPadrao(r3, 1);
    r2->setPadrao(r4, 1);
    r3->setPadrao(r4, 1);
    r4->setPadrao(r3, 1);
    r5->setPadrao(r3, 2);
    r6->setPadrao(r4, 1);

    int loop = 1;
    while (loop == 1) {
        int opcao;
        cout << "Simulador de Rede" << endl << "1) Enviar um datagrama" << endl << "2) Passar tempo" << endl << "0) Sair" << endl << "Escolha uma opcao: ";
        cin >> opcao;
        cout << endl;

        if (opcao == 1) {
            int endOrigem, instante, destino;
            string mensagem;
            cout << "Endereco do roteador de origem: ";
            cin >> endOrigem;
            cout << "Instante: ";
            cin >> instante;
            cout << "Endereco de destino: ";
            cin >> destino;
            cout << "Mensagem: ";
            cin >> mensagem;

            // ORIGEM DESCONHECIDA
            int contaDesconhecido = 0;
            for (int i = 0; i < rede1->getQuantidade(); i++) {
                if (endOrigem != rede1->getRoteadores()[i]->getEndereco()) contaDesconhecido += 1;
            }
            if (contaDesconhecido >= rede1->getQuantidade()) {
                cout << "Erro: origem desconhecida" << endl;
                return 0;
            }
            // GUARDA ROTEADOR DESTINO
            Roteador *rotDest;
            for (int i = 0; i < rede1->getQuantidade(); i++) {
                if (destino == rede1->getRoteadores()[i]->getEndereco()) rotDest = rede1->getRoteadores()[i];
            }
            // FILA DO AGENDADOR CHEIA
            Datagrama *data = new Datagrama(endOrigem, destino, mensagem);
            if (!agenda1->agendar(instante, rotDest, data)) {
                cout << "Erro: Sem espaco para agendar o evento" << endl;
                return 0;
            }
            // AGENDADO
            agenda1->agendar(instante, rotDest, data);
            cout << endl;
        }

        else if (opcao == 2) {
            int tempo2;
            cout << "Quantidade de tempo: ";
            cin >> tempo2;
            cout << endl;
            for (int i = 1; i <= tempo2; i++) {
                cout << "Instante " << i << endl << "---" << endl;
                agenda1->processar(); // Deleta o evento da lista da agenda
                cout << endl;
                r1->processar(i);
                r2->processar(i);
                r3->processar(i);
                r4->processar(i);
                r5->processar(i);
                r6->processar(i);
            }
        }

        else return 0;
    }
}
*/
