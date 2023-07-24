#ifndef PERSISTENCIA_MUSICA_H
#define  PERSISTENCIA_MUSICA_H

#include <string>

#include "Musica.h"
#define NUMERO_MAXIMO_VALORES 10

using namespace std;

class PersistenciaMusica {
public:
    PersistenciaMusica(string arquivo);
    ~PersistenciaMusica();

    void inserir(Musica* m);

    Musica** obter(int& quantidade);
private:
    /* Colocar atributos necessarios */
    string arquivo;






    Musica* mustemp;
    string nometemp;
    int duracaotemp;
    int quantidadetemp;
    int somatemp;
    int totalmusicas = 0;




#endif /* PERSISTENCIA_MUSICA_H */
};
