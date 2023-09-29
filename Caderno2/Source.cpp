#pragma once 

#include <iostream>
#include <fstream>
#include <string>

#include "Data.h"
#include "Pessoa.h"
#include "Funcionario.h"
#include "Operario.h"
#include "Administrativo.h"

using namespace std;

typedef Administrativo Admin;
typedef Funcionario Func;
typedef Operario Oper;

void Swap(Funcionario **x, Funcionario **y){
	Funcionario*	aux;

	aux = *x;
	*x = *y;
	*y = aux;
}
void BubbleSort(Funcionario *A[], int size){
	bool swaped;
	int i, j;

	i = size;
	do {
		swaped = false;
		for (j = 1; j<i; j++) {
			if ((*(A + j - 1))->GetNome() >(*(A + j))->GetNome()) {
				Swap((A + j - 1), (A + j));
				swaped = true;
			}
		}
		i--;
	} while (i>0 && swaped);
}
void SelectionSort(Funcionario *A[], int size)
{
	int i, j, aux;

	for (i = 0; i<size - 1; i++)
	{
		aux = i;
		for (j = i + 1; j<size; j++)
			if ((*(A + j))->GetData() < (*(A + aux))->GetData())
				aux = j;
		Swap((A + aux),(A + i));
	}
}
void InsertionSort(Funcionario *A[], int size)
{
	int i, j;
	Funcionario* aux;

	for (i = 1; i<size; i++) {
		aux = *(A + i);
		j = i;
		while (j>0 && (*(A + j - 1))->GetNome() > (*aux).GetNome())	{
			*(A + j) = *(A + j - 1);
			j = j - 1;
		}
		*(A + j) = aux;
	}
}

char menu(void) {
	char op = 's';
	cout << endl << endl;
	system("pause");
	system("cls");
	cout << endl << endl;
	cout << "\t" << "MENU";
	cout << endl << endl;
	cout << "a - Leitura do ficheiro para um vetor de apontadores " << endl;
	cout << "b - Calcular e apresentar o ordenado de todos os funcionarios" << endl;
	cout << "c - Pesquisar um funcionario pelo seu numero" << endl;
	cout << "d - Alterar o ordenado base de um funcionario pelo seu numero" << endl;
	cout << "e - Adicionar ao vetor um Operario ou Administrativo" << endl;
	cout << "f - Apresentar o nome dos operários que trabalham por turnos" << endl;
	cout << "g - Eliminar do vetor um funcionário, identificado pelo número" << endl;
	cout << "h - Guardar, num ficheiro, os dados dos Administrativos" << endl;
	cout << "i - Guardar, num ficheiro, os dados dos Operarios" << endl;
	cout << "j - Guardar, num ficheiro, os dados de todos os Funcionarios" << endl;
	cout << "k - Listagem de todos os dados dos Funcionarios" << endl;
	cout << "l - Ordenar todos os funcionarios por ordem alfabetica" << endl;
	cout << endl;
	cout << "s - Sair" << endl;
	cout << "Escolha uma opcao: ";
	cin >> op;
	return op;

}

int main(void) {

	int size = 0;
	Func* lista[100];
	ifstream ifile;
	
	//inicialização da lista
	for (int j = 0; j < 100; j++) {	
		lista[j] = NULL;
	}
	char op = '0';

	while (op != 's') {
		op = menu();
		switch (op) {
		case 'a': {case 'A': 
			ifile.open("funcionario.txt");
			if (!ifile) {
				cout << endl << "Erro de abertura de ficheiro" << endl;
				exit(1);
			}
			
			char aux[5];
			while (!ifile.eof()) {
				ifile.getline(aux, sizeof(aux), ':');
				//ifile.get();
				if (strcmp(aux, "O") == 0) {
					lista[size] = (Oper*) new Oper;
				}
				if (strcmp(aux, "A") == 0) {
					lista[size] = (Admin*) new Admin;
				}
				if (lista[size] != NULL) {
					lista[size]->ReadFile(ifile);
					ifile.get();
					size++;
				}
			}
			ifile.close();
			break;}
		case 'b': {case 'B':
			cout << endl << endl;
			cout << "nome: " << "\t\t" << "Ordenado: " << endl << endl;
			for (int j = 0; j < size; j++) {
				//lista[j]->Show();
				cout << lista[j]->GetNome() << "\t" << 
					lista[j]->Calcula_ordenado() << endl;
			}
			break;}
		case 'c': {case 'C': 
			cout << endl << "Numero do funcionario a procurar: ";
			int num;
			bool flag = false;
			cin >> num;
			for (int j = 0; j < size; j++)
				if (num == lista[j]->getNumFunc()) {
					flag = true;
					cout << endl << lista[j]->GetNome() << endl;
				}
			if (!flag) {
				cout << endl << "Funcionario nao encontrado!" << endl;
			}
			break;}
		case 'd': {case 'D': 
			int num = 0;
			bool flag = false;
			cout << endl << "Numero do funcionario a alterar ordenado: ";
			cin >> num;
			float novo_ord;
			for (int j = 0; j < size; j++)
				if (num == (lista[j])->getNumFunc()) {
					flag = true;
					cout << "Insira o novo ordenado do " << lista[j]->GetNome() << ": ";
					cin >> novo_ord;
					lista[j]->set_ord_base(novo_ord);
				}
			if (!flag) {
				cout << "Funcionario nao encontrado!" << endl;
			}
			break;}
		case 'e': {case 'E': 
			char op;
			cout << endl << "Adicionar:  1- Operário 2 - Administrativo:  ";
			cin >> op;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			switch (op) {
			case '1': lista[size] = (Oper *) new Oper;
				lista[size]->ReadK();
				size++;
				break;

			case '2': lista[size] = (Admin *) new Admin;
				lista[size]->ReadK();
				size++;
				break;

			default: cout << endl << "Opção incorreta";
				break;
			}
			break;}
		case 'f': {case 'F': 
			Oper* O;
			cout << endl << "Operarios que trabalham por turnos " << endl;
			for (int j = 0; j<size; j++) {
				if (O = dynamic_cast <Oper *> (lista[j]))
					if (O->get_f_turno() == true) {
						lista[j]->Show();
						cout << endl;
					}
			}
			break;}
		case 'g': {case 'G': 
			int num = 0;
			bool flag = false;
			cout << "Numero do funcionario a eliminar: ";
			cin >> num;
			for (int j = 0; j < size; j++) {
				if (num == lista[j]->getNumFunc()) {
					flag = true;
					delete lista[j];
					lista[j] = NULL;
					for (int i = j; i < size - 1; i++)
						lista[i] = lista[i + 1];
					size--;
				}
			}
			if (!flag) {
				cout << "Funcionario nao encontrado!" << endl;
			}
			break;}
		case 'h': {case 'H': 
			ofstream ofile;
			Admin* A = NULL;
			ofile.open("Administrativos.txt");
			if (!ofile) {
				cout << "ERRO: nao e possivel criar o ficheiro Administrativos.txt" << endl;
				exit(0);
			}
			for (int i = 0; i<size; i++) {
				if (A = dynamic_cast <Admin *> (lista[i])) {
					lista[i]->SaveFile(ofile);
					ofile << "Ordenado Final: " << A->Calcula_ordenado() << endl;
				}
			}
			ofile.close();
			break;}
		case 'i': {case 'I': 
			ofstream ofile;
			Oper* O = NULL;
			ofile.open("Operarios.txt");
			if (!ofile) {
				cout << "ERRO: nao e possivel criar o ficheiro Operarios.txt" << endl;
				exit(0);
			}
			for (int i = 0; i<size; i++) {
				if (O = dynamic_cast <Oper *> (lista[i])) {
					lista[i]->SaveFile(ofile);
					ofile << "Ordenado Final: " << O->Calcula_ordenado() << endl;
				}
			}
			ofile.close();
			break;}
		case 'j': {case 'J': 
			ofstream ofile;
			Oper* O = NULL;
			ofile.open("Funcionarios.txt");
			if (!ofile) {
				cout << "ERRO: nao e possivel criar o ficheiro Funcionarios.txt" << endl;
				exit(0);
			}
			for (int i = 0; i<size; i++) {
				if (O = dynamic_cast <Oper *> (lista[i])) {
					ofile << "O:";
				}
				if (A = dynamic_cast <Admin *> (lista[i])) {
					ofile << "A:";
				}				
				lista[i]->SaveFile(ofile);
				if (i + 1 != size) { ofile << endl; }
			}
			ofile.close();
			break;}
		case 'k': {case 'K': 
			for (int j = 0; j < size; j++) {
				lista[j]->Show();
				cout << endl;
			}
			break;}
		case 'l': {case 'L': 
			//BubbleSort(lista, size);
			//SelectionSort(lista, size);
			InsertionSort(lista, size);
			break;}
		case 's': {case 'S': 
			// limpeza da memória antes de sair
			for (int j = 0; j < size; j++) {
				if (lista[j] != NULL) {
					delete lista[j];
					lista[j] = NULL;
				}
			}
			size = 0;
			break;}
		default:  {
			cout << endl << endl << "Opcao invalida.";
			break;}
		}
	}

	cout << endl << endl;
	system("pause");
	return 0;
}
