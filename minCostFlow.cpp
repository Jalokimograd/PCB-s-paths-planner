//Znajdowanie ścieżek na mikrokontrolerze
//Data 18-01-2019
//Autor: Mikołaj Kowalczewski


#include "functions.h"
#include <iostream>
using namespace std;
//_________________________________________________________________FUNKCJA_SZUKAJ¥CA_NAJTAÑSZY_MAKSYMALNY_PRZEP£YW___________________
void minCostFlow(int v1, int v2, int n, int x, int y, slistEl** & A, int & flow, int & cost, char* & tab, int* & p, long long* & d, clock_t & timeAlg) {
    int i, j;
    slistEl *rv, *pv;
    bool test;
    int pom=x*y;
    clock_t timeAlg1 = 0;

    while(1) {
        //W³aœciwa forma algorytmu Bellmana-Forda


        timeAlg1 = clock();

        for(i=0; i<n; i++)
            d[i] = MAXINT;

        d[v1] = 0;
        p[v1] = -1;                      //Ustawiamy poprzednika


        for(i=1, test=false; (i<n) && test!=true; ++i) {      //Pêtla relaksacji
            test=true;                              //Oznacza, ¿e algorytm nie wprowadzi³ zmian do d i p
            for(j=0; j<n; ++j)                      //Przechodzimy przez kolejne wierzcho³ki grafu
                for(pv = A[j]; pv; pv = pv->next)   //Przegl¹damy listê s¹siadów wierzcho³ka x
                    if(d[pv->v] > d[j] + pv->w) {   //Sprawdzamy warunek relaksacji
                    test=false;
                    d[pv->v] = d[j] + pv->w;        //Relaksujemy krawêdŸ z x do jego s¹siada
                    p[pv->v] = j;                   //Poprzednikiem s¹siada bêdzie x
                    }
        }
        timeAlg = clock() - timeAlg1 + timeAlg;
        //Je¿eli oka¿e siê ¿e koszt dotarcia do ujœcia bêdzie równy MAXINT
        //to znaczy ¿e nie uda³o siê znaleŸæ nowej drogi wiêc zosta³
        //ju¿ osi¹gniêty maksymalny przep³yw

        if(d[v2] == MAXINT) break;


        //Zapisywanie do tablicy kolejnych wyznaczonych ścieżek wraz z modyfikacją już istniejących
        for(i=p[p[p[p[v2]]]], j=p[p[v2]]; i!=-1; i=p[p[i]], j=p[p[j]]) {
            if(tab[i]!='o'){
                if(j==i+1) tab[i]='>';
                else if(j==i-1) tab[i]='<';
                else if(j==i+x) tab[i]='^';
                else if(j==i-x) tab[i]='v';
            }
            if((p[j]-pom)!=j && (p[j]-pom!=i && tab[p[j]-pom]!='o')){
                if(j==p[j]-pom+1) tab[p[j]-pom]='>';
                else if(j==p[j]-pom-1) tab[p[j]-pom]='<';
                else if(j==p[j]-pom+x) tab[p[j]-pom]='^';
                else if(j==p[j]-pom-x) tab[p[j]-pom]='v';
            }
        }

        //Po ka¿dym obiegu algorytmu Bellmana-Forda nastêpuje sumowanie ca³kowitego
        //przep³ywu i kosztu z nim zwi¹zanego
        flow++;
        cost += d[v2];
        j = v2;
        //Teraz musimy zmieniæ kierunki krawêdzi i zamieniæ ich wagi na przeciwne
        while(j!=v1) {
            //cout<<"x = "<<x<<endl;
            i = p[j];
            pv=A[i];
            if(pv->v == j) A[i] = pv->next;

            else {
                while(pv->next->v != j) pv = pv->next;
                //Poprawnie przypinamy krawêdŸ
                rv = pv->next;
                pv->next = pv->next->next;
                pv = rv;
            }

            pv->v = i;
            pv->next = A[j];
            A[j] = pv;
            pv->w *= -1;
            j=i;
        }
    }
}
