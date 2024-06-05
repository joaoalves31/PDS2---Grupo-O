#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "conta.hpp"
#include <map>
#include "transacao.hpp"


class Banco
{
public:

    std::vector<std::string> Users;

    std::map<std::string, Conta *> Contas;

    std::vector<Transacao>transacoes;

    float saldo;

public:

    Banco();

    void adicionaConta(Conta &conta);

    Conta *login();

    int selecionaOperacao();

    void realizaOperacao(int opcao, Conta *conta);

    float get_saldo();

    void imprimeExtrato();
};