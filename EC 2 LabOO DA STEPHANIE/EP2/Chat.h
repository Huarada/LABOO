#ifndef CHAT_H
#define CHAT_H

#include "Hospedeiro.h"
#include "Datagrama.h"

class Hospedeiro;

class Chat {
public:
    Chat(Hospedeiro* h, int porta, int enderecoDestino, int portaDestino);
    virtual ~Chat();

    virtual int getPorta();
    virtual void enviar(string texto);
    virtual void receber(Datagrama* d);
    virtual string getTextoCompleto();

    virtual void imprimir();

protected:

private:
    int porta, enderecoDestino, portaDestino;
    Hospedeiro* h;
    string textoCompleto;
};

#endif // CHAT_H
