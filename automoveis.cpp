
//Body for "automoveis" C++ application
//Created by r4m0nl1m4 09/09/2019

//Cabeçalho
#include "./automoveis.h"

//Construtores

automovel::automovel(string _marca, float _preco, float _chass, time_t _dataF)
{
    marca = _marca;
    preco = _preco;
    chass = _chass;
    dataF = _dataF;
    total++;
}

automovel::automovel(string _marca, float _preco, float _chass)
{
    marca = _marca;
    preco = _preco;
    chass = _chass;
    dataF = time(NULL);
    total++;
}

automovel::automovel()
{
    preco = 0;
    chass = 0;
    dataF = time(NULL);
}

//Destrutor

automovel::~automovel() {}

//Métodos

int automovel::getTotal()
{
    return total;
}

void automovel::setMarca(string setMarca)
{
    marca = setMarca;
}

string automovel::getMarca()
{
    return marca;
}

void automovel::setPreco(float setPreco)
{
    preco = setPreco;
}

float automovel::getPreco()
{
    return preco;
}

void automovel::setChass(float setChass)
{
    chass = setChass;
}

float automovel::getChass()
{
    return chass;
}

void automovel::setDataF(time_t setDataF)
{
    dataF = setDataF;
}

time_t automovel::getDataF()
{
    return dataF;
}

//Sobrecarga de Operadores Relacionais

bool automovel::operator ==(automovel a)
{
    return ( (marca == a.marca && preco == a.preco) && (chass == a.chass && dataF == a.dataF) );
}

bool automovel::operator !=(automovel a)
{
    return ( (marca != a.marca || preco != a.preco) || (chass != a.chass || dataF != a.dataF) );
}

//Sobrecarga do Operador de Atribuição

automovel & automovel::operator =(const automovel & a)
{
    if (this != & a)
    {
        marca = a.marca;
        preco = a.preco;
        chass = a.chass;
        dataF = a.dataF;
    }
    return *this;
}

//Sobrecarga de Operadores IO

istream & operator >>(istream & is, automovel & a)
{
    automovel aux;
    string marca;
    float preco = 0, chass = 0;
    struct tm data = {0};
    time_t dataF;
    int y = 0, m = 0, d = 0; 

    cout << " Automóvel" << endl;
    cout << "  Digite a marca: ";
    cin.ignore(sizeof(is),'\n');
    getline(cin, marca);

    cout << "  Digite o preço: ";
    cin >> preco;

    cout << "  Digite o chass: ";
    cin >> chass;

    cout << "  Digite a dataF: " << endl;
    cout << "   Digite o dia [ 1-31 ]: ";
    cin >> d;
    cout << "   Digite o mes [ 1-12 ]: ";
    cin >> m;
    cout << "   Digite o ano [ 1900-]: ";
    cin >> y;

    data.tm_mday = d;
    data.tm_mon  = m - 1;
    data.tm_year = y - 1900;

    dataF = mktime(&data);

    a = automovel(marca, preco, chass, dataF);

    return is;
}

ostream & operator <<(ostream & os, automovel & a)
{
    cout << "├─── Automóvel"                                         << endl;
    cout << "├──── Marca "    << a.marca                             << endl;
    cout << "├──── Preço R$ " << fixed << setprecision(2) << a.preco << endl;
    cout << "├──── Chass "    << fixed << setprecision(0) << a.chass << endl;
    cout << "├──── data  "    << ctime(&a.dataF);

    return os;
}