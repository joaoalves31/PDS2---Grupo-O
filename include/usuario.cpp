#include <iostream>
#include <string>
#include "usuario.hpp"

void Usuario::signIn()
{
    std::string cpf;
    std::cout << "CPF: " << '\n';
    std::getline(std::cin, cpf);
    
    std::string senha;
    std::cout << "Senha: " << '\n';
    std::getline(std::cin, senha);
}

void Usuario::logIn()
{
    std::string cpf;
    std::cout << "CPF: " << '\n';
    std::getline(std::cin, cpf);
    
    std::string senha;
    std::cout << "Senha: " << '\n';
    std::getline(std::cin, senha);

    this->username = "NOMEDAPESSOA";
}

void Usuario::logOut()
{
    std::cout << "Tchau!" << std::endl;
}