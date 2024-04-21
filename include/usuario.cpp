#include <iostream>
#include <string>
#include "usuario.hpp"

void Usuario::pegarDados()
{
    std::string cpf;
    std::cout << "CPF: " << '\n';
    std::getline(std::cin, cpf);
    
    std::string senha;
    std::cout << "Senha: " << '\n';
    std::getline(std::cin, senha);
}

void Usuario::criarConta()
{
    void pegarDados();
}

void Usuario::logIn()
{
    void pegarDados();
}

void Usuario::logOut()
{
    std::cout << "Tchau!" << std::endl;
}