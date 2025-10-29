#include <iostream>
#include <string>
using namespace std;

class Restaurant
{
	string nume="Anonim";
	int nrMese=0;
	bool* meseOcupate = nullptr;

public:
	Restaurant() {}

	Restaurant(string _nume)
	{
		this->nume = _nume;
	}

	Restaurant(string _nume, int _nrMese, bool* _meseOcupaate)
	{
		this->nume = _nume;

		if (_nrMese > 0)
		{
			this->nrMese = _nrMese;

			this->meseOcupate = new bool[this->nrMese];
			for (int i = 0; i < _nrMese; i++)
			{
				this->meseOcupate[i] = _meseOcupaate[i];
			}
		}
	}

	void rezervare(int _masa)
	{
		if (this->nrMese > 0 && this->meseOcupate[_masa] == 0 && _masa<this->nrMese)
		{
			this->meseOcupate[_masa] = 1;
		}
	}

	void eliberareMasa(int _masa)
	{
		if (this->nrMese > 0 && this->meseOcupate[_masa] == 1 && _masa < this->nrMese)
		{
			this->meseOcupate[_masa] = 0;
		}
	}

	bool cateMeseLibere(int _nr)
	{
		if (this->nrMese > 0 && _nr <= this->nrMese)
		{
			int ct = 0;
			for (int i = 0; i < this->nrMese; i++)
			{
				if (this->meseOcupate[i] == 0)
				{
					ct++;
				}
			}

			if (ct >= _nr)
			{
				return true;
			}
			else return false;
		}
	}

	bool cateMeseLibereAlat(int _nr)
	{
		if (this->nrMese > 0 && _nr <= this->nrMese)
		{
			int ct = 0;
			for (int i = 0; i < this->nrMese; i++)
			{
				if (this->meseOcupate[i] == 0)
				{
					ct++;
					for (int j = i + 1; j < this->nrMese; j++)
					{
						if (this->meseOcupate[i] != 0)
						{
							break;
						}
						else ct++;
					}

					if (ct == _nr)
					{
						return true;
					}
					else ct = 0;
				}
			}
			
			return false;
		}
	}

	void adaugaMese(int _nr)
	{
		if (this->nrMese > 0)
		{
			bool* aux = new bool[this->nrMese + _nr];

			for (int i = 0; i < this->nrMese + _nr; i++)
			{
				if (i >= this->nrMese)
				{
					aux[i] = 0;
				}
				else aux[i] = this->meseOcupate[i];
			}

			delete[] this->meseOcupate;

			this->nrMese += _nr;
			this->meseOcupate = aux;
		}
	}

	void afisare()
	{
		cout << "\n-------------- Nume: " << this->nume << " ----------------";
		cout << "\nNr mese: " << this->nrMese;
		cout << "\nMese ocupate: ";
		for (int i = 0; i < this->nrMese; i++)
		{
			cout << this->meseOcupate[i] << "  ";
		}
	}
};

int main()
{
	Restaurant r1;
	r1.afisare();

	Restaurant r2("Rosa");
	r2.afisare();

	bool mese[] = { 1, 0, 1, 0, 0, 0 , 1, 0 };
	Restaurant r3("Rummy", 8, mese);
	r3.afisare();

	r3.rezervare(3);
	r3.afisare();

	r3.eliberareMasa(6);
	r3.afisare();

	cout << "\nExita 4 mese libere? " << r3.cateMeseLibere(4);
	cout << "\nExita 5 mese libere alaturate? " << r3.cateMeseLibereAlat(5);

	r3.adaugaMese(5);
	r3.afisare();

	return 0;
}