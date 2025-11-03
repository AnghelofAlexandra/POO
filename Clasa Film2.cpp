#include <iostream>
using namespace std;

float medie(int n, float* v)
{
	if (n > 0)
	{
		float med = 0;
		for (int i = 0; i < n; i++)
		{
			med += v[i];
		}

		return med / n;
	} return 0;
}

class Film
{
	string titlu = "anonim";
	int nrActori = 0;
	float* onorarii = nullptr;
	int rating = 0;
	bool arePremii = 0;

public:
	Film()
	{

	}

	Film(string _titlu, int _nrActori, float* _onorarii, int _rating, bool _arePremii)
	{
		if (_titlu.size() >= 3)
		{
			this->titlu = _titlu;
		}

		if (_nrActori > 0)
		{
			this->nrActori = _nrActori;
			this->onorarii = new float[this->nrActori];

			for (int i = 0; i < _nrActori; i++)
			{
				if (_onorarii[i] < 0)
				{
					this->onorarii[i] = medie(i, this->onorarii);
				}
				else this->onorarii[i] = _onorarii[i];
			}

		}

		if (_rating > 0 && _rating <= 10)
		{
			this->rating = _rating;
		}

		this->arePremii = _arePremii;
	}

	bool esteProfitabil()
	{
		if (this->nrActori > 0)
		{
			float s = 0;
			for (int i = 0; i < this->nrActori; i++)
			{
				s += this->onorarii[i];
			}

			if (s < this->rating * 10000)
			{
				return 1;
			}
			else return 0;
		}
		else return 0;
	}

	void afisare() 
	{
		cout << "\nTitlu: " << this->titlu;
		cout << "\nNr actori: " << this->nrActori;
		cout << "\nOnorarii: ";
		for (int i = 0; i < this->nrActori; i++)
		{
			cout << this->onorarii[i] << "  ";
		}

		cout << "\nRating: " << this->rating;
		cout << "\nAre premii: " << this->arePremii;
	}
};

void addActor(int& n, float*& v, float onorariu)
{
	if (onorariu > 0)
	{
		float* aux = new float[n + 1];
		for (int i = 0; i < n; i++)
		{
			aux[i] = v[i];
		}
		aux[n] = onorariu;

		delete[] v;

		n += 1;
		v = aux;
	}

}

int main()
{
	Film f1;
	f1.afisare();

	float o[] = { 10, 7, -9, 11, 3, -9, 10 };
	Film f2("Avatar", 7, o, 9, 1);
	f2.afisare();
	cout << "\nEste profitabil: " << f2.esteProfitabil();

	int n = 4;
	float* v = new float[n] {10, 9, 8, 10};
	addActor(n, v, 10);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << "  ";
	}
	return 0;
}
