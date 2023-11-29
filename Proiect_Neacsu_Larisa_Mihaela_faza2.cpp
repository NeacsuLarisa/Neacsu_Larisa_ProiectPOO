//Magazin de instrumente muzicale

#include<iostream>
#include<string>
using namespace std;

class Microfon {
private:
	string marca;
	int stocMicrofoane;
	const int idModel;
	static int nrMicrofoaneSet;
	int* colectie;

public:

	string getMarca() {
		return marca;
	}
	int getStocMicrofoane() {
		return stocMicrofoane;
	}
	int* getColectie() {
		return colectie;
	}

	void setMarca(string marca) {
		if (marca.length() <= 5)
		{
			this->marca = marca;
		}
	}
	void setStocMicrofoane(int stocMicrofoane) {
		if (stocMicrofoane > 0) {
			this->stocMicrofoane = stocMicrofoane;
		}
	}
	void setColectie(int stocMicrofoane, int* colectie)
	{
		if (this->colectie != NULL)
		{
			delete[]this->colectie;
		}
		this->stocMicrofoane = stocMicrofoane;
		this->colectie = new int[this->stocMicrofoane];
		for (int i = 0; i < this->stocMicrofoane; i++)
		{
			this->colectie[i] = colectie[i];
		}
	}

	int getIdModel() const {
		return idModel;
	}

	Microfon() :idModel(20) {
		this->marca = "Shure";
		this->stocMicrofoane = 0;
		this->colectie = NULL;
	}
	Microfon(int idModelNou, string marca) :idModel(idModelNou)
	{
		this->marca = marca;
		this->stocMicrofoane = 0;
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
	Microfon(const Microfon& c) :idModel(c.idModel) {
		marca = c.marca;
		stocMicrofoane = c.stocMicrofoane;
		if (stocMicrofoane != 0) {
			this->colectie = new int[stocMicrofoane];
			for (int i = 0; i < stocMicrofoane; i++)
			{
				this->colectie[i] = c.colectie[i];
			}
		}
		else this->colectie = NULL;

	}

	friend void schimbaMarca(Microfon& m, string nouaMarca)
	{
		m.marca = nouaMarca;
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
	static int getNrMicrofoaneSet() {
		return Microfon::nrMicrofoaneSet;
	}
	static void setNrMicrofoaneSet(int nrMicrofoane)
	{
		if (nrMicrofoane > 5)
		{
			cout << "Numarul microfoanelor este gresit" << ".";
		}
		else
			cout << "Numarul microfoanelor este gresit si trebuie actualizat:" << ".";
	}

	static void actualizeazaNrMicrofoaneSet(int noulNrMicrofoaneSet) {
		nrMicrofoaneSet = noulNrMicrofoaneSet;
	}

};


int Microfon::nrMicrofoaneSet = 2;


class Pian {
private:
	string marcaPian;
	int stoc;
	const int idModel;
	static int stocInitial;
	int* colectiePian;

public:
	string getMarcaPian() {
		return marcaPian;
	}
	int getStoc() {
		return stoc;
	}
	int* getColectiePian() {
		return colectiePian;
	}

	void setMarcaPian(string marcaPian) {
		if (marcaPian.length() != 3)
		{
			this->marcaPian = marcaPian;
		}
	}
	void setStoc(int stoc) {
		if (stoc > 0) {
			this->stoc = stoc;
		}
	}
	void setColectiePian(int stoc, int* colectiePian)
	{
		if (this->colectiePian != NULL)
		{
			delete[]this->colectiePian;
		}
		this->stoc = stoc;
		this->colectiePian = new int[this->stoc];
		for (int i = 0; i < this->stoc; i++)
		{
			this->colectiePian[i] = colectiePian[i];
		}
	}

	int getIdModel() const {
		return idModel;
	}


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

	Pian(const Pian& p) :idModel(p.idModel) {
		marcaPian = p.marcaPian;
		stoc = p.stoc;
		if (stoc != 0) {
			this->colectiePian = new int[stoc];
			for (int i = 0; i < stoc; i++)
			{
				this->colectiePian[i] = p.colectiePian[i];
			}
		}
		else this->colectiePian = NULL;

	}

	static int getStocInitial() {
		return Pian::stocInitial;
	}
	static void setStocInitial(int stocInitial)
	{
		if (stocInitial >= 15)
		{
			cout << "Stocul initial este gresit:" << ".";
		}
		else
			cout << "Stocul initial nu este gresit:" << ".";
	}

	static void modificaStoc(int noulStoc) {
		stocInitial = noulStoc;
	}

	~Pian() {
		if (this->colectiePian != NULL) {
			delete[]this->colectiePian;
		}
	}

	void afisare() {
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
private:
	string tipChitara;
	int stoc;
	const int idModel;
	static int colectie;
	int* nrCorzi;

public:
	string getTipChitara() {
		return tipChitara;
	}
	int getStoc() {
		return stoc;
	}
	int* getNrCorzi() {
		return nrCorzi;
	}

	void setTipChitara(string tipChitara) {
		if (tipChitara.length() <= 2)
		{
			this->tipChitara = tipChitara;
		}
	}
	void setStoc(int stoc) {
		if (stoc > 0) {
			this->stoc = stoc;
		}
	}
	void setNrCorzi(int stoc, int* nrCorzi)
	{
		if (this->nrCorzi != NULL)
		{
			delete[]this->nrCorzi;
		}
		this->stoc = stoc;
		this->nrCorzi = new int[this->stoc];
		for (int i = 0; i < this->stoc; i++)
		{
			this->nrCorzi[i] = nrCorzi[i];
		}
	}

	static void colectieActualizata(int nouaColectie)
	{
		colectie = nouaColectie;
	}


	Chitara() :idModel(20)
	{
		this->tipChitara = "acustica";
		this->stoc = 10;
		this->nrCorzi = NULL;
	}
	Chitara(int idModelNou, string tipChitara) : idModel(idModelNou)
	{
		this->tipChitara = tipChitara;
		this->stoc = 14;
		this->nrCorzi = NULL;
	}
	Chitara(int idModel, string tipChitara, int stoc, int* nrCorzi) :idModel(idModel), tipChitara(tipChitara), nrCorzi(nrCorzi)
	{
		if (stoc != 0) {
			this->nrCorzi = new int[stoc];
			for (int j = 0; j < stoc; j++)
			{
				this->nrCorzi[j] = nrCorzi[j];
			}
		}
		else this->nrCorzi = NULL;
	}

	Chitara(const Chitara& p) :idModel(p.idModel) {
		tipChitara = p.tipChitara;
		stoc = p.stoc;
		if (stoc != 0) {
			this->nrCorzi = new int[stoc];
			for (int i = 0; i < stoc; i++)
			{
				this->nrCorzi[i] = p.nrCorzi[i];
			}
		}
		else this->nrCorzi = NULL;

	}

	static int getColectie() {
		return Chitara::colectie;
	}

	static void setColectie(int nrCorziChitara)
	{
		if (nrCorziChitara > 16)
		{
			cout << "Chitara este din colectia:" << ".";
		}
		else cout << "Este din aceeasi colectie:" << ".";
	}

	friend int marireStoc(Chitara c, int a)
	{
		return c.stoc + a;
	}

	~Chitara()
	{
		if (this->nrCorzi != NULL) {
			delete[]this->nrCorzi;
		}
	}

	void afisare()
	{

		cout << idModel << "." << "tipChitara:" << tipChitara << "." << "colectie:" << colectie << "." << "nrCorzi" << stoc << "." << "stoc:";
		if (nrCorzi != NULL)
		{
			for (int j = 0; j < stoc; j++) {
				cout << nrCorzi[j];
			}
		}
		else
		{
			cout << " 10";
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
	schimbaMarca(microfon1, "Nnnn");
	Microfon microfon2(21, "Sennheiser", 2, colectie);
	microfon2.afisare();
	Microfon microfon3(22, "Audio");
	microfon3.afisare();

	microfon3.setMarca("Shure");
	microfon3.setStocMicrofoane(5);
	cout << microfon3.getMarca() << "." << microfon3.getStocMicrofoane() << endl;
	microfon3.setStocMicrofoane(3);
	int stocMicrofoane[] = { 21,22,24 };
	microfon3.setColectie(3, stocMicrofoane);
	for (int i = 0; i < microfon3.getColectie()[i]; i++)
	{
		cout << microfon3.getColectie()[i] << ",";
	}
	cout << endl;
	microfon3.getNrMicrofoaneSet();
	cout << "Numar microfoane set:" << microfon3.getNrMicrofoaneSet() << endl;

	Microfon microfon4(microfon1);
	Microfon microfon5(microfon4);
	microfon5.afisare();

	Microfon microfon6;
	microfon6.setNrMicrofoaneSet(4);
	cout << Microfon::getNrMicrofoaneSet();


	Microfon::actualizeazaNrMicrofoaneSet(4);

	int* colectiePian;
	colectiePian = new int[2];
	colectiePian[0] = 23;
	colectiePian[1] = 22;
	Pian pian1;
	pian1.afisare();
	Pian pian2(21, "Yamaha", 2, colectiePian);
	pian2.afisare();
	Pian pian3(22, "Korg");
	pian3.afisare();

	pian3.setMarcaPian("Roland");
	pian3.setStoc(10);
	cout << pian3.getMarcaPian() << "." << pian3.getStoc() << endl;
	pian3.setStoc(2);
	int stocP[] = { 21,22 };
	pian3.setColectiePian(2, stocP);
	for (int i = 0; i < pian3.getColectiePian()[i]; i++)
	{
		cout << pian3.getColectiePian()[i] << ",";
	}
	cout << endl;
	Pian pian4(pian2);
	Pian pian5(pian4);
	pian5.afisare();

	Pian pian6;
	pian6.setStocInitial(10);
	cout << Pian::getStocInitial();

	Pian::modificaStoc(15);








	int* stoc;
	stoc = new int[1];
	stoc[0] = 5;
	Chitara chitara1;
	chitara1.afisare();
	Chitara chitara2(21, "electrica", 0, stoc);
	chitara2.afisare();
	marireStoc(chitara2, 2);
	Chitara chitara3(22, "clasica");
	chitara3.afisare();

	chitara3.setTipChitara("Chitara este");
	chitara3.setStoc(10);
	cout << chitara3.getTipChitara() << "." << chitara3.getStoc() << endl;
	chitara3.setStoc(2);
	int stocC[] = { 16,18 };
	chitara3.setNrCorzi(2, stocC);
	for (int i = 0; i < chitara3.getNrCorzi()[i]; i++)
	{
		cout << chitara3.getNrCorzi()[i] << ",";
	}
	cout << endl;
	Chitara chitara4(chitara2);
	Chitara chitara5(chitara4);
	chitara5.afisare();

	Chitara chitara6;
	chitara6.setColectie(24);
	cout << Chitara::getColectie();

	Chitara::colectieActualizata(24);
}