#include <iostream>
using namespace std;

class Film
{
	string titlu = "neales";
	int durata = 0;
	int nrActori = 0;
	float* onorariiActori = nullptr;
	float rating = 0;

public:
	Film()
	{

	}

	Film(string _titlu, int _durata, int _nrActori, float* _onorariiActori, float _rating)
	{
		if (_titlu.size() >= 2)
		{
			this->titlu = _titlu;
		}

		if (_durata > 0)
		{
			this->durata = _durata;
		}

		if (_nrActori > 0)
		{
			float med = 0;
			for (int i = 0; i < _nrActori; i++)
			{
				med += _onorariiActori[i];
			}

			med /= _nrActori;

			float* aux = new float[_nrActori];
			int k = 0;
			for (int i = 0; i < _nrActori; i++)
			{
				if (_onorariiActori[i] < med)
				{
					aux[k++] = _onorariiActori[i];
				}
			}

			this->nrActori = k;
			this->onorariiActori = new float[k];
			for (int i = 0; i < _nrActori; i++)
			{

				this->onorariiActori[i] = aux[i];

			}

			delete[] aux;
		}

		if (_rating > 0 && _rating <= 10)
		{
			this->rating = _rating;
		}
	}

	float bugetTotal()
	{
		if (this->nrActori > 0)
		{
			float buget = 0;
			for (int i = 0; i < this->nrActori; i++)
			{
				buget += this->onorariiActori[i];
			}

			return buget;
		}
		else return 0;
	}

	void afisare()
	{
		cout << "\nTitlu: " << this->titlu;
		cout << "\nDurata: " << this->durata;
		cout << "\nNr actori: " << this->nrActori;
		cout << "\nOnorarii actori: ";
		for (int i = 0; i < this->nrActori; i++)
		{
			cout << this->onorariiActori[i] << "  ";
		}
		cout << "\nRating: " << this->rating;
	}
};

int main()
{
	Film f1;
	f1.afisare();

	float o[] = { 13000, 12000, 2000, 3000 };
	Film f2("Titanic", 120, 4, o, 9);
	f2.afisare();
	cout << "\nBuget: " << f2.bugetTotal();

	return 0;
}