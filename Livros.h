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

    int getCod_livros()const {return cod_livro;}
    string getNome()const {return nome;}
    int getCod_editora()const {return cod_editora;}
    int getCod_autor()const {return cod_autor;}
    int getCod_genero()const {return cod_genero;}
    string getDisponivel() const { return disponivel; }

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



void Livros::dadoseditora(const vector<Editoras>& editoras) const {
    int comeco = 0;
    int fim = (int)editoras.size() - 1;

    while (comeco <= fim) {
        int meio = comeco + (fim - comeco) / 2;
        int cod_meio = editoras[meio].getcod_editora();

        if (cod_meio == cod_editora) {
            cout << "Editora: " << editoras[meio].getnome_editora() << endl;
            return;
        }
        else if (cod_meio < cod_editora) {
            comeco = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    cout << "Editora não encontrada para o código" << endl;
}

void Livros::dadosautor(const vector<Autores>& autores_ordenados) const {
    int comeco = 0;
    int fim = autores_ordenados.size() - 1;

    while (comeco <= fim) {
        int meio = (comeco + fim) / 2;
        if (autores_ordenados[meio].get_cod_autor() == cod_autor) {
            cout << "Autor: " << autores_ordenados[meio].get_nome() << endl;
            return;
        } else if (autores_ordenados[meio].get_cod_autor() < cod_autor) {
            comeco = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    cout << "Autor não encontrada para o código" << endl;
}

void Livros::dadosgenero(const vector<Generos>& generos_ordenados) const {
    int comeco = 0;
    int fim = generos_ordenados.size() - 1;

    while (comeco <= fim) {
        int meio = (comeco + fim) / 2;
        if (generos_ordenados[meio].getcod_genero() == cod_genero) {
            cout << "Gênero: " << generos_ordenados[meio].getdescricao_genero() << endl;
            return;
        } else if (generos_ordenados[meio].getcod_genero() < cod_genero) {
            comeco = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    cout << "Gênero não encontrada para o código" << endl;
}
