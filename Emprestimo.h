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

    void dadospessoa(const vector<Pessoas>& pessoas, const vector<Cidades>& cidades)const;
    void dadoslivros(const vector<Livros>& livros, const vector<Editoras>& editoras,
                     const vector<Autores>& autores) const;
    bool verifica_disponibilidade(const vector<Livros>& livros) const;
    void buscapessoa(const vector<Pessoas>& pessoas, const int& busca)const;
    void buscalivro(const vector<Livros>& livros, const vector<Editoras>& editoras,
                    const vector<Autores>& autores, const int& busca)const;
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

void Emprestimo::dadospessoa(const vector<Pessoas>& pessoas, const vector<Cidades>& cidades) const {
    for (const Pessoas& p : pessoas) {
        if (p.getcod_pessoa() == cod_pessoa) {
            cout << "Nome: " << p.getnome_pessoa() << endl;

            for (const Cidades& c : cidades) {
                if(c.getcod_cidade() == p.getcod_cidade()){
                    cout << "Cidade: " << c.getdescricao_cidade() << endl;
                }
            }
            return;
        }
    }

    cout << "Pessoa não encontrada para o código" << endl;
}

void Emprestimo::dadoslivros(const vector<Livros>& livros, const vector<Editoras>& editores,
                             const vector<Autores>& autores) const {
    bool livroEncontrado = false;

    for (const Livros& l : livros) {
        if (l.getCod_livros() == cod_livro) {
            livroEncontrado = true;
            cout << "Livro: " << l.getNome() << endl;

            bool editoraEncontrada = false;
            for (const Editoras& e : editores) {
                if (e.getcod_editora() == l.getCod_editora()) {
                    cout << "Editora: " << e.getnome_editora() << endl;
                    editoraEncontrada = true;
                    break;
                }
            }
            if (!editoraEncontrada)
                cout << "Editora não encontrada." << endl;

            bool autorEncontrado = false;
            for (const Autores& a : autores) {
                if (a.get_cod_autor() == l.getCod_autor()) {
                    cout << "Autor: " << a.get_nome() << endl;
                    autorEncontrado = true;
                    break;
                }
            }
            if (!autorEncontrado)
                cout << "Autor não encontrado." << endl;

            break;
        }
    }
    if (!livroEncontrado)
        cout << "Livro não encontrado." << endl;
}


bool Emprestimo::verifica_disponibilidade(const vector<Livros>& livros) const {
    for (const Livros& l : livros) {
        if (l.getCod_livros() == cod_livro) {
            if (l.getDisponivel() == "S" || l.getDisponivel() == "s") {
                return true;
            } else {
                cout << "Livro não disponível." << endl;
                return false;
            }
        }
    }
    return false;
}

void Emprestimo::buscapessoa(const vector<Pessoas>& pessoas, const int& busca) const {
    int inicio = 0;
    int fim = pessoas.size() - 1;
    bool encontrada = false;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int codAtual = pessoas[meio].getcod_pessoa();

        if (codAtual == busca) {
            cout << "Nome da Pessoa: " << pessoas[meio].getnome_pessoa() << endl;
            encontrada = true;
            break;
        } else if (codAtual < busca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (!encontrada) {
        cout << "Pessoa com código " << busca << " não encontrada." << endl;
    }
}



void Emprestimo::buscalivro(const vector<Livros>& livros, const vector<Editoras>& editoras,
                             const vector<Autores>& autores, const int& busca) const {
    int inicio = 0;
    int fim = livros.size() - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int codAtual = livros[meio].getCod_livros();

        if (codAtual == busca) {
            const Livros& l = livros[meio];

            cout << "Nome do Livro: " << l.getNome() << endl;

            bool editoraEncontrada = false;
            for (const Editoras& e : editoras) {
                if (e.getcod_editora() == l.getCod_editora()) {
                    cout << "Nome da Editora: " << e.getnome_editora() << endl;
                    editoraEncontrada = true;
                    break;
                }
            }
            if (!editoraEncontrada) {
                cout << "Editora não encontrada." << endl;
            }

            bool autorEncontrado = false;
            for (const Autores& a : autores) {
                if (a.get_cod_autor() == l.getCod_autor()) {
                    cout << "Nome do Autor: " << a.get_nome() << endl;
                    autorEncontrado = true;
                    break;
                }
            }
            if (!autorEncontrado) {
                cout << "Autor não encontrado." << endl;
            }

            return;
        } else if (codAtual < busca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    cout << "Livro não encontrado.\n";
}
