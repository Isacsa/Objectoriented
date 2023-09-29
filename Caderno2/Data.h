#pragma once
#include <iostream>
#include <fstream>

using namespace std;

//NOTA: Nesta classe n�o se verifica a validade de uma Data
class Data{

private:
	int ano, mes, dia;

public:
	Data();

	Data(int _dia, int _mes, int _ano);		// Construtor com par�metros
	virtual ~Data();

	void SetDia(int _dia);
	void SetMes(int _mes);
	void SetAno(int _ano) { ano = _ano; }
	
	int GetDia(void) const { return dia; }	// m�todo inline
	int GetMes(void) const { return mes; }	// m�todo inline
	int GetAno(void) const { return ano; }	// m�todo inline

	void Show(void) const;
	void ReadK(void);
	void Update(int _dia, int _mes, int _ano);
	bool Igual(const Data data) const;

	bool operator == (const Data data) const;
	bool operator != (const Data data) const;
	bool operator < (const Data data) const;
	bool operator > (const Data data) const;

	Data operator + (const Data data) const;
	//Data operator - (const Data data) const; //Falta definir

	friend ostream & operator << (ostream &os, const Data data);
	friend istream & operator >> (istream &is, Data &data);

	void SaveFile(ofstream& os) const;
	void ReadFile(ifstream& is);

};

