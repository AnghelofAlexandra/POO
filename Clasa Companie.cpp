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
	}
	else return 0;
}

class Companie
{
	string denumireCompanie = "anonim";
	int nrAni = 0;
	float* venitAnual = nullptr;
	float costuriOperationale = 0;
	bool esteActiva = 0;

public:
	Companie() {}

	Companie(string _denumireCompanie, int _nrAni, float* _venitAnual, float _costuriOperationale, bool _esteActiva)
	{
		if (_denumireCompanie.size() >= 3)
		{
			this->denumireCompanie = _denumireCompanie;
		}

		if (_nrAni > 0)
		{
			this->nrAni = _nrAni;
			this->venitAnual = new float[this->nrAni];

			for (int i = 0; i < this->nrAni; i++)
			{
				if (_venitAnual[i] < 0)
				{
					this->venitAnual[i] = medie(i, this->venitAnual);
				}
				else this->venitAnual[i] = _venitAnual[i];
			}
		}

		this->costuriOperationale = _costuriOperationale;
		this->esteActiva = _esteActiva;
	}

	bool urmeazaFaliment(int x)
	{
		if (this->nrAni > 0 && x <= this->nrAni)
		{
			for (int i = 0; i < this->nrAni; i++)
			{
				if (this->venitAnual[i] < this->costuriOperationale)
				{
					int ct = 0;
					for (int j = i; j < this->nrAni; j++)
					{
						if (this->venitAnual[j] < this->costuriOperationale)
						{
							ct++;
						}
						else
						{
							ct = 0;
							break;
						}
					}

					if (ct >= x)
					{
						return 1;
					}
					else ct = 0;
				}
			}

			return 0;
		}
		else return 0;
	}

	void afisare()
	{
		cout << "\nDenumire: " << this->denumireCompanie;
		cout << "\nNr ani: " << this->nrAni;
		cout << "\nVenit anual: ";
		for (int i = 0; i < this->nrAni; i++)
		{
			cout << this->venitAnual[i] << "  ";
		}
		cout << "\nCosturi operationale: " << this->costuriOperationale;
		cout << "\nEste activa: " << this->esteActiva;
	}
};

void addVenit(int& n, float*& v, float venit)
{
	if (n > 0)
	{
		float* aux = new float[n + 1];

		for (int i = 0; i < n; i++)
		{
			aux[i] = v[i];
		}

		if (venit < 0)
		{
			aux[n] = medie(n, v);
		}
		else aux[n] = venit;

		delete[] v;
		n = n + 1;
		v = aux;
	}
}

int main()
{
	Companie c1;
	c1.afisare();

	float v[] = { 20, -10, 30, 10, -10 };
	Companie c2("MARA", 5, v, 30, 1);
	c2.afisare();
	cout << "\nUrmeaza faliment: " << c2.urmeazaFaliment(2);

	int n = 3;
	float* v1 = new float[n] {3, 4, 5};
	addVenit(n, v1, -9);
	cout << "\nVector dupa adaugare: ";
	for (int i = 0; i < n; i++)
	{
		cout << v1[i] << " ";
	}

	return 0;
}
