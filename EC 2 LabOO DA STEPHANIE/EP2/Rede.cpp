#include "Rede.h"

Rede::Rede() : nos(new list<No*>()) {}

Rede::~Rede() {
    while (!nos->empty()) {
        No *deletando = nos->front();
        nos->pop_front();
        delete deletando;
    }
    delete[] nos;
}

void Rede::adicionar(No* n) {
    list<No*>::iterator ad = nos->begin();
    while (ad != nos->end()) {
        if (*ad == n) throw new logic_error("Ja tem no");
        ad++;
    }
    nos->push_back(n);
}

No* Rede::getNo(int endereco) {
    list<No*>::iterator tem = nos->begin();
    while (tem != nos->end()) {
        if ((*tem)->getEndereco() == endereco) return (*tem);
        tem++;
    }
    return NULL;
}

list<No*>* Rede::getNos() {
    return nos;
}

list<Hospedeiro*>* Rede::getHospedeiros() {
    hospedeiros = new list<Hospedeiro*>();

    list<No*>::iterator i = nos->begin();

    while (i != nos->end()) {
        Hospedeiro *h1 = dynamic_cast<Hospedeiro*>(*i);
        if (h1 != NULL) {
            //hospedeiros->push_back(i);
        }
        i++;
    }
    return hospedeiros;
}

void Rede::imprimir() {
}
