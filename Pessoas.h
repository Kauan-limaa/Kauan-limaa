
class Pessoas{
    private:
        int cod_pessoa;
        string nome_pessoa;
        string cpf;
        string endereco;
        int cod_cidade;

    public:
        Pessoas();
        Pessoas(int, string, string, string, int);

        int getcod_pessoa(){return this -> cod_pessoa;}
        string getnome_pessoa(){return this -> nome_pessoa;}
        string getcpf(){return this -> cpf;}
        string getendereco(){return this -> endereco;}
        int getcod_cidade(){return this -> cod_cidade;}

        void setcod_pessoa(int _cod_pessoa){this -> cod_pessoa = _cod_pessoa;}
        void setnome_pessoa(string _nome_pessoa){this -> nome_pessoa = _nome_pessoa;}
        void setcpf(string _cpf){this -> cpf = _cpf;}
        void setendereco(string _endereco){this -> endereco = _endereco;}
        void setcod_cidade(int _cod_cidade){this -> cod_cidade = _cod_cidade;}
};

Pessoas::Pessoas(){
    this -> cod_pessoa = 0;
    this -> nome_pessoa = "";
    this -> cpf = "";
    this -> endereco = "";
    this -> cod_cidade = 0;
}

Pessoas::Pessoas(int _cod_pessoa, string _nome_pessoa, string _cpf, string _endereco, int _cod_cidade){
    this -> cod_pessoa = _cod_pessoa;
    this -> nome_pessoa = _nome_pessoa;
    this -> cpf = _cpf;
    this -> endereco = _endereco;
    this -> cod_cidade = _cod_cidade;
}
