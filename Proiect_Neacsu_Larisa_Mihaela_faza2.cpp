//Magazin de instrumente muzicale

#include<iostream>
#include<string>
#include<fstream>
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
	Microfon(int idModel, string marca) :idModel(idModel)
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

	Microfon operator=(const Microfon& c)
	{
		if (this != &c)
		{
			if (this->colectie != NULL) {
				delete[]this->colectie;
			}

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
		return *this;
	}

	friend istream& operator>>(istream& in, Microfon& c)
	{
		if (c.colectie != NULL) {
			delete[]c.colectie;
		}

		cout << "Introduceti marca:";
		in >> c.marca;
		cout << "Introduceti numarul de microfoane pe stoc:";
		in >> c.stocMicrofoane;
		c.colectie = new int[c.stocMicrofoane];
		for (int i = 0; i < c.stocMicrofoane; i++)
		{
			cout << "Introduceti colectia:";
			in >> c.colectie[i];
			cout << endl;
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, const Microfon& c)
	{
		out << "Marca microfonului este:" << c.marca << endl;
		out << "Stocul Microfoanelor este:" << c.stocMicrofoane << endl;
		out << "Id-ul modelului este:" << c.idModel << endl;
		out << "Colectiile sunt:";
		for (int i = 0; i < c.stocMicrofoane; i++)
		{
			out << c.colectie[i] << "," << endl;
		}
		return out;
	}
	friend ofstream& operator<<(ofstream& fis, const Microfon& microfon) {
		fis << microfon.idModel << endl << microfon.marca << endl;
		return fis;
	}

	friend ifstream& operator>>(ifstream& fis1, Microfon& microfon) {
		fis1 >> microfon.stocMicrofoane;
		fis1 >> microfon.marca;
		if (microfon.colectie != NULL) {
			delete[]microfon.colectie;
		}
		microfon.colectie = new int[microfon.stocMicrofoane];
		for (int i = 0; i < microfon.stocMicrofoane; i++)
			fis1 >> microfon.colectie[i];
		return fis1;
	}


	Microfon operator+(int s)
	{
		this->stocMicrofoane = this->stocMicrofoane + s;
		return *this;
	}
	explicit operator float() {
		float aux = 0;
		if (stocMicrofoane > 0) {
			for (int i = 0; i < stocMicrofoane; i++)
				aux = aux + colectie[i];
			aux = aux / stocMicrofoane;
		}
		return aux;
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


	Pian& operator+=(int stocNou)
	{
		this->stoc += stocNou;
		return *this;
	}

	bool operator>(Pian pian) {
		return this->stoc > pian.stoc;
	}

	Pian operator=(const Pian& pian)
	{
		if (this != &pian)
		{
			if (this->colectiePian != NULL) {
				delete[]this->colectiePian;
			}

			marcaPian = pian.marcaPian;
			stoc = pian.stoc;
			if (stoc != 0) {
				this->colectiePian = new int[stoc];
				for (int i = 0; i < stoc; i++)
				{
					this->colectiePian[i] = pian.colectiePian[i];
				}
			}
			else this->colectiePian = NULL;
		}
		return *this;
	}

	Pian operator+(int stoc) const {
		Pian aux = *this;
		aux.stoc = this->stoc + stoc;
		return aux;
	}

	friend Pian operator+(int stoc, const Pian& p) {
		Pian aux = p;
		aux.stoc = p.stoc + stoc;
		return aux;
	}


	friend istream& operator>>(istream& in, Pian& p)
	{
		if (p.colectiePian != NULL)
		{
			delete[]p.colectiePian;
		}
		cout << "Stoc:";
		in >> p.stoc;
		cout << "Introduceti marca pianului:";
		in >> p.marcaPian;
		p.colectiePian = new int[p.stoc];
		for (int i = 0; i < p.stoc; i++)
		{
			cout << "Introduceti colectia Pianului:";
			in >> p.colectiePian[i];
			cout << endl;
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, const Pian& p) {
		out << "Marca pianului este:" << p.marcaPian << endl;
		out << "Stoc:" << p.stoc << endl;
		for (int i = 0; i < p.stoc; i++)
		{
			out << p.colectiePian;
		}
		return out;
	}

	friend ofstream& operator<<(ofstream& fis2, const Pian& pian) {
		fis2 << pian.marcaPian << endl << pian.stoc << endl;
		if (pian.colectiePian != NULL) {
			for (int i = 0; i < pian.stoc; i++) {
				fis2 << pian.colectiePian[i] << " ";
			}
		}
		fis2 << endl;
		return fis2;
	}


	friend ifstream& operator>>(ifstream& fis3, Pian& pian) {
		fis3 >> pian.stoc;
		fis3 >> pian.marcaPian;
		if (pian.colectiePian != NULL) {
			delete[]pian.colectiePian;
		}
		pian.colectiePian = new int[pian.stoc];
		for (int i = 0; i < pian.stoc; i++)
			fis3 >> pian.colectiePian[i];
		return fis3;
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
	Chitara(int idModel, string tipChitara) : idModel(idModel)
	{
		this->tipChitara = tipChitara;
		this->stoc = 14;
		this->nrCorzi = NULL;
	}
	Chitara(int idModel, string tipChitara, int stoc, int* nrCorzi) :idModel(idModel), tipChitara(tipChitara), stoc(stoc), nrCorzi(nrCorzi)
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

	Chitara operator=(const Chitara& p)
	{
		if (this != &p)
		{
			if (this->nrCorzi != NULL) {
				delete[]this->nrCorzi;
			}
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

		return *this;
	}


	friend istream& operator>>(istream& in, Chitara& m) {
		if (m.nrCorzi != NULL) {
			delete[]m.nrCorzi;
		}
		cout << "Stocul este:";
		in >> m.stoc;
		cout << "Introduceti tipul chitarii:";
		in >> m.tipChitara;
		m.nrCorzi = new int[m.stoc];
		for (int i = 0; i < m.stoc; i++)
		{
			cout << "Introduceti numarul de corzi:";
			in >> m.nrCorzi[i];
			cout << endl;
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, const Chitara& m)
	{
		out << "Tip chitara:" << m.tipChitara << endl;
		out << "Stoc:" << m.stoc << endl;
		for (int i = 0; i < m.stoc; i++)
		{
			out << m.nrCorzi[i];
		}
		return out;
	}

	void scrieInFisierBinar(fstream& f) {
		f.write((char*)&this->stoc, sizeof(int));
		f.write((char*)&this->tipChitara, sizeof(string));
		//f.write((char*)&this->idModel, sizeof(const int));
	}

	void citesteDinFisierBinar(fstream& f) {
		f.read((char*)&this->stoc, sizeof(int));
		f.read((char*)&this->tipChitara, sizeof(string));
	}
	Chitara operator++()
	{
		for (int i = 0; i < this->stoc; i++)
		{
			this->nrCorzi[i]++;
		}
		return *this;
	}

	Chitara operator++(int)
	{
		Chitara aux = *this;
		for (int i = 0; i < this->stoc; i++)
		{
			this->nrCorzi[i]++;
		}
		return aux;
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

class Depozit {
public:
	string numeStrada;
	Microfon* colectie;
	int stoc;
	int* nrCutii;

	Depozit() {
		this->numeStrada = "Mihai Eminescu";
		this->stoc = 10;
		this->colectie = new Microfon();
		this->nrCutii = NULL;
	}

	Depozit(string numeStrada, Microfon* colectie, int stoc, int* nrCutii) {
		this->numeStrada = numeStrada;
		this->stoc = stoc;
		this->nrCutii = new int[this->stoc];
		for (int i = 0; i < this->stoc; i++)
		{
			this->nrCutii[i] = nrCutii[i];
		}
		this->colectie = new Microfon();
		*(this->colectie) = *(colectie);
	}

	void scrieInFisierBinar(fstream& f) {
		f.write((char*)&this->stoc, sizeof(int));
		f.write((char*)&this->numeStrada, sizeof(string));
		for (int i = 0; i < this->stoc; i++) {
			f.write((char*)&this->nrCutii, sizeof(int));
		}
	}

	void citesteDinFisierBinar(fstream& f) {
		f.read((char*)&this->stoc, sizeof(int));
		f.read((char*)&this->numeStrada, sizeof(string));
		for (int i = 0; i < this->stoc; i++) {
			f.write((char*)&this->nrCutii, sizeof(int));
		}
	}
	Depozit(const Depozit& d)
	{
		this->numeStrada = d.numeStrada;
		this->stoc = d.stoc;
		this->nrCutii = new int[this->stoc];
		for (int i = 0; i < this->stoc; i++)
		{
			this->nrCutii[i] = d.nrCutii[i];
		}
		this->colectie = new Microfon();
		*(this->colectie) = *(d.colectie);
	}

	string getNumeStrada()
	{
		return this->numeStrada;
	}
	int getStoc()
	{
		return this->stoc;
	}
	int* getNrCutii()
	{
		return this->nrCutii;
	}
	Microfon* getColectie()
	{
		return this->colectie;
	}

	void setNumeStrada(string numeStrada) {
		this->numeStrada = numeStrada;
	}
	void setStoc(int stoc) {
		this->stoc = stoc;
	}
	void setNrCutii(int stoc, int* nrCutii) {
		if (this->nrCutii != NULL)
		{
			delete[]this->nrCutii;
		}
		this->stoc = stoc;
		this->nrCutii = new int[this->stoc];
		for (int i = 0; i < this->stoc; i++)
		{
			this->nrCutii[i] = nrCutii[i];
		}

	}
	void setColectie(Microfon* colectie) {
		if (this->colectie != NULL)
		{
			delete[] this->colectie;
		}
		this->colectie = new Microfon();
		*(this->colectie) = *(colectie);
	}

	Depozit& operator=(const Depozit& d)
	{
		if (this != &d)
		{
			if (this->nrCutii != NULL)
			{
				delete[]this->nrCutii;
			}
			this->numeStrada = d.numeStrada;
			this->stoc = d.stoc;
			this->nrCutii = new int[this->stoc];
			for (int i = 0; i < this->stoc; i++)
			{
				this->nrCutii[i] = d.nrCutii[i];
			}
			this->colectie = new Microfon();
			*(this->colectie) = *(d.colectie);
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Depozit& d) {
		out << "Numele strazii unde se afla depozitul este:" << d.numeStrada << endl;
		out << "Stocul este:" << d.stoc << endl;
		out << "Colectie microfonului este:" << d.colectie << endl;
		for (int i = 0; i < d.stoc; i++)
		{
			out << d.nrCutii;
		}
		return out;
	}




	Depozit operator+(int stoc)const {
		Depozit aux = *this;
		aux.stoc = this->stoc + stoc;
		return aux;
	}

	void afisare()
	{
		cout << "Depozitul se afla pe strada:" << numeStrada << "." << " Afisarea stocurilor este : " << stoc << "." << endl;
	}
	~Depozit() {
		if (this->nrCutii != NULL)
		{
			delete[]this->nrCutii;
		}
	}
};





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
	microfon3 = microfon2;
	cout << microfon3;
	microfon2 = microfon2 + 3;

	Microfon microfon7;
	float medie;
	medie = (float)microfon7;
	cout << medie << endl;

	Microfon* microfon = new Microfon[3];
	for (int i = 0; i < 3; i++)
		cin >> microfon[i];
	for (int i = 0; i < 3; i++)
		cout << microfon[i];

	Microfon** matrice = new Microfon * [2];
	for (int i = 0; i < 2; i++)
	{
		matrice[i] = new Microfon[2];
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "Citeste Matricea:";
			cin >> matrice[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << matrice[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < 2; i++) {
		delete[]matrice[i];
	}
	delete[]matrice;

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
	cout << Pian::getStocInitial() << endl;
	Pian pian7;
	pian7 += 3;
	pian7.afisare();
	/*Pian pian7;
	pian7 = pian2;
	pian7.afisare();
	pian7 = pian2 + 0;
	pian7.afisare();
	pian7 = 0 + pian2;
	*/

	if (pian2 > pian3) {
		cout << "p2 este mai mare decat p3" << endl;
	}
	else
	{
		cout << "p2 nu este m ai mare decat p3" << endl;
	}

	pian3 = pian2;

	Pian* pian = new Pian[3];
	for (int i = 0; i < 3; i++)
		cin >> pian[i];
	for (int i = 0; i < 3; i++)
		cout << pian[i];


	Pian::modificaStoc(15);


	int* stoc;
	stoc = new int[1];
	stoc[0] = 5;
	Chitara chitara1;
	chitara1.afisare();
	Chitara chitara2(21, "electrica", 0, stoc);
	++chitara2;
	chitara2.afisare();
	marireStoc(chitara2, 2);
	Chitara chitara3(22, "clasica");
	chitara3.afisare();
	chitara3 = chitara2++;
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

	chitara3 = chitara2;


	Chitara* chitara = new Chitara[3];
	for (int i = 0; i < 3; i++)
		cin >> chitara[i];
	for (int i = 0; i < 3; i++)
		cout << chitara[i];

	Chitara::colectieActualizata(24);

	Depozit d1;
	d1.afisare();
	int* nrCutii = new int[2];
	nrCutii[0] = 10;
	nrCutii[1] = 15;
	Microfon* colectieD = new Microfon();
	Depozit d2("Dinu Lipatti", colectieD, 2, nrCutii);
	d2.afisare();
	Depozit d3 = d2;

	d2.setNumeStrada("Mihai Bravu");
	d2.setStoc(2);
	cout << d2.getNumeStrada() << "." << d2.getStoc() << endl;
	int stocD[] = { 1,2 };
	d2.setNrCutii(2, stocD);
	for (int i = 0; i < d2.getNrCutii()[i]; i++)
	{
		cout << d2.getNrCutii()[i] << ",";
	}
	cout << endl;


	Microfon* colectie2 = new Microfon();
	d2.setColectie(colectie2);
	cout << d2.getColectie() << endl;

	d2 = d3;
	d2 = d1 + 1;
	cout << d2;

	Microfon microfon8(5, "Shure");
	ofstream fis("fisier.txt", ios::out);
	fis << microfon8;
	ifstream fis1("fisier.txt", ios::in);
	fis1 >> microfon8;

	Pian pian8;
	ofstream fis2("fisier.txt", ios::out);
	fis2 << pian8;
	ifstream fis3("fisier.txt", ios::in);
	fis3 >> pian8;
	cout << pian8;

	Chitara c8(8, "electrica");
	fstream fisier("fisier.txt", ios::out | ios::binary);
	fisier.write((char*)&c8, sizeof(c8));
	fisier.close();
	fstream fisier1("fisier.txt", ios::in | ios::binary);
	fisier1.read((char*)&c8, sizeof(c8));
	cout << c8;

	Depozit d;
	fstream fisier2("fisier.txt", ios::out | ios::binary);
	fisier2.write((char*)&d, sizeof(d));
	d.scrieInFisierBinar(fisier2);
	fisier2.close();
	fstream fisier3("fisier.txt", ios::in | ios::binary);
	fisier3.read((char*)&d, sizeof(d));
	d.citesteDinFisierBinar(fisier3);
	cout << d;
	fisier3.close();

}