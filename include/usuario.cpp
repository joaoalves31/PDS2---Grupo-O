#include "usuario.hpp"
#include <iostream>

Usuario::Usuario() : idUsuario(0) {} // Inicializa o ID do usuário como 0

Usuario::Usuario(const std::string &nome, int idUsuario) : nome(nome), idUsuario(idUsuario) {}

void Usuario::criarConta(const std::string &nomeNovoUsuario)
{
    nome = nomeNovoUsuario;
    // Aqui você pode adicionar a lógica para gerar o ID do usuário
    // Por enquanto, vamos apenas imprimir uma mensagem indicando que a conta foi criada
    std::cout << "Conta criada para o usuário: " << nome << std::endl;
}

void Usuario::logIn()
{
    // Aqui você pode adicionar a lógica para realizar o login do usuário
    std::cout << "Usuário " << nome << " logado com sucesso!" << std::endl;
}

void Usuario::logOut()
{
    std::cout << "Tchau, " << nome << "!" << std::endl;
}

std::string Usuario::getNome()
{
    return nome;
}

int Usuario::getId()
{
    return idUsuario;
}
