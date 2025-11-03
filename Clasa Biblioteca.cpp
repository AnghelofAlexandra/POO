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

class Biblioteca
{
	string numeBiblioteca = "anonim";
	int nrCarti = 0;
	int* idCarti = nullptr;
	float costMediuCarte = 0;
	bool deschisaPublicului = 0;

public:
	Biblioteca() {}

	Biblioteca(string _numeBiblioteca, int _nrCarti, int* _idCarti, float _costMediuCarte, bool _deschisPublicului)
	{
		if (_numeBiblioteca.size() >= 3)
		{
			this->numeBiblioteca = _numeBiblioteca;
		}

		if (_nrCarti > 0)
		{
			int* aux = new int[_nrCarti];
			int k = 0;
			aux[k++] = _idCarti[0];

			for (int i = 1; i < _nrCarti; i++)
			{
				if (unic(i, aux, _idCarti[i]) == 1)
				{
					aux[k++] = _idCarti[i];
				}
			}

			this->nrCarti = k;
			this->idCarti = new int[k];
			for (int i = 0; i < k; i++)
			{
				this->idCarti[i] = aux[i];
			}

			delete[] aux;
		}

		if (_costMediuCarte > 0)
		{
			this->costMediuCarte = _costMediuCarte;
		}

		this->deschisaPublicului = _deschisPublicului;
	}

	bool esteMare()
	{
		if (this->nrCarti > 1000 && this->costMediuCarte > 50)
		{
			return 1;
		}
		else return 0;
	}

	void afisare()
	{
		cout << "\nNume biblioteca : " << this->numeBiblioteca;
		cout << "\nNr Carti: " << this->nrCarti;
		cout << "\nId carti: ";
		for (int i = 0; i < this->nrCarti; i++)
		{
			cout << this->idCarti[i] << "  ";
		}
		cout << "\nCost mediu carte: " << this->costMediuCarte;
		cout << "\nDeschisa publicului: " << this->deschisaPublicului;
	}
};

void adaugaCarte(int& n, int*& v, int carte)
{
	if (unic(n, v, carte))
	{
		int* aux = new int[n + 1];
		for (int i = 0; i < n;i++)
		{
			aux[i] = v[i];
		}

		aux[n] = carte;

		delete[] v;

		n += 1;
		v = aux;
	}
}

int main()
{
	Biblioteca b1;
	b1.afisare();

	int id[] = { 13, 12, 13, 11, 10 };
	Biblioteca b2("Locala", 5, id, 50, 1);
	b2.afisare();
	cout << "\nEste mare biblioteca: " << b2.esteMare();

	int n = 3;
	int* v = new int[3] {5, 7, 8};
	cout << "\nAdaugare carte: ";
	adaugaCarte(n, v, 3);
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << "  ";
	}

	return 0;
}