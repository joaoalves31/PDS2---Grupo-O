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