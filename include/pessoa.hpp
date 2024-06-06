#ifndef __PESSOA_HPP__
#define __PESSOA_HPP__

#include <iostream>
#include <string>
#include "cpf.hpp"

class Pessoa
{
protected:

    std::string nome;
    Cpf cpf;

public:

    Pessoa(std::string n, int i, std::string c);
    
    std::string get_cpf();
};

#endif