#include "Jansen.h"
#include <stdexcept>
#include <iostream>

using namespace std;
// Inicialize os contadores de doses e de lotes desta vacina
 int Jansen::contLote = 1  ;
 int Jansen::contDose = 1  ;

// Implementar

Jansen::Jansen(int dataFabricacao) :Vacina(dataFabricacao)
{
    if(contDose == LOTE_MAX){
      contLote++;
      contDose = 1;
    }
    else contDose++;

}

Jansen::~Jansen()
{

}

int Jansen::getValidade(){

return (dataFabricacao + 100*contLote);

};

void Jansen::imprimir()
{
    // Descomente e complete
    cout << "Jansen, Lote "<<contLote<<" Fabricacao "<<getDataFabricacao();
    // Utilize refinamento para invocar o método imprimir de Vacina
}
