
#include "fila.h"


class FilaComPrioridade : public Fila {

public:
using Fila::enqueue;

FilaComPrioridade(int tamanho);

virtual ~FilaComPrioridade();
virtual void enqueue(Datagrama* d, bool prioritario);

private:
int apoio = inicio;
};
