
//Header for "concessionarias" C++ application
//Created by r4m0nl1m4 09/09/2019

//Guarda
#ifndef concessionarias_H
#define concessionarias_H

//Bibliotecas
#include <ctime>
#include <iostream>
#include <list>
#include <string>

//Bibliotecas novas
#include "./automoveis.h"

//Classe implícita
using namespace std;

class concessionaria
{
    private:
        //propriedades
        string nome, cnpj;
        list<automovel> estoque;
        int naut;
    public:
        //contador objetos
        static int total;
        //Construtores
        concessionaria(string nome, string cnpj, list<automovel> estoque);
        concessionaria(string _nome, string _cnpj);
        concessionaria();
        //Destrutor
        ~concessionaria();

        //Métodos
        static int getTotal();
        void setNome(string setNome);
        string getNome();
        void setCNPJ(string setCNPJ);
        string getCNPJ();
        void setEstoque(list<automovel> setEstoque);
        list<automovel> getEstoque();
        list<automovel> getProducao_trimestre();
        void add_automovel();
        void increase_tax_rate(float n);

        //Sobrecarga de Operadores Relacionais
        bool operator ==(concessionaria a);
        bool operator !=(concessionaria a);

        //Sobrecarga do Operador de Atribuição
        concessionaria & operator =(const concessionaria & a);

        //Sobrecarga de Operadores IO
        friend istream & operator >>(istream & is, concessionaria & a);
        friend ostream & operator <<(ostream & os, concessionaria & a);
};

#endif    /* concessionarias_H */