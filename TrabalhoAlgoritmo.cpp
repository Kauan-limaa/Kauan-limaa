#include <iostream>
#include <locale.h>
#include <vector>
#include <ctime>
using namespace std;

#include "Cidades.h"
#include "Pessoas.h"
#include "Editoras.h"
#include "Autores.h"
#include "Generos.h"
#include "Livros.h"
#include "Data.h"
#include "Emprestimo.h"

// Função para leitura da classe Cidades
Cidades leitura_cidades() {
    Cidades c;
    int codigo;
    string nome, uf;

    cout << "\n\nInserir dados de uma cidade\n";
    cout << "Código: ";
    cin >> codigo;
    c.setcod_cidade(codigo);

    cin.ignore();

    cout << "Nome: ";
    getline(cin, nome);
    c.setdescricao_cidade(nome);

    cout << "UF: ";
    getline(cin, uf);
    c.setuf(uf);

    return c;
}

// Função para leitura da classe Pessoas
Pessoas leitura_pessoas(const vector<Cidades>& cidades) {
    Pessoas p;
    int codigo, codigo_cidade;
    string nome, cpf, endereco;

    cout << "\n\nInserir dados de uma pessoa\n";
    cout << "Código: ";
    cin >> codigo;
    p.setcod_pessoa(codigo);

    cin.ignore();

    cout << "Nome: ";
    getline(cin, nome);
    p.setnome_pessoa(nome);

    cout << "CPF: ";
    getline(cin, cpf);
    p.setcpf(cpf);

    cout << "Endereço (Rua e número): ";
    getline(cin, endereco);
    p.setendereco(endereco);

    cout << "Código (cidade): ";
    cin >> codigo_cidade;
    p.setcod_cidade(codigo_cidade);
    p.dadoscidade(cidades);

    return p;
}

// Função para leitura da classe Editoras
Editoras leitura_editoras() {
    Editoras e;
    int codigo, codigo_cidade;
    string nome;

    cout << "\n\nInserir dados da editora\n";
    cout << "Código: ";
    cin >> codigo;
    e.setcod_editora(codigo);

    cin.ignore();

    cout << "Nome: ";
    getline(cin, nome);
    e.setnome_editora(nome);

    cout << "Código (cidade): ";
    cin >> codigo_cidade;
    e.setcod_cidade(codigo_cidade);

    return e;
}

// Função para leitura da classe Autores
Autores leitura_autores() {
    Autores a;
    int codigo;
    string nome;

    cout << "\n\nInserir dados do autor\n";
    cout << "Código: ";
    cin >> codigo;
    a.set_cod_autor(codigo);

    cin.ignore();

    cout << "Nome: ";
    getline(cin, nome);
    a.set_nome(nome);

    return a;
}

// Função para leitura da classe Generos
Generos leitura_genero() {
    Generos g;
    int codigo;
    string nome;

    cout << "\n\nInserir dados de gênero\n";
    cout << "Código: ";
    cin >> codigo;
    g.setcod_genero(codigo);

    cin.ignore();

    cout << "Nome: ";
    getline(cin, nome);
    g.setdescricao_genero(nome);

    return g;
}


// Função para leitura da classe Livros
Livros leitura_livros(const vector<Editoras>& editoras, const vector<Autores>& autores, const vector<Generos>& generos) {
    Livros l;
    int codigo, codigo_editora, codigo_autor, codigo_genero;
    string nome, disponivel;

    cout << "\n\nInserir dados de livros\n";
    cout << "Código: ";
    cin >> codigo;
    l.setCod_livros(codigo);

    cin.ignore();

    cout << "Nome: ";
    getline(cin, nome);
    l.setNome(nome);

    cout << "Código (Editora): ";
    cin >> codigo_editora;
    l.setCod_editora(codigo_editora);

    vector<Editoras> editoras_ordenadas = editoras;

    for (size_t i = 0; i < editoras_ordenadas.size(); i++) {
    size_t menor = i;
    for (size_t j = i + 1; j < editoras_ordenadas.size(); j++) {
        if (editoras_ordenadas[j].getcod_editora() < editoras_ordenadas[menor].getcod_editora()) {
            menor = j;
        }
    }
    if (menor != i) {
        Editoras temp = editoras_ordenadas[i];
        editoras_ordenadas[i] = editoras_ordenadas[menor];
        editoras_ordenadas[menor] = temp;
        }
    }

    l.dadoseditora(editoras_ordenadas);


    cout << "Código (Autor): ";
    cin >> codigo_autor;
    l.setCod_autor(codigo_autor);
    vector<Autores> autores_ordenados = autores;

    for (size_t i = 0; i < autores_ordenados.size(); i++) {
        size_t menor = i;
    for (size_t j = i + 1; j < autores_ordenados.size(); j++) {
        if (autores_ordenados[j].get_cod_autor() < autores_ordenados[menor].get_cod_autor()) {
            menor = j;
        }
    }
    if (menor != i) {
        Autores temp = autores_ordenados[i];
        autores_ordenados[i] = autores_ordenados[menor];
        autores_ordenados[menor] = temp;
    }
    }

    l.dadosautor(autores);

    cout << "Código (Gênero): ";
    cin >> codigo_genero;
    l.setCod_genero(codigo_genero);
    vector<Generos> generos_ordenados = generos;

    for (size_t i = 0; i < generos_ordenados.size(); i++) {
        size_t menor = i;
        for (size_t j = i + 1; j < generos_ordenados.size(); j++) {
            if (generos_ordenados[j].getcod_genero() < generos_ordenados[menor].getcod_genero()) {
            menor = j;
            }
        }
        if (menor != i) {
            Generos temp = generos_ordenados[i];
            generos_ordenados[i] = generos_ordenados[menor];
            generos_ordenados[menor] = temp;
            }
    }

    l.dadosgenero(generos);

    cin.ignore();

    cout << "Livro disponível? (S ou N): ";
    getline(cin, disponivel);
    l.setDisponivel(disponivel);

    return l;
}

//Função para empréstimo de um livro
Emprestimo leitura_emprestimo(vector<Emprestimo>& emprestimos, vector<Pessoas>& pessoas,
                              vector<Cidades>& cidades, vector<Livros>& livros,
                              vector<Editoras>& editoras, vector<Autores>& autores, vector<Generos>& generos) {
    Emprestimo emp;
    int codigo_pessoa, codigo_livro;

    Data data_emprestimo;
    Data data_prev_dev;

    cout << "\n\nInserir dados do Empréstimo\n";

    int codigo_emprestimo = emprestimos.empty() ? 1 : emprestimos.back().getCod_emprestimo() + 1;
    cout << "Código do Empréstimo: " << codigo_emprestimo << endl;
    emp.set_cod_emprestimo(codigo_emprestimo);

    cout << "Código da Pessoa: ";
    cin >> codigo_pessoa;
    emp.set_cod_pessoa(codigo_pessoa);

    vector<Pessoas> pessoas_ordenadas = pessoas;

    for (size_t i = 0; i < pessoas_ordenadas.size(); i++) {
        size_t menor = i;
        for (size_t j = i + 1; j < pessoas_ordenadas.size(); j++) {
            if (pessoas_ordenadas[j].getcod_pessoa() < pessoas_ordenadas[menor].getcod_pessoa()) {
                menor = j;
            }
        }
        if (menor != i) {
            Pessoas temp = pessoas_ordenadas[i];
            pessoas_ordenadas[i] = pessoas_ordenadas[menor];
            pessoas_ordenadas[menor] = temp;
        }
    }

    vector<Cidades> cidades_ordenadas = cidades;

    for (size_t i = 0; i < cidades_ordenadas.size(); i++) {
        size_t menor = i;
        for (size_t j = i + 1; j < cidades_ordenadas.size(); j++) {
            if (cidades_ordenadas[j].getcod_cidade() < cidades_ordenadas[menor].getcod_cidade()) {
                menor = j;
            }
        }
        if (menor != i) {
            Cidades temp = cidades_ordenadas[i];
            cidades_ordenadas[i] = cidades_ordenadas[menor];
            cidades_ordenadas[menor] = temp;
        }
    }

    emp.dadospessoa(pessoas, cidades);

    cout << "Código do Livro: ";
    cin >> codigo_livro;
    emp.set_cod_livro(codigo_livro);
    emp.dadoslivros(livros, editoras, generos, autores);


    vector<Livros> livros_ordenados = livros;

    for (size_t i = 0; i < livros_ordenados.size(); i++) {
        size_t menor = i;
        for (size_t j = i + 1; j < livros_ordenados.size(); j++) {
            if (livros_ordenados[j].getCod_livros() < livros_ordenados[menor].getCod_livros()) {
            menor = j;
            }
        }
        if (menor != i) {
            Livros temp = livros_ordenados[i];
            livros_ordenados[i] = livros_ordenados[menor];
            livros_ordenados[menor] = temp;
        }
    }

    bool verifica = emp.verifica_disponibilidade(livros_ordenados);

    if (verifica) {
        time_t t = time(0);
        tm* now = localtime(&t);

        data_emprestimo.setDia(now->tm_mday);
        data_emprestimo.setMes(now->tm_mon + 1);
        data_emprestimo.setAno(now->tm_year + 1900);
        emp.set_data_emprestimo(data_emprestimo);

        cout << "Data de empréstimo: " << data_emprestimo.getDia() << "/"
                                       << data_emprestimo.getMes() << "/"
                                       << data_emprestimo.getAno() << endl;

        data_prev_dev.setDia(now->tm_mday + 7);
        data_prev_dev.setMes(now->tm_mon + 1);
        data_prev_dev.setAno(now->tm_year + 1900);
        emp.set_data_prev_dev(data_prev_dev);

        cout << "Previsão de devolução: " << data_prev_dev.getDia() << "/"
                                        << data_prev_dev.getMes() << "/"
                                        << data_prev_dev.getAno() << endl;

        for (auto& l : livros) {
            if (l.getCod_livros() == codigo_livro) {
                l.setDisponivel("N");
                cout << "\nEmpréstimo realizado com sucesso!" << endl;
                break;
            }
        }
    } else {
        cout << "Empréstimo não realizado." << endl;
    }
    return emp;
}


// Função para devolução de um livro
void devolucao_emprestimo(vector<Emprestimo>& emprestimos, vector<Pessoas>& pessoas,
                          vector<Cidades>& cidades, vector<Livros>& livros,
                          vector<Editoras>& editoras, vector<Autores>& autores) {
    int codigo_emprestimo;
    cout << "\n\n--- Devolução de Livro ---\n";
    cout << "Informe o código do empréstimo a ser devolvido: ";
    cin >> codigo_emprestimo;

    int inicio = 0;
    int fim = emprestimos.size() - 1;
    Emprestimo* emp = nullptr;


    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (emprestimos[meio].getCod_emprestimo() == codigo_emprestimo) {
            emp = &emprestimos[meio];
            break;
        } else if (emprestimos[meio].getCod_emprestimo() < codigo_emprestimo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (emp == nullptr) {
        cout << "Empréstimo não encontrado.\n";
        return;
    }

    // Mostrar a data em que o livro foi emprestado
    Data data_emprestimo = emp->getData_emprestimo();
    cout << "Data do empréstimo: " << data_emprestimo.getDia() << "/"
         << data_emprestimo.getMes() << "/"
         << data_emprestimo.getAno() << endl;


    int dia, mes, ano;
    cout << "Informe a data de devolução:\n";
    cout << "Dia: "; cin >> dia;
    cout << "Mês: "; cin >> mes;
    cout << "Ano: "; cin >> ano;

    Data data_devolucao;
    data_devolucao.setDia(dia);
    data_devolucao.setMes(mes);
    data_devolucao.setAno(ano);
    emp->set_data_devolucao(data_devolucao);


    for (auto& livro : livros) {
        if (livro.getCod_livros() == emp->getCod_livro()) {
            livro.setDisponivel("S");
            break;
        }
    }

    cout << "Livro devolvido com sucesso!\n";
}


//mostrar livros emprestados
void mostraremp(const vector<Livros>& livros) {
    cout << "\n\n--- Livros Emprestados ---\n";
    cout << "Código / Nome do Livro\n";
    cout << "------------------------\n";
    int livrosEmprestados = 0;
    int livrosDisponiveis = 0;

    for (const auto& l : livros) {
        if (l.getDisponivel() == "N") {
            cout << l.getCod_livros() << "      / " << l.getNome() << endl;
            livrosEmprestados++;
        } else {
            livrosDisponiveis++;
        }
    }
    if (livrosEmprestados == 0) {
        cout << "Nenhum livro atualmente emprestado.\n";
    }

    cout << "\n--- Resumo ---\n";
    cout << "Total de livros emprestados: " << livrosEmprestados << endl;
    cout << "Total de livros disponíveis: " << livrosDisponiveis << endl;
    cout << "---------------------------\n";
}

//mostrar empréstimos atrasados
void mostrardev_atrasada(vector<Emprestimo>& emprestimos, vector<Pessoas>& pessoas,
                         vector<Livros>& livros, vector<Autores>& autores,
                         vector<Editoras>& editoras, vector<Generos>& generos) {
    cout << "\nLivros com devolução em atraso\n\n";

    int dia_atual, mes_atual, ano_atual;
    cout << "Informe a data atual:\n";
    cout << "Dia: "; cin >> dia_atual;
    cout << "Mês: "; cin >> mes_atual;
    cout << "Ano: "; cin >> ano_atual;

    bool atrasos_encontrados = false;

    for (Emprestimo& e : emprestimos) {

        Data d = e.getData_devolucao();
        if (d.getDia() == 1 && d.getMes() == 1 && d.getAno() == 1900) {




        Data prev = e.getData_prev_dev();

        bool em_atraso =
            (prev.getAno() < ano_atual) ||
            (prev.getAno() == ano_atual && prev.getMes() < mes_atual) ||
            (prev.getAno() == ano_atual && prev.getMes() == mes_atual && prev.getDia() < dia_atual);

        if (em_atraso) {
            atrasos_encontrados = true;

            cout << "Código do Empréstimo: " << e.getCod_emprestimo() << endl;
            cout << "Código da Pessoa: " << e.getCod_pessoa() << endl;
            e.buscapessoa(pessoas, e.getCod_pessoa());
            cout << "Código do Livro: " << e.getCod_livro() << endl;
            e.buscalivro(livros, editoras, autores, generos, e.getCod_livro());
            cout << "Data Prevista de Devolução: "
                 << prev.getDia() << "/" << prev.getMes() << "/" << prev.getAno() << endl;

            tm dataPrevista = {};
            dataPrevista.tm_mday = prev.getDia();
            dataPrevista.tm_mon = prev.getMes() - 1;
            dataPrevista.tm_year = prev.getAno() - 1900;

            tm dataAtual = {};
            dataAtual.tm_mday = dia_atual;
            dataAtual.tm_mon = mes_atual - 1;
            dataAtual.tm_year = ano_atual - 1900;

            time_t tPrev = mktime(&dataPrevista);
            time_t tAtual = mktime(&dataAtual);

            double diferenca = difftime(tAtual, tPrev);
            int dias_atraso = static_cast<int>(diferenca / (60 * 60 * 24));

            cout << "Dias de atraso: " << dias_atraso << " dia(s)\n\n";
        }
    }
    }

    if (!atrasos_encontrados) {
        cout << "Nenhum empréstimo em atraso encontrado.\n";
    }
}


// Menu principal
int main() {
    setlocale(LC_ALL, "Portuguese");

    ///
    Cidades cidade(1, "assis","sp" );
    Pessoas pessoa(2, "pessoa1", "517.938.348-06"," teste 20",1);
    Editoras editora(2, "galera", 1);
    Autores autor(4, "raphael");
    Generos genero(5, "terror");
    Livros livro(6, "testando", 2, 4, 5, "s" );
    ///

    int opcao;
    vector<Cidades> cidades= {cidade};
    vector<Pessoas> pessoas= {pessoa};
    vector<Editoras> editoras= {editora};
    vector<Autores> autores= {autor};
    vector<Generos> generos= {genero};
    vector<Livros> livros= {livro};
    vector<Emprestimo> emprestimos;

    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Cadastrar\n";
        cout << "2. Devolução\n";
        cout << "3. Dados livros emprestados\n";
        cout << "4. Dados livros devoluções em atraso\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1: {
                int opcaoCadastro;

                do {
                    cout << "\n   MENU DE CADASTRO   \n";
                    cout << "1. Cadastrar Cidade\n";
                    cout << "2. Cadastrar Pessoa\n";
                    cout << "3. Cadastrar Editora\n";
                    cout << "4. Cadastrar Autor\n";
                    cout << "5. Cadastrar Gênero\n";
                    cout << "6. Cadastrar Livro\n";
                    cout << "7. Cadastrar Empréstimo\n";
                    cout << "0. Voltar ao menu principal\n";
                    cout << "Escolha uma opção: ";
                    cin >> opcaoCadastro;
                    cin.ignore();

                    switch (opcaoCadastro) {
                        case 1:
                            cidades.push_back(leitura_cidades());
                            break;
                        case 2:
                            pessoas.push_back(leitura_pessoas(cidades));
                            break;
                        case 3:
                            editoras.push_back(leitura_editoras());
                            break;
                        case 4:
                            autores.push_back(leitura_autores());
                            break;
                        case 5:
                            generos.push_back(leitura_genero());
                            break;
                        case 6:
                            livros.push_back(leitura_livros(editoras, autores, generos));
                            break;
                        case 7:
                            emprestimos.push_back(leitura_emprestimo(emprestimos, pessoas, cidades, livros,
                                                                     editoras, autores,generos));
                            break;
                        case 0:
                            cout << "Voltando ao menu principal...\n";
                            break;
                        default:
                            cout << "Opção inválida. Tente novamente.\n";
                            break;
                    }

                } while (opcaoCadastro != 0);
                break;
            }
             case 2:
                devolucao_emprestimo(emprestimos, pessoas, cidades, livros,
                                     editoras, autores);
                break;
            case 3:
                mostraremp(livros);
                break;
            case 4:
                mostrardev_atrasada(emprestimos, pessoas, livros, autores, editoras, generos);
                break;
            case 0:
                cout << "Saindo do menu.\n";
                break;
            default:
                cout << "Opção inválida.\n";
                break;
        }

    } while (opcao != 0);


    return 0;
}
