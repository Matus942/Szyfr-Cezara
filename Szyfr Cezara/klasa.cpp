#include "stdafx.h"
#include "klasa.h"

///naprawic deszyfrowanie nie dziala poprawnie i dorobic opcje deszyfrowania tekstu ktory juz jest zaszyfrowany

void cezar::wczytaj()
{
	string a;
	
	cout << "Podaj nazwe pliku do wczytania: " << endl;
	cin >> a;
	ifstream plik(a);
	if (!plik) cout << "Brak pliku w katalogu z programem. Sproboj ponownie\n";
	string x;
	while (getline(plik,x)) dane.push_back(x);

	plik.close();
	
	/*
		cout << "podaj ciag znakow do szyfrowania: " << endl;
		getline(cin, a);
		dane.push_back(a);
	*/
	
}
void cezar::szyfruj()
{
	string a;
	for (int g = 0; g < dane.size(); g++)
	{
		a = dane[g];
		for (int y = 0; y < a.size(); y++)
		{
			a[y] = toupper(a[y]);
		}
		for (int i = 0; i < a.size(); i++)
		{
			int x = 0;
			int d = 0;
			for (int j = 0; j < 27; j++)
			{
				if (a[i] == alfabet1[j])
				{
					x = j + przesuniecie;
					if (x > 26)
					{
						d = x - 26;
						szyfr.push_back(alfabet1[d - 1]);
						break;
					}
					else
					{
						szyfr.push_back(alfabet1[x]);
						break;
					}
				}
				if (a[i] == alfabet2[j]) szyfr.push_back(alfabet2[j]);
				if (a[i] == cyfry[j]) szyfr.push_back(cyfry[j]);
			}
		}
	}
}
void cezar::przes()
{
	int a;
	cout << "Podaj przesuniecie" << endl;
	cin >> a;
	przesuniecie = a;
}
void cezar::out(int v)
{
	ofstream plik2;
	string c;
	cout << "Podaj nazwe pliku do zapisu: ";
	cin >> c;
	plik2.open(c);
	switch (v)
	{
		case 1:
		{
			cout << "Szyfrowanie: " << endl;
			for (int i = 0; i < szyfr.size(); i++)
			{
				cout << szyfr[i];
				plik2 << szyfr[i];
			}
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "Deszyfrowanie: " << endl;
			for (int i = 0; i < deszyf.size(); i++)
			{
				cout << deszyf[i];
				plik2 << deszyf[i];
			}
			cout << endl;
			break;
		}
	}
	dane.clear();
	szyfr.clear();
	deszyf.clear();
	plik2.close();
	
}
void cezar::deszyfruj()
{
	string a;
	for (int g = 0; g < dane.size(); g++)
	{
		a = dane[g];
		for (int i = 0; i < a.size(); i++)
		{
			int x = 0;
			int b = przesuniecie;
			int d = 0;
			for (int j = 0; j < 27; j++)
			{
				x = j - (przesuniecie - 1);
				if (a[i] == alfabet1[j])
				{
					//cout << "x : " << x << endl;
					if (j < b)
					{
						x = x * (-1);
						d = 26 - x;
						//cout << "x : " << x << endl;
						//cout << "d : " << d << endl;
						deszyf.push_back(alfabet1[d]);
					}
					else deszyf.push_back(alfabet1[x-1]);
				}
				if (a[i] == alfabet2[j]) deszyf.push_back(alfabet2[j]);
				if (a[i] == cyfry[j]) deszyf.push_back(cyfry[j]);
			}
		}
	}
}
