#include "No.h"

class TabelaDeRepasse{
public:

TabelaDeRepasse(int tamanho);
   virtual ~TabelaDeRepasse();

   virtual void mapear(int endereco, No* adjacente, int atraso);
   virtual No** getAdjacentes();
   virtual int getQuantidadeDeAdjacentes();

   virtual void setPadrao(No* padrao, int atraso);

   virtual No* getProximoSalto(int endereco, int& atraso);

   virtual void imprimir();

private:
    int quantidadeDeAdjacentes;
    No** adjacentes;

    int* atrasos;
    int* enderecos;
    No* padrao;
    int atraso_padrao;
    int tamanho;

};
