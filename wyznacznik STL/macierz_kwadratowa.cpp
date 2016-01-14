#include "stdafx.h"
#include "macierz_kwadratowa.h"

macierz_kwadratowa::macierz_kwadratowa()
{
	cout << "Podaj wymiar macierzy kwadratowej: ";
	cin >> this->n;

	macierz.resize(n);
	for (int i = 0; i<n; i++)
		macierz[i].resize(n);


	for (int i = 0; i < n; i++)
	{
		cout << "Podaj " << n << " elementow " << i + 1 << ". wiersza \n";
		for (int j = 0; j < n; j++)
		{
			cin >> macierz[i][j];
		}
		cout << endl;
	}

}

void macierz_kwadratowa::wyswietl_macierz()
{
	vector < vector <double> > wektory = this->macierz;
	int m = n = this->n;
	for (int i = 0; i < m; i++)
	{
		cout << "\t[";

		for (int j = 0; j < n; j++)
		{
			cout.width(6);
			cout.precision(4);
			cout << wektory[i][j];
			if (j != n - 1) cout << " ; ";
		}

		cout << "]" << endl;
	}
}

double macierz_kwadratowa::wyznacznik()
{
	vector < vector <double> > tab = this->macierz;
	int n = this->n;
	int  wiersz, flag = 1;
	double pom, det = 1.0;

	for (int i = 0; i<n; i++)
	{
		if (tab[i][i] == 0)
		{
			flag = 0;
			for (int j = i + 1; j<n; j++)
			{
				if (tab[j][i] != 0)
				{
					wiersz = j;
					for (int k = i; k<n; k++)
					{
						pom = tab[i][k];                //zamiana wierszy
						tab[i][k] = tab[wiersz][k];
						tab[wiersz][k] = pom;
					}
					det = -det;
					j = n;
					flag = 1;
				}
			}
		}



		if (!flag) return 0;    //jesli flaga zero -> zerowa kolumna


		for (int j = i + 1; j<n; j++)
		{
			pom = tab[j][i] / tab[i][i];

			for (int k = i; k<n; k++)
			{
				tab[j][k] -= pom*tab[i][k];     // zerowanie pod glowna przekatna - macierz trojkatna
			}
		}
		det *= tab[i][i];
	}
	return det;
}

macierz_kwadratowa::~macierz_kwadratowa()
{
}
