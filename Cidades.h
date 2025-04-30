
class Cidades{
    private:
        int cod_cidade;
        string descricao_cidade;
        string uf;
        
    public:
        Cidades(): cod_cidade(0), descricao_cidade(""), uf(""){}
        Cidades(int, string, string);
        
        int getcod_cidade(){return this -> cod_cidade;}
        string getdescricao_cidade(){return this -> descricao_cidade;}
        string getuf(){return this -> uf;}
        
        void setcod_cidade(int _cod_cidade){this -> cod_cidade = _cod_cidade;}
        void setdescricao_cidade(string _descricao_cidade){this -> descricao_cidade = _descricao_cidade;}
        void setuf(string _uf){this -> uf = _uf;}
};

 Cidades::Cidades(int _cod_cidade, string _descricao_cidade, string _uf){
    this -> cod_cidade = _cod_cidade;
    this -> descricao_cidade = _descricao_cidade;
    this -> uf = _uf;
 }
