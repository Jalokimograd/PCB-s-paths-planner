//Znajdowanie œcie¿ek na mikrokontrolerze
//Data 18-01-2019
//Autor: Miko³aj Kowalczewski


#include <iostream>
#include "functions.h"
#include <cstdlib>
#include <time.h>
using namespace std;


bool sw=false;
bool ran=true;
bool spec=true;

// Zmienne
slistEl ** A;                       // Tablica dynamiczna list s¹siedztwa
long long * d;                      // Tablica kosztów dojœcia
int * p;                            // Tablica poprzedników
int m, n;                           // Liczba krawêdzi i wierzcho³ków w grafie
int v1, v2;                         // Wierzcho³ek Ÿród³a i ujœcia
int x, y, z=0, z2=0;                //szerokoœæ, wysokoœæ, liczna pinów wyjœcia, liczba pinów wejœcia
int iterations;


char * tab;                         // Tablica znaków do reprezantacji pseudo-graficznej
int flow=0, cost=0;                 //Dodatkowe zmienne przechowuj¹ce informacje do maksymalnym przep³ywie i jego koszcie

int* Ed1, *Ed2;
int minX, maxX, minY, maxY, minPo, maxPo, minPi, maxPi; //Dodatkowe zmienne do parametryzacji losowania

clock_t timeAlg;    //przechowywanie czasu trwania algorytmu

//_________________________________________________________________FUNKCJA_MAIN______________________________________________
int main(int argc, char ** argv) {
    string parametr;
    for(int i=1; i<argc; ++i){
        parametr = argv[i];
        if(parametr=="-help"){
            cout<<"domyslnie program wczytuje wymiary plytki, ilosc pinow oraz ich wspolrzedne ale sa dodatkowe opcje:"<<endl;
            cout<<"-random - pozwala wykonac zadana ilosc losowych prob"<<endl;
            cout<<"-defIn - pozwala wykonac algorytm dla zdefiniowanych pinow wejsciowych"<<endl;
            cout<<"-spec - Wlacza tryb analizy. Zamiast schematu plytki dostajemy konkretne"<<endl;
            cout<<"        informacje o ilosci wierzcholkow, krawedzi, czasu wykonania itp.\n"<<endl;
            cout<<"Przyklady:"<<endl;
            cout<<".exe -random"<<endl;
            cout<<".exe -defIn"<<endl;
            cout<<".exe -random -defIn"<<endl;
            cout<<".exe -random -spec -defIn"<<endl;
            return 1;
        }
        else if(parametr=="-random") ran=true;
        else if(parametr=="-defIn") sw=true;
        else if(parametr=="-spec") spec=true;
        else return 2;
    }

    switch(ran){
    case false:
        defaultInput(x, y, z, z2, Ed1, Ed2, sw, ran);
        //Inicjowanie zmiennych odpowiednimi wartoœciami
        create(x, y, z, z2, n, m, A, d, p, tab, v1, v2, Ed1, Ed2, sw);

        //Odpowiednie tworzenie krawêdzi grafu
        readEdges(v1, v2, x, y, z, z2, A, tab, Ed1, Ed2, sw);
        //printPCB(x, y, tab, flow, cost);

        //Wyznaczamy najkrótsze œcie¿ki
        //timeAlg = clock();
        minCostFlow(v1, v2, n, x, y, A, flow, cost, tab, p, d, timeAlg);
        //timeAlg = clock() - timeAlg;
        //Wypisywanie w konsoli wyniku
        printPCB(x, y, tab, flow, cost, timeAlg, n, m, spec);

        //Zwalnianie zmiennych dynamicznych
        clearAll(n, A, d, p, tab, Ed1, Ed2, z2, flow, cost);
        break;

    case true:
        srand (time(NULL));
        cout<<"\nMinimalna szerokosc: ";
        cin>>minX; if(minX<3){cout<<"za malo"; return 4;}
        cout<<"\nMaksymalna szerokosc: ";
        cin>>maxX; if(minX>maxX){cout<<"blad danych"; return 4;}
        cout<<"\nMinimalna wysokosc: ";
        cin>>minY; if(minY<3){cout<<"za malo"; return 4;}
        cout<<"\nMaksymalna szerokosc: ";
        cin>>maxY; if(minY>maxY){cout<<"blad danych"; return 4;}
        cout<<"\nMinimalny odsetek pinow wyjsciowych:";
        cin>>minPo; if(minPo<0){cout<<"blad"; return 4;}
        cout<<"\nMaksymalny odsetek pinow wyjsciowych:";
        cin>>maxPo; if(minPo>maxPo || maxPo>100){cout<<"blad danych"; return 4;}
        if(sw==true){
            cout<<"\nMinimalny odsetek pinow wejsciowych:";
            cin>>minPi; if(minPi<0){cout<<"blad"; return 4;}
            cout<<"\nMaksymalny odsetek pinow wejsciowych:";
            cin>>maxPi; if(minPi>maxPi || maxPi>100){cout<<"blad danych"; return 4;}
        }

        cout<<"Ilosc powtorzen: ";
        cin>>iterations;

        while(iterations--) {
            randomInput(x, y, z, z2, Ed1, Ed2, minX, maxX, minY, maxY, minPo, maxPo, minPi, maxPi, sw, ran);
            create(x, y, z, z2, n, m, A, d, p, tab, v1, v2, Ed1, Ed2, sw);
            readEdges(v1, v2, x, y, z, z2, A, tab, Ed1, Ed2, sw);
            //printPCB(x, y, tab, flow, cost, timeAlg, n, m);
            //timeAlg = clock();
            minCostFlow(v1, v2, n, x, y, A, flow, cost, tab, p, d, timeAlg);
            //timeAlg = clock() - timeAlg;
            printPCB(x, y, tab, flow, cost, timeAlg, n, m, spec);
            clearAll(n, A, d, p, tab, Ed1, Ed2, z2, flow, cost);
        }
        break;
    }




    return 0;
}
