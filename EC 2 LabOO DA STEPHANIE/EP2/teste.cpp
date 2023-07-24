#include "Segmento.h"
#include "Datagrama.h"
#include "Fila.h"
#include "FilaComPrioridade.h"
#include "No.h"
#include "Roteador.h"
#include "RoteadorComQoS.h"
#include "PersistenciaDeRede.h"

using namespace std;
#include <string>
#include <iostream>

void teste() {
    Segmento *s1 = new Segmento(30, 45, "Hello");
    Segmento *s2 = new Segmento(21, 4, "Hey");
    Datagrama *d1 = new Datagrama(50, 12, s1);
    Datagrama *d2 = new Datagrama(2, 1, s2);
    // TESTE ROTEADOR COM QOS
    RoteadorComQoS *rqos = new RoteadorComQoS(3);

    rqos->priorizar(1);
    rqos->receber(d1);
    rqos->receber(d1);
    rqos->receber(d1);
    rqos->receber(d1);
    rqos->receber(d1);
    rqos->receber(d1); // ESTOUROU

    PersistenciaDeRede* per1 = new PersistenciaDeRede("exemplo.txt");

    Rede* red1 = per1->carregar();
}

int main() {
    teste();
    return 0;
}
