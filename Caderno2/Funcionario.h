#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Pessoa.h"
#include "Data.h"

using namespace std;
class Funcionario : public Pessoa {
private:
	int num_func;
	string setor;
	float ord_base;
	int	h_extra;
	float p_hora_extra;

public:
	Funcionario();
	Funcionario(string nome, Data dn, string mor, int num, string s);
	Funcionario(float _ord_base, int _h_extra, float _p_hora_extra,
		int num, string _setor, string nome, Data dn, string mor);
	virtual ~Funcionario();

	//Métodos de acesso
	int		getNumFunc(void) const { return num_func; }
	string	getSetor(void) const { return setor; }
	void	setNumFunc(int num) { num_func = num; }
	void	setSetor(string s) { setor = s; }

	float get_ord_base(void) const {return ord_base;}
	int	get_h_extra(void) const { return h_extra; }
	float get_p_hora_extra(void) const { return p_hora_extra; }

	void set_ord_base(float _ord_base)		{ ord_base = _ord_base; }
	void set_h_extra(int _h_extra)			{ h_extra = _h_extra; }
	void set_p_hora_extra(float _ph_extra)  { p_hora_extra = _ph_extra; }

	//Outros métodos
	virtual void Show(void) const;
	virtual void ReadK(void);
	
	friend istream & operator >> (istream &is, Funcionario &F);
	friend ostream & operator << (ostream &os, const Funcionario &F);

	virtual void SaveFile(ofstream &os) const;
	virtual void ReadFile(ifstream &is);

	virtual float Calcula_ordenado() = 0; //método virtual puro => classe abstrata
};