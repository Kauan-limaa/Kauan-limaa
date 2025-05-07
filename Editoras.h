class Editoras {
private:
    int cod_editora;
    string nome_editora;
    int cod_cidade;

public:
    Editoras() : cod_editora(0), nome_editora(""), cod_cidade(0) {}
    Editoras(int cod_editora, const string& nome_editora, int cod_cidade);

    int getcod_editora() const { return cod_editora; }
    string getnome_editora() const { return nome_editora; }
    int getcod_cidade() const { return cod_cidade; }

    void setcod_editora(int _cod_editora) { this->cod_editora = _cod_editora; }
    void setnome_editora(const string& _nome_editora) { this->nome_editora = _nome_editora; }
    void setcod_cidade(int _cod_cidade) { this->cod_cidade = _cod_cidade; }
};

Editoras::Editoras(int cod_editora, const string& nome_editora, int cod_cidade) {
    this->cod_editora = cod_editora;
    this->nome_editora = nome_editora;
    this->cod_cidade = cod_cidade;
}
