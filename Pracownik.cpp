
#include "Pracownik.h"
int Pracownik::ID = 0;
Pracownik::Pracownik(const char* im, const char* naz, int dzien, int miesiac, int rok): m_nIDZatrudnienia(ID){
	ID++;
	m_Imie.Ustaw(im);
	m_Nazwisko.Ustaw(naz);
	m_DataUrodzenia.Ustaw(dzien, miesiac, rok);

}
Pracownik::Pracownik(const Pracownik & wzor) : m_nIDZatrudnienia(ID) {
	ID++;
	this->m_Imie = wzor.m_Imie;
	this->m_Nazwisko = wzor.m_Nazwisko;
	this->m_DataUrodzenia.Ustaw(wzor.m_DataUrodzenia.Dzien(), wzor.m_DataUrodzenia.Miesiac(), wzor.m_DataUrodzenia.Rok());
}


Pracownik & Pracownik::operator=(const Pracownik &wzor)  {
	this->m_Imie = wzor.m_Imie;
	this->m_Nazwisko = wzor.m_Nazwisko;
	this->m_DataUrodzenia.Ustaw(wzor.m_DataUrodzenia.Dzien(), wzor.m_DataUrodzenia.Miesiac(), wzor.m_DataUrodzenia.Rok());
	return *this;
}


bool  Pracownik::operator==(const Pracownik &wzor) {
	if (this->Porownaj(wzor) == 0)
		return true;

	return false;
}

ostream & operator<<(ostream & wy, const Pracownik &p) {
	return wy <<"ID:"<<p.m_nIDZatrudnienia<< "\t" << p.m_Nazwisko << "\t" << p.m_Imie << "\t" << p.m_DataUrodzenia << endl;
}

istream & operator >> (istream & we, Pracownik & p) {
	  cout<<"Podaj: \tNazwisko\tImie\tDate urodzenia";
	cout << "Nazwisko\n";
	we >> p.m_Nazwisko;
	cout << "Imie\n";
	we >> p.m_Imie;
	cout << "Dzien urodzenia\n";
	we >> p.m_DataUrodzenia;
	return we;
}




const char* Pracownik::Imie() const {

	return m_Imie.Zwroc();
};
const char* Pracownik::Nazwisko() const {

	return m_Nazwisko.Zwroc();
};
void Pracownik::Imie(const char* nowe_imie) {
	m_Imie.Ustaw(nowe_imie);
};

void Pracownik::Nazwisko(const char* nowe_nazwisko) {
	m_Nazwisko.Ustaw(nowe_nazwisko);
};
void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok) {

	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
};
void Pracownik::Wypisz() const {
	cout << *this;


	//
	//m_Nazwisko.Wypisz();
	//cout << "\t";
	//m_Imie.Wypisz();
	//cout << "\t";

	//m_DataUrodzenia.Wypisz();
	//cout << "\n";
};
void Pracownik::Wpisz() {
	cin >> *this;
	/*
	cout << "Podaj imie\n";
	m_Imie.Wpisz();
	cout << "Podaj nazwisko\n";
	m_Nazwisko.Wpisz();
	cout << "Podaj data\n";
	m_DataUrodzenia.Wpisz();
	*/

};
int Pracownik::sprawdz_imie(const char* por_imie) const {
	return m_Imie.SprawdzNapis(por_imie);
};

int Pracownik::sprawdz_nazwisko(const char* por_nazwisko) const {
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
};


int Pracownik::Porownaj(const Pracownik& wzorzec) const {

	int imie, nazwisko, data;
	imie = sprawdz_imie(wzorzec.Imie());
	nazwisko = sprawdz_nazwisko(wzorzec.Nazwisko());
	data = m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);


	if (nazwisko == 0) {
		if (imie == 0) {
			return data;
		}
		else
			return imie;
	}
	else return nazwisko;


};

