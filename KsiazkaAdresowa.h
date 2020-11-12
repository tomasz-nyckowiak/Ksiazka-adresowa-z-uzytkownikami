#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };

    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int aktualneId);
    void zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);

    int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void ustawIdOstatniegoAdresata(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
};

#endif
