#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Data.h"

using namespace std;
class Pessoa{
private:
	string nome, morada;
	Data   data;

public:
	Pessoa();
	Pessoa(string _nome, string _morada, Data _data);
	Pessoa(string _nome, string _morada, int _dia, int _mes, int _ano);
	virtual ~Pessoa();

	void SetNome(string _nome) { nome = _nome; }
	void SetMorada(string _morada) { morada = _morada; }
	void SetData(Data _data) { data = _data; }
	string GetNome(void) const { return nome; }
	string GetMorada(void) const { return morada; }
	Data GetData(void) const { return data; }

	bool MaisNovo(const Pessoa P) const;
	void Show(void) const;
	void ReadK(void);

	friend ostream & operator << (ostream &os, const Pessoa P);
	friend istream & operator >> (istream &is, Pessoa &P);

	bool operator == (const Pessoa P) const;
	bool operator != (const Pessoa P) const;

	void SaveFile(ofstream &os) const;
	void ReadFile(ifstream &is);
};

