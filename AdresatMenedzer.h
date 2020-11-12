#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    PlikZAdresatami plikZAdresatami;

public:
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);
    int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void ustawIdOstatniegoAdresata(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    void wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
};

#endif
