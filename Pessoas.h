#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Pessoas{
private:
    int cod_pessoa;
    string nome_pessoa;
    string cpf;
    string endereco;
    int cod_cidade;

    bool valcpf(const string& cpf);

public:
    Pessoas();
    Pessoas(int, string, string, string, int);

    int getcod_pessoa() const { return this->cod_pessoa; }
    string getnome_pessoa() const { return this->nome_pessoa; }
    string getcpf() const { return this->cpf; }
    string getendereco() const { return this->endereco; }
    int getcod_cidade() const { return this->cod_cidade; }

    void setcod_pessoa(int _cod_pessoa) { this->cod_pessoa = _cod_pessoa; }
    void setnome_pessoa(string _nome_pessoa) { this->nome_pessoa = _nome_pessoa; }
    void setcpf(string _cpf);
    void setendereco(string _endereco) { this->endereco = _endereco; }
    void setcod_cidade(int _cod_cidade){this -> cod_cidade = _cod_cidade;}

    void dadoscidade(const vector<Cidades>& cidades) const;
};

Pessoas::Pessoas() {
    this->cod_pessoa = 0;
    this->nome_pessoa = "";
    this->cpf = "";
    this->endereco = "";
    this->cod_cidade = 0;
}

Pessoas::Pessoas(int _cod_pessoa, string _nome_pessoa, string _cpf, string _endereco, int _cod_cidade) {
    this->cod_pessoa = _cod_pessoa;
    this->nome_pessoa = _nome_pessoa;
    setcpf(_cpf);
    this->endereco = _endereco;
    this->cod_cidade = _cod_cidade;
}

void Pessoas::setcpf(string _cpf) {
    while (!valcpf(_cpf)) {
        cerr << "CPF inválido. Digite novamente: ";
        getline(cin, _cpf);
    }
    this->cpf = _cpf;
}

bool Pessoas::valcpf(const string& cpf) {
    string numeros;
    for (char c : cpf) {
        if (isdigit(c))
            numeros += c;
    }

    if (numeros.length() != 11)
        return false;

    bool todosIguais = true;
    for (int i = 1; i < 11; ++i) {
        if (numeros[i] != numeros[0]) {
            todosIguais = false;
            break;
        }
    }
    if (todosIguais)
        return false;

    // verificador do primeiro digito
    int soma = 0;
    for (int i = 0; i < 9; ++i)
        soma += (numeros[i] - '0') * (10 - i);
    int dig1 = (soma * 10) % 11;
    if (dig1 == 10) dig1 = 0;

    //verificador do segundo digito
    soma = 0;
    for (int i = 0; i < 10; ++i)
        soma += (numeros[i] - '0') * (11 - i);
    int dig2 = (soma * 10) % 11;
    if (dig2 == 10) dig2 = 0;

    return dig1 == (numeros[9] - '0') && dig2 == (numeros[10] - '0');
}


void Pessoas::dadoscidade(const vector<Cidades>& cidades) const{
    for (const Cidades& c : cidades) {
        if (c.getcod_cidade() == cod_cidade) {
            cout << "Cidade: " << c.getdescricao_cidade() << " - " << c.getuf() << endl;
            return;
        }
    }

    cout << "Cidade não encontrada para o código" << endl;
}
