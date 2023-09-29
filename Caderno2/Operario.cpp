#include "Operario.h"


Operario::Operario():Funcionario(){
	f_turno = false;
	set_p_hora_extra(p_hora_extra_op);
}

Operario::Operario(bool _f_turno, float _ord_base, int _h_extra, float _p_hora_extra, int num, string _setor, string nome, Data dn, string mor)
: Funcionario(_ord_base, _h_extra, _p_hora_extra, num, _setor, nome, dn, mor) {
	f_turno = _f_turno;
	set_p_hora_extra(p_hora_extra_op);
}

Operario::~Operario(){}

void Operario::SaveFile(ofstream & os) const{
	//os << "O:";
	Funcionario::SaveFile(os);
	if (get_f_turno()) {
		os << "sim;";
	}	else {
		os << "nao;";
	}
}

void Operario::ReadFile(ifstream & is){
	char aux[100];
	//is.getline(aux, ':');
	//is.get();
	Funcionario::ReadFile(is);
	is.getline(aux, 100, ';');
//	is.get();
	if (strcmp(aux, "sim")==0) {
		set_f_turno(true);
	}else{ 
		set_f_turno(false); 
	}
}
void Operario::Show(void){
	Funcionario::Show();
	cout << " Preço por hora Extra: " << this->get_p_hora_extra();
	if (f_turno)
		cout << " Turnos: " << "sim" << endl;
	else
		cout << " Turnos: " << "nao" << endl;
}

void Operario::ReadK(void){
	char op = 'n';
	float _p_h_extra = 0.0f;

	Funcionario::ReadK();
	this->set_p_hora_extra( p_hora_extra_op );  //8 € por hora extra

	cout << "Turnos (s/n):";
	cin >> op;
	if (op == 's')
		f_turno = true;
	else
		f_turno = false;
}

ostream & operator << (ostream &os, const Operario O){
	os << (Funcionario &)O;
	if (O.f_turno)
		os << "Turnos:" << "sim" << endl;
	else
		os << "Turnos:" << "nao" << endl;

	return os;
}
istream & operator >> (istream &is, Operario &O){
	char op;

	is >> (Funcionario &)O;
	O.set_p_hora_extra( p_hora_extra_op );	 //8 € por hora extra
	cout << "Turnos (s/n):";
	cin >> op;
	if (op == 's')
		O.f_turno = true;
	else
		O.f_turno = false;

	return is;
}

float Operario::Calcula_ordenado(){
	float aux = get_ord_base() + get_h_extra() * get_p_hora_extra();
	if (get_f_turno()) aux *= 1.25;
	return aux;
}
