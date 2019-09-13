
//Body for "concessionarias" C++ application
//Created by r4m0nl1m4 09/09/2019

//Cabeçalho
#include "./concessionarias.h"

//Construtores

concessionaria::concessionaria(string _nome, string _cnpj, list<automovel> _estoque)
{
    nome = _nome;
    cnpj = _cnpj;
    estoque = _estoque;
    naut = _estoque.size();
    total++;
}

concessionaria::concessionaria(string _nome, string _cnpj)
{
    nome = _nome;
    cnpj = _cnpj;
    naut = 0;
    total++;
}

concessionaria::concessionaria()
{
    naut = 0;
}

//Destrutor

concessionaria::~concessionaria() {}

//Métodos

int concessionaria::getTotal()
{
    return total;
}

void concessionaria::setNome(string setNome)
{
    nome = setNome;
}

string concessionaria::getNome()
{
    return nome;
}

void concessionaria::setCNPJ(string setCNPJ)
{
    cnpj = setCNPJ;
}

string concessionaria::getCNPJ()
{
    return cnpj;
}

void concessionaria::setEstoque(list<automovel> setEstoque)
{
    estoque = setEstoque;
}

list<automovel> concessionaria::getEstoque()
{
    return estoque;
}

list<automovel> concessionaria::getProducao_trimestre()
{
    double idade = 0, trimestre = 3*30*24*60*60;
    list<automovel> proT;
    time_t now, dataF;

    //Acesso ao estoque de automóveis
    for(list<automovel>::iterator i = estoque.begin() ; i != estoque.end() ; i++)
    {   
        //Data atual
        now = time(NULL);
        //Data de fabricação
        dataF = (*i).getDataF();
        //Idade da produção em segundos
        idade = difftime(now, dataF);
        if(idade <= trimestre)
        {
            proT.push_back(*i);
        }    
    }

    return proT;
}

void concessionaria::add_automovel()
{
    automovel novo;
    cin >> novo;

    list<automovel>::iterator i;

    //Acesso ao estoque de automóveis
    for(i = estoque.begin() ; i != estoque.end() ; i++)
    {
        //Lógica operacional para a aferição de igualdade
        if((*i) == novo)
        {
            cout << endl << "ERROR! Automovel já adicionado" << endl;
            (*i).total--;
            //Sai da iteração
            break;
        } 
    }

    //Lógica operacional para o incremento de um automóvel ao estoque
    if((*i) != novo)
    {
        estoque.push_back(novo);
        naut++;
    } 
}

void concessionaria::increase_tax_rate(float n)
{
    //Acesso ao estoque de automóveis
    for(list<automovel>::iterator i = estoque.begin() ; i != estoque.end() ; i++)
    {
        (*i).setPreco( (*i).getPreco()*( 1+n/100 ) );
    }
}

//Sobrecarga de Operadores Relacionais

bool concessionaria::operator ==(concessionaria a)
{
    return ( nome == a.nome && cnpj == a.cnpj );
}

bool concessionaria::operator !=(concessionaria a)
{
    return ( nome != a.nome || cnpj != a.cnpj );
}

//Sobrecarga do Operador de Atribuição

concessionaria & concessionaria::operator =(const concessionaria & a)
{
    if (this != & a)
    {
        nome = a.nome;
        cnpj = a.cnpj;
        estoque = a.estoque;
    }
    return *this;
}

//Sobrecarga de Operadores IO

istream & operator >>(istream & is, concessionaria & a)
{
    list<automovel> estoque;
    int qntd = 0;
    string nome, cnpj, comando; 

    cout << "Concessionária" << endl;
    cout << " Digite o nome: ";
    //Limpa o caracter de nova linha \n do buffer de entrada
    cin.ignore(nome.size(),'\n');
    //Lê o dado de entrada até que uma nova linha seja detectada
    getline(cin, nome);

    cout << " Digite o CNPJ: ";    
    cin.ignore(cnpj.size(),'\n');
    getline(cin, cnpj);

    cout << " Cadastrar auto [Y/N]? ";
    cin.ignore(comando.size(),'\n');
    getline(cin, comando);

    a = concessionaria(nome, cnpj);

    //Lógica operacional para o incremento do estoque
    if (comando == "Y" || comando == "y" )
    {
        cout << " Digite a qntd: ";
        cin >> qntd;
    }

    //Adiciona uma quantidade de automóveis ao estoque
    for(int i = 0 ; i < qntd ; i++)
    {
        a.add_automovel();
    }

    return is;
}

ostream & operator <<(ostream & os, concessionaria & a)
{
    cout << "├── Concessionária"                               << endl;
    cout << "├─── Nome " << a.nome                             << endl;
    cout << "├─── CNPJ " << a.cnpj                             << endl;
    cout << "├─── Naut " << a.naut                             << endl;
    cout << "├─── ProT " << (a.getProducao_trimestre()).size() << endl;

    //Acesso ao estoque de automóveis
    for(list<automovel>::iterator i = a.estoque.begin() ; i != a.estoque.end() ; i++)
    {
        cout << *i ;    
    }

    return os;
}