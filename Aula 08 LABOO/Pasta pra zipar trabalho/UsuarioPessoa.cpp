/* Implemente a classe aqui */
#include "UsuarioPessoa.h"

UsuarioPessoa::UsuarioPessoa(string nome,string login,int maximoFavoritos,int quantidadeMaxima) : Usuario(login,maximoFavoritos), Pessoa(quantidadeMaxima,nome){
 this -> nome = nome;
 this -> login = login;
 this -> maximoFavoritos = maximoFavoritos;
 this -> quantidadeMaxima = quantidadeMaxima;


}

UsuarioPessoa:: ~UsuarioPessoa(){

}
