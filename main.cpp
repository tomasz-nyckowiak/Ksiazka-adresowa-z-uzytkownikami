#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include <stdio.h>

using namespace std;

struct Uzytkownik
{
    int id = 0;
    string nazwa = "", haslo = "";
};

struct Adresat
{
    int id = 0;
    int idUzytkownika = 0;
    string imie = "", nazwisko = "", telefon = "", email = "", adres = "";
};

void WyswietlKsiazkeAdresowa(vector <Adresat> &adresaci, int iloscOsob)
{
    if (iloscOsob != 0)
    {
        for (int i = 0; i < iloscOsob; i++)
        {
            cout << adresaci[i].id << ") " << adresaci[i].imie << " " << adresaci[i].nazwisko << endl;
            cout << "Telefon: " << adresaci[i].telefon << endl;
            cout << "Email: "<< adresaci[i].email << endl;
            cout << "Adres: "<< adresaci[i].adres << endl;

        }
        cout << endl;
        system("pause");
    }
    else
    {
        cout << "Ksiazka adresowa jest pusta!" << endl;
        Sleep(2500);
    }
}

void WyszukajPoImieniu(vector <Adresat> &adresaci, int iloscOsob)
{
    string imie;

    if (iloscOsob != 0)
    {
        cout << "Podaj imie szukanej osoby: ";
        cin >> imie;

        int i = 0;
        int temp = 0; //zmienna pomocnicza

        while (i < iloscOsob)
        {
            if (adresaci[i].imie == imie)
            {
                cout << adresaci[i].id << ") " << adresaci[i].imie << " " << adresaci[i].nazwisko << endl;
                cout << "Telefon: " << adresaci[i].telefon << endl;
                cout << "Email: "<< adresaci[i].email << endl;
                cout << "Adres: "<< adresaci[i].adres << endl;
                temp++;
            }
            i++;
        }

        if (temp == 0)
            cout << "W ksiazce adresowej nie ma osoby o takim imieniu!" << endl;

        cout << endl;
        system("pause");
    }
    else
    {
        cout << "Ksiazka adresowa jest pusta!" << endl;
        Sleep(2500);
    }
}

void WyszukajPoNazwisku(vector <Adresat> &adresaci, int iloscOsob)
{
    string nazwisko;

    if (iloscOsob != 0)
    {
        cout << "Podaj nazwisko szukanej osoby: ";
        cin >> nazwisko;

        int i = 0;
        int temp = 0; //zmienna pomocnicza

        while (i < iloscOsob)
        {
            if (adresaci[i].nazwisko == nazwisko)
            {
                cout << adresaci[i].id << ") " << adresaci[i].nazwisko << " " << adresaci[i].imie << endl;
                cout << "Telefon: " << adresaci[i].telefon << endl;
                cout << "Email: "<< adresaci[i].email << endl;
                cout << "Adres: "<< adresaci[i].adres << endl;
                temp++;
            }
            i++;
        }

        if (temp == 0)
            cout << "W ksiazce adresowej nie ma osoby o takim nazwisku!" << endl;

        cout << endl;
        system("pause");
    }
    else
    {
        cout << "Ksiazka adresowa jest pusta!" << endl;
        Sleep(2500);
    }
}

vector <Adresat> DodanieAdresataDoWektora(vector <Adresat> &adresaci, int osoby, int idZalogowanegoUzytkownika)
{
    Adresat nowyAdresat;

    string linia;
    int i = 0;

    fstream plik;
    plik.open("Adresaci.txt", ios::in);

    if (plik.good() == true)
    {
        while (i < osoby)
        {
            getline(plik, linia, '|');
            nowyAdresat.id = atoi(linia.c_str());
            getline(plik, linia, '|');
            nowyAdresat.idUzytkownika = atoi(linia.c_str());
            getline(plik, linia, '|');
            nowyAdresat.imie = linia;
            getline(plik, linia, '|');
            nowyAdresat.nazwisko = linia;
            getline(plik, linia, '|');
            nowyAdresat.telefon = linia;
            getline(plik, linia, '|');
            nowyAdresat.email = linia;
            getline(plik, linia, '|');
            nowyAdresat.adres = linia;

            if (nowyAdresat.idUzytkownika == idZalogowanegoUzytkownika)
            {
                adresaci.push_back(nowyAdresat);
            }
            i++;
        }
        plik.close();
    }
    return adresaci;
}

int WczytajOsobyZPliku()
{
    string linia;
    int nr_linii = 1;
    int ile_osob = 0;

    fstream plik;
    plik.open("Adresaci.txt", ios::in);

    if (plik.good() == true)
    {
        while (getline(plik, linia))
        {
            if (nr_linii >= 1)
            {
                ile_osob++;
                nr_linii = 1;
            }
            else
                nr_linii++;
        }
        plik.close();
    }

    return ile_osob;
}

int DodajAdresata(vector <Adresat> &adresaci, int iloscOsob, int idZalogowanegoUzytkownika)
{
    int ID, iloscOsobWKsiazceAdresowej;
    string imie, nazwisko, telefon, email, adres;

    Adresat nowyAdresat;

    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin, telefon);
    cout << "Podaj email: ";
    cin >> email;
    cout << "Podaj adres: ";
    cin.sync();
    getline(cin, adres);

    iloscOsobWKsiazceAdresowej = WczytajOsobyZPliku();

    if (iloscOsob == 0)
        ID = iloscOsob + 1;
    else
        ID = adresaci[iloscOsob - 1].id + 1;

    nowyAdresat.id = ID;
    nowyAdresat.imie = imie;
    nowyAdresat.nazwisko = nazwisko;
    nowyAdresat.telefon = telefon;
    nowyAdresat.email = email;
    nowyAdresat.adres = adres;

    nowyAdresat.idUzytkownika = idZalogowanegoUzytkownika;

    adresaci.push_back(nowyAdresat);

    fstream plik;
    plik.open("Adresaci.txt", ios::out | ios::app);

    if (plik.good() == true)
    {
        plik << iloscOsobWKsiazceAdresowej + 1 << '|' << adresaci[iloscOsob].idUzytkownika << '|' << adresaci[iloscOsob].imie << '|' << adresaci[iloscOsob].nazwisko << '|' << adresaci[iloscOsob].telefon << '|' << adresaci[iloscOsob].email << '|' << adresaci[iloscOsob].adres << '|' << endl;
        plik.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych!" << endl;
        system("pause");
    }

    cout << endl;
    cout << "Osoba zostala dodana." << endl;
    Sleep(1500);
    return iloscOsob + 1;
}

void ZmianaNazwyPliku()
{
    int result;
    char oldname[] = "Adresaci_tymczasowy.txt";
    char newname[] = "Adresaci.txt";

    result = rename(oldname, newname);

    if (result == 0)
    {
        ;
    }
    else
    {
        cout << "Wystapil blad podczas proby zmiany nazwy pliku!" << endl;
        system("pause");
    }
}

void UsunieciePliku()
{
    if (remove("Adresaci.txt") != 0)
    {
        cout << "Wystapil blad podczas usuniecia pliku!" << endl;
        system("pause");
    }
    else
    {
        ;
    }
}

void ZapisDoPlikuPoEdycjiAdresata(vector <Adresat> &adresaci, int numerEdytowanegoAdresata, int ID)
{
    vector <Adresat> tymczasowy;
    Adresat tymczasowiAdresaci;

    string linia;
    int i = 0;

    int ile_osob = 0;
    ile_osob = WczytajOsobyZPliku();

    fstream plik;
    plik.open("Adresaci.txt", ios::in);

    if (plik.good() == true)
    {
        while (i < ile_osob)
        {
            getline(plik, linia, '|');
            tymczasowiAdresaci.id = atoi(linia.c_str());
            getline(plik, linia, '|');
            tymczasowiAdresaci.idUzytkownika = atoi(linia.c_str());
            getline(plik, linia, '|');
            tymczasowiAdresaci.imie = linia;
            getline(plik, linia, '|');
            tymczasowiAdresaci.nazwisko = linia;
            getline(plik, linia, '|');
            tymczasowiAdresaci.telefon = linia;
            getline(plik, linia, '|');
            tymczasowiAdresaci.email = linia;
            getline(plik, linia, '|');
            tymczasowiAdresaci.adres = linia;

            tymczasowy.push_back(tymczasowiAdresaci);

            i++;
        }
        plik.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych!" << endl;
        system("pause");
    }

    fstream plikTymczasowy;
    plikTymczasowy.open("Adresaci_tymczasowy.txt", ios::out | ios::app);

    if (plikTymczasowy.good() == true)
    {
        for (int j = 0; j < ile_osob; j++)
        {
            if (tymczasowy[j].id == ID)
            {
                plikTymczasowy << adresaci[numerEdytowanegoAdresata].id << '|' << adresaci[numerEdytowanegoAdresata].idUzytkownika << '|' << adresaci[numerEdytowanegoAdresata].imie << '|' << adresaci[numerEdytowanegoAdresata].nazwisko << '|' << adresaci[numerEdytowanegoAdresata].telefon << '|' << adresaci[numerEdytowanegoAdresata].email << '|' << adresaci[numerEdytowanegoAdresata].adres << '|' << endl;
            }
            else
            {
                plikTymczasowy << tymczasowy[j].id << '|' << tymczasowy[j].idUzytkownika << '|' << tymczasowy[j].imie << '|' << tymczasowy[j].nazwisko << '|' << tymczasowy[j].telefon << '|' << tymczasowy[j].email << '|' << tymczasowy[j].adres << '|' << endl;
            }
        }
        plikTymczasowy.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych!" << endl;
        system("pause");
    }

    UsunieciePliku();
    ZmianaNazwyPliku();
}

void EdytujAdresata(vector <Adresat> &adresaci, int iloscOsob)
{
    string imie, nazwisko, telefon, email, adres;
    char wybor;
    int ID;
    int i = 0;
    int temp = 0; //zmienna pomocnicza

    if (iloscOsob != 0)
    {
        cout << "Podaj nr ID adresata, ktorego dane chcesz edytowac: ";
        cin >> ID;

        while (i < iloscOsob)
        {
            if (adresaci[i].id == ID)
            {
                while (1)
                {
                    system("cls");
                    cout << "1 - imie" << endl;
                    cout << "2 - nazwisko" << endl;
                    cout << "3 - numer telefonu" << endl;
                    cout << "4 - email" << endl;
                    cout << "5 - adres" << endl;
                    cout << "6 - powrot do glownego menu" << endl;
                    cout << endl;
                    cin >> wybor;

                    if (wybor == '1')
                    {
                        cout << "Podaj nowe imie: ";
                        cin >> imie;

                        adresaci[i].imie = imie;

                        cout << "Wprowadzono nowe imie!";
                        cout << endl;
                        system("pause");

                        break;
                    }
                    else if (wybor == '2')
                    {
                        cout << "Podaj nowe nazwisko: ";
                        cin >> nazwisko;

                        adresaci[i].nazwisko = nazwisko;

                        cout << "Wprowadzono nowe nazwisko!";
                        cout << endl;
                        system("pause");

                        break;
                    }
                    else if (wybor == '3')
                    {
                        cout << "Podaj nowy nr telefonu: ";
                        cin.sync();
                        getline(cin, telefon);

                        adresaci[i].telefon = telefon;

                        cout << "Wprowadzono nowy nr telefonu!";
                        cout << endl;
                        system("pause");

                        break;
                    }
                    else if (wybor == '4')
                    {
                        cout << "Podaj nowy adres email: ";
                        cin >> email;

                        adresaci[i].email = email;

                        cout << "Wprowadzono nowy adres email!";
                        cout << endl;
                        system("pause");

                        break;
                    }
                    else if (wybor == '5')
                    {
                        cout << "Podaj nowy adres: ";
                        cin.sync();
                        getline(cin, adres);

                        adresaci[i].adres = adres;

                        cout << "Wprowadzono nowy adres!";
                        cout << endl;
                        system("pause");

                        break;
                    }
                    else if (wybor == '6')
                        break;
                }
                temp++;

                ZapisDoPlikuPoEdycjiAdresata(adresaci, i, ID);
            }
            i++;
        }

        if (temp == 0)
        {
            cout << "W ksiazce adresowej nie ma osoby o takim nr. ID!" << endl;
            cout << endl;
            system("pause");
        }
    }
    else
    {
        cout << "Ksiazka adresowa jest pusta!" << endl;
        Sleep(2500);
    }
}

void AktualizacjaLiczbyAdresatowWPliku(vector <Adresat> &adresaci, int numerEdytowanegoAdresata, int ID)
{
    vector <Adresat> tymczasowy;
    Adresat tymczasowiAdresaci;

    string linia;
    int i = 0;

    int ile_osob = 0;
    ile_osob = WczytajOsobyZPliku();

    fstream plik;
    plik.open("Adresaci.txt", ios::in);

    if (plik.good() == true)
    {
        while (i < ile_osob)
        {
            getline(plik, linia, '|');
            tymczasowiAdresaci.id = atoi(linia.c_str());
            getline(plik, linia, '|');
            tymczasowiAdresaci.idUzytkownika = atoi(linia.c_str());
            getline(plik, linia, '|');
            tymczasowiAdresaci.imie = linia;
            getline(plik, linia, '|');
            tymczasowiAdresaci.nazwisko = linia;
            getline(plik, linia, '|');
            tymczasowiAdresaci.telefon = linia;
            getline(plik, linia, '|');
            tymczasowiAdresaci.email = linia;
            getline(plik, linia, '|');
            tymczasowiAdresaci.adres = linia;

            tymczasowy.push_back(tymczasowiAdresaci);

            i++;
        }
        plik.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych!" << endl;
        system("pause");
    }

    fstream plikTymczasowy;
    plikTymczasowy.open("Adresaci_tymczasowy.txt", ios::out);

    if (plikTymczasowy.good() == true)
    {
        for (int j = 0; j < ile_osob; j++)
        {
            if (tymczasowy[j].id == ID)
            {
                ;
            }
            else
            {
                plikTymczasowy << tymczasowy[j].id << '|' << tymczasowy[j].idUzytkownika << '|' << tymczasowy[j].imie << '|' << tymczasowy[j].nazwisko << '|' << tymczasowy[j].telefon << '|' << tymczasowy[j].email << '|' << tymczasowy[j].adres << '|' << endl;
            }
        }
        plikTymczasowy.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych!" << endl;
        system("pause");
    }

    UsunieciePliku();
    ZmianaNazwyPliku();
}

int UsunAdresata(vector <Adresat> &adresaci, int iloscOsob)
{
    int ID;
    int i = 0;
    int temp = 0; //zmienna pomocnicza

    char wybor;

    if (iloscOsob != 0)
    {
        cout << "Podaj nr ID adresata, ktorego chcesz usunac: ";
        cin >> ID;

        while (i < iloscOsob)
        {
            if (adresaci[i].id == ID)
            {
                cout << "Czy na pewno chcesz usunac tego adresata? <Wcisnij klawisz 't', aby potwierdzic>: ";
                cin >> wybor;

                if (wybor == 't')
                {
                    adresaci.erase(adresaci.begin() + i);

                    cout << "Usunieto wybranego adresata!" << endl;
                    cout << endl;
                    system("pause");

                    AktualizacjaLiczbyAdresatowWPliku(adresaci, iloscOsob, ID);

                    return iloscOsob - 1;
                }
                temp++;
            }
            i++;
        }

        if (temp == 0)
        {
            cout << "W ksiazce adresowej nie ma osoby o takim nr. ID!" << endl;
        }

        cout << endl;
        system("pause");
    }
    else
    {
        cout << "Ksiazka adresowa jest pusta!" << endl;
        Sleep(2500);
    }
    return iloscOsob;
}

int Logowanie(vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow)
{
    string nazwa, haslo;

    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa;

    int i = 0;

    while (i < iloscUzytkownikow)
    {
        if (uzytkownicy[i].nazwa == nazwa)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "Podaj haslo. Pozostalo prob " << 3 - j << ": ";
                cin >> haslo;

                if (uzytkownicy[i].haslo == haslo)
                {
                    cout << "Zalogowales sie." << endl;
                    Sleep(1000);
                    return uzytkownicy[i].id;
                }
            }

            cout << "Podales 3 razy bledne haslo. Poczeka 3 sekundy przed kolejna proba." << endl;
            Sleep(3000);
            return 0;
        }
        else
            i++;
    }

    cout << "Nie ma uzytkownika z takim loginem!" << endl;
    Sleep(1500);
    return 0;
}

int Rejestracja(vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow)
{
    string nazwa, haslo;

    Uzytkownik nowyUzytkownik;

    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa;

    int i = 0;

    while (i < iloscUzytkownikow)
    {
        if (uzytkownicy[i].nazwa == nazwa)
        {
            cout << "Taki uzytkownik juz istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> nazwa;
            i = 0;
        }
        else
            i++;
    }

    cout << "Podaj haslo: ";
    cin >> haslo;

    nowyUzytkownik.id = iloscUzytkownikow + 1;
    nowyUzytkownik.nazwa = nazwa;
    nowyUzytkownik.haslo = haslo;

    uzytkownicy.push_back(nowyUzytkownik);

    fstream plik;
    plik.open("Uzytkownicy.txt", ios::out | ios::app);

    if (plik.good() == true)
    {
        plik << uzytkownicy[iloscUzytkownikow].id << '|' << uzytkownicy[iloscUzytkownikow].nazwa << '|' << uzytkownicy[iloscUzytkownikow].haslo << endl;
        plik.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych!" << endl;
        system("pause");
    }

    cout << "Konto zalozone!" << endl;
    Sleep(1000);
    return iloscUzytkownikow + 1;
}

vector <Uzytkownik> DodanieUzytkownikaDoWektora(vector <Uzytkownik> &uzytkownicy, int osoby)
{
    Uzytkownik nowyUzytkownik;

    string linia;
    int i = 0;

    fstream plik;
    plik.open("Uzytkownicy.txt", ios::in);

    if (plik.good() == true)
    {
        while (i < osoby)
        {
            getline(plik, linia, '|');
            nowyUzytkownik.id = atoi(linia.c_str());
            getline(plik, linia, '|');
            nowyUzytkownik.nazwa = linia;
            getline(plik, linia, '\n');
            nowyUzytkownik.haslo = linia;
            uzytkownicy.push_back(nowyUzytkownik);
            i++;
        }
        plik.close();
    }
    return uzytkownicy;
}

int WczytajUzytkownikowZPliku()
{
    string linia;
    int nr_linii = 1;
    int ilu_uzytkownikow = 0;

    fstream plik;
    plik.open("Uzytkownicy.txt", ios::in);

    if (plik.good() == true)
    {
        while (getline(plik, linia))
        {
            if (nr_linii >= 1)
            {
                ilu_uzytkownikow++;
                nr_linii = 1;
            }
            else
                nr_linii++;
        }
        plik.close();
    }

    return ilu_uzytkownikow;
}

void ZapisDoPlikuPoZmianieHaslaUzytkownika(vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow)
{
    fstream plik;
    plik.open("Uzytkownicy.txt", ios::out);

    if (plik.good() == true)
    {
        for (int i = 0; i < iloscUzytkownikow; i++)
        {
            plik << uzytkownicy[i].id << '|' << uzytkownicy[i].nazwa << '|' << uzytkownicy[i].haslo << endl;
        }
        plik.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych!" << endl;
        system("pause");
    }
}

void ZmianaHasla(vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow, int idZalogowanegoUzytkownika)
{
    string haslo;
    cout << "Podaj nowe haslo: ";
    cin >> haslo;

    for (int i = 0; i < iloscUzytkownikow; i++)
    {
        if (uzytkownicy[i].id == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].haslo = haslo;
            cout << "Haslo zostalo zmienione!" << endl;
            Sleep(1500);
        }
    }

    ZapisDoPlikuPoZmianieHaslaUzytkownika(uzytkownicy, iloscUzytkownikow);
}

int main()
{
    vector <Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika = 0;
    int iloscUzytkownikow = 0;

    vector <Adresat> adresaci;
    int iloscOsobWKsiazceAdresowej = 0;

    char wybor;

    while (1)
    {
        if (idZalogowanegoUzytkownika == 0)
        {
            uzytkownicy.clear();

            iloscUzytkownikow = WczytajUzytkownikowZPliku();

            if (iloscUzytkownikow > 0)
                uzytkownicy = DodanieUzytkownikaDoWektora(uzytkownicy, iloscUzytkownikow);

            system("cls");
            cout << "1. Logowanie" << endl;
            cout << "2. Rejestracja" << endl;
            cout << "3. Zamknij program" << endl;
            cout << endl;
            cin >> wybor;

            if (wybor == '1')
                idZalogowanegoUzytkownika = Logowanie(uzytkownicy, iloscUzytkownikow);
            else if (wybor == '2')
                iloscUzytkownikow = Rejestracja(uzytkownicy, iloscUzytkownikow);
            else if (wybor == '3')
                exit(0);
        }
        else
        {
            iloscOsobWKsiazceAdresowej = WczytajOsobyZPliku();

            adresaci.clear();

            adresaci = DodanieAdresataDoWektora(adresaci, iloscOsobWKsiazceAdresowej, idZalogowanegoUzytkownika);

            iloscOsobWKsiazceAdresowej = adresaci.size();

            system("cls");
            cout << "1. Dodaj adresata" << endl;
            cout << "2. Wyszukaj po imieniu" << endl;
            cout << "3. Wyszukaj po nazwisku" << endl;
            cout << "4. Wyswietl wszystkich adresatow" << endl;
            cout << "5. Usun adresata" << endl;
            cout << "6. Edytuj adresata" << endl;
            cout << "7. Zmien haslo" << endl;
            cout << "8. Wyloguj sie" << endl;
            cin >> wybor;

            if (wybor == '1')
                iloscOsobWKsiazceAdresowej = DodajAdresata(adresaci, iloscOsobWKsiazceAdresowej, idZalogowanegoUzytkownika);
            else if (wybor == '2')
                WyszukajPoImieniu(adresaci, iloscOsobWKsiazceAdresowej);
            else if (wybor == '3')
                WyszukajPoNazwisku(adresaci, iloscOsobWKsiazceAdresowej);
            else if (wybor == '4')
                WyswietlKsiazkeAdresowa(adresaci, iloscOsobWKsiazceAdresowej);
            else if (wybor == '5')
                iloscOsobWKsiazceAdresowej = UsunAdresata(adresaci, iloscOsobWKsiazceAdresowej);
            else if (wybor == '6')
                EdytujAdresata(adresaci, iloscOsobWKsiazceAdresowej);
            else if (wybor == '7')
                ZmianaHasla(uzytkownicy, iloscUzytkownikow, idZalogowanegoUzytkownika);
            else if (wybor == '8')
                idZalogowanegoUzytkownika = 0;
        }
    }
    return 0;
}
