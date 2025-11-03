#include <iostream>
using namespace std;

bool unic(int n, int* v, int x)
{
	bool ok = 1;

	for (int i = 0; i < n; i++)
	{
		if (v[i] == x)
		{
			ok = 0;
			return ok;
		}
	}

	return ok;
}

class Magazin
{
	string denumire = "anonim";
	int nrProduse = 0;
	int* coduri = nullptr;

public:
	Magazin() {}

	Magazin(string _denumire)
	{
		if (_denumire.size() >= 3)
		{
			this->denumire = _denumire;
		}
	}

	Magazin(string _denumire, int _nrProduse, int* _coduri)
	{
		if (_denumire.size() >= 3)
		{
			this->denumire = _denumire;
		}

		if (_nrProduse > 0)
		{
			int* aux = new int[_nrProduse];
			int k = 0;
			aux[k++] = _coduri[0];

			for (int i = 1; i < _nrProduse; i++)
			{
				if (unic(i, aux, _coduri[i]) == 1)
				{
					aux[k++] = _coduri[i];
				}
			}

			this->nrProduse = k;
			this->coduri = new int[k];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->coduri[i] = aux[i];
			}

			delete[] aux;
		}
	}

	void adaugareCod(int _cod)
	{
		if (this->nrProduse > 0 && unic(this->nrProduse, this->coduri, _cod) == 1 )
		{
			int* aux = new int[this->nrProduse + 1];
			for (int i = 0; i < this->nrProduse; i++)
			{
				aux[i] = this->coduri[i];
			}

			aux[this->nrProduse] = _cod;

			delete[] this->coduri;

			this->nrProduse += 1;
			this->coduri = aux;
		}
	}

	void afisare()
	{
		cout << "\nDenumire: " << this->denumire;
		cout << "\nNr produse: " << this->nrProduse;
		cout << "\nCod produse: ";
		for (int i = 0; i < this->nrProduse; i++)
		{
			cout << this->coduri[i] << "  ";
		}
	}
};

int main()
{
	Magazin m1;
	m1.afisare();

	int v[] = { 1, 2, 2, 3, 4 };
	Magazin m2("Lidl", 5, v);
	m2.afisare();
	m2.adaugareCod(7);
	m2.afisare();
	m2.adaugareCod(3);
	m2.afisare();

	return 0;
}