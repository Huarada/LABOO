#ifndef CORONAVAC_H
#define CORONAVAC_H

#include "Vacina.h"

class Coronavac: public Vacina{
public:
    Coronavac(int dataFabricacao);
    virtual ~Coronavac();
    static int getDataProximaDose (int dataAplicacao);
    virtual void imprimir();
    virtual int getValidade();
private:
    // Defina as constantes estaticas

    // Defina o contador de doses da vacina

    // Defina o contador de lotes da vacina

    static int contLote  ;
    static int contDose  ;

    static const int LOTE_MAX = 2;
    static const int INTERVALO = 28;

};

#endif // CORONAVAC_H
