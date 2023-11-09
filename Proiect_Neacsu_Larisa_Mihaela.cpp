//Magazin de instrumente muzicale

#include<iostream>
using namespace std;

class Microfon {
public:
	string marca;
	int stocMicrofoane;
	const int idModel;
	static int nrMicrofoaneSet;
	int* colectie;

	Microfon() :idModel(20) {
		this->marca = "Shure";
		this->stocMicrofoane = 2;
		this->colectie = NULL;
	}
	Microfon(int idModelNou, string marca) :idModel(idModelNou)
	{
		this->marca = marca;
		this->stocMicrofoane = 9;
		this->colectie = NULL;
	}
	Microfon(int idModel, string marca, int stocMicrofoane, int* colectie) :idModel(idModel), marca(marca), stocMicrofoane(stocMicrofoane)
	{
		if (stocMicrofoane != 0) {
			this->colectie = new int[stocMicrofoane];
			for (int i = 0; i < stocMicrofoane; i++)
			{
				this->colectie[i] = colectie[i];
			}
		}
		else this->colectie = NULL;
	}
	~Microfon() {
		if (this->colectie != NULL) {
			delete[]this->colectie;
		}
	}

	void afisare() {
		cout << idModel << "." << "marca:" << marca << "." << "nrMicrofoaneSet:" << nrMicrofoaneSet << "." << "stocMicrofoane" << stocMicrofoane << "." << "colectie:";
		if (colectie != NULL)
		{
			for (int i = 0; i < stocMicrofoane; i++) {
				cout << colectie[i] << ",";
			}
		}
		else {
			cout << "21";
		}
		cout << endl;
	}
};

int Microfon::nrMicrofoaneSet = 2;


class Pian {
public:
	string marcaPian;
	int stoc;
	const int idModel;
	static int stocInitial;
	int* colectiePian;

	Pian() :idModel(20) {
		this->marcaPian = "Roland";
		this->stoc = 0;
		this->colectiePian = NULL;
	}
	Pian(int idModelNou, string marcaPian) :idModel(idModelNou)
	{
		this->marcaPian = marcaPian;
		this->stoc = 0;
		this->colectiePian = NULL;
	}
	Pian(int idModel, string marcaPian, int stoc, int* colectiePian) :idModel(idModel), marcaPian(marcaPian), stoc(stoc)
	{
		if (stoc != 0) {
			this->colectiePian = new int[stoc];
			for (int j = 0; j < stoc; j++)
			{
				this->colectiePian[j] = colectiePian[j];
			}
		}
		else this->colectiePian = NULL;
	}
	~Pian() {
		if (this->colectiePian != NULL) {
			delete[]this->colectiePian;
		}
	}

	void afisare2() {
		cout << idModel << "." << "marca:" << marcaPian << "." << " stocInitial:" << stocInitial << "." << "stoc" << stoc << "." << "colectiePian:";
		if (colectiePian != NULL)
		{
			for (int j = 0; j < stoc; j++) {
				cout << colectiePian[j] << ",";
			}
		}
		else {
			cout << "21";
		}
		cout << endl;
	}
};

int Pian::stocInitial = 10;

class Chitara {
public:
	string tipChitara;
	int nrCorzi;
	const int idModel;
	static int colectie;
	int* stoc;

	Chitara() :idModel(20)
	{
		this->tipChitara = "acustica";
		this->nrCorzi = 10;
		this->stoc = NULL;
	}
	Chitara(int idModelNou, string tipChitara) : idModel(idModelNou)
	{
		this->tipChitara = tipChitara;
		this->nrCorzi = 14;
		this->stoc = NULL;
	}
	Chitara(int idModel, string tipChitara, int nrCorzi, int* stoc) :idModel(idModel), tipChitara(tipChitara), nrCorzi(nrCorzi)
	{
		if (nrCorzi != 0) {
			this->stoc = new int[nrCorzi];
			for (int j = 0; j < nrCorzi; j++)
			{
				this->stoc[j] = stoc[j];
			}
		}
		else this->stoc = NULL;
	}
	~Chitara()
	{
		if (this->stoc != NULL) {
			delete[]this->stoc;
		}
	}

	void afisare()
	{

		cout << idModel << "." << "tipChitara:" << tipChitara << "." << "colectie:" << colectie << "." << "nrCorzi" << nrCorzi << "." << "stoc:";
		if (stoc != NULL)
		{
			for (int j = 0; j < nrCorzi; j++) {
				cout << stoc[j];
			}
		}
		else
		{
			cout << "nu se afla pe stoc";
		}
		cout << endl;
	}
};
int Chitara::colectie = 2023;


void main() {
	int* colectie;
	colectie = new int[2];
	colectie[0] = 2023;
	colectie[1] = 2022;
	Microfon microfon1;
	microfon1.afisare();
	Microfon microfon2(21, "Sennheiser", 2, colectie);
	microfon2.afisare();
	Microfon microfon3(22, "Audio");
	microfon3.afisare();

	int* colectiePian;
	colectiePian = new int[2];
	colectiePian[0] = 23;
	colectiePian[1] = 22;
	Pian pian1;
	pian1.afisare2();
	Pian pian2(21, "Yamaha", 2, colectiePian);
	pian2.afisare2();
	Pian pian3(22, "Korg");
	pian3.afisare2();

	int* stoc;
	stoc = new int[1];
	stoc[0] = 5;
	Chitara chitara1;
	chitara1.afisare();
	Chitara chitara2(21, "electrica", 1, stoc);
	chitara2.afisare();
	Chitara chitara3(22, "clasica");
	chitara3.afisare();
}
