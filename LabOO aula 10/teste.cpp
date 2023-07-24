// Faca os includes necessarios
#include "PersistenciaMusica.h"
#include "Musica.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void teste() {
    // IMPLEMENTE seguindo o enunciado
    PersistenciaMusica * obj = new PersistenciaMusica("teste.txt");




   try{
    int quantidade;
    Musica** musicvec = obj ->obter(quantidade);

    cout << quantidade << " musica(s),";
    for( int i = 0; i < quantidade ; i++){

      musicvec[i] ->imprimir();

    }

    }

    catch(invalid_argument *e){
     cout << e->what();
     delete e;}
    catch(logic_error *r){
    cout<< *r ->what();
    delete r;}




}

int main() {
    teste();
    return 0;
}


