
class Generos{
    private:
        int cod_genero;
        string descricao_genero;

    public:
        Generos():cod_genero(0), descricao_genero(""){}
        Generos(int _cod_genero, string _descricao_genero):cod_genero(_cod_genero),descricao_genero(_descricao_genero){}

        int getcod_genero(){return this -> cod_genero;}
        string getdescricao_genero(){return this -> descricao_genero;}

        void setcod_genero(int _cod_genero){this -> cod_genero = _cod_genero;}
        void setdescricao_genero(string _descricao_genero){this -> descricao_genero = _descricao_genero;}

};

