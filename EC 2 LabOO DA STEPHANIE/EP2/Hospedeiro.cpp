#include "Hospedeiro.h"

Hospedeiro::Hospedeiro(int endereco, Roteador* gateway, int atraso)
    : No(endereco), endereco(endereco), gateway(gateway), atraso(atraso) {
    quantidadeDeChats = 0;
    chats = new vector<Chat*>();
}

Hospedeiro::~Hospedeiro() {
    while (!chats->empty()) {
        Chat *ultimo = chats->back();
        chats->pop_back();
        delete ultimo;
    }
    delete[] chats;
}

void Hospedeiro::adicionarChat(int porta, int enderecoDestino, int portaDestino) {
    //chats->push_back(c);
    quantidadeDeChats++;
}

vector<Chat*>* Hospedeiro::getChats() {
    return chats;
}

Chat* Hospedeiro::getChat(int porta) {
    for (unsigned int i = 0; i < chats->size(); i++) {
        if (porta == chats->at(i)->getPorta()) return chats->at(i);
    }
    return NULL;
}

Evento* Hospedeiro::processar(int instante) {
    if (fila->isEmpty()) return NULL;
    Datagrama *d = fila->dequeue();
    cout << "Hospedeiro " << endereco << endl;

    // 1 - destino eh esse hospedeiro
    if (d->getDestino() == endereco) {
        Chat *c = getChat(d->getSegmento()->getPortaDeDestino());
        // A - tem chat na porta destino
        if (c != NULL) {
            c->receber(d);
            cout << "\tMensagem recebida" << endl << c->getTextoCompleto() << endl;
        }
        // B - nao tem chat na porta destino
        else {
            cout << "\tSem chat: ";
            d->imprimir();
            cout << endl;
            delete d;
        }
        return NULL;
    }
    // 2 - destino eh outro endereco
    Evento *e = new Evento(instante + atraso, gateway, d);
    cout << "\rMensagem enviada" << endl;
    return e;
}
