#include "Data.h"

Data::Data(){
	dia = mes = ano = 0;
}

Data::~Data(){}

void Data::SetDia(int _dia){
	if (dia < 2) {	dia = 1;}
	else {	if (dia > 30) {	dia = 31; }
			else {	dia = _dia;	}
	}
}
void Data::SetMes(int _mes) {
	if (mes < 2) { mes = 1; }
	else {
		if (mes > 11) { mes = 12; }
		else { mes = _mes; }
	}
}
Data::Data(int _dia, int _mes, int _ano){
	dia = _dia;
	mes = _mes;
	ano = _ano;
}

void Data::Show(void) const{
	cout << "Data: " << GetDia() << "/" << GetMes() << "/" << GetAno() << "\n";
}

void Data::ReadK(void){

	cout << "Insira o ano: ";
	cin >> ano;
	cout << "Insira o mes: ";
	cin >> mes;
	cout << "Insira o dia: ";
	cin >> dia;
}

void Data::Update(int _dia, int _mes, int _ano){
	SetDia(_dia);// dia = _dia;
	SetMes(_mes);//	mes = _mes;
	SetAno(_ano);//	ano = _ano;
}

bool Data::Igual (const Data data) const {
	if (data.ano != ano || data.mes != mes || data.dia != dia)
		return(false);
	return(true);
}

ostream & operator << (ostream &os, const Data data){
	os << /*"Data:" <<*/ data.GetDia() << "/" << data.GetMes() << "/" << data.GetAno() << ";";

	return os;
}

istream & operator >> (istream &is, Data &data){	
	int aux;

	cout << "Dia: ";
	is >> aux;
	data.SetDia(aux);
	cout << "Mês: ";
	is >> data.mes;		//métodos friend têm acesso direto aos membros da classe
	cout << "Ano: ";
	is >> data.ano;

	return is;
}

bool Data::operator == (const Data data) const{
	//if (data.ano != ano || data.mes != mes || data.dia != dia)
	//	return(false);
	//return(true);
	return this->Igual(data); // pode fazer-se uso de outro método da classe
}

bool Data::operator!=(const Data data) const{
	return !(this->operator==(data));
}

bool Data::operator < (const Data data) const{
	if (data.ano < ano)
		return(false);
	else	if (data.ano == ano && data.mes < mes)
		return(false);
	else	if (data.ano == ano && data.mes == mes && data.dia < dia)
		return(false);
	return(true);
}

bool Data::operator >(const Data data) const{
	if (data.ano > ano)
		return(false);
	else	if (data.ano == ano && data.mes > mes)
		return(false);
	else	if (data.ano == ano && data.mes == mes && data.dia > dia)
		return(false);
	return(true);
}

Data Data::operator+(const Data data) const{
	Data aux;
	aux.ano = this->GetAno() + data.GetAno();
	aux.mes = this->GetMes() + data.GetMes();
	aux.dia = this->GetDia() + data.GetDia();
	if (aux.dia > 31) {
		aux.dia -= 31;
		aux.mes++;
	}
	if (aux.mes > 12) {
		aux.mes -= 12;
		aux.ano++;
	}
	return Data();
}

void Data::SaveFile(ofstream& os) const{
	os << /*"Data:" <<*/ GetDia() << "/" << GetMes() << "/" << GetAno() << ";";
}

void Data::ReadFile(ifstream& is){	
	char aux[10];

	//is.getline(aux,10,':');
	
	is.getline(aux, 10, '/');
	dia = atoi(aux);
	is.getline(aux, 10, '/');
	mes = atoi(aux);
	is.getline(aux, 10, ';');
	ano = atoi(aux);
}
