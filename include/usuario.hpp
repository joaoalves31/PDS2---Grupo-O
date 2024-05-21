#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario
{
    private:
        std::string nome;
        int idUsuario;

    public:
        Usuario(); // Construtor padrão
        Usuario(const std::string &nome, int idUsuario); // Construtor com parâmetros
        void criarConta(const std::string &nomeNovoUsuario); // Função para criar uma nova conta de usuário
        void logIn(); // Função para realizar o login do usuário
        void logOut(); // Função para realizar o logout do usuário
        std::string getNome(); // Getter para o nome do usuário
        int getId(); // Getter para o ID do usuário
};

#endif
