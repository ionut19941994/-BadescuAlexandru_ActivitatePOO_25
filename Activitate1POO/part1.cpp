#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct Casa {
	int nr;
	char* adresa;
	char* proprietar;
};

void afisareCasa(Casa c);

float calculMedieNumereIntregi(int vector[], int dim) {
	int suma = 0;
	for (int i = 0; i < dim; i++) {
		suma += vector[i];
	}

	if (dim > 0) {
		return suma / dim;
	}
}

void afisareVector(int* vector, int dimensiune);

int pozitieMaximInVector(int* vector, int dimensiune) {
	int pozitieMax = 0;
	for (int i = 1; i < dimensiune; i++) {
		if (vector[pozitieMax] < vector[i]) {
			pozitieMax = i;
		}
	}
	return pozitieMax;
}

void stergereElementDePePozitieData(
	int** vector, int* dimensiune, int pozitie) {
	//dereferentiere
	int* vectorCopie = new int[*dimensiune - 1];
	int j = 0;
	for (int i = 0; i < *dimensiune; i++) {
		if (i != pozitie) {
			vectorCopie[j] = (*vector)[i];
			j++;
		}
	}

	delete[] * vector;
	(*dimensiune)--;
	*vector = vectorCopie;
}

// valoarea se poate transmite prin valoare, pointer, sau referinta

void main2() {

	cout << "Primul mesaj";


	cout << endl << "Hello ID!";
	Casa c;
	c.nr = 10;
	c.adresa = new char[strlen("Eminescu") + 1];
	strcpy(c.adresa, "Eminescu");
	c.proprietar = new char[strlen("PopescuIon") + 1];
	strcpy(c.proprietar, "PopescuIon");
	
	afisareCasa(c);
	//afisareCasa este o functie
	int vector[] = { 10, 20, 30, 40, 50 };
	int dim = 5;

	cout << endl << "Media este: " <<
		calculMedieNumereIntregi(vector, dim);

	//dezalocari - altfel memory leaks
	delete[] c.adresa;
	delete[] c.proprietar;

	//char* nume;
	//char sirCaractere[20];

	//cout << endl << "Citim de la tastatura: ";
	//cin.getline(sirCaractere, 20);

	//cout << endl << "Sirul citit este: "<<sirCaractere;

	////definim un buffer
	//char buffer[20];
	//cout << endl << "Numele este: ";
	//cin >> buffer;

	//nume = new char[strlen(buffer)+1];
	//strcpy_s(nume, strlen(buffer) + 1, buffer);

	//cout << endl << "Numele citit este: " << nume;

	//delete[] nume;

	//dereferentiere

	//vectori
	int* vector1;
	int dimensiune = 5;

	vector1 = new int[dimensiune];
	for (int i = 0; i < dimensiune; i++) {
		cout << endl << "Vector[" << i << "]= ";
		cin >> vector1[i];
	}

	cout << endl << "Valorile din vector sunt:";
	afisareVector(vector1, dimensiune);

	cout << endl << "Pozitia pe care se afla maximul este: " << pozitieMaximInVector(vector1, dimensiune);

	stergereElementDePePozitieData(&vector1, &dimensiune, 3);

	afisareVector(vector1, dimensiune);

	delete[] vector1;
}

void afisareCasa(Casa c) {
	cout << endl << "Casa aflata la adresa " << c.adresa <<
		", numarul " << c.nr << " are proprietar pe "
		<< c.proprietar << "!";
}

void afisareVector(int* vector, int dimensiune) {
	for (int i = 0; i < dimensiune; i++) {
		cout << endl << "Vector[" << i << "]= " << vector[i];
	}
}