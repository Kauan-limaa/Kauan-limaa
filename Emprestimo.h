class Emprestimo {
private:
    int cod_emprestimo;
    int cod_pessoa;
    int cod_livro;
    Data data_emprestimo;
    Data data_prev_dev;
    Data data_devolucao;

public:
    Emprestimo() : cod_emprestimo(0), cod_pessoa(0), cod_livro(0) {}
    Emprestimo(int, int, int, const Data&, const Data&, const Data&);

    int getCod_emprestimo() const { return this->cod_emprestimo; }
    int getCod_pessoa() const { return this->cod_pessoa; }
    int getCod_livro() const { return this->cod_livro; }
    const Data& getData_emprestimo() const { return this->data_emprestimo; }
    const Data& getData_prev_dev() const { return this->data_prev_dev; }
    const Data& getData_devolucao() const { return this->data_devolucao; }

    void set_cod_emprestimo(int cod_emprestimo) { this->cod_emprestimo = cod_emprestimo; }
    void set_cod_pessoa(int cod_pessoa) { this->cod_pessoa = cod_pessoa; }
    void set_cod_livro(int cod_livro) { this->cod_livro = cod_livro; }
    void set_data_emprestimo(const Data& data_emprestimo) { this->data_emprestimo = data_emprestimo; }
    void set_data_prev_dev(const Data& data_prev_dev) { this->data_prev_dev = data_prev_dev; }
    void set_data_devolucao(const Data& data_devolucao) { this->data_devolucao = data_devolucao; }

};

Emprestimo::Emprestimo(int cod_emprestimo, int cod_pessoa, int cod_livro,
const Data& data_emprestimo, const Data& data_prev_dev, const Data& data_devolucao)  {
    this -> cod_emprestimo = cod_emprestimo;
    this -> cod_pessoa = cod_pessoa;
    this -> cod_livro = cod_livro;
    this -> data_emprestimo = data_emprestimo;
    this -> data_prev_dev = data_prev_dev;
    this -> data_devolucao = data_devolucao;
}