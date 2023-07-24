#ifndef USUARIOPESSOA_H
#define USUARIOPESSOA_H
// Inclua aqui as diretivas de compilacao necessarias
#include "Usuario.h"
#include "Pessoa.h"
#include <string>

class UsuarioPessoa : public Usuario, public  Pessoa{
private:
        // Inclua aqui os atributos necessarios
    string nome;
    string login;
    int maximoFavoritos;
    int quantidadeMaxima;


public:
    UsuarioPessoa(string nome, string login, int maximoFavoritos, int quantidadeMaxima);
    virtual ~UsuarioPessoa();
};

#endif // USUARIOPESSOA_H
