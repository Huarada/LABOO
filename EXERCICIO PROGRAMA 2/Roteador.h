#include "No.h"

#include "TabelaDeRepasse.h"





class Roteador: public No{
protected:
Roteador(int endereco,Fila* fila);

public:
Roteador(int endereco);

virtual ~Roteador();

virtual void mapear(int endereco, No* adjacente, int atraso);
virtual void setPadrao(No* padrao, int atraso);

virtual Evento* processar(int instante);



static const int TAMANHO_TABELA = 10;

private:

Fila* fila;

TabelaDeRepasse* tabela;


};
