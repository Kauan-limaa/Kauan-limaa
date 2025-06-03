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

    void dadospessoa( const vector<Pessoas>& pessoas_ordenadas, const vector<Cidades>& cidades_ordenadas);
    void dadoslivros( vector<Livros>& livros,  vector<Editoras>& editoras, vector <Generos>& generos,
                      vector<Autores>& autores) ;
    bool verifica_disponibilidade( const vector<Livros>& livros) ;
    void buscapessoa( vector<Pessoas>& pessoas, const int& busca);
    void buscalivro( vector<Livros>& livros,  vector<Editoras>& editoras,
                         vector<Autores>& autores, vector<Generos>&generos, const int& busca);
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

void Emprestimo::dadospessoa(const vector<Pessoas>& pessoas_ordenadas, const vector<Cidades>& cidades_ordenadas) {
    int inicio = 0;
    int fim = pessoas_ordenadas.size() - 1;
    bool pessoa_encontrada = false;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (pessoas_ordenadas[meio].getcod_pessoa() == cod_pessoa) {
            pessoa_encontrada = true;
            cout << "Nome: " << pessoas_ordenadas[meio].getnome_pessoa() << endl;

            int cod_cidade = pessoas_ordenadas[meio].getcod_cidade();
            int ini_cidade = 0;
            int fim_cidade = cidades_ordenadas.size() - 1;

            while (ini_cidade <= fim_cidade) {
                int meio_cidade = (ini_cidade + fim_cidade) / 2;
                if (cidades_ordenadas[meio_cidade].getcod_cidade() == cod_cidade) {
                    cout << "Cidade: " << cidades_ordenadas[meio_cidade].getdescricao_cidade() << endl;
                    break;
                } else if (cidades_ordenadas[meio_cidade].getcod_cidade() < cod_cidade) {
                    ini_cidade = meio_cidade + 1;
                } else {
                    fim_cidade = meio_cidade - 1;
                }
            }

            break;
        } else if (pessoas_ordenadas[meio].getcod_pessoa() < cod_pessoa) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (!pessoa_encontrada) {
        cout << "Pessoa não encontrada" << endl;
    }
}


void Emprestimo::dadoslivros( vector<Livros>& livros,  vector<Editoras>& editores, vector <Generos>& generos, vector<Autores>& autores)  {
    bool livroEncontrado = false;

    for (const Livros& l : livros) {
        if (l.getCod_livros() == cod_livro) {
            livroEncontrado = true;
            cout << "Livro: " << l.getNome()<< endl;

            bool generoEncontrado = false;
                for (const Generos& e : generos) {
                    if (e.getcod_genero() == l.getCod_genero()) {
                        cout << "Genêro: " << e.getdescricao_genero() << endl;
                        generoEncontrado = true;
                        break;
                    }
                }

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


bool Emprestimo::verifica_disponibilidade(const vector<Livros>& livros_ordenados) {
    int inicio = 0;
    int fim = livros_ordenados.size() - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (livros_ordenados[meio].getCod_livros() == cod_livro) {
            string disp = livros_ordenados[meio].getDisponivel();
            if (disp == "S" || disp == "s") {
                return true;
            } else {
                cout << "Livro não disponível." << endl;
                return false;
            }
        } else if (livros_ordenados[meio].getCod_livros() < cod_livro) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return false;
}

void Emprestimo::buscapessoa( vector<Pessoas>& pessoas,  const int& busca)  {
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



void Emprestimo::buscalivro( vector<Livros>& livros,  vector<Editoras>& editoras,
                              vector<Autores>& autores, vector<Generos>&generos, const int& busca)  {
    int inicio = 0;
    int fim = livros.size() - 1;
    bool encontrada = false;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int codAtual = livros[meio].getCod_livros();

        if (codAtual == busca) {
            const Livros& l = livros[meio];

            cout << "Nome do Livro: " << l.getNome() << endl;
            l.dadoseditora(editoras);
            l.dadosautor(autores);
            l.dadosgenero(generos);
            encontrada = true;
            break;
        } else if (codAtual < busca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    if (!encontrada) {
        cout << "Livro com código " << busca << " não encontrado." << endl;
    }
}
