#ifndef JANSEN_H
#define JANSEN_H
#include "Vacina.h"
class Jansen : public Vacina {
public:
    Jansen(int dataFabricacao);
    virtual ~Jansen();
    virtual int getValidade();
    virtual void imprimir();
private:
    // Defina as constantes estaticas
    static const int LOTE_MAX = 3;

    // Defina o contador de doses da vacina
    static int contLote  ;
    static int contDose  ;
    // Defina o contador de lotes da vacina

};

#endif // JANSEN_H
