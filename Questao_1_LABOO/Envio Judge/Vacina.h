#ifndef VACINA_H
#define VACINA_H

class Vacina {
public:
    Vacina(int dataFabricacao);
    virtual ~Vacina();
    virtual int getLote();
    virtual int getDataFabricacao();
    virtual int getValidade() = 0; // METODO ABSTRATO E NAO IMPLEMENTADO
    virtual void imprimir();
private:



protected:
   int dataFabricacao;
};

#endif // VACINA_H
