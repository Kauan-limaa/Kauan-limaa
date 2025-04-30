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
};

  Livros::Livros(int cod_livros, string nome, int cod_editora, int cod_autor, int cod_genero, string disponivel) {
      this->cod_livro = cod_livros;
      this->nome = nome;
      this->cod_editora = cod_editora;
      this->cod_autor = cod_autor;
      this->cod_genero = cod_genero;
      this->disponivel = disponivel;
}
