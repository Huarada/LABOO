
class PersistenciaDeRede{
public:

PersistenciaDeRede(string arquivo);
virtual ~PersistenciaDeRede();

virtual Rede* carregar();

private:

string arquivo;
Rede*
};
