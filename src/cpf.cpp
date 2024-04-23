#include "../include/cpf.hpp"
#include <iostream>
#include <regex>

bool Cpf::cpfValido(const std::string &cpf)
{
    // Expressão regular para validar CPF
    std::regex pattern("\\d{3}\\.\\d{3}\\.\\d{3}-\\d{2}");
    return std::regex_match(cpf, pattern);
}

Cpf::Cpf(const std::string &n) : numero(n)
{
    if (!cpfValido(numero))
    {
        std::cerr << "CPF inválido!" << std::endl;
        // Atribuir um valor padrão para o número do CPF
        numero = "000.000.000-00";
    }
}

std::string Cpf::get_numero()
{
    return numero;
}
