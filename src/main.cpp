#include <iostream>
#include "include/database.hpp"
#include "include/usuario.hpp"


int main()
{
	Database db;
	int opcao {};

	// Primeiro Menu - Acesso ao Usuário
	while(true)
	{
		std::cout << "Bem Vindo ao Banquinho!" << '\n';
		std::cout << "Primeiro, registre-se ou entre em nosso sistema." << '\n';
		std::cout << "[1] Entrar na Minha conta" << '\n';
		std::cout << "[2] Criar Conta" << '\n';
		std::cout << "[3] Sair do Sistema" << '\n';

		std::cin >> opcao;

		if (opcao == 3)
		{
			std::cout << "Volte Sempre!" << std::endl; 
			exit(0);
		}
		else if (opcao == 1 || opcao == 2)
		{
			break;
		}
	}

	/* TO DO
		Registro do usuário!
	*/

	// Segundo Menu - Opções do Usuário
	while(true)
	{
		opcao = 0;

		std::cout << "Bem Vindo <usuario>, o que voce gostaria de fazer hoje?" << '\n';
		std::cout << "[1] ..." << '\n';
		std::cout << "[10] Sair" << '\n';

		if (opcao == 10)
		{
			std::cout << "Tchau <usuario>!!!" << std::endl;
		}

	}
}
