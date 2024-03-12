#include <iostream>
#include <string>
using namespace std;

class Potwor
{
public:

    int hp;
    int atak;

    void pobierz();
    void wypisz();
    void zapisz();
};

class Postac
{
public:

    int hp;
    int atak;
    string imie;
    int gold;

    void pobierz();
    void wypisz();
    void zapisz();

};
