#include <iostream>
#include "../include/sqlite/sqlite3.h"
#include "../include/usuario.hpp"

int main()
{
	/*
		Bem Vindo ao Banquin!

		Implemenetação de dois menus, um para gerar autenticação do usuário e outro para
		prover as opções dadas ao usuário. Utilização de uma variável para armazenar a
		intenção do usuário.
	*/

	int opcao {};

	// Primeiro Menu - Acesso ao Usuário
	while(true)
	{
		std::cout << "Bem Vindo ao Banquin!" << '\n';
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

	// TO DO - Registro do usuário

	// Segundo Menu - Opções do Usuário
	while(true)
	{
		opcao = 0;

		std::cout << "Bem Vindo <usuario>, o que voce gostaria de fazer hoje?" << '\n';
		std::cout << "[1] Depositar" << '\n';
		std::cout << "[2] Sacar" << '\n';
		std::cout << "[3] Transferir" << '\n';
		std::cout << "[4] Comprar Ações" << '\n';
		std::cout << "[5] Comprar Criptomoedas" << '\n';
		std::cout << "[6] Visualizar meu Extrato" << '\n';
		std::cout << "[7] Sair" << '\n';

		std::cin >> opcao;

		if (opcao == 7)
		{
			std::cout << "Tchau <usuario>!!!" << std::endl;
			exit(0);
		}
	}
}
