#include <iostream>
#include <locale.h>
using namespace std;

#include "Cidades.h"
#include "Pessoas.h"
#include "Editoras.h"
#include "Autores.h"
#include "Generos.h"
#include "Livros.h"

// Função para leitura da classe Cidades
void leitura_cidades(Cidades& c) {
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
}

// Função para leitura da classe Pessoas
void leitura_pessoas(Pessoas& p) {
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

    cout << "CPF (inserir pontos e traços): ";
    getline(cin, cpf);
    p.setcpf(cpf);

    cout << "Endereço (Rua e número): ";
    getline(cin, endereco);
    p.setendereco(endereco);

    cout << "Código (cidade): ";
    cin >> codigo_cidade;
    p.setcod_cidade(codigo_cidade);
}

// Função para leitura da classe Editoras
void leitura_editoras(Editoras& e) {
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
}

// Função para leitura da classe Autores
void leitura_autores(Autores& a) {
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
}

// Função para leitura da classe Generos
void leitura_genero(Generos& g) {
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
}

// Função para leitura da classe Livros
void leitura_livros(Livros& l) {
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

    cout << "Código (Autor): ";
    cin >> codigo_autor;
    l.setCod_autor(codigo_autor);

    cout << "Código (Gênero): ";
    cin >> codigo_genero;
    l.setCod_genero(codigo_genero);

    cin.ignore();

    cout << "Livro disponível? (Sim ou Não): ";
    getline(cin, disponivel);
    l.setDisponivel(disponivel);
}


// Menu principal
int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    Cidades c;
    Pessoas p;
    Editoras e;
    Autores a;
    Generos g;
    Livros l;

    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Cadastrar\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                int opcaoCadastro;

                do {
                    cout << "\n   MENU DE CADASTRO   \n";
                    cout << "1. Cadastrar Cidade\n";
                    cout << "2. Cadastrar Pessoa\n";
                    cout << "3. Cadastrar Editora\n";
                    cout << "4. Cadastrar Autor\n";
                    cout << "5. Cadastrar Gênero\n";
                    cout << "6. Cadastrar Livro\n";
                    cout << "0. Voltar ao menu principal\n";
                    cout << "Escolha uma opção: ";
                    cin >> opcaoCadastro;
                    cin.ignore();

                    switch (opcaoCadastro) {
                        case 1:
                            leitura_cidades(c);
                            break;
                        case 2:
                            leitura_pessoas(p);
                            break;
                        case 3:
                            leitura_editoras(e);
                            break;
                        case 4:
                            leitura_autores(a);
                            break;
                        case 5:
                            leitura_genero(g);
                            break;
                        case 6:
                            leitura_livros(l);
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

            case 0:
                cout << "Saindo do menu.\n";
                break;
            default:
                cout << "Opção inválida.\n";
                break;
        }

    } while (opcao != 0);

    cout << "CPF: " << p.getcpf();

    return 0;
}
