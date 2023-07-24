#include <iostream>
#include <string>
#include "Segmento.h"
#include "Datagrama.h"
#include <stdexcept>
#include "FilaComPrioridade.h"

#include "Roteador.h"
using namespace std;

int main()
{   // O TRY EH PRA VALER
    try{
    Fila *pilha0 = new Fila(-1);
    Fila *pilha1 = new Fila (0);

    Segmento *s0 = new Segmento(1,1,"peido");
    Datagrama *d1 = new Datagrama(1,2, s0);
    Datagrama *d2 = new Datagrama(3,2,s0);
    Datagrama *d3 = new Datagrama(3,3 ,s0);


    Fila *pilha2 = new Fila(2);
    pilha2->dequeue();
    pilha2->enqueue(d1);
    pilha2 ->enqueue(d2);
    pilha2 ->enqueue(d3);

    } catch (invalid_argument *e){cout << e->what() <<endl;
                                  delete e;}
      catch (overflow_error *o){cout << o->what();
                                delete o;}
      catch (underflow_error *u){cout <<u ->what();
                                 delete u;}


/*    cout << "Hello world!" << endl;

 Segmento *seg1 = new Segmento(1,2,"teste");
    seg1->imprimir();

    Datagrama* dat1 = new Datagrama(24,33,seg1);
    dat1 ->imprimir();

*/
// TESTES DA PRIORIDADE

Segmento * seg8 = new Segmento(1,0,"d8");
Datagrama* d8 = new Datagrama(1,2,seg8);

Segmento * seg9 = new Segmento(1,0,"d9");
Datagrama* d9 = new Datagrama(1,2,seg9);

Segmento * segp1 = new Segmento(1,0,"p1");
Datagrama* p1 = new Datagrama(1,2,segp1);

Segmento * segp2 = new Segmento(1,0,"p2");
Datagrama* p2 = new Datagrama(1,2,segp2);


FilaComPrioridade* f1 = new FilaComPrioridade(5);
f1->enqueue(d8,false);
f1->enqueue(d9,false);
f1->enqueue(p1,true);
f1 ->enqueue(p2,true);

f1->imprimir();

 Roteador* rot1 = new Roteador(5);




//TESTAR O METODO MAPEAR!!!!!

TabelaDeRepasse* tab2 = new TabelaDeRepasse(6);

rot1->mapear(4,new No(1),7);


rot1->mapear(3,new No(2),21);
rot1->mapear(1,new No(9),43);
rot1->mapear(65,new No(10),20);









    return 0;
}
