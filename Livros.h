class Livros {
private:
    int cod_livro;
    string nome;
    int cod_editora;
    int cod_autor;
    int cod_genero;
    string disponivel;
    public:
    Livros(): cod_livro(0), nome(""), cod_editora(0), cod_autor(0), cod_genero(0), disponivel("")  {}
    Livros(int cod_livros, string nome, int cod_editora, int cod_autor, int cod_genero, string disponivel);

    int getCod_livros(){return cod_livro;}
    string getNome(){return nome;}
    int getCod_editora(){return cod_editora;}
    int getCod_autor(){return cod_autor;}
    int getCod_genero(){return cod_genero;}
    string getDisponivel() { return disponivel; }

    void setCod_livros(int cod_livro){ this-> cod_livro = cod_livro;}
    void setNome(string nome){this->nome = nome;}
    void setCod_genero(int cod_genero) {this -> cod_genero = cod_genero;}
    void setCod_editora(int cod_editora){this-> cod_editora = cod_editora;}
    void setCod_autor(int cod_autor){this-> cod_autor = cod_autor;}
    void setDisponivel(string disponivel){this-> disponivel = disponivel;}

    void dadoseditora(const vector<Editoras>& editoras) const;
    void dadosautor(const vector<Autores>& autores) const;
    void dadosgenero(const vector<Generos>& generos) const;
};

  Livros::Livros(int cod_livros, string nome, int cod_editora, int cod_autor, int cod_genero, string disponivel) {
      this->cod_livro = cod_livros;
      this->nome = nome;
      this->cod_editora = cod_editora;
      this->cod_autor = cod_autor;
      this->cod_genero = cod_genero;
      this->disponivel = disponivel;
}

void Livros::dadoseditora(const vector<Editoras>& editoras) const{
    for (const Editoras& e : editoras) {
        if (e.getcod_editora() == cod_editora) {
            cout << "Editora: " << e.getnome_editora() << endl;
            return;
        }
    }

    cout << "Editora não encontrada para o código" << endl;
}

void Livros::dadosautor(const vector<Autores>& autores) const{
    for (const Autores& a : autores) {
        if (a.get_cod_autor() == cod_autor) {
            cout << "Autor: " << a.get_nome() << endl;
            return;
        }
    }

    cout << "Autor não encontrada para o código" << endl;
}

void Livros::dadosgenero(const vector<Generos>& generos) const{
    for (const Generos& g : generos) {
        if (g.getcod_genero() == cod_genero) {
            cout << "Gênero: " << g.getdescricao_genero() << endl;
            return;
        }
    }

    cout << "Gênero não encontrada para o código" << endl;
}
