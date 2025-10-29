#include <iostream>
using namespace std;

bool validRatinguri(float rating)
{
	if (rating > 0 && rating <= 10)
	{
		return true;
	}
	else return false;
}

class Carte
{
	char titlu[50] = "Necunoscut";
	char autor[50] = "Anonim";
	int nrRatinguri = 0;
	float ratinguri[100];

public:
	Carte() {}

	Carte(const char _titlu[], const char _autor[])
	{
		strcpy_s(this->titlu, strlen(_titlu) + 1, _titlu);
		strcpy_s(this->autor, strlen(_autor) + 1, _autor);
	}

	Carte(const char _titlu[], const char _autor[], int _nrRatinguri, float _ratinguri[])
	{
		strcpy_s(this->titlu, strlen(_titlu) + 1, _titlu);
		strcpy_s(this->autor, strlen(_autor) + 1, _autor);

		if (_nrRatinguri != 0)
		{
			for (int i = 0; i < _nrRatinguri; i++)
			{
				if (!validRatinguri(_ratinguri[i]))
				{
					for (int j = i; j < _nrRatinguri - 1; j++)
					{
						_ratinguri[j] = _ratinguri[j + 1];
					}

					_nrRatinguri--;
				}
			}

			this->nrRatinguri = _nrRatinguri;

			for (int i = 0; i < _nrRatinguri; i++)
			{
				this->ratinguri[i] = _ratinguri[i];
			}
		}
	}

	void addRating(float _rating)
	{
		if (this->nrRatinguri > 0)
		{
			if (validRatinguri(_rating))
			{
				this->nrRatinguri++;
				this->ratinguri[this->nrRatinguri - 1] = _rating;
			}
		}
	}

	float medie()
	{
		if (this->nrRatinguri > 0)
		{
			int med = 0;
			for (int i = 0; i < this->nrRatinguri; i++)
			{
				med += this->ratinguri[i];
			}

			med = med / this->nrRatinguri;
			
			return med;
		}
	}

	void elimSubMedie()
	{
		if (this->nrRatinguri > 0)
		{
			float med = medie();

			for (int i = 0; i < this->nrRatinguri; i++)
			{
				if (this->ratinguri[i] < med)
				{

					for (int j = i; j < this->nrRatinguri - 1; j++)
					{
						this->ratinguri[j] = this->ratinguri[j + 1];
					}

					this->nrRatinguri--;
				}
			}
		}
	}

	void dubleazaRating()
	{
		if (this->nrRatinguri > 0)
		{
			this->nrRatinguri++;
			this->ratinguri[this->nrRatinguri - 1] = this->ratinguri[this->nrRatinguri - 2];
		}
	}

	void afisare()
	{
		cout << "\n-------------------- " << this->titlu << " -----------------------";
		cout << "\nAutor: " << this->autor;
		cout << "\nNr ratinguri: " << this->nrRatinguri;
		cout << "\nRating: ";
		for (int i = 0; i < this->nrRatinguri; i++)
		{
			cout << this->ratinguri[i] << "   ";
		}
	}
};

int main()
{
	Carte c1;
	c1.afisare();

	Carte c2("Moara cu Noroc", "Ioan Slavici");
	c2.afisare();

	float rate3[] = { 10, 12, 7, 8.5, 9, 0, 8, 9.5, 10, 7, 8.5 };
	Carte c3("Leul, vrajitoarea si dulapul", "C.S.Lewis", 11, rate3);
	c3.afisare();

	c3.addRating(10);
	c3.afisare();

	cout << "\nMedie Rating: " << c3.medie();

	c3.elimSubMedie();
	c3.afisare();

	c3.dubleazaRating();
	c3.afisare();

	return 0;
}