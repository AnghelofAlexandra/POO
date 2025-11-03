#include <iostream>
using namespace std;

int med(int n, int* v)
{
	if (n > 0)
	{
		int med = 0;
		for (int i = 0; i < n; i++)
		{
			med += v[i];
		}

		return med / n;
	}
	else return 1;
}

int suma(int n, int* v)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s += v[i];
	}

	return s;
}

class Student
{
	string numeStudent = "anonim";
	int nrNote = 0;
	int* note = nullptr;
	float bursa = 0;
	bool integralist = 0;

public:
	Student() {}

	Student(string _numeStudent, int _nrNote, int* _note, float _bursa, bool _integralist)
	{
		if (_numeStudent.size() >= 3)
		{
			this->numeStudent = _numeStudent;
		}

		if (_nrNote > 0)
		{
			int* aux = new int[_nrNote];
			for (int i = 0; i < _nrNote; i++)
			{
				if (_note[i] >= 1 && _note[i] <= 10)
				{
					aux[i] = _note[i];
				}
				else aux[i] = med(i, aux);
			}

			this->nrNote = _nrNote;
			this->note = new int[_nrNote];
			for (int i = 0; i < _nrNote; i++)
			{
				this->note[i] = aux[i];
			}

			delete[] aux;
		}

		if (_bursa > 0)
		{
			this->bursa = _bursa;
		}

		this->integralist = _integralist;
	}

	bool eligibilBursa()
	{
		if (this->nrNote > 0 && this->integralist==1)
		{
			if (med(this->nrNote, this->note) >= 8)
			{
				return 1;
			}
		}
		return 0;
	}

	void afisare()
	{
		cout << "\nNume: " << this->numeStudent;
		cout << "\nNr note: " << this->nrNote;
		cout << "\nSuma note: " << suma(this->nrNote, this->note);
		cout << "\nBursa: " << this->bursa;
		cout << "\nIntegralist: " << this->integralist;
	}
};

void adaugareNota(int& n, int*& v, int nota)
{
	if (nota>=1 && nota<=10)
	{
		int* aux = new int[n + 1];
		for (int i = 0; i < n; i++)
		{
			aux[i] = v[i];
		}

		aux[n] = nota;

		delete[] v;

		n += 1;
		v = aux;
	}
}

int main()
{
	Student s1;
	s1.afisare();

	int v[] = { 11, 10, 9 };
	Student s2("Gigel", 3, v, 1000, 1);
	s2.afisare();
	cout << "\nEligibil pentru bursa: " << s2.eligibilBursa();

	int n = 3;
	int* vect = new int[n] { 7, 8, 9 };
	adaugareNota(n, vect, 10);
	cout << "\nNote dupa adaugare: ";
	for (int i = 0; i < 4; i++)
	{
		cout << vect[i] << "  ";
	}

	return 0;
}