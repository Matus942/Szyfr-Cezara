// Cezar.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>
#include "klasa.h"



int main()
{
	cezar l;
	string i;
	int a = 0;
/*	l.wczytaj();
	l.przes();
	l.szyfruj();
*/	do
	{
		l.wczytaj();
		l.przes();
		system("CLS");
		cout << "Wybierz: " << endl;
		cout << "1.Szyfrowanie" << endl;
		cout << "2.Deszyfrowanie" << endl;
		cout << "Pamietaj ze aby deszyfrowac trzeba najpierw szyfrowac" << endl;
		cin >> a;
		switch (a)
		{
			case 1:
			{
				l.szyfruj();
				break;
			}
			case 2:
			{
				l.deszyfruj();
				break;
			}
		}
		l.out(a);
		cout << "Czy chcesz kontynuowac?[y/n]" << endl;
		cin >> i;
	} while (i == "y");
	system("PAUSE");
	return 0;
}

