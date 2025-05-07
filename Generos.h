#include <string>

class Generos {
private:
    int cod_genero;
    string descricao_genero;

public:
    Generos() : cod_genero(0), descricao_genero("") {}
    Generos(int cod_genero, const string& descricao_genero);

    int getcod_genero() const { return cod_genero; }
    string getdescricao_genero() const { return descricao_genero; }

    void setcod_genero(int _cod_genero) { this->cod_genero = _cod_genero; }
    void setdescricao_genero(const string& _descricao_genero) { this->descricao_genero = _descricao_genero; }
};

Generos::Generos(int cod_genero, const string& descricao_genero) {
    this->cod_genero = cod_genero;
    this->descricao_genero = descricao_genero;
}
