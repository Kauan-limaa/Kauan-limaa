class Data {
private:
    int dia, mes, ano;
public:
    Data();
    Data(int d, int m, int a);

    int getDia() const; int getMes() const; int getAno() const;

    void setDia(int d); void setMes(int m); void setAno(int a);
    void imprimir();
};


Data::Data() : dia(1), mes(1), ano(1900) {}
Data::Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}

int Data::getDia() const { return dia; }
int Data::getMes() const { return mes; }
int Data::getAno() const { return ano; }

void Data::setDia(int d) { this->dia = d; }
void Data::setMes(int m) { this->mes = m; }
void Data::setAno(int a) { this->ano = a; }

void Data::imprimir() {
    cout << dia << "/" << mes << "/" << ano;
}