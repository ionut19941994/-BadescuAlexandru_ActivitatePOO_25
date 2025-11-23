//Biblioteca, Instrument, Aparat 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Biblioteca {
private:
	const int id;
	static int nrBiblioteci;
	int nrRafturi;
	string culoare;
	float* preturi;
	float inaltime;
public:
	//constructor default//fara parametri
	Biblioteca() :id(++nrBiblioteci) {
		this->culoare = "necunoscuta";
		this->nrRafturi = 0;
		this->preturi = nullptr;
		this->inaltime = 0;
	}

	Biblioteca(int nrRafturi, string culoare, float* preturi, float inaltime) :id(++nrBiblioteci) {
		this->nrRafturi = nrRafturi;
		this->culoare = culoare;
		this->inaltime = inaltime;
		this->preturi = new float[this->nrRafturi];
		for (int i = 0; i < this->nrRafturi; i++) {
			this->preturi[i] = preturi[i];
		}
	}

	Biblioteca(int nrRafturi, float pretUnic) :id(++nrBiblioteci) {
		this->nrRafturi = nrRafturi;
		this->culoare = "gri antracit";
		this->inaltime = 1.6;
		if (nrRafturi > 0) {
			this->preturi = new float[this->nrRafturi];
			for (int i = 0; i < this->nrRafturi; i++) {
				this->preturi[i] = pretUnic;
			}
		}
		else {
			this->preturi = nullptr;
		}
	}

	~Biblioteca() {
		if (this->preturi != nullptr) {
			delete[] this->preturi;
		}
	}

	void afisareBiblioteca() {
		cout << this->id << ". Biblioteca " << this->culoare << " de inaltime " << this->inaltime;
		if (this->nrRafturi > 0) {
			cout << " metri are " << this->nrRafturi << " seturi de rafturi cu urmatoarele preturi:";
			if (this->preturi != nullptr) {
				for (int i = 0; i < this->nrRafturi; i++) {
					cout << " " << this->preturi[i];
				}
			}
		}
		cout << endl;
	}

	void afisareBibliotecaPretUnic() {
		int j;
		cout << this->id << ". Biblioteca " << this->culoare << " de inaltime " << this->inaltime;
		if (this->nrRafturi > 0) {
			cout << " metri are " << this->nrRafturi << " seturi de rafturi cu urmatorul pret:";
			if (this->preturi != nullptr) {
				for (int i = 0; i < this->nrRafturi; i++) {
					j = this->preturi[i];
				}
				cout << " " << j;
			}
		}
		cout << endl;
	}
};

class Instrument {
private:
	const int id;
	string tip;
	float greutate;
	char* descriere;
	static int nrInstrumente;
public:
	Instrument() :id(++nrInstrumente) {
		this->tip = "necunoscut";
		this->greutate = 0;
		this->descriere = nullptr;
	}

	Instrument(string tip, float greutate, char* descriere) :id(++nrInstrumente) {
		this->tip = tip;
		this->greutate = greutate;
		if (descriere != nullptr) {
			this->descriere = new char[strlen(descriere) + 1];
			strcpy(this->descriere, descriere);
		}
		else { this->descriere = nullptr; }
	}

	~Instrument() {
		if (descriere != nullptr) {
			delete[] this->descriere;
		}
	}

	void afisareInstrument() {
		cout << this->id << ". Instrumentul de tip " << this->tip << " de " << this->greutate << "kg este ";
		if (this->descriere != nullptr) {
			cout << this->descriere;
		}
		else {
			cout << "nedefinit";
		}
		cout << endl;
	}
};

class Aparat {
private:
	const int id;
	static int nrAparate;
	string nume;
	int nrComponente;
	float* cantitati;
public:
	Aparat() :id(++nrAparate) {
		this->nume = "este nedefinit";
		this->nrComponente = 0;
		this->cantitati = nullptr;
	}

	Aparat(string nume, int nrComponente, float* cantitati) :id(++nrAparate) {
		this->nume = nume;
		this->nrComponente = nrComponente;
		this->cantitati = new float[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++) {
			this->cantitati[i] = cantitati[i];
		}
	}

	~Aparat() {
		if (this->cantitati != nullptr) {
			delete[] this->cantitati;
		}
	}

	void afisareAparat() {
		cout << this->id << ". Aparatul " << this->nume;
		if (this->nrComponente > 0) {
			cout << " cu numarul de componente " << this->nrComponente << " se afla in cantitate de";
			if (this->cantitati != nullptr) {
				for (int i = 0; i < this->nrComponente; i++)
					cout << " " << this->cantitati[i];
			}
		}
		cout << endl;
	}
};

int Biblioteca::nrBiblioteci = 0;
int Instrument::nrInstrumente = 0;
int Aparat::nrAparate = 0;

void main() {
	Biblioteca b1;
	b1.afisareBiblioteca();

	float preturi1[] = { 100, 150, 180 };
	Biblioteca b2(3, "rosie", preturi1, 2.3);
	b2.afisareBiblioteca();

	Biblioteca b3(4, 75);
	b3.afisareBibliotecaPretUnic();

	Instrument i1;
	i1.afisareInstrument();

	char desc[] = "cu corzi";
	Instrument i2("chitara", 1.5, desc);
	i2.afisareInstrument();

	Aparat a1;
	a1.afisareAparat();

	float cantitati1[] = { 20, 10 };
	Aparat a2("foto", 2, cantitati1);
	a2.afisareAparat();
}