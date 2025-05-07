class Livros {
private:
    int cod_livro;
    string nome;
    int cod_editora;
    int cod_autor;
    int cod_genero;
    string disponivel;
public:
    Livros() : cod_livro(0), nome(""), cod_editora(0), cod_autor(0), cod_genero(0), disponivel("") {}
    Livros(int cod_livros, const string& nome, int cod_editora, int cod_autor, int cod_genero, const string& disponivel);

    int getCod_livros() const { return cod_livro; }
    string getNome() const { return nome; }
    int getCod_editora() const { return cod_editora; }
    int getCod_autor() const { return cod_autor; }
    int getCod_genero() const { return cod_genero; }
    string getDisponivel() const { return disponivel; }

    void setCod_livros(int cod_livro) { this->cod_livro = cod_livro; }
    void setNome(const string& nome) { this->nome = nome; }
    void setCod_genero(int cod_genero) { this->cod_genero = cod_genero; }
    void setCod_editora(int cod_editora) { this->cod_editora = cod_editora; }
    void setCod_autor(int cod_autor) { this->cod_autor = cod_autor; }
    void setDisponivel(const string& disponivel) { this->disponivel = disponivel; }

    void dadosautor(const vector<Autores>& autor) const;
    void dadoseditora(const vector<Editoras>& editora) const;
    void dadosgenero(const vector<Generos>& genero) const;
};

Livros::Livros(int cod_livros, const string& nome, int cod_editora, int cod_autor, int cod_genero, const string& disponivel) {
    this->cod_livro = cod_livros;
    this->nome = nome;
    this->cod_editora = cod_editora;
    this->cod_autor = cod_autor;
    this->cod_genero = cod_genero;
    this->disponivel = disponivel;
}

void Livros::dadosautor(const vector<Autores>& autor) const {
    for (const Autores& a : autor) {
        if (a.get_cod_autor() == cod_autor) {
            cout << "Autor: " << a.get_nome() << endl;
            return;
        }
    }
    cout << "Autor não encontrado para o código: " << cod_autor << endl;
}

void Livros::dadoseditora(const vector<Editoras>& editora) const {
    for (const Editoras& e : editora) {
        if (e.getcod_editora() == cod_editora) {
            cout << "Editora: " << e.getnome_editora() << endl;
            return;
        }
    }
    cout << "Editora não encontrada para o código: " << cod_editora << endl;
}

void Livros::dadosgenero(const vector<Generos>& genero) const {
    for (const Generos& g : genero) {
        if (g.getcod_genero() == cod_genero) {
            cout << "Gênero: " << g.getdescricao_genero() << endl;
            return;
        }
    }
    cout << "Gênero não encontrado para o código: " << cod_genero << endl;
}
