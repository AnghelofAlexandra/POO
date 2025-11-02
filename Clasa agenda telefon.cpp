#include <iostream>
using namespace std;

enum Tip
{
	ACASA, DE_SERVICI
};

class AgendaTelefon
{
	string posesor = "Anonim";
	int nrContacte = 0;
	string* numeContacte = nullptr;
	Tip tip=ACASA;
	bool sincronizata = 0;

public:
	AgendaTelefon() {}

	AgendaTelefon(string _posesor)
	{
		if (_posesor.size() >= 3)
		{
			this->posesor = _posesor;
		}
	}

	void addContact(string _contact)
	{
		if (this->nrContacte == 0)
		{
			this->nrContacte += 1;
			this->numeContacte = new string[this->nrContacte];
			this->numeContacte[0] = _contact;
		}
		else
		{
			string* aux = new string[this->nrContacte + 1];
			bool exista = 0; // pp ca nu

			for (int i = 0; i < this->nrContacte; i++)
			{
				if (_contact == this->numeContacte[i])
				{
					exista = 1;
					break;
				}
				aux[i] = this->numeContacte[i];
			}

			if (exista == 0)
			{
				aux[this->nrContacte] = _contact;

				delete[] this->numeContacte;

				this->nrContacte += 1;
				this->numeContacte = aux;
			}
			else delete[] aux;
		}
	}

	void afisare()
	{
		cout << "\nPosesor: " << this->posesor;
		cout << "\nNr contacte: " << this->nrContacte;
		cout << "\nNume conatacte: ";
		for (int i = 0; i < this->nrContacte; i++)
		{
			cout << "\n" << this->numeContacte[i];
		}

		cout << "\nTip: " << this->tip;
		cout << "\nSincronizata: " << this->sincronizata;
	}
};

int main()
{
	AgendaTelefon a1;
	a1.afisare();

	AgendaTelefon a2("Marcel");
	a2.afisare();
	a2.addContact("Ioana");
	a2.afisare();
	a2.addContact("Mara");
	a2.afisare();
	a2.addContact("Ioana");
	a2.afisare();

	return 0;
}