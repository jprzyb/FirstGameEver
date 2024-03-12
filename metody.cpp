#include <iostream>
#include <fstream>
#include "klasy.h"
#include <windows.h>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

    string imiep()
    {
        srand(time(NULL));
        int a=rand()%17;

        switch(a)
        {
            case 1: return "Remek";break;
            case 2: return "Zdzisiek";break;
            case 3: return "Maciek";break;
            case 4: return "Gacus";break;
            case 5: return "Wladek";break;
            case 6: return "Mr. Immortal";break;
            case 7: return "Zebra";break;
            case 8: return "Alfa";break;
            case 9: return "Omega";break;
            case 10: return "Mrs. Devil";break;
            case 11: return "Jarek";break;
            case 12: return "Szynek";break;
            case 13: return "Minato";break;
            case 14: return "Ola";break;
            case 15: return "Abi";break;
            case 16: return "Ember";break;
            case 17: return "Guzy";break;
        }
    }

    void Potwor::pobierz()
    {
        ifstream plik;
        plik.open("exp.txt");

        plik>>hp>>atak;

        plik.close();
    }

    void Potwor::wypisz()
    {
        string imie=imiep();
        cout<<"Imie\t| "<<imie<<"\t|"<<endl;
        cout<<"HP\t| "<<hp<<"\t|"<<endl;
        cout<<"DMG\t| "<<atak<<"\t|"<<endl;
    }

    void Potwor::zapisz()
    {
        ofstream plik;
        plik.open("exp.txt");

        plik<<hp<<endl<<atak;

        plik.close();
    }

    void Postac::pobierz()
    {
        ifstream plik;
        plik.open("postac.txt");

        getline(plik,imie);
        plik>>hp>>atak>>gold;

        plik.close();
    }
    void Postac::zapisz()
    {
        ofstream plik;
        plik.open("postac.txt");

        plik<<imie<<endl<<hp<<endl<<atak<<endl<<gold;

        plik.close();
    }

    void Postac::wypisz()
    {
        cout<<"Nazwa postaci: "<<imie<<endl<<endl;
        cout<<"HP\t| "<<hp<<"\t|"<<endl;
        cout<<"DMG\t| "<<atak<<"\t|"<<endl;
        cout<<"gold\t| "<<gold<<"\t|"<<endl;
    }
