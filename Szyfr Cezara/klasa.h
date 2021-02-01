#pragma once
#ifndef KLASA_H
#define KLASA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class cezar
{
private:
	vector<string> dane;
	vector<char>szyfr;
	vector<char>deszyf;
	char alfabet1[27] = { 'A', 'B', 'C','D' ,'E' ,'F' ,'G' ,'H' ,'I' ,'J' ,'K' ,'L' ,'M' ,'N' ,'O' ,'P' ,'Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y' ,'Z', ' '};
	char alfabet2[10] = { '.', ',', '?', '!', '"', ':', '(', ')', ';', '-' };
	char cyfry[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int przesuniecie;
public:
	void wczytaj();
	void szyfruj();
	void przes();
	void out(int);
	void deszyfruj();
};



#endif // !KLASA_H
