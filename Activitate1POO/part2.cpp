#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Cofetarie {
private: 
	const int id;
	//char* denumire;
	string denumire;
	int nrProduse;
	float* preturi;
	static int nrCofetarii;
public: 

	Cofetarie():id(++nrCofetarii) {
		//this->id = 0; Asa nu pentru const
		this->denumire = "Cofetarie generala";
		this->nrProduse = 0;
		this->preturi = nullptr;

	}

	Cofetarie(int _id, string denumire, int nrProduse, float* preturi) :id(_id) {
		//this->id = 0; Asa nu pentru const
		this->denumire = denumire;
		this->nrProduse = nrProduse;
		this->preturi = new float[nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->preturi[i] = preturi[i];
		}
		delete[] preturi;
	}
	void afisare() {
		cout << endl << "ID: " << this->id;
		cout << endl << "denumire: " << this->denumire;
		cout << endl << "nr Produse: " << this->nrProduse;
		if (nrProduse > 0) {
		cout << "cu urmatoarele preturi: ";
		for (int i = 0; i < this->nrProduse; i++) {
			cout << endl << this->preturi[i] << "lei";
		}
	}

		//this este referire la obiectul curent
	}
};

int Cofetarie::nrCofetarii = 0;

void main() {
	//Incapsulare
	Cofetarie cofetarieGenerala;
	cofetarieGenerala.afisare();

	float* preturi = new float[] {18.5, 24, 15.5};
	Cofetarie cofetarieRomana(2, "Cofetarie Romana", 3, preturi);
	cofetarieRomana.afisare();

	delete cofetarieRomana;
}