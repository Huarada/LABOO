
#include "PersistenciaDeRede.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

using namespace std;

PersistenciaDeRede::PersistenciaDeRede(string arquivo){
 this->arquivo = arquivo;

}

PersistenciaDeRede::~PersistenciaDeRede(){
}


Rede* PersistenciaDeRede::carregar(){

int quantidadeRot = 0;
int quantidade = 0;

ifstream input;

input.open(arquivo);

if (input.fail()){
    input.close();
    throw new invalid_argument("Erro de leitura");

}


input>> quantidadeRot;  // Se falhar n entra no laco

int endereco_temp = 0;

rot_vec = new Roteador*[quantidadeRot];

for( int i = 0; i < quantidadeRot && input ; i++){ // descricao dos roteadores

      input>> contorno;
      if(contorno == "r"){ // classe roteador
        input>> endereco_temp;
        rot_temp = new Roteador(endereco_temp);
        rot_vec[i] = rot_temp;

        redetemp->adicionar(rot_temp);

      }

      else if(contorno == "q"){ // Classe roteadro com qos
        int nprioridade;
        input>>endereco_temp>>nprioridade;
        rotqos_temp = new RoteadorComQoS(endereco_temp);
        for(int j = 0; j< nprioridade;j++){
            input>>endereco_temp;
            rotqos_temp->priorizar(endereco_temp);}
        rot_vec[i] = rotqos_temp;
        redetemp ->adicionar(rotqos_temp); //TA ERRADO, TEM Q ADICIONAR NO FINAL
        }
      }

input>> quantidade; // agora ver quantos hospedeiros tem no arquivo

int quantidadechat,gateendereco,atraso = 0;    // variaveis para criacao de hospedeiro
int  porta,addressdestino, portadestino = 0;                                  //variaveis para a criacao de chat

for( int k = 0; k < quantidade && input; k++){ // adicionar um && input , cria cada hospedeiro


    input>>endereco_temp>>gateendereco>>atraso>>quantidadechat;
    Roteador* gateway= new Roteador(gateendereco);
    hosptemp = new Hospedeiro(endereco_temp,gateway,atraso);

    for( int z = 0; z< quantidadechat; z++){ // adicionar chat

        input>> porta>> addressdestino >> portadestino;
        hosptemp->adicionarChat(porta,addressdestino,portadestino);
        }

    redetemp->adicionar(hosptemp);


}
//variaveis para o mapeamento



int tabelarot,rotender, atrpad, numeromap;
int destinotabela,adjaddress, atrasotabela;


while(input){        //mapeamento das tabelas
  input>> tabelarot>> rotender >> atrpad >> numeromap;

  Roteador* rotpad = new Roteador(rotender);
  rot_vec[tabelarot]->setPadrao(rotpad,atrpad);
  for(int x = 0; x< numeromap; x++){
  input>> destinotabela>>adjaddress>>atrasotabela;
  Roteador* adjacentetabela = new Roteador(adjaddress);
  rot_vec[tabelarot]->mapear(destinotabela,adjacentetabela,atrasotabela);
  }




}


return redetemp;
}
