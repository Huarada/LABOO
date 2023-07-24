#include "Passaporte.h"
#include <stdexcept>
#include <iostream>

using namespace std;
// Implementar

Passaporte::Passaporte(string nome): nome(nome)
{
 if (nome == "") throw new invalid_argument("Nome do usuario invalido");

 vacinas = new vector<Vacina*>();
 aplicacoes = new vector<int>();
}

Passaporte::~Passaporte()
{
vacinas->clear();
aplicacoes->clear();
cout <<"Passaporte "<< nome<<" destruido"<<endl;
}

string Passaporte::getNome()
{
 return nome;
}

bool Passaporte::aplicaVacina(Vacina* v, int dataAplicacao)
{
  if (v ==NULL) throw new invalid_argument("Vacina invalida");
  if (dataAplicacao <= 0) throw new invalid_argument("Data de aplicacao da vacina invalida");

  if(v->getValidade() <dataAplicacao) throw new logic_error("Data de validade da vacina vencida");


   quantidade++;


  if(quantidade>MAXIMO_VACINAS) return false;

  vacinas->push_back(v);                //ESPECIFICADO PARA INSERIR OS VALORES EM VETORES DE CLASSE
  aplicacoes->push_back(dataAplicacao);

  return true;


}

Vacina** Passaporte::getVacinas()
{
    Vacina** vactemp = new Vacina*[quantidade-1];
    for(int i = 0; i< quantidade;i++){
        vactemp[i] = (*vacinas)[i];
    }
return vactemp;
}

int* Passaporte::getDataAplicacoes()
{
 int* aplitemp = new int[quantidade-1];
 for(int j = 0; j<quantidade;j++){
    aplitemp[j] = (*aplicacoes)[j];
 }
return aplitemp;
}

int Passaporte::getQuantidadeVacinas()
{
 return quantidade;
}

void Passaporte::imprimir()
{

}

