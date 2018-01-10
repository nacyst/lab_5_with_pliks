#pragma once

#include<iostream>
using namespace std;
class Data
{
public:
	Data(int d = 1, int m = 1, int r = 2000);
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz() const;
	void Wpisz();
	int Porownaj(const Data &wzor) const;
	friend ostream & operator<< (ostream &wy, const Data &d);
	friend istream & operator >> (istream &we, Data &d);


	~Data();
private:
	void Koryguj();
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;

};

