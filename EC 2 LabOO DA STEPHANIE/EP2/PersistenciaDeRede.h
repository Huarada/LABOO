
#include "Hospedeiro.h"
#include "RoteadorComQoS.h"
#include <fstream>
#include "Rede.h"
class PersistenciaDeRede{
public:

PersistenciaDeRede(string arquivo);
virtual ~PersistenciaDeRede();

virtual Rede* carregar();

private:

string arquivo;

string contorno;

Rede* redetemp;
Roteador* rot_temp;

Roteador** rot_vec;
RoteadorComQoS* rotqos_temp;
Hospedeiro* hosptemp;



};
