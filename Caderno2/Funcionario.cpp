#include "Funcionario.h"

Funcionario::Funcionario() :Pessoa() {
	num_func = 0;
	setor = "";
}

Funcionario::Funcionario(string nome, Data dn, string mor, int num, string s) :
	Pessoa(nome, mor, dn) {
	num_func = num;
	setor = s;
	ord_base = 600;
	h_extra = 0;
	p_hora_extra = 8;
}

Funcionario::Funcionario(float _ord_base, int _h_extra, float _p_hora_extra,
	int num, string _setor, string nome, Data dn, string mor):
	Pessoa(nome, mor, dn){
		num_func = num;
		setor = _setor;
		ord_base = _ord_base;
		h_extra = _h_extra;
		p_hora_extra = _p_hora_extra;
}

Funcionario::~Funcionario() {}

void Funcionario::Show(void) const {

	Pessoa::Show();
	cout << " Horas extra: " << get_h_extra() << " Ord. Base: " << get_ord_base()
		<< " Num: " << getNumFunc() << " Setor: " << getSetor() << "\n";
}

void Funcionario::ReadK(void){
	Pessoa::ReadK();
	cout << "Horas extra:";
	cin >> this->h_extra;
	cout << "Ord. Base:";
	cin >> this->ord_base;
	cout << "Num:";
	cin >> this->num_func;
	cout << "Setor:";
	cin >> this->setor;
}

void Funcionario::SaveFile(ofstream & os) const{
	Pessoa::SaveFile(os);
	os << num_func << ";" << setor << ";" << ord_base << ";" << h_extra << ";";
}

void Funcionario::ReadFile(ifstream & is){
	Pessoa::ReadFile(is);
	char aux[100];

	is.getline(aux, 100, ';');
	num_func = atoi(aux);
	is.getline(aux, 100, ';');
	setor = aux;				//	is.get();
	is.getline(aux, 100, ';');
	ord_base = (float)atof(aux);//	is.get();
	is.getline(aux, 100, ';');
	h_extra = atoi(aux);		//	is.get();
}

istream & operator >> (istream &is, Funcionario &F) {
	char aux[100];

	cin >> (Pessoa&)F;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Numero: ";
	cin >> F.num_func;
	cout << "Setor: ";
	is >> aux;	F.setor = aux;
	cout << "Ord Base: ";
	cin >> F.ord_base;
	cout << "Horas extra: ";
	cin >> F.h_extra;

	return is;
}
ostream & operator << (ostream &os, const Funcionario &F) {
	os << (Pessoa&)F;
	os << "Numero: "	<< F.getNumFunc()	<< ";";
	os << "Setor: "		<< F.getSetor()		<< ";";
	os << "Ord Base: "	<< F.get_ord_base() << ";";
	os << "Horas extra:" << F.get_h_extra() << ";";

	return os;
}