#include <iostream>
#include "../include/sqlite/sqlite3.h"
#include "../include/usuario.hpp"

void clear_screen() {
    std::cout << "\033[2J\033[H"; // Função que limpa o console;
}

int main()
{
    /*
        Bem Vindo ao Banquin!

        Implementação de dois menus, um para gerar autenticação do usuário e outro para
        prover as opções dadas ao usuário. Utilização de uma variável para armazenar a
        intenção do usuário.
    */

    int opcao {};

    // Primeiro Menu - Acesso ao Usuário
    while(true)
    {
        clear_screen();

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
    // TO DO - Registro do usuário
if (opcao == 2) // Se o usuário escolheu a opção de criar conta
{
    clear_screen();
    std::cout << "Bem Vindo ao Banquin!" << '\n';
    std::cout << "Vamos começar o cadastro de um novo usuário." << '\n';
    
    // Variável para armazenar o nome do novo usuário
    std::string nomeNovoUsuario;
    std::cout << "Digite o nome do novo usuário: ";
    std::cin.ignore(); // Limpa o buffer do teclado
    std::getline(std::cin, nomeNovoUsuario);
    
    // Cria um objeto Usuario para lidar com o cadastro
    Usuario novoUsuario;
    novoUsuario.criarConta(nomeNovoUsuario);
}

    // Segundo Menu - Opções do Usuário
    while(true)
    {
        opcao = 0;

        std::cout << "Bem Vindo <usuario>, o que voce gostaria de fazer hoje?" << '\n';
        std::cout << "[1] - Depositar" << '\n';
        std::cout << "[2] - Sacar" << '\n';
        std::cout << "[3] - Transferir" << '\n';
        std::cout << "[4] - Comprar Ações" << '\n';
        std::cout << "[5] - Comprar Criptomoedas" << '\n';
        std::cout << "[6] - Visualizar meu Extrato" << '\n';
        std::cout << "[7] - Sair" << '\n';

        std::cin >> opcao;

        if (opcao == 7)
        {
            clear_screen();

            std::cout << "Tchau <usuario>!!!" << std::endl;
            exit(0);
        }
    }

    return 0;
}
