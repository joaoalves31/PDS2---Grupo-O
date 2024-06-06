#include<iostream>
#include<string>
#pragma once

class ExcecaoTransferencia:public std::exception{
    private:
 
    std:: string _erro;
    
};