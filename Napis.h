
#pragma once

#include <iostream>
#include <stdio.h>
#include<string.h>
using namespace std;
class Napis {
public:
	Napis(const char* nap = "");
	Napis(const Napis & wzor);

	const char* Zwroc() const;
	void Ustaw(const char* nowy_napis);
	void Wypisz()const;
	void Wpisz();
	int SprawdzNapis(const char*por_napis)const;

	Napis & operator=(const Napis &wzor);
	bool operator==(const   Napis &wzor) const;
	friend ostream & operator<<(ostream &wy, const Napis &p);
	friend istream & operator >> (istream &we, Napis &p);

	~Napis();
private:

	char *m_pszNapis;
	unsigned long int m_nDl;

};



