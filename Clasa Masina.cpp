#include <iostream>
using namespace std;

double med(int n, double* v)
{
	if (n > 0)
	{
		double med = 0;
		for (int i = 0; i < n; i++)
		{
			med += v[i];
		}

		return med / n;
	}
	else return 0;
}

class Masina
{
	string numarMasina = "RO 00 ABC";
	double capacitateRezervor = 0;
	double capacitateCurenta = 0;
	int nrAlimentari = 0;
	double* alimentari = nullptr;

public:
	Masina() {}

	Masina(string _numarMasina)
	{
		if (_numarMasina.size() == 9)
		{
			this->numarMasina = _numarMasina;
		}
	}

	Masina(string _numarMasina, double _capacitateRezervor)
	{
		if (_numarMasina.size() == 9)
		{
			this->numarMasina = _numarMasina;
		}

		if (_capacitateRezervor > 0)
		{
			this->capacitateRezervor = _capacitateRezervor;
		}
	}

	Masina(string _numarMasina, double _capacitateRezervor, double _capacitateCurenta, int _nrAlimentari, double* _alimentari)
	{
		if (_numarMasina.size() == 9)
		{
			this->numarMasina = _numarMasina;
		}

		if (_capacitateRezervor > 0)
		{
			this->capacitateRezervor = _capacitateRezervor;
		}

		if (_capacitateCurenta > 0)
		{
			this->capacitateCurenta = _capacitateCurenta;
		}

		if (_nrAlimentari > 0)
		{
			this->nrAlimentari = _nrAlimentari;
			this->alimentari = new double[this->nrAlimentari];
			for (int i = 0; i < this->nrAlimentari; i++)
			{
				if (_alimentari[i] > _capacitateRezervor)
				{
					this->alimentari[i] = _capacitateRezervor;
				}
				else this->alimentari[i] = _alimentari[i];
			}
		}
	}

	void alimenare(int _alimentare)
	{
		if (this->nrAlimentari > 0 && this->capacitateCurenta+_alimentare<=this->capacitateRezervor)
		{
			double* aux = new double[this->nrAlimentari + 1];
			for (int i = 0; i < this->nrAlimentari; i++)
			{
				aux[i] = this->alimentari[i];
			}

			aux[this->nrAlimentari] = _alimentare;

			delete[] this->alimentari;

			this->nrAlimentari += 1;
			this->alimentari = aux;
			this->capacitateCurenta += _alimentare;
		}
	}

	void afisare()
	{
		cout << "\nNr masina: " << this->numarMasina;
		cout << "\nCapacitate rezervor: " << this->capacitateRezervor;
		cout << "\nCapaciatte curenta: " << this->capacitateCurenta;
		cout << "\nNr alimentari: " << this->nrAlimentari;
		cout << "\nMedia :" << med(this->nrAlimentari, this->alimentari);
	}
};

int main()
{
	Masina m1;
	m1.afisare();

	double a[] = { 20, 40, 10, 40 };
	Masina m2("DB 13 ANG", 30, 20, 4, a);
	m2.afisare();
	cout << "\nAlimentez 20";
	m2.alimenare(20);
	m2.afisare();
	cout << "\nAlimentez 10";
	m2.alimenare(10);
	m2.afisare();

	return 0;
}
