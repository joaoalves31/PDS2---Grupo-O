
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Transacao{
	private:
	
		float valor;

		std::string tipo;

		std::string autor;
		std::string destino;
	public:

		Transacao(float v, std::string t, std::string a);
		Transacao(float v, std::string t, std::string a, std::string d);

		float get_valor();

		std::string get_tipo();
		std::string get_autor();
		std::string get_destino();	
};