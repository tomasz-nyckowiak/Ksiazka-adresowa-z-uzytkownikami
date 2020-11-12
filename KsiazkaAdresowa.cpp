#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    return uzytkownikMenedzer.logowanieUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    return uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    return uzytkownikMenedzer.wybierzOpcjeZMenuUzytkownika();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::ustawIdZalogowanegoUzytkownika(int aktualneId)
{
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(aktualneId);
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}

int KsiazkaAdresowa::dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    return adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
}

void KsiazkaAdresowa::ustawIdOstatniegoAdresata(int idZalogowanegoUzytkownika)
{
    adresatMenedzer.ustawIdOstatniegoAdresata(idZalogowanegoUzytkownika);
}

int KsiazkaAdresowa::pobierzIdOstatniegoAdresata()
{
    return adresatMenedzer.pobierzIdOstatniegoAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer.wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::wczytajAdresatowZPliku(int idZalogowanegoUzytkownika)
{
    adresatMenedzer.wczytajAdresatowZPliku(idZalogowanegoUzytkownika);
}
