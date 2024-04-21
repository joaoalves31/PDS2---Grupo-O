#ifndef USUARIO_H
#define USUARIO_H

class Usuario
{
    private:
        std::string nome;
        int idUsuario;
        void pegarDados();
        
    public:
        void criarConta();
        void logIn();
        void logOut();
};

#endif