//Znajdowanie œcie¿ek na mikrokontrolerze
//Data 18-01-2019
//Autor: Miko³aj Kowalczewski


#include "functions.h"
#include <iostream>
#include <time.h>
using namespace std;
//_________________________________________________________________FUNKCJA_WYPISUJ¥CA_SCHHEMAT_ŒCIE¯EK_______________________________
void printPCB(int x, int y, char* & tab, int& flow, int& cost, clock_t & timeAlg, int n, int m, bool spec) {
    int i, j;

    if(spec==false)
        for(j=(y-1); j>=0; --j) {
            for(i=0; i<x; ++i) {
                cout<<" "<<tab[j*x + i];
            }
            cout<<endl;
        }

    else {
    cout<<"laczny koszt:        "<<cost<<endl;
    cout<<"przeplyw:            "<<flow<<endl;
    cout<<"liczba wierzcholkow: "<<n<<endl;
    cout<<"liczba lrawedzi:     "<<m<<endl;
    cout<<"czas wykonania:      "<<timeAlg<<endl;

    double t = (((double)n*m*flow)/10000)/timeAlg;
    cout<<"zaleznosc czasu (l.wierzcholkow * l.krawedzi * przeplyw)/(czas wykonania*10000): "<<t<<endl;
    }
    cout<<"_____________________________________________________________________________"<<endl;

}
