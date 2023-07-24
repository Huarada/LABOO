#include <stdexcept>
#include <string>

using namespace std;

class SemAvaliacao : public invalid_argument{
 public:
     SemAvaliacao(string mensagem);

     ~SemAvaliacao();

 private:

    string mensagem;


};
