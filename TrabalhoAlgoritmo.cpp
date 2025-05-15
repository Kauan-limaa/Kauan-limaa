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
    l.dadoseditora(editoras);

    cout << "Código (Autor): ";
    cin >> codigo_autor;
    l.setCod_autor(codigo_autor);
    l.dadosautor(autores);

    cout << "Código (Gênero): ";
    cin >> codigo_genero;
    l.setCod_genero(codigo_genero);
    l.dadosgenero(generos);

    cin.ignore();

    cout << "Livro disponível? (S ou N): ";
    getline(cin, disponivel);
    l.setDisponivel(disponivel);

    return l;
}

Emprestimo leitura_emprestimo(vector<Emprestimo>& emprestimos, vector<Pessoas>& pessoas,
                              vector<Cidades>& cidades, vector<Livros>& livros,
                              vector<Editoras>& editoras, vector<Autores>& autores) {
    Emprestimo emp;
    int codigo_pessoa, codigo_livro;
    int dia, mes, ano;

    Data data_emprestimo;
    Data data_prev_dev;
    Data data_devolucao;

    cout << "\n\nInserir dados do Empréstimo\n";

    int codigo_emprestimo = emprestimos.empty() ? 1 : emprestimos.back().getCod_emprestimo() + 1;
    cout << "Código do Empréstimo: " << codigo_emprestimo << endl;
    emp.set_cod_emprestimo(codigo_emprestimo);

    cout << "Código da Pessoa: ";
    cin >> codigo_pessoa;
    emp.set_cod_pessoa(codigo_pessoa);
    emp.dadospessoa(pessoas, cidades);

    cout << "Código do Livro: ";
    cin >> codigo_livro;
    emp.set_cod_livro(codigo_livro);
    emp.dadoslivros(livros, editoras, autores);

    bool verifica = emp.verifica_disponibilidade(livros);

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
                break;
            }
        }

        cout << "\nData de devolução:\n";
        cout << "Dia: "; cin >> dia;
        cout << "Mês: "; cin >> mes;
        cout << "Ano: "; cin >> ano;

        data_devolucao.setDia(dia);
        data_devolucao.setMes(mes);
        data_devolucao.setAno(ano);
        emp.set_data_devolucao(data_devolucao);
    } else {
        cout << "\nLivro indisponível no momento!\n";
    }

    return emp;
}


// Menu principal
int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    vector<Cidades> cidades;
    vector<Pessoas> pessoas;
    vector<Editoras> editoras;
    vector<Autores> autores;
    vector<Generos> generos;
    vector<Livros> livros;
    vector<Emprestimo> emprestimos;

    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Cadastrar\n";
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
                                                                     editoras, autores));
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
