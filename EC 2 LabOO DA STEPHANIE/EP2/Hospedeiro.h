#ifndef HOSPEDEIRO_H
#define HOSPEDEIRO_H

#include "Roteador.h"
#include "Chat.h"
#include <vector>

using namespace std;

class Chat;

class Hospedeiro : public No {
public:
    Hospedeiro(int endereco, Roteador* gateway, int atraso);
    virtual ~Hospedeiro();

    virtual void adicionarChat(int porta, int enderecoDestino, int portaDestino);
    virtual vector<Chat*>* getChats();
    virtual Chat* getChat(int porta);

    Evento* processar(int instante); // REDEFINICAO

protected:

private:
    int endereco, atraso, quantidadeDeChats;
    Roteador* gateway;
    vector<Chat*>* chats;
};

#endif // HOSPEDEIRO_H
