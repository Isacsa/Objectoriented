#include "Administrativo.h"

Administrativo::Administrativo() :Funcionario(){
	set_p_hora_extra(p_hora_extra_ad);
}

Administrativo::Administrativo(float _ord_base, int _h_extra, float _p_hora_extra, int num, string _setor, string nome, Data dn, string mor)
:Funcionario(_ord_base, _h_extra, _p_hora_extra, num, _setor, nome, dn, mor){
	set_p_hora_extra(p_hora_extra_ad);
}

Administrativo::~Administrativo(){}

float Administrativo::Calcula_ordenado(){
	float aux = get_ord_base() + get_h_extra() * get_p_hora_extra();
	return aux;
}
void Administrativo::Show(void){
	Funcionario::Show();
}
void Administrativo::ReadK(void){
	Funcionario::ReadK();
}
ostream & operator << (ostream &os, const Administrativo A){
	os << (Funcionario &)A;
	return os;
}
istream & operator >> (istream &is, Administrativo &A){
	is >> (Funcionario &)A;
	A.set_p_hora_extra(p_hora_extra_ad);
	return is;
}
void Administrativo::SaveFile(ofstream & os) const{
	//os << "A:";
	Funcionario::SaveFile(os);
}
void Administrativo::ReadFile(ifstream & is){
	Funcionario::ReadFile(is);
	this->set_p_hora_extra(p_hora_extra_ad); //10 € por hora extra
}
