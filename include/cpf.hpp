#pragma once

#include <string>

class Cpf
{
private:
    std::string numero;
    bool cpfValido(const std::string &cpf);
    bool validarDigitos(const std::string &cpf);

public:
    Cpf(const std::string &n);
    std::string get_numero() const;
};
