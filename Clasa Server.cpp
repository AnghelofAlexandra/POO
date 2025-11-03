#include <iostream>
using namespace std;

class Server
{
	string ip = "NO_IP";
	int nrProcese = 0;
	float* consumProcese = nullptr;
	float consumMaxim = 0;

public:
	Server() {}

	Server(string _ip, int _nrProcese, float* _consumProcese, float _consumMaxim)
	{
		this->ip = _ip;

		if (_nrProcese > 0 && _consumMaxim > 0)
		{
			float* aux = new float[_nrProcese];
			int k = 0;
			for (int i = 0; i < _nrProcese; i++)
			{
				if (_consumProcese[i] < _consumMaxim)
				{
					aux[k++] = _consumProcese[i];
				}
			}

			this->nrProcese = k;
			this->consumProcese = new float[k];
			for (int i = 0; i < _nrProcese; i++)
			{
				this->consumProcese[i] = aux[i];
			}

			delete[] aux;

			this->consumMaxim = _consumMaxim;
		}
	}

	float consumTotal()
	{
		if (this->nrProcese > 0)
		{
			float s = 0;
			for (int i = 0; i < this->nrProcese; i++)
			{
				s += this->consumProcese[i];
			}
			return s;
		}
		else return 0;
	}

	void afisare()
	{
		cout << "\nIp: " << this->ip;
		cout << "\nNr procese: " << this->nrProcese;
		cout << "\n Consum procese: ";
		for (int i = 0; i < this->nrProcese; i++)
		{
			cout << this->consumProcese[i] << "  ";
		}
		cout << "\nConsum Maxim: " << this->consumMaxim;
	}
};

int main()
{
	Server s1;
	s1.afisare();

	float c[] = { 3.5, 6, 9, 10.8, 9, 8.1 };
	Server s2("API", 6, c, 8);
	s2.afisare();
	cout << "\nConsum total: " << s2.consumTotal();

	return 0;
}
