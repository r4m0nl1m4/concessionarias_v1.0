
//Header for "automoveis" C++ application
//Created by r4m0nl1m4 09/09/2019

//Guarda
#ifndef automoveis_H
#define automoveis_H

//Bibliotecas
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

//Classe implícita
using namespace std;

class automovel
{
    private:
        //propriedades
        string marca;
        float preco, chass;
        time_t dataF;
    public:        
        //contador objetos
        static int total;

        //Construtores
        automovel(string marca, float preco, float chass, time_t dataF);
        automovel(string marca, float preco, float chass);
        automovel();

        //Destrutor
        ~automovel();

        //Métodos
        static int getTotal();
        void setMarca(string setMarca);
        string getMarca();
        void setPreco(float setPreco);
        float getPreco();
        void setChass(float setChass);
        float getChass();
        void setDataF(time_t setDataF);
        time_t getDataF();

        //Sobrecarga de Operadores Relacionais
        bool operator ==(automovel a);
        bool operator !=(automovel a);

        //Sobrecarga do Operador de Atribuição
        automovel & operator =(const automovel & a);

        //Sobrecarga de Operadores IO
        friend istream & operator >>(istream & is, automovel & a);
        friend ostream & operator <<(ostream & os, automovel & a);
};

#endif    /* automoveis_H */