
#include<iostream>
#include<string>

#pragma once

class ExcecaoCpf:public std::exception{

    std:: string _erro;
    public:

    ExcecaoCpf();
    virtual const char* what() const noexcept override;
};