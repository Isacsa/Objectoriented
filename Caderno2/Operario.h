#pragma once
#include <fstream>
//#include <string>
//#include "Pessoa.h"
//#include "Data.h"
#include "Funcionario.h"

#define p_hora_extra_op 8

using namespace std;

class Operario : public Funcionario{
private:
	bool f_turno;
public:
	Operario();
	Operario(bool _f_turno, 
		float _ord_base, int _h_extra, float _p_hora_extra,
		int num, string _setor, string nome, Data dn, string mor);
	virtual ~Operario();

	bool get_f_turno(void) const { return f_turno; }
	void set_f_turno(bool _turno) { f_turno = _turno; }

	virtual void SaveFile(ofstream &os) const;
	virtual void ReadFile(ifstream &is);
	
	void Show(void);
	void ReadK(void);

	friend ostream & operator << (ostream &os, const Operario O);
	friend istream & operator >> (istream &is, Operario &O);

	virtual float Calcula_ordenado();
};

