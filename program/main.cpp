#include <iostream>

#include "banco.hpp"
#include "conta.hpp"
#include "contaPoupança.hpp"
#include "cpf.hpp"
#include "pessoa.hpp"
#include "titular.hpp"
#include "contaUniversitaria.hpp"
#include "transacao.hpp"
#include "ExcecaoCpf.hpp"
#include "ExcecaoNegativo.hpp"
#include "ExcecaoSaque.hpp"
#include "ExcecaoTransferencia.hpp"

using namespace std;

int main()
{

    try
    {
        Banco banco;


        Titular t1("PedroFeijao", 20, "11125298618", "feijao", "0987");
        ContaPoupanca p2(t1);
        banco.adicionaConta(p2);
        
        Titular t2("Joao", 20, "12345678900", "joao", "123");
        ContaPoupanca p5(t2);
        banco.adicionaConta(p5);
        
        Titular t3("Andre", 23, "69426942690", "andre", "0000");
        ContaPoupanca p3(t3);
        banco.adicionaConta(p3);

        Conta *contaLogada = banco.login();

        int operacao = 0;

        do
        {
            try
            {
                operacao = banco.selecionaOperacao();

                banco.realizaOperacao(operacao, contaLogada);

                if (operacao == 5)
                {
                    //system("");
                    contaLogada = banco.login();
                }           
                else if(operacao == 7 || operacao == 0) {
                break;
                }   
              
            }
            catch (ExcecaoNegativo &e)
            {
                cout << e.what() << endl;
                cout << "====================================================================\n";
                cin.get();
            }
            catch (ExcecaoSaque &e)
            {
                cout << e.what() << endl;
                cout << "====================================================================\n";
                cin.get();
            }
            catch (ExcecaoCpf &e)
            {
                cout << e.what() << endl;
                cout << "====================================================================\n";
                cin.get();
            }
            catch (ExcecaoTransferencia &e)
            {
                cout << e.what() << endl;
                cout << "====================================================================\n";
                cin.get();
            }

        } while (operacao != 7);
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
        cout << "====================================================================\n";
        cin.get();
    }
}
