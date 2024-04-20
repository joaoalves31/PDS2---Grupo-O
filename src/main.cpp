#include <iostream>
#include "include/usuario.hpp"

int main()
{
	std::cout << "Bem Vindo ao Banquinho!" << '\n';
	std::cout << "Primeiro, registre-se ou entre em nosso sistema." << '\n';
	std::cout << "[1] Entrar na Minha conta" << '\n';
	std::cout << "[2] Criar Conta" << '\n';
	std::cout << "[3] Sair do Sistema" << '\n';

	int opcao;
	std::cin >> opcao;

	if (opcao == 3)
	{
		std::cout << "Volte Sempre!" << std::endl; 
		exit(0);
	}

	Usuario usuarioAtual;
	if (opcao == 2)
	{
		usuarioAtual.criarConta();
	}
}
