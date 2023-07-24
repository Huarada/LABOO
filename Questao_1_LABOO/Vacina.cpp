#include "Vacina.h"
#include <stdexcept>
#include <iostream>

using namespace std;
// Implementar

Vacina::Vacina(int dataFabricacao) : dataFabricacao(dataFabricacao)
{
  if (dataFabricacao ==NULL){
    throw new invalid_argument("Data de fabricacao de vacina invalida");
  }
}

Vacina::~Vacina()
{

}

int Vacina::getLote()
{
}

int Vacina::getDataFabricacao()
{
    return dataFabricacao;
}

void Vacina::imprimir(){

    cout    << "Lote: " << getLote()
            << ", Fabricacao: " << getDataFabricacao();

}


