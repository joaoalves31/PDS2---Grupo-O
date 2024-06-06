#include "Cpf.hpp"
#include "ExcecaoCpf.hpp"
#include <algorithm>
#include <cctype>

Cpf::Cpf(const std::string &n) : numero(n)
{
    // Remover caracteres não numéricos
    numero.erase(std::remove_if(numero.begin(), numero.end(),
        [](char c) { return !isdigit(c); }), numero.end());

    if (!cpfValido(numero))
    {
        throw ExcecaoCpf();
    }
}

std::string Cpf::get_numero() const
{
    return numero;
}

bool Cpf::cpfValido(const std::string &cpf)
{
    if (cpf.size() != 11)
    {
        return false;
    }

    // Checar se todos os dígitos são iguais
    if (std::all_of(cpf.begin(), cpf.end(), [&](char c) { return c == cpf[0]; }))
    {
        return false;
    }

    return validarDigitos(cpf);
}

bool Cpf::validarDigitos(const std::string &cpf)
{
    // Implementação da validação dos dígitos verificadores
    int soma1 = 0, soma2 = 0;
    for (int i = 0; i < 9; ++i)
    {
        int digito = cpf[i] - '0';
        soma1 += digito * (10 - i);
        soma2 += digito * (11 - i);
    }

    int digito1 = (soma1 * 10) % 11;
    if (digito1 == 10) digito1 = 0;

    soma2 += digito1 * 2;
    int digito2 = (soma2 * 10) % 11;
    if (digito2 == 10) digito2 = 0;

    return (digito1 == (cpf[9] - '0') && digito2 == (cpf[10] - '0'));
}
