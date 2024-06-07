#ifndef CONTA_HPP
#define CONTA_HPP

#include <iostream>
#include <map>
#include "titular.hpp"

class Conta {
private:
    Titular titular;
    float saldo;

public:
    Conta(Titular t);
    ~Conta();

    void realizaSaque(float valorSaque);
    void realizaDeposito(float valorDeposito);
    float get_saldo();
    void imprimeSaldo();
    void transfere(std::string userDestino, float valor, std::map<std::string, Conta *> contas);
    Titular *get_titular();
    void enviaValor(float valor);
    void recebeValor(float valor);

    virtual float taxaSaque();
};

#endif // CONTA_HPP
