#ifndef USUARIO_H
#define USUARIO_H

class Usuario
{
    private:
        std::string username;
        void pegarDados();
        
    public:
        void criarConta();
        void logIn();
        void logOut();
};

#endif