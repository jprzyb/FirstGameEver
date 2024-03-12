//Jakub Przybylski 15.04.2021r. p2w1
#include <iostream>
#include "klasy.h"
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <fstream>
using namespace std;

void kontynuuj()
{
    cout<<endl<<"Nacisnij [ENTER] aby kontynowac"<<endl;
    getch(); system("CLS");
}

void statystyki(int z)
{
    int wygr,przegr,w_boss,p_boss,lacznie;
    ifstream odczyt;
    odczyt.open("statystyki.txt"); odczyt>>wygr>>przegr>>w_boss>>p_boss>>lacznie; odczyt.close();

    if(z==1) {wygr++; lacznie++;}
    else if(z==0) {przegr++; lacznie++;}
    else if(z==2) {p_boss++; lacznie++;}
    else if(z==3) {w_boss++; lacznie++;}

    ofstream zapis;
    zapis.open("statystyki.txt"); zapis<<wygr<<endl<<przegr<<endl<<w_boss<<endl<<p_boss<<endl<<lacznie; zapis.close();
}

void nazwa_reset()
{
    Potwor potwor; potwor.pobierz();
    Postac postac; postac.pobierz();

    string nazwa;
    cout<<"Podaj nowa nazwe swojego bohatera(zatwierdz klawiszem [ENTER]): "; getline(cin, nazwa);

    //zapisanie nowej nazwy
    ofstream zapisuj;
    zapisuj.open("postac.txt");
    zapisuj<<nazwa<<endl<<postac.atak<<endl<<postac.hp<<endl<<postac.gold;
    zapisuj.close();
}

void reset_reset()
{
            system("CLS");
            ofstream plik1, plik2, plik3, plik4;
            plik1.open("exp.txt"); plik1<<30<<endl<<30; plik1.close(); cout<<"Zresetowano 25%"<<endl; Sleep(500);
            plik2.open("postac.txt"); plik2<<"Brak nazwy"<<endl<<30<<endl<<30<<endl<<0; plik2.close(); cout<<"Zresetowano 50%"<<endl; Sleep(500);
            plik3.open("ekonomia.txt"); plik3<<10<<endl<<10; plik3.close();cout<<"Zresetowano 75%"<<endl; Sleep(500);
            plik4.open("statystyki.txt"); plik4<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0; plik4.close();cout<<"Zresetowano 99%"<<endl; Sleep(500);
            cout<<"Zapis"<<endl;
            cout<<"Ukonczono 100%!"; kontynuuj();
}

void reset()
{
    char x;
    cout<<"Czy napewno chcesz zresetowac swoje dane?"<<endl<<"1. Tak"<<endl<<"2. Nie"; x=getch();
    switch(x)
    {
        case '1':
        {
            reset_reset();

            char y;
            cout<<"Czy chcesz zmienic nazwe postaci? "<<endl<<"1. TAK"<<endl<<"2. NIE"; y=getch();
            switch(y)
            {
            case '1':
                {
                    system("CLS");
                    nazwa_reset();
                    break;
                }
            }

            break;
        }
        default: cout<<endl<<"Resetowanie nie powiodlo sie!"; kontynuuj(); break;
        system("CLS");
        kontynuuj();
    }
}

void sprawdz_ulepszenie()
{
    Postac postac; postac.pobierz();
    if(postac.gold < 0)
    {
        ofstream zapis("postac.txt");
        zapis<<postac.imie<<endl<<postac.atak<<endl<<postac.hp<<endl<<0;
    }
}

int ulepszanie()
{
    Postac postac;  postac.pobierz();

    ifstream od;
    od.open("ekonomia.txt");
    int cena_hp,cena_atak;
    od>>cena_hp>>cena_atak;
    od.close();

        system("CLS");
        cout<<"=====Co chcesz ulepszyc?=====\t\t\t\t\t(masz "<<postac.gold<<" golda)"<<endl;
        cout<<"1. +10 HP za "<<cena_hp<<" golda"<<endl;
        cout<<"2. +10 DMG za "<<cena_atak<<" golda"<<endl;
        cout<<"3. Aby wyjsc do menu "<<endl;

        char n;
        cout<<"Wybierz: "; n=getch();

            switch(n)
            {
                case '1':
                    {
                        if(postac.gold - cena_hp >= 0)
                        {
                            cout<<"Zakup powiodl sie! Masz teraz "<<postac.hp+10<<" HP!\t\t\t\t\t (trwa zapis)"<<endl;

                            int cena=postac.gold - cena_hp;
                            //zapis nowych statystyk postaci
                            ofstream pos;
                            pos.open("postac.txt");
                            pos<<postac.imie<<endl<<postac.atak<<endl<<postac.hp + 10<<endl<<cena; pos.close();

                            //zapis nowych statystyk ekonomi
                            ofstream zap;
                            zap.open("ekonomia.txt");
                            zap<<cena_hp + 10<<endl<<cena_atak;
                            zap.close();

                            kontynuuj();
                        }
                        else {cout<<"Za malo srodkow :c"<<endl; kontynuuj();}

                        return 0;

                        break;
                    }
                case '2':
                    {
                        if(postac.gold - cena_atak >=0)
                        {
                            postac.gold-=cena_atak;
                            cout<<"Zakup powiodl sie! Masz teraz "<<postac.atak + 10<<" DMG!\t\t\t\t\t (trwa zapis)"<<endl;

                            int cena=postac.gold - cena_atak;
                            //zapis nowych statystyk postaci
                            ofstream pos;
                            pos.open("postac.txt");
                            pos<<postac.imie<<endl<<postac.atak + 10<<endl<<postac.hp<<endl<<cena; pos.close();

                            //zapis nowych statystyk ekonomii
                            ofstream zap;
                            zap.open("ekonomia.txt");
                            zap<<cena_hp<<endl<<cena_atak + 10;
                            zap.close();

                            kontynuuj();
                        }
                        else {cout<<"Za malo srodkow :c"<<endl; kontynuuj();}

                        return 0;

                        break;
                    }
                case '3':
                    {
                        return 1; break;
                    }

            default: cout<<"Niepoprawny wybor!"<<endl; kontynuuj(); return 0; break;
    }
    sprawdz_ulepszenie();

}

void spojnosc()
{
    ifstream spr1,spr2,spr3,spr4;

//sprawdzenie czy pliki istnieja
    spr1.open("exp.txt"); spr2.open("postac.txt"); spr3.open("ekonomia.txt");spr4.open("statystyki.txt");
    if(!spr1.good() || !spr2.good() || !spr3.good() ||!spr4.good() )
    {
        cout<<endl<<"Wystapila niespojosc w plikach (normalne przy pierwszym uruchomieniu)"<<endl<<endl; Sleep(2000);
        cout<<"RESETOWANIE"; Sleep(1000); reset_reset();

    }
    spr1.close(); spr2.close(); spr3.close(); spr4.close();
}

void walka_boss()
{
    Potwor potwor;
    Postac postac;
    potwor.pobierz();
    postac.pobierz();

    int potwor_hp = potwor.hp*5, potwor_atak = potwor.atak/5;
    int postac_hp = postac.hp, postac_atak = postac.atak;

    cout<<"===== BOSS ====="<<endl;
    potwor.wypisz(); cout<<endl;
    cout<<"===== POJEDYNEK ====="<<endl;
    for(int i=0 ; ; i++)
    {
        Sleep(1000);
        cout<<"===Kolejka "<<i+1<<". === ";

        if(i%2==0)
        {
            potwor_hp-=postac_atak;
            cout<<"\tAtakujesz z sila: "<<postac_atak<<"DMG, a bossowi zostaje "<<potwor_hp<<" HP!"<<endl<<endl;
        }

        if(i%2==1)
        {
            postac_hp-=potwor_atak;
            cout<<"\tBOSS atakuje z z sila: "<<potwor_atak<<" DMG, a tobie zostaje "<<postac_hp<<" HP!"<<endl<<endl;
        }

//PRZEGRANA
        if(postac_hp <= 0)
        {
            cout<<endl<<"\t\t\t\t===========================\n\t\t\t\tPRZEGRALES STARCIE W "<<i+1<<". kolejce :c\n\t\t\t\t==========================="<<endl;

            //OSLABIANIE POTWORA
            ofstream pot;
            pot.open("exp.txt");
            pot<<potwor.hp - 10<<endl<<potwor.atak - 5;
            pot.close();

            statystyki(2);
            Sleep(500);
            break;

        }
//WYGRANA
        else if(potwor_hp <= 0)
        {
            cout<<"\t\t\t\t===========================\n\t\t\t\t   WYGRALES STARCIE W "<<i+1<<". kolejce!\n\t\t\t\t==========================="<<endl;

            //zapis postaci
            ofstream pos;
            pos.open("postac.txt");
            pos<<postac.imie<<endl<<postac.atak<<endl<<postac.hp<<endl<<postac.gold+100;
            pos.close();

            statystyki(3);
            Sleep(500); break;
        }
    }
}

void walka_exp()
{
    Potwor potwor;
    Postac postac;
    potwor.pobierz();
    postac.pobierz();

    int potwor_hp=potwor.hp, potwor_atak=potwor.atak;
    int postac_hp=postac.hp, postac_atak=postac.atak;

    cout<<"===== PRZECIWNIK ====="<<endl;
    potwor.wypisz(); cout<<endl;
    cout<<"===== WALKA ====="<<endl;
    for(int i=0 ; ; i++)
    {
        Sleep(1000);
        cout<<"|||Kolejka "<<i+1<<". ||| ";

        if(i%2==0)
        {
            potwor_hp-=postac_atak;
            cout<<"\tAtakujesz z sila: "<<postac_atak<<"DMG, a przecikowi zostaje "<<potwor_hp<<" HP!"<<endl<<endl;
        }

        if(i%2==1)
        {
            postac_hp-=potwor_atak;
            cout<<"\tPotwor atakuje z z sila: "<<potwor_atak<<" DMG, a tobie zostaje "<<postac_hp<<" HP!"<<endl<<endl;
        }

//PRZEGRANA
        if(postac_hp <= 0)
        {
            cout<<endl<<"\t\t\t\t===========================\n\t\t\t\tPRZEGRALES w "<<i+1<<". kolejce :c\n\t\t\t\t==========================="<<endl<<"\t\t\t\tUlepsz swoja postac w menu!\n\t\t\t\t==========================="<<endl;

            //OSLABIANIE POTWORA
            ofstream pot;
            pot.open("exp.txt");
            pot<<potwor.hp - 10<<endl<<potwor.atak - 5;
            pot.close();

            statystyki(0);
            Sleep(500);
            break;

        }
//WYGRANA
        else if(potwor_hp <= 0)
        {
            cout<<"\t\t\t\t===========================\n\t\t\t\t   WYGRALES w "<<i+1<<". kolejce!\n\t\t\t\t==========================="<<endl;

            //zapis potwora
            ofstream pot;
            pot.open("exp.txt");
            pot<<potwor.hp + 10<<endl<<potwor.atak + 5;
            pot.close();

            //zapis postaci
            ofstream pos;
            pos.open("postac.txt");
            pos<<postac.imie<<endl<<postac.atak<<endl<<postac.hp<<endl<<postac.gold+50;
            pos.close();

            statystyki(1);
            Sleep(500); break;
        }
    }
}

void walka()
{
    ifstream odczyt; odczyt.open("statystyki.txt"); int x;
    for(int i=0;i<5;i++)
    {
        odczyt>>x;//cout<<"|"<<x; Sleep(1000);
    }
    odczyt.close();

    if(x == 0)walka_boss();
    else if( x%10 != 0) walka_exp();

    kontynuuj();
}

void menu()
{
    char n;
    Potwor potwor; potwor.pobierz();
    Postac postac; postac.pobierz();

    cout<<"=====MENU====="<<endl;
    cout<<"1. Wyswietl swoja postac"<<endl;
    cout<<"2. Walka!"<<endl;
    cout<<"3. Zapisz gre"<<endl;
    cout<<"4. Ulepsz postac"<<endl;
    cout<<"5. Zmien nazwe"<<endl;
    cout<<"6. Restart/Pierwsze uruchomienie"<<endl;
    cout<<"7. Wyjdz z gry"<<endl;
    cout<<endl<<endl<<"Wybierz: "; n=getch(); system("CLS");

    switch(n)
    {
        case '1':
            {
                cout<<"===== TWOJ BOHATER ====="<<endl;
                postac.wypisz();

                //wczytywanie statystyk
                ifstream staty;
                staty.open("statystyki.txt");
                int wygrane,przegrane,w_b,p_b,lacznie;
                staty>>wygrane>>przegrane>>w_b>>p_b>>lacznie;
                staty.close();

                //wypisywanie statystyk
                cout<<endl<<"===== STATYSTYKI WALK ====="<<endl;
                cout<<"Wygrane \t|"<<wygrane<<"\t|"<<endl;
                cout<<"Przegrane \t|"<<przegrane<<"\t|"<<endl;
                cout<<"Wygrane boss \t|"<<w_b<<"\t|"<<endl;
                cout<<"Przegrane boss \t|"<<p_b<<"\t|"<<endl;
                cout<<"Lacznie wygrane \t|"<<lacznie<<"\t|"<<endl;

                kontynuuj();
                break;
            }
        case '2':
            {
                walka();
                break;
            }
        case '3':
            {
                potwor.zapisz();
                postac.zapisz();
                cout<<"Pomyslnie zapisano!"<<endl;
                kontynuuj();
                break;
            }
        case '4':
            {
                for( ; ; )
                {
                    if(ulepszanie()==1) break;
                }
                break;
            }
        case '5':
            {
                nazwa_reset(); break;
            }
        case '6':
            {
                reset();
                break;
            }
        case '7':
            {
                cout<<"\n\n\t\t\t\t\t\tDO ZOBACZENIA!";
                Sleep(1500);
                exit(0);
                break;
            }
        case '+':
            {
                postac.wypisz();
                cout<<endl;
                potwor.wypisz();
                cout<<endl;

                ifstream e; int ee; e.open("ekonomia.txt");
                e>>ee; cout<<"ekonomia: "<<ee<<" ; "; e>>ee; cout<<ee; e.close();

                e.open("statystyki.txt");
                e>>ee; cout<<endl<<"wygrane: "<<ee<<endl<<"przegrane: "; e>>ee; cout<<ee;
                e>>ee; cout<<endl<<"wygrane_boss: "<<ee<<endl<<"przegrane_boss: "; e>>ee; cout<<ee; e.close();

                kontynuuj();
                break;
            }
        default:
            {
                cout<<"Blad!"<<endl; Sleep(250);
                break;
            }
    }
}

int main()
{
    cout << "===========START!==========="<<endl<<endl;
    spojnosc();
    for( ; ; )
    {
        menu();
        system("CLS");
    }

    return 0;
}
