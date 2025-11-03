#include <iostream>
using namespace std;

class Produs
{
	string denumire = "anonim";
	int nrPreturi = 0;
	double* preturi = nullptr;

public:
	Produs() {}

	Produs(string _denumire)
	{
		if (_denumire.size() >= 3)
		{
			this->denumire = _denumire;
		}
	}

	Produs(string _denumire, int _nrPreturi, double* _preturi)
	{
		if (_denumire.size() >= 3)
		{
			this->denumire = _denumire;
		}

		if (_nrPreturi > 0)
		{
			double* aux = new double[_nrPreturi];
			int k = 0;
			aux[k++] = _preturi[0];

			for (int i = 1; i < _nrPreturi; i++)
			{
				if (_preturi[i] != aux[k - 1])
				{
					aux[k++] = _preturi[i];
				}
			}

			this->nrPreturi = k;
			this->preturi = new double[k];

			for (int i = 0; i < k; i++)
			{
				this->preturi[i] = aux[i];
			}

			delete[] aux;
		}
	}

	void adaugaPret(double _pret)
	{
		if (this->nrPreturi > 0 && this->preturi[this->nrPreturi - 1] != _pret)
		{
			double* aux = new double[this->nrPreturi + 1];
			for (int i = 0; i < this->nrPreturi; i++)
			{
				aux[i] = this->preturi[i];
			}

			aux[this->nrPreturi] = _pret;

			delete[] this->preturi;

			this->nrPreturi += 1;
			this->preturi = aux;
		}
		else if(this->nrPreturi == 0)
		{
			this->nrPreturi = 1;
			this->preturi = new double[this->nrPreturi];
			this->preturi[0] = _pret;
		}
	}

	void eliminaPrimeleK(int k)
	{
		if (this->nrPreturi > 0 && k < this->nrPreturi)
		{
			double* aux = new double[this->nrPreturi - k];
			int ct = 0;
			for (int i = k; i < this->nrPreturi; i++)
			{
				aux[ct++] = this->preturi[i];
			}

			delete[] this->preturi;

			this->nrPreturi = ct;
			this->preturi = aux;
		}
	}

	void golirePreturi()
	{
		if (this->nrPreturi > 0)
		{
			delete[] this->preturi;

			this->nrPreturi = 0;
			this->preturi = nullptr;
		}
	}

	double pretMediu()
	{
		if (this->nrPreturi > 0)
		{
			double med = 0;
			for (int i = 0; i < this->nrPreturi; i++)
			{
				med += this->preturi[i];
			}

			return med / this->nrPreturi;
		}
		else return 0;
	}

	double pretMin()
	{
		if (this->nrPreturi > 0)
		{
			double min = this->preturi[0];
			for (int i = 1; i < this->nrPreturi; i++)
			{
				if (min > this->preturi[i])
				{
					min = this->preturi[i];
				}
			}

			return min;
		}
		else return 0;
	}

	void afisare()
	{
		cout << "\n-------------------- Denumire: " << this->denumire << " ----------------------";
		cout << "\nNr preturi: " << this->nrPreturi;
		cout << "\nPreturi: ";
		for (int i = 0; i < this->nrPreturi; i++)
		{
			cout << this->preturi[i] << "  ";
		}
	}
};

int main()
{
	Produs p1;
	p1.afisare();

	Produs p2("Linco");
	p2.afisare();

	double p[] = { 2, 3, 3, 4, 3 };
	Produs p3("Caiet", 5, p);
	p3.afisare();
	p3.adaugaPret(3);
	p3.afisare();
	p3.adaugaPret(7);
	p3.afisare();
	p3.eliminaPrimeleK(3);
	p3.afisare();
	cout<<"\nPret mediu: " << p3.pretMediu();
	cout << "\nPret minim: " << p3.pretMin();
	p3.golirePreturi();

	return 0;
}