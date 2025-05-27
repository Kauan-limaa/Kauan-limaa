//Data.h
class Data {
    //atributos
private:
    int dia;
    int mes;
    int ano;


    //métodos
public:
    //construtor padrão
    Data(): dia(1), mes(1), ano(1900){}

    //construtor parametrizado
    Data(int, int, int);
    // Data(int d, int mes, int ano): dia(d), mes(mes), ano(ano){}

    //getters
    int getDia() {return this->dia;}
    int getMes() {return this->mes;}
    int getAno() {return this->ano;}

    //setters
    void setAno(int);
    void setMes(int);
    void setDia(int);

    void imprimir(){
        cout << endl << "Data: " << dia << "/" << mes << "/" << ano << endl;
    }

    void ler();

};


Data::Data(int d, int mes, int ano){
    // this->dia = d;
    // this->mes = mes;
    // this->ano = ano;

    setAno(ano);
    setMes(mes);
    setDia(d);
}


void Data::setAno(int ano){
    if (ano >=1900 && ano <= 2100)
        this->ano = ano;
    else this->ano = 1900;
}

void Data::setMes(int mes) {
    //uso de operador ternário de condicional
    (mes>=1 && mes<=12) ? this->mes = mes : this->mes = 1;
}

void Data::setDia(int dia){
    if (this->mes==2){
        if (this->ano%4==0){
            if ((dia>0) && (dia<30))
                this->dia = dia;
            else this->dia =1;
        }
        else { if ((dia>0) && (dia<29))
            this->dia = dia;
        else this->dia = 1;;
        }
    } else if ((this->mes==4)|| (this->mes==6) || (this->mes==9) || (this->mes==11)) {
        if ((dia>0) && (dia<31))
            this->dia = dia;
        else this->dia = 1;
    }
    else {  if (dia>0 && dia<32)
        this->dia = dia;
    else this->dia = 1;
    }

}


void Data::ler(){
    int ano;
    cout << "Informe o ano";
    cin >> ano;
    setAno(ano);
}
