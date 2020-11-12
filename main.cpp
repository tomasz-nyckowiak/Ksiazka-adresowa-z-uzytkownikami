#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");

    ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(0);

    while (true)
    {
        if (ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() == 0)
        {
            switch (ksiazkaAdresowa.wybierzOpcjeZMenuGlownego())
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(ksiazkaAdresowa.logowanieUzytkownika());
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            ksiazkaAdresowa.wczytajAdresatowZPliku(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());
            ksiazkaAdresowa.ustawIdOstatniegoAdresata(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());

            switch (ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika())
            {
            case '1':
                ksiazkaAdresowa.ustawIdOstatniegoAdresata(ksiazkaAdresowa.dodajAdresata(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika(), ksiazkaAdresowa.pobierzIdOstatniegoAdresata()));
                break;
            case '2':
                ;
                //wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                ;
                //wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                //wyswietlWszystkichAdresatow(adresaci);
                break;
            case '5':
                ;
                //idUsunietegoAdresata = usunAdresata(adresaci);
                //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                ;
                //edytujAdresata(adresaci);
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());
                //zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
                break;
            case '8':
                //cout << "Wylogowales sie!" << endl << endl;
                ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(0);
                //system("pause");
                //idZalogowanegoUzytkownika = 0;
                //adresaci.clear();
                break;
            }
        }
    }
    return 0;
}
