#include <iostream>
#include <fstream>
#include "LiczbaZespolona.hh"
#include "WyrazenieZespolone.hh"
#include "Statystyka.hh"

#define PROBY 3

using namespace std;

int main(int argc, char **argv){
    
    LZ wynik, lz_user; // struktury przechoujace liczby zespolone, lz1 lz2- argumenty pobrane z pliku
    // lz_user- liczba zespolona podana przez użytkownika
    WZ wyrazenie; // struktura przechowujaca wczytane wyrazenie zespolone
    ST stat; // struktura do przechowywania wyników testu
    int Prb;

    ifstream input(argv[1]);
    if(input.fail()){
        cerr<<"Blad: nie podano prawidlowego pliku"<<endl;
        return -1;
    }
    
    input>>wyrazenie;

    while (!input.eof()){
        
        if(input.bad()){
            cerr<<"Blad odczytu ";
            return -1; }

        if(input.fail()&&!input.eof()) cout<<"Bledne wyrazenie "<<endl;
        else{
            if(!modul_kwadrat(wyrazenie.LiczbaZesp2)&&(wyrazenie.Oper=O_Dz)) cout<<"Bledne wyrazenie"<<endl;
            else{
                cout<<"Podaj wynik wyrazenia: "<<wyrazenie<<endl;
                // zadanie pytania uzytkownikowi

                cin>>lz_user; // pierwsza proba podania odpowiedzi (chodzi o forme)
                Prb=1; // ustawienie zmiennej pomocniczej na wartosc 1
            
                while ((Prb<PROBY)&&(cin.fail())) // petla bedzie wykonywana maks 3 razy, do momentu
                //,w ktorym uzytkownik programu poda odpowiedz w poprawnej formie
                {
                    cin.clear(); // zresetowanie flag, z poprzednich prob/proby
                    cout<<"Bledna odpowiedz, podaj jeszcze raz"<<endl;
                    cin>>lz_user; 
                    ++Prb; // po pobraniu liczby zwiekaszamy licznik o jeden
                }

                if(!cin.fail()) cout<<lz_user<<endl; // jezeli po danej ilosci prob uzytkownik poda
                // poprawna forme liczby zespolonej- odpowiedz bedzie wyswietlona
                else{
                    cout<<"Blad, odpowiedz falszywa"<<endl; //w przypadku, gdy dopuszczalna liczba prob zostanie
                    ++stat.Falsz;}// przekroczona, zamiast pobranej liczby zostanie wyświetlony komunikat
                
                cin.clear();

                if(Wynik(wyrazenie, wynik)){
                    cout<<"Wynik wyrazenia: "<<wynik<<endl;
                    if(wynik==lz_user) cout<<":-) Odpowiedz poprawna "<<endl;
                    else cout<<":-( Odpowiedz falszywa"<<endl;
                    PorownanieStatystyka(stat,(wynik==lz_user));
                }
                else cerr<<"Bledne wyrazenie, zostanie ono pominiete"<<endl;
            }
        }

        input.clear();
        input>>wyrazenie;
    }

    cout<<stat;
    cout<<"Koniec pytan!!!"<<endl;
    
    return 0;
    
}
