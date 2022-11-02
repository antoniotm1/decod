#include "intruso.hpp"

void Intruso::set_senha_vazada(std::string senha_vazada){
			_senhas_vazadas.push_back(senha_vazada);
		};
		
    std::string Intruso::crack_senha(){
    std::stringstream numeros;
	std::stringstream letras;
	std::stringstream temp;
	
	for(std::vector<std::string>::iterator it = _senhas_vazadas.begin(); it != _senhas_vazadas.end(); it++){
		numeros.str("");
		letras.str("");
		for(int i = 0; i < it->size(); i++){
			if(i%2 == 0 && i < 19)
				numeros << it->at(i);

			if(i%2 == 0 && i > 19)
				letras << it->at(i);
		}
		
		temp.str("");
		for(int i = 0; i < letras.str().size(); i++){
			if(letras.str().at(i) == 'A')
				temp << numeros.str().at(0) << numeros.str().at(1);
			if(letras.str().at(i) == 'B')
				temp << numeros.str().at(2) << numeros.str().at(3);
			if(letras.str().at(i) == 'C')
				temp << numeros.str().at(4) << numeros.str().at(5);
			if(letras.str().at(i) == 'D')
				temp << numeros.str().at(6) << numeros.str().at(7);
			if(letras.str().at(i) == 'E')
				temp << numeros.str().at(8) << numeros.str().at(9); 
		}
		_senhas_organizadas.push_back(temp.str());
	}


    for(std::vector<std::string>::iterator a = _senhas_organizadas.begin(); a != _senhas_organizadas.end() - 1; a++){
		for(std::vector<std::string>::iterator b = _senhas_organizadas.begin() + 1; b != _senhas_organizadas.end(); b++){
			int aux = 0;
			for(int k = 0; k < 6; k++){
				for(int i = 2*aux; i < 2*aux + 2; i++){
					for(int j = 2*aux; j < 2*aux + 2; j++){
						if(a->at(i) == b->at(j)){
					        _senha_crackeada << a->at(i) << " ";
						}
					}
				}
			    aux++;
			}
		}
	}
	
    for(int i = _senha_crackeada.str().size() - 12; i < _senha_crackeada.str().size(); i++)
        _senha_final << _senha_crackeada.str().at(i);
	
	return _senha_final.str();
	
	

}
