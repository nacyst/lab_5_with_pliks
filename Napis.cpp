
#include "Napis.h"
Napis::Napis(const char* nap) {      //konstruktor domyœlny
	m_nDl = strlen(nap)+1;
	m_pszNapis = new char[m_nDl];
	//cout<<"!!!!!!"<<strlen(m_pszNapis)<<endl;
	for (int i = 0; i<m_nDl; ++i) {
		m_pszNapis[i] = nap[i];
	}

}


Napis::~Napis() {                    //destruktor
	cout << "\ndesrtucto\n";
	delete[] m_pszNapis;
}


Napis::Napis(const Napis & wzor) {          //konstruktor kopiujacy
	cout << "Konstruktor kopiujacy\n";
	this->m_nDl = wzor.m_nDl;
	m_pszNapis = new char[m_nDl];
	//cout<<strlen(m_pszNapis)<<endl;
	for (int i = 0; i<m_nDl; ++i) {
		this->m_pszNapis[i] = wzor.m_pszNapis[i];
	}

}

Napis & Napis::operator= (const Napis &wzor) {
	if (this->m_pszNapis != nullptr) {
		delete[] this->m_pszNapis;
	}
	this->m_nDl = wzor.m_nDl;
	m_pszNapis = new char[m_nDl];

	for (int i = 0; i<wzor.m_nDl; i++) {
		m_pszNapis[i] = wzor.m_pszNapis[i];

	}
	return *this;
}


bool Napis::operator==(const   Napis &wzor) const {
	if (this->m_nDl == wzor.m_nDl) {
		if (this->SprawdzNapis(wzor.m_pszNapis) == 0)
			return true;
	}
	return false;
}
ostream & operator<<(ostream &wy, const Napis &p) {
	return wy << p.m_pszNapis;
}

istream & operator >> (istream &we, Napis &p) {
	char buf[80];
	we >> buf;

	p.Ustaw(buf);
	return we;
}





void Napis::Wpisz() {


	//cout<<"Podaj napis\n";
	cin >> *this;
	//cin >> m_pszNapis;
	 //stdin(m_pszNapis,40);

};
const char* Napis::Zwroc() const {
	return m_pszNapis;
};


void Napis::Ustaw(const char* nowy_napis) {

	this->m_nDl = strlen(nowy_napis)+1;
	m_pszNapis = new char[m_nDl];
	//cout<<strlen(m_pszNapis)<<endl;
	for (int i = 0; i<m_nDl; ++i) {
		this->m_pszNapis[i] = nowy_napis[i];
	}
	//strcpy(m_pszNapis,nowy_napis);

};
void Napis::Wypisz()const {
	cout << *this;

};


int Napis::SprawdzNapis(const char*por_napis)const {



	return strcmp(m_pszNapis, por_napis);
	/*
	int i=0;
	while((por_napis[i]!='\0')||(m_pszNapis[i]!='\0')){
	if (por_napis[i]>m_pszNapis[i])
	return -1;
	if (por_napis[i]<m_pszNapis[i])
	return 1;

	i++;
	}

	return 0;
	*/
};




