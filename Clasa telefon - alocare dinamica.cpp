#include<iostream>
#include<string.h>
using namespace std;

double maximPret(double* preturi, int n)
{
	double max = preturi[0];
	for (int i = 1; i < n; i++)
	{
		if (max < preturi[i])
		{
			max = preturi[i];
		}
	}

	return max;
}

class Telefon
{
	char* marca = nullptr;
	char* model = nullptr;
	int nrVersiuni = 0;
	double* pret = nullptr; // nu pot exista 2 preturi consecutive egale

public:
	Telefon()
	{
		this->marca = new char[strlen("Neindentificata") + 1];
		strcpy_s(this->marca, strlen("Neindentificata") + 1, "Neidentificat");

		this->model = new char[strlen("Necunoscut") + 1];
		strcpy_s(this->model, strlen("Necunoscut") + 1, "Necunoscut");
	}

	Telefon(const char* _marca, const char* _model)
	{
		this->marca = new char[strlen(_marca) + 1];
		strcpy_s(this->marca, strlen(_marca) + 1, _marca);

		this->model = new char[strlen(_model) + 1];
		strcpy_s(this->model, strlen(_model) + 1, _model);
	}

	Telefon(const char* _marca, const char* _model, int _nrVersiuni, double* _pret)
	{
		this->marca = new char[strlen(_marca) + 1];
		strcpy_s(this->marca, strlen(_marca) + 1, _marca);

		this->model = new char[strlen(_model) + 1];
		strcpy_s(this->model, strlen(_model) + 1, _model);

		if (_nrVersiuni > 0)
		{
			double* aux = new double[_nrVersiuni];

			int k = 0;
			aux[k++] = _pret[0];
			for (int i = 1; i < _nrVersiuni; i++)
			{
				if (_pret[i] == _pret[i - 1])
				{
					continue;
				}
				else aux[k++] = _pret[i];
			}

			this->nrVersiuni = k;
			this->pret = new double[k];

			for (int i = 0; i < k; i++)
			{
				this->pret[i] = aux[i];
			}
		}
	}

	void adaugarePret(double _pretNou)
	{
		if (this->nrVersiuni > 0)
		{
			if (this->pret[this->nrVersiuni - 1] != _pretNou)
			{
				double* aux = new double[this->nrVersiuni + 1];

				for (int i = 0; i < this->nrVersiuni; i++)
				{
					aux[i] = this->pret[i];
				}
				aux[this->nrVersiuni] = _pretNou;

				delete[] this->pret;

				this->nrVersiuni += 1;
				this->pret = aux;
			}
		}
	}

	void elimPreturiFinal(int k)
	{
		if (this->nrVersiuni > 0)
		{
			if (k<this->nrVersiuni)
			{
				double* aux = new double[this->nrVersiuni - k];

				for (int i = 0; i < this->nrVersiuni - k; i++)
				{
					aux[i] = this->pret[i];
				}

				delete[] this->pret;

				this->nrVersiuni -= k;
				this->pret = aux;
			}
		}
	}

	void golirePreturi()
	{
		if (this->nrVersiuni > 0)
		{
			delete[] this->pret;
		}
	}

	double medie()
	{
		if (this->nrVersiuni > 0)
		{
			double med = 0;
			for (int i = 0; i < this->nrVersiuni; i++)
			{
				med += this->pret[i];
			}

			med /= this->nrVersiuni;

			return med;
		}
	}

	double pretMax()
	{
		if (this->nrVersiuni > 0)
		{
			return maximPret(this->pret, this->nrVersiuni);
		}
	}

	void afisare()
	{
		cout << "\n---------------------------------------------------";
		cout << "\nMarca: " << this->marca;
		cout << "\nModel: " << this->model;
		cout << "\nNr versiuni: " << this->nrVersiuni;
		cout << "\nPreturi: ";
		for (int i = 0; i < this->nrVersiuni; i++)
		{
			cout << this->pret[i] << "  ";
		}
	}
};

int main()
{
	Telefon t1;
	t1.afisare();

	Telefon t2("Samsung", "A16");
	t2.afisare();

	double preturi[] = { 700, 850, 650, 650, 720.99, 803, 803.50, 900, 900 };
	Telefon t3("Samsung", "A51", 9, preturi);
	t3.afisare();

	t3.adaugarePret(801);
	t3.afisare();

	t3.elimPreturiFinal(3);
	t3.afisare();

	cout<<"\nMedie Pret: " << t3.medie();
	cout << "\nPret maxim: " << t3.pretMax();

	return 0;
}