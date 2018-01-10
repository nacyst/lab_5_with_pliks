#include <iostream>
#include "ListaPracownikow.h"
#include "Pracownik.h"


using namespace std;
int main(int argc, const char * argv[]) {
	ListaPracownikow A;
	Pracownik B;
	Data D;

	int wybor;
	char imie[10], nazwisko[10];

	while (1) {
		cout << "1 - Dodaj pracownika\n";
		cout << "2 - Wyswietl pracownikow\n";
		cout << "3 - Usun pracownika\n";
		cout << "4 - Szukaj pracownika\n";
		cout << "5 - Podac i wyswietlic date\n";
		cout << "6 - Podac i wyswietlic napis\n";
		cout << "7 - Podac i wyswietlic pracownika\n";
		cout << "8 -Pobrac z pliku\n";
		cin >> wybor;

		switch (wybor) {
		case 2:
			A.WypiszPracownikow();
			break;
		case 1:
			B.Wpisz();
			A.Dodaj(B);
			break;
		case 3:
			B.Wpisz();
			A.Usun(B);
			break;
		case 4:

			cout << "PODAJ IMIE :\n";
			cin >> imie;
			cout << "PODAJ NAZWISKO :\n";
			cin >> nazwisko;

			if (A.Szukaj(nazwisko, imie) == NULL)
				cout << "\n\nNIE MA TAKIEGO PRACOWNIKA\n\n";
			else
			{
				cout << "PRACOWNIKA ZNALEZIONO\n";
				B = *A.Szukaj(nazwisko, imie);
				B.Wypisz();
			}
			break;

		case 5:
			cin >> D;
			cout << D;
			break;

		case 7: {
			//char imie1[]="Mykyta";
			Pracownik A1;//("Mykyta","Vovk",11,9,1999);
			cin >> A1;
			cout << A1;
			Pracownik K(A1);
			cout << K;
			cin >> K;
			Pracownik K1;
			K1 = K;
			cout << K1;
			cin >> K1;
			cout << (K1 == A1) << endl;

			//                A1.Wypisz();
			//                Pracownik B1(A1);
			//                B1.Wypisz();
			//                B1.Wpisz();
			//                B1.Wypisz();
			//                Pracownik C1;
			//                C1=B1;
			//                C1.Wypisz();
			//                cout<<(C1==A1)<<endl;



			break; }
		case 6:
		{
			Napis N;// ("Mykyta");
			cout << "PODAJ IMIE :\n";
			cin >> N;
			cout << N;
			cout << endl;
			Napis A(N);
			//A = N;
			cout << A;
			cout << endl;
			/*
			Napis M("lolkek");
			cout << M;
			cout << endl;
			Napis k;
			k = N;
			cin >> k;
			cout << k;
			cout << endl;
			bool kex;
			kex = (k == N);
			cout << kex << endl;*/
			break;
		}
		case 8:
		{
			ifstream in("H:\\Mykyta_Vovk\\Lab_3\\file.txt");
			while(1){
				
			in >> B;
			if (!in)
				break;
			A.Dodaj(B);
			}


			break;
		}



		}
	}

	return 0;
}
