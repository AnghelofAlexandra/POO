#include <iostream>
using namespace std;

float medie(int nr, float* v)
{
	float med = 0;
	for (int i = 0; i < nr; i++)
	{
		med += v[i];
	}

	return med / nr;
}

class Festival
{
	string nume = "Anonim";
	int nrZile = 0;
	float* incasariZilnice = nullptr;
	int nrArtisti = 0;
	string* numeArtisti = nullptr;

public:
	Festival() {}

	Festival(string _nume, int _nrZile, float* _incasariZilnice, int _nrArtisti, string* _numeArtisti)
	{
		if (_nume.size() >= 3)
		{
			this->nume = _nume;
		}

		if (_nrZile > 0)
		{
			float* aux = new float[_nrZile];
			int k = 0;
			float med = medie(_nrZile, _incasariZilnice);
			for (int i = 0; i < _nrZile; i++)
			{
				if ( med < _incasariZilnice[i])
				{
					aux[k++] = _incasariZilnice[i];
				}
			}

			this->nrZile = k;
			this->incasariZilnice = new float[k];
			for (int i = 0; i < k; i++)
			{
				this->incasariZilnice[i] = aux[i];
			}

			delete[] aux;
		}

		if (_nrArtisti > 0)
		{
			string* aux = new string[_nrArtisti];
			int k = 0;
			for (int i = 0; i < _nrZile; i++)
			{
				if (_numeArtisti[i].size() >= 3)
				{
					aux[k++] = _numeArtisti[i];
				}
			}

			this->nrArtisti = k;
			this->numeArtisti = new string[k];
			for (int i = 0; i < k; i++)
			{
				this->numeArtisti[i] = aux[i];
			}

			delete[] aux;
		}
	}

	float incasariTotale()
	{
		if (this->nrZile > 0)
		{
			float s = 0;
			for (int i = 0; i < this->nrZile; i++)
			{
				s += this->incasariZilnice[i];
			}

			return s;
		}
		else return 0;
	}

	void afisare()
	{
		cout << "\nNume: " << this->nume;
		cout << "\nNr zile: " << this->nrZile;
		cout << "\nIncasari: ";
		for(int i = 0; i < this->nrZile; i++)
		{
			cout << this->incasariZilnice[i] << "  ";
		}
		cout << "\nNr artisti: " << this->nrArtisti;
		cout << "\nAristi: ";
		for (int i = 0; i < this->nrArtisti; i++)
		{
			cout << this->numeArtisti[i] << "  ";
		}
	}
};

int main()
{
	Festival f1;
	f1.afisare();

	float v[] = { 4, 5, 2, 3, 9, 8, 10 };
	string a[] = { "Usher", "Imagine Dragons", "Justin Biber", "Inna", "Maroon 5", "Delia", "Irina Rimes" };
	Festival f2("Untold", 7, v, 7, a);
	f2.afisare();
	cout << "\nIncasari totale: " << f2.incasariTotale();
	return 0;
}