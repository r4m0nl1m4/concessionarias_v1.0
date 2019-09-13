
//Main for "concessionarias" C++ application
//Created by r4m0nl1m4 09/09/2019

//Bibliotecas
#include <iostream>
#include <string>

//Bibliotecas novas
#include "./automoveis.h"
#include "./concessionarias.h"

//Classe implícita
using namespace std;

//inicialização dos atributos estáticos das classes
int automovel::total = 0, concessionaria::total = 0;

//Program
int main(int argc, char* argv[])
{
	//Declaração das concessionárias
	concessionaria c1;

	//Instanciação de uma concessionária
	cout << endl << "...Instanciação de uma concessionária..." << endl << endl;
	cin >> c1;

	//Apresentação dos dados das concessionárias
	cout << endl << "...Apresentação dos dados da(s) concessionária(s)..." << endl << endl;
	cout << c1;

	//Produção trimestral da(s) concessionária(s)
	cout << endl << "...Produção trimestral da(s) concessionária(s)..." << endl << endl;
	list<automovel> ptotal1 = c1.getProducao_trimestre();
	cout << "├── Concessionária " << c1.getNome() << " produziu " << ptotal1.size() << " automovel(is) no último trimestre." << endl;
    for(list<automovel>::iterator i = ptotal1.begin() ; i != ptotal1.end() ; i++)
    {   
        cout << *i << endl;  
    }
    if(ptotal1.size() == 0)
    {
        cout << "├─── Nenhum automóvel produzido no último trimestre" << endl;
    }	

	//Ajuste nos preços dos veículos de uma concessionária
	cout << "...Aplicando o incremento de 50% na alíquota do preço dos veículos de uma concessionária..." << endl;
	c1.increase_tax_rate(50);
	cout << endl << c1 ;

	//Total de automóveis
	int atotal = automovel::getTotal();
	//Total de concessionárias
	int ctotal = concessionaria::getTotal();
    //Média de automóveis por concessionárias
	float amedia = float(atotal)/float(ctotal);
	//Produção trimestral total da(s) concessionária(s)
	int ptotal = ptotal1.size();

    //Apresentação do balanço das operações das concessionárias 
    cout << endl << "...Apresentação do balanço das operações da(s) concessionária(s)..." << endl << endl;    
    cout << "Balanço             " << endl;
    cout << " Média              " << amedia << endl;
    cout << " Automóveis         " << atotal << endl;
    cout << " Concessionárias    " << ctotal << endl;
    cout << " Produção Trimestre " << ptotal << endl;
    cout << endl;

	return 0;
}