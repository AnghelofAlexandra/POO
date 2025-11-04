#include <iostream>
using namespace std;

int suma(int n, int* v)
{
	int s = 0; 
	for (int i = 0; i < n; i++)
	{
		s += v[i];
	}

	return s;
}

enum tipLivrare
{
	ACASA, EASYBOX
};

class Curier
{
	string numeCurier = "anonim";
	int nrLivrari = 0;
	int* distantaPerLivrare = nullptr;
	int distantaMaxima = 0;
	tipLivrare tip = ACASA;

public:
	Curier() {}

	Curier(string _numeCurier, int _nrLivrari, int* _distantaPerLivrare, int _distantaMaxima, tipLivrare _tip)
	{
		if (_numeCurier.size() >= 3)
		{
			this->numeCurier = _numeCurier;
		}

		if (_nrLivrari > 0)
		{
			int* aux = new int[_nrLivrari];
			int k = 0;
			aux[k++] = _distantaPerLivrare[0];

			for (int i = 1; i < _nrLivrari; i++)
			{
				if (suma(k, aux) + _distantaPerLivrare[i] <= _distantaMaxima)
				{
					aux[k++] = _distantaPerLivrare[i];
				}
			}

			this->nrLivrari = k;
			this->distantaPerLivrare = new int[this->nrLivrari];

			for (int i = 0; i < this->nrLivrari; i++)
			{
				this->distantaPerLivrare[i] = aux[i];
			}

			delete[] aux;
		}

		this->distantaMaxima = _distantaMaxima;

		this->tip = _tip;
	}

	int distantePesteMedie()
	{
		if (this->nrLivrari > 0)
		{
			int med = suma(this->nrLivrari, this->distantaPerLivrare) / this->nrLivrari;
			int ct = 0;

			for (int i = 0; i < this->nrLivrari; i++)
			{
				if (med < this->distantaPerLivrare[i])
				{
					ct++;
				}
			}

			return ct;
		}
		else return 0;
	}

	void stergeElemente(int _k)
	{
		if (this->nrLivrari > 0 && _k < this->nrLivrari)
		{
			int* aux = new int[this->nrLivrari - _k];
			for (int i = _k; i < this->nrLivrari; i++)
			{
				aux[i - _k] = this->distantaPerLivrare[i];
			}

			delete[] distantaPerLivrare;

			this->nrLivrari -= _k;
			this->distantaPerLivrare = aux;
		}
	}

	void afisare()
	{
		cout << "\nNume curier: " << this->numeCurier;
		cout << "; Nr livrari: " << this->nrLivrari;
		cout << "; Distanta per Livrare: ";
		for (int i = 0; i < this->nrLivrari; i++)
		{
			cout << this->distantaPerLivrare[i] << "   ";
		}
		cout << "; Distanta maxima: " << this->distantaMaxima;
		cout << "; Tip livrare: " << this->tip;
	}
};

int main()
{
	Curier c1;
	c1.afisare();

	int v[] = { 3, 8, 4, 5, 6, 2, 1 };
	Curier c2("Gigel", 7, v, 20, EASYBOX);
	c2.afisare();
	cout << "\nDistanta peste medie: " << c2.distantePesteMedie();
	c2.stergeElemente(3);
	c2.afisare();

	return 0;
}