class Autores {
  private:
    int cod_autor;
    string nome;
public:
  Autores(): cod_autor(0), nome("") {};
  Autores(int cod_autor, string nome);

  int get_cod_autor() const {return cod_autor;};
  string get_nome() const {return nome;}

  void set_cod_autor(int cod_autor){this->cod_autor = cod_autor;}
  void set_nome(string nome) {this->nome = nome;};

};

  Autores::Autores(int cod_autor, string nome) {
  this->cod_autor = cod_autor;
  this->nome = nome;
}
