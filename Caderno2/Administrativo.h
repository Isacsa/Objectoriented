#pragma once
#include <fstream>
//#include <string>
//#include "Pessoa.h"
//#include "Data.h"
#include "Funcionario.h"

#define p_hora_extra_ad 10

using namespace std;
class Administrativo :public Funcionario{
public:
	Administrativo();
	Administrativo(	float _ord_base, int _h_extra, float _p_hora_extra,
		int num, string _setor, string nome, Data dn, string mor );
	virtual ~Administrativo();

	virtual float Calcula_ordenado();
	
	void Show(void);
	void ReadK(void);

	friend ostream & operator << (ostream &os, const Administrativo A);
	friend istream & operator >> (istream &is, Administrativo &A);

	virtual void SaveFile(ofstream &os) const;
	virtual void ReadFile(ifstream &is);
};

