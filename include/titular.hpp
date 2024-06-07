#ifndef __TITULAR_HPP__
#define __TITULAR_HPP__

#include <iostream>
#include <string>
#include "pessoa.hpp"

class Titular : public Pessoa
{
private:

    std::string usuario, senha;

public:

    Titular(std::string n, int i, std::string c, std::string u, std::string s);
    Titular(std::string n, int i, std::string c);

    std::string get_senha();
    std::string get_usuario();
    std::string get_nome();
};

#endif