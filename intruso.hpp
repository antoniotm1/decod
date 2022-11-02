#include <string>
#include <sstream>
#include <vector>

class Intruso{
    std::vector<std::string> _senhas_vazadas;
	std::vector<std::string> _senhas_organizadas;
	std::stringstream _senha_crackeada;
    std::stringstream _senha_final;

    public:
        void set_senha_vazada(std::string vazou);
        std::string crack_senha();
};