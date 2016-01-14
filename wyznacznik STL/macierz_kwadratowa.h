#include "stdafx.h"
#include <vector>
#include <cstdarg>
#include <iostream>
using namespace std;

class macierz_kwadratowa
{
private:
	vector < vector <double> > macierz;		//macierz
	int n;									//wymiar

public:
	macierz_kwadratowa();
	double wyznacznik();
	void wyswietl_macierz();
	~macierz_kwadratowa();
};