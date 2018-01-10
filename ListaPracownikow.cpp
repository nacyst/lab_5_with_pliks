#include "ListaPracownikow.h"







ListaPracownikow::ListaPracownikow()
{
	m_pPoczatek = NULL;
	m_nLiczbaPracownikow = 0;
}


ListaPracownikow::~ListaPracownikow()
{
}


void ListaPracownikow::Dodaj(const Pracownik  &p) {

	Pracownik *k, *x;


	k = new Pracownik(p);

	if (m_nLiczbaPracownikow != 0) {

		x = m_pPoczatek;


		while (1) {
			if (x->Porownaj(*k)>0) {
				k->m_pNastepny = m_pPoczatek;
				m_pPoczatek = k;
				break;
			}
			if ((x->Porownaj(*k) == 0)) {
				cout << "\n\nNIE MOZESZ DODAC TAKI SAMY ELEMENT\n\n";
				m_nLiczbaPracownikow--;
				delete k;

				break;

			}

			if (x->m_pNastepny == NULL) {
				k->m_pNastepny = x->m_pNastepny;
				x->m_pNastepny = k;
				break;
			}





			if ((x->m_pNastepny->Porownaj(*k)>0)) {
				//     k->m_pNastepny=x->m_pNastepny;
				//   x->m_pNastepny=k;

				k->m_pNastepny = x->m_pNastepny;
				x->m_pNastepny = k;
				break;
			}

			x = x->m_pNastepny;
		}

	}
	else {
		k->m_pNastepny = m_pPoczatek;
		m_pPoczatek = k;
	}
	m_nLiczbaPracownikow++;

};

void ListaPracownikow::WypiszPracownikow()const {
	Pracownik *k = m_pPoczatek;
	ofstream out("H:\\Mykyta_Vovk\\Lab_3\\Lista.txt");
	cout << "\n\nLICZBA PRACOWNIKOW :" << m_nLiczbaPracownikow << endl;
	while (k != NULL) {
		
		out <<*k<<endl;
		
		k->Wypisz();
		k = k->m_pNastepny;
	}
	out.close();
};


void ListaPracownikow::Usun(const Pracownik& wzorzec) {



	Pracownik *x = m_pPoczatek, *buf;



	if (x->Porownaj(wzorzec) == 0) {
		m_pPoczatek = x->m_pNastepny;
		m_nLiczbaPracownikow--;
		delete x;


	}
	else {

		if (m_nLiczbaPracownikow != 0) {
			while (1) {



				if (x->m_pNastepny == NULL) {
					cout << "\n\nNIE MA TAKIEGO PRACOWNIKA\n\n";
					break;
				}


				if ((x->m_pNastepny->Porownaj(wzorzec) == 0)) {
					buf = x->m_pNastepny->m_pNastepny;
					delete x->m_pNastepny;
					x->m_pNastepny = buf;
					m_nLiczbaPracownikow--;
					break;

				}
				x = x->m_pNastepny;
			}
		}



		else
			cout << "\n\nNIE MA TAKIEGO PRACOWNIKA\n\n";


	}




	//    while(1){
	/*
	if(x->Porownaj(wzorzec)==0){
	m_pPoczatek=x->m_pNastepny;
	m_nLiczbaPracownikow--;
	delete x;

	}
	else if(x->m_pNastepny!=NULL){
	while((x->m_pNastepny->Porownaj(wzorzec)!=0)){

	x=x->m_pNastepny;
	if (x->m_pNastepny==NULL)
	break;

	}
	if (x->m_pNastepny==NULL)
	cout<<"Nie ma takiego\n";
	else{
	m_nLiczbaPracownikow--;
	// x->m_pNastepny
	buf =x->m_pNastepny->m_pNastepny;
	delete x->m_pNastepny;
	x->m_pNastepny=buf;
	}
	}
	else{
	cout<<"Nie ma takiego\n";
	}

	*/
};


//const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie) const
//{
//    Pracownik *ListPrac = m_pPoczatek;
//
//    while (ListPrac != NULL) {
//
//        if (ListPrac->sprawdz_nazwisko(nazwisko) == 0 && ListPrac->sprawdz_imie(imie) == 0) {
//            return ListPrac;
//            break;
//        }
//
//
//
//        ListPrac = ListPrac->m_pNastepny;
//    }
//
//}

const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char * imie) const {
	Pracownik *x = m_pPoczatek;
	while ((strcmp(x->Nazwisko(), nazwisko) != 0) || (strcmp(x->Imie(), imie) != 0)) {
		x = x->m_pNastepny;
		if (x == NULL) {
			return NULL;
		}
	}
	return x;
};
