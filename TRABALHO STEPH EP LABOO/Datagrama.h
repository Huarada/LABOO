#ifndef DATAGRAMA_H
#define DATAGRAMA_H




#include <string>



using namespace std;


class Datagrama{
  private:
    int origem;
    int destino;
    string dado;




  public:
   Datagrama(int origem, int destino, string dado);
   ~Datagrama();
   int getOrigem();
   int getDestino();
   string getDado();
   void imprimir();


};



#endif  // DATAGRAMA_H















