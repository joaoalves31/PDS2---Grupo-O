#include "contaPoupança.hpp"


ContaPoupanca::ContaPoupanca(Titular t) : Conta(t) {}


float ContaPoupanca::taxaSaque()
{
	return 0.01;
}
