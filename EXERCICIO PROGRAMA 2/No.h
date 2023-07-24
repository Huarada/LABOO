
#ifndef NO_H
#define NO_H

#include "fila.h"
#include "Evento.h"
class Evento;


class No{
public:
No(int endereco);
No(int endereco,  Fila* fila);

virtual ~No();
virtual int getEndereco();

virtual Evento* processar(int instante); // ESSE TERMO PRECISA SER IMAGINARIO
virtual void receber(Datagrama* d);

virtual void imprimir();

static const int TAMANHO_FILA = 5;

protected:
int endereco;

private:


Fila* fila;

int tamanhoMaxFila;



};

#endif // NO_H
