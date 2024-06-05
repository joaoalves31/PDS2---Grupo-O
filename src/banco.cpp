#include "../include/banco.hpp"
#include "ExcecaoCpf.hpp"
#include "ExcecaoNegativo.hpp"
#include "ExcecaoSaque.hpp"
#include "ExcecaoTransferencia.hpp"


bool existe(std::string palavra, std::vector<std::string> vetor)
{
    for (unsigned int i = 0; i < vetor.size(); i++)
    {
        if (vetor[i] == palavra)
        {
            return true;
        }
    }
    return false;
}


Banco::Banco()
{
    std::cout << "\n\n    ============ Seja bem-vindo ao NossoBanco! ================" << std::endl;
    std::cout << "====================================================================\n";
    saldo = 10000;
}

void Banco::realizaOperacao(int opcao, Conta *conta)
{
    if (opcao == 1)
    {
        float valorSaque;
        std::cout << "====================================================================\n";
        std::cout << "Digite o valor do saque ou digite 9 para cancelar a operação" << std::endl;
        std::cout << "↓\n";
        std::cin >> valorSaque;
        system("clear");
        if (valorSaque == 9){
            system("clear");
            Banco::selecionaOperacao();
        }
            else {
            if (valorSaque <= saldo)
            {
                conta->realizaSaque(valorSaque);
                Transacao t(valorSaque, "Saque", conta->get_titular()->get_nome());
            transacoes.push_back(t);
            }
            else
            {
                std::cout << "====================================================================\n";
                throw ExcecaoSaque();
                std::cout << "====================================================================\n";
            }
        }
    }

    else if (opcao == 2)
    {
            float valorDeposito;
            std::cout << "====================================================================\n";
            std::cout << "Digite o valor do depósito ou digite 9 para cancelar a operação" << std::endl;
            std::cout << "↓\n";
            std::cin >> valorDeposito;
            system("clear");
                if (valorDeposito == 9){
                    system("clear");
                    Banco::selecionaOperacao();
                }
            else
            {
            conta->realizaDeposito(valorDeposito);
            Transacao t(valorDeposito, "Depósito", conta->get_titular()->get_nome());
            transacoes.push_back(t);
        }
    }
    else if (opcao == 3)
    {
            float valorTransferencia;
            bool usuarioExiste =  false;
            std::string userReceber;
            std::cout << "\nInforme o valor a ser transferido e o usuário de quem vai receber ou digite 9 para cancelar a operação: " << std::endl;
            std::cout << "↓\n";
            std::cin >> valorTransferencia >> userReceber;
            system("clear");
            if (valorTransferencia == 9){
                    system("clear");
                Banco::selecionaOperacao();
                }
            else if (valorTransferencia != 9) {
                while(!usuarioExiste){
                    if(existe(userReceber,Users)){
                            usuarioExiste = true;
                }

                    else {
                                    usuarioExiste = false;
                        std::cout << "====================================================================\n";
                                    std::cout << "Digite um usuário válido.\n";
                        std::cout << "====================================================================\n";
                                }

            conta-> transfere(userReceber, valorTransferencia, Contas);
           Transacao t(valorTransferencia, "Transferencia", conta->get_titular()->get_nome(), Contas[userReceber]->get_titular()->get_nome());
            transacoes.push_back(t);
            }
        }
    }
    else if (opcao == 4)
    {
        conta->imprimeSaldo();
    }
    else if (opcao == 5)
    {
        std::cout << "====================================================================\n";
    }
    else if (opcao == 6)
    {
        if (transacoes.size() == 0) {
            system("clear");
            std::cout << "====================================================================\n";
            std::cout << "Nenhuma transação foi realizada!\n";
            std::cout << "====================================================================\n";
        }
        else if (transacoes.size() != 0) {
        std::cout << "====================================================================\n";
        std::cout << "Extrato: \n\n";
            imprimeExtrato();
        std::cout << "====================================================================\n";
        }
    }
    else if (opcao == 7)
    {
        std::cout << "\n============ Agradecemos por utilizar o NossoBanco! ================" << std::endl;
        std::cout << "====================================================================\n";
    }
}


int Banco::selecionaOperacao()
{
    int opcao;
    std::cout << "Digite a opção referente a sua operação: " << std::endl;
    std::cout << "[1] - Saque\n[2] - Depósito\n[3] - Transferência\n[4] - Saldo\n[5] - Fazer login\n[6] - Extrato\n[7] - Finalizar operação\n" << std::endl;
    std::cout << "====================================================================\n";
    std::cin >> opcao;
    return opcao;
}

void Banco::adicionaConta(Conta &conta)
{
    std::string nomeDoUsuario = conta.get_titular()->get_usuario();
    Contas[nomeDoUsuario] = &conta;
    Users.push_back(nomeDoUsuario);
}