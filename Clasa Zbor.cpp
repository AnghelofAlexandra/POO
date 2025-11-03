#include <iostream>
using namespace std;

class Zbor
{
	string destinatie = "necunoscuta";
	string sursa = "necunoscuta";
	int nrLocuri = 0;
	bool* loc = nullptr;

public:
	Zbor() {}

	Zbor(string _destinatie, string _sursa)
	{
		if (_destinatie.size() >= 3)
		{
			this->destinatie = _destinatie;
		}
		if (_sursa.size() >= 3)
		{
			this->sursa = _sursa;
		}
	}

	Zbor(string _destinatie, string _sursa, int _nrLocuri, bool* _loc)
	{
		if (_destinatie.size() >= 3)
		{
			this->destinatie = _destinatie;
		}
		if (_sursa.size() >= 3)
		{
			this->sursa = _sursa;
		}

		if (_nrLocuri > 0)
		{
			this->nrLocuri = _nrLocuri;
			this->loc = new bool[this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++)
			{
				this->loc[i] = _loc[i];
			}
		}
	}

	bool kLocuriLibere(int _k)
	{
		if (this->nrLocuri > 0)
		{
			int ct = 0;
			for (int i = 0; i < this->nrLocuri; i++)
			{
				if (this->loc[i] == 0)
				{
					ct++;
				}
			}

			if (ct == _k)
			{
				return true;
			}
			else return false;
		}
		else return false;
	}

	bool kLocuriLibereAlaturate(int _k)
	{
		if (this->nrLocuri > 0)
		{
			for (int i = 0; i < this->nrLocuri; i++)
			{
				if (this->loc[i] == 0)
				{
					int ct = 0;
					for (int j = i + 1; j < this->nrLocuri; j++)
					{
						if (this->loc[j] == 0)
						{
							ct++;
						}
					}

					if (ct >= _k)
					{
						return true;
					}
				}
			}
		}
		else return false;
	}

	void acupaLoc(int _k)
	{
		if (this->nrLocuri > 0 && _k < this->nrLocuri && this->loc[_k] == 0)
		{
			this->loc[_k] = 1;
		}
	}

	void adaugaLoc(int _k)
	{
		if (this->nrLocuri)
		{
			bool* aux = new bool[this->nrLocuri + _k];
			for (int i = 0; i < this->nrLocuri + _k; i++)
			{
				aux[i] = this->loc[i];
				if (i >= this->nrLocuri)
				{
					aux[i] = 0;
				}
			}

			delete[] this->loc;

			this->nrLocuri += _k;
			this->loc = aux;
		}
	}

	void afisare()
	{
		cout << "\n------------ Zbor --------------";
		cout << "\nDestinatie: " << this->destinatie;
		cout << "\nSursa: " << this->sursa;
		cout << "\nNr locuri: " << this->nrLocuri;
		cout << "\nLocuri: ";
		for (int i = 0; i < this->nrLocuri; i++)
		{
			cout << this->loc[i] << "   ";
		}
	}
};

int main()
{
	Zbor z1;
	z1.afisare();

	Zbor z2("Londra", "Berlin");
	z2.afisare();

	bool v[] = { 1, 0, 1, 0, 0, 1, 1 };
	Zbor z3("Barcelona", "Madrid", 7, v);
	z3.afisare();
	cout << "\nExista 3 locuri libere? " << z3.kLocuriLibere(3);
	cout << "\nExista 2 locuri libere alaturate? " << z3.kLocuriLibereAlaturate(2);
	z3.acupaLoc(3);
	z3.afisare();
	z3.adaugaLoc(4);
	z3.afisare();

	return 0;
}