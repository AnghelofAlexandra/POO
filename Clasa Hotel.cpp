#include <iostream>
using namespace std;

enum Stea
{
	ZERO, UNA, DOUA, TREI, PATRU
};

float medie(int n, float* v)
{
	float med = 0;
	for (int i = 0; i < n; i++)
	{
		med += v[i];
	}

	return med / n;
}

class Hotel
{
	string numeHOtel = "anonim";
	int nrAni = 0;
	float* profitAnual = nullptr;
	float costuriAnuale = 0;
	Stea stele = ZERO;

public:
	Hotel() {

	}

	Hotel(string _numeHotel, int _nrAni, float* _profitAnual, float _costuriAnuale, Stea _stele)
	{
		if (_numeHotel.size() >= 3)
		{
			this->numeHOtel = _numeHotel;
		}

		if (_nrAni > 0)
		{
			float* aux = new float[_nrAni];
			int k = 0;
			if (_profitAnual[0] < 0)
			{
				aux[k++] = 0;
			}
			else aux[k++] = _profitAnual[0];

			for (int i = 1; i < _nrAni; i++)
			{
				if (_profitAnual[i] < 0)
				{
					aux[k++] = medie(i, aux);
				}
				else aux[k++] = _profitAnual[i];
			}

			this->nrAni = k;
			this->profitAnual = new float[k];
			for (int i = 0; i < k; i++)
			{
				this->profitAnual[i] = aux[i];
			}

			delete[] aux;
		}

		if (_costuriAnuale > 0)
		{
			this->costuriAnuale = _costuriAnuale;
		}

		this->stele = _stele;
	}

	bool pePierdere()
	{
		if (this->nrAni > 0)
		{
			float med = medie(this->nrAni, this->profitAnual);

			if (med < this->costuriAnuale)
			{
				return 1;
			}
			else return 0;
		}
		else return 0;
	}

	void afisare()
	{
		cout << "\nNume: " << this->numeHOtel;
		cout << "\nNr ani: " << this->nrAni;
		cout << "\nProfit anual: ";
		for (int i = 0; i < this->nrAni; i++)
		{
			cout << this->profitAnual[i] << "  ";
		}
		cout << "\nCosturi Anuale: " << this->costuriAnuale;
		cout << "\nStele: " << this->stele;
	}
};

void addAn(int& n, float*& v, float profit)
{
	if (profit > 0)
	{
		float* aux = new float[n + 1];
		for (int i = 0; i < n; i++)
		{
			aux[i] = v[i];
		}

		aux[n] = profit;

		delete[] v;
		
		n += 1;
		v = aux;
	}
}

int main()
{
	Hotel h1;
	h1.afisare();

	float v[] = { 10000, -900, 90000, 7000, -8000, 5000, 4000, 8000 };
	Hotel h2("Intercontinental", 8, v, 10000, PATRU);
	h2.afisare();
	cout << "\nEste pe pierdere: " << h2.pePierdere();

	int n = 3;
	float* v1 = new float[n] {3000, 2000, 4000};

	cout << "\nAdaugare profit: ";
	addAn(n, v1, 3000);
	for (int i = 0; i < n;i++)
	{
		cout << v1[i] << " ";
	}


	return 0;
}