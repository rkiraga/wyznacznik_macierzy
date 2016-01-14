#include "stdafx.h"
#include <vector>
#include <cstdarg>
#include <iostream>
#include "macierz_kwadratowa.h"
using namespace std;

int main()
{

	macierz_kwadratowa m1;

	m1.wyswietl_macierz();

	cout<<"\nwyznacznik tej macierzy = "<<m1.wyznacznik()<<endl;

    return 0;
}

