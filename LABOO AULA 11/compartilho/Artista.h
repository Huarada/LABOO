#ifndef ARTISTA_H
#define  ARTISTA_H

#include <string>
#include <list>
#include "Musica.h"

using namespace std;

class Artista {
private:

    string nome;
    list<Musica*>* musicas;


    bool temMusica(Musica *m) const;

public:
    Artista(string nome);
    virtual ~Artista();

    list<Musica*>* getMusicas();



    string getNome() const;

    virtual double getNota() const;

    void adicionarMusica(Musica* musica);

    void imprimir();
};

#endif /* ARTISTA_H */
