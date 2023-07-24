#include "Coronavac.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Inicialize os contadores de doses e de lotes desta vacina

// Implementar
 int Coronavac::contLote = 1  ;
 int Coronavac::contDose = 1  ;
Coronavac::Coronavac(int dataFabricacao) : Vacina(dataFabricacao)
{



    if(contDose == LOTE_MAX){
      contLote++;
      contDose = 1;
    }
    else contDose++;

}

Coronavac::~Coronavac()
{

}

int Coronavac::getDataProximaDose(int dataAplicacao)
{
  if(dataAplicacao<= 0) throw new invalid_argument("Vacina ainda nao foi aplicada"); //PROTECAO FINALIZA O CODIGO

  return (dataAplicacao+INTERVALO);
}

void Coronavac::imprimir()
{
    // Descomente e complete
     cout << "Coronavac, Lote "<<contLote<<" Fabricacao "<<getDataFabricacao();
    // Utilize refinamento para invocar o método imprimir de Vacina
}



int Coronavac::getValidade(){

 if (dataFabricacao <100) return (dataFabricacao +200);

 else return (dataFabricacao + 300);
}
