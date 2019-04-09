//Znajdowanie œcie¿ek na mikrokontrolerze
//Data 18-01-2019
//Autor: Miko³aj Kowalczewski


#include "functions.h"
#include <iostream>
using namespace std;
//_________________________________________________________________FUNKCJA_ZAPISUJ¥CA_KRAWÊDZIE___________________
void readEdges(int v1, int v2, int x, int y, int z, int z2, slistEl** & A, char* & tab, int* & Ed1, int* & Ed2, bool sw) {

    //zmienne pomocne
    slistEl *pv;
    int pom1=x*y;
    int i, j;
    bool ch;

    //inicjujemy krawêdzie w³asne. Reguluj¹ one przep³yw przez wêze³
    for(i=0; i<pom1; ++i){
        pv = new slistEl;             //Tworzymy element listy
        pv->v = pom1+i;
        pv->w = 0;
        pv->next = A[i];
        A[i] = pv;
    }
    //inicjujemy pozosta³e krawêdzie
    for(j=pom1, i=0; i<pom1; ++i, ++j){
        if(sw==false) ch=true;
        else ch=false;

        if(i-x>=0) {//do do³u
            pv = new slistEl;             //Tworzymy krawêdŸ miêdzy miêdzy kolejnymi wierzcho³kami na p³ytce
            pv->v = (i-x);
            pv->next = A[j];
            A[j] = pv;
        }
        else if(ch == true){
            pv = new slistEl;             //Tworzymy krawêdŸ miêdzy Ÿród³em a wierzcho³kiem na boku p³ytki
            pv->v = i;
            pv->next = A[v1];
            pv->w = 0;
            A[v1] = pv;
            ch=false;
        }
        //_____________________________________
        if(i+x<pom1) {//do góry
            pv = new slistEl;
            pv->v = (i+x);
            pv->next = A[j];
            A[j] = pv;
        }
        else if(ch == true){
            pv = new slistEl;
            pv->v = i;
            pv->next = A[v1];
            pv->w = 0;
            A[v1] = pv;
            ch=false;
        }
        //_____________________________________
        if((i+1)%x!=0) {//w prawo
            pv = new slistEl;
            pv->v = (i+1);
            pv->next = A[j];
            A[j] = pv;
        }
        else if(ch == true){
            pv = new slistEl;
            pv->v = i;
            pv->next = A[v1];
            pv->w = 0;
            A[v1] = pv;
            ch=false;
        }
        //_____________________________________
        if(i%x!=0) {//w lewo
            pv = new slistEl;
            pv->v = (i-1);
            pv->next = A[j];
            A[j] = pv;
        }
        else if(ch == true){
            pv = new slistEl;
            pv->v = i;
            pv->next = A[v1];
            pv->w = 0;
            A[v1] = pv;
            ch=false;
        }
    }

    //Tworzymy krawêdzie od pinu do ujœcia
    for(int i=0; i<z; i++)
    {
        pv = new slistEl;               //Tworzymy element listy
        pv->v = v2;                     //Inicjujemy go
        pv->w = 0;
        pv->next = A[(Ed2[i]-1)*x + Ed1[i]-1 + pom1];                //Dodajemy go na pocz¹tek listy s¹siadów wierzcho³ka x
        A[(Ed2[i]-1)*x + Ed1[i]-1 + pom1] = pv;
        tab[(Ed2[i]-1)*x + Ed1[i]-1]='o';
    }

    //przypadek zdefiniowanych pinów
    if(sw==true){
        for(int i=z; i<z+z2; i++)
        {
            pv = new slistEl;
            pv->v = (Ed2[i]-1)*x + Ed1[i]-1;
            pv->w = 0;
            pv->next = A[v1];
            A[v1] = pv;
        }
    }
}

void clearAll(int n, slistEl** & A, long long* & d, int* & p, char* & tab, int* & Ed1, int* & Ed2, int & z2, int & flow, int & cost) {
    slistEl *rv, *pv;
    z2=0;
    flow=0;
    cost=0;
    //Usuwamy struktury dynamiczne
    for(int i = 0; i < n; i++){
        pv = A[i];
        while(pv){
            rv = pv;
            pv = pv->next;
            delete rv;
        }
    }
    delete [] A;
    delete [] d;
    delete [] p;
    delete [] tab;
    delete [] Ed1;
    delete [] Ed2;
}


void create(int & x, int & y, int & z, int & z2, int & n, int & m, slistEl** & A, long long * & d, int* & p, char* & tab, int & v1, int & v2, int* & Ed1, int* & Ed2, bool sw) {
    //Obliczamy iloœæ wierzcho³ków
    n = (x*y*2) + 2;
    //Obliczamy iloœæ krawêdzi
    if(x>2 && y>2) {
        m = (x*y) + 8 + 2*(x+y-4)*3 + (x-2)*(y-2)*4 + z;

        if(sw) m += z2;
        else m += 2*(x+y)-4;
    }

    A = new slistEl * [n];          //Tworzymy tablicê list s¹siedztwa
    d = new long long [n];          //Tworzymy tablicê kosztów dojœcia
    p = new int [n];                //Tworzymy tablice poprzedników
    tab = new char[n-2];


    for(int i=0; i<x*y; ++i) {
        tab[i] = '.';
    }


    for(int i = 0; i < n; i++) {     //Inicjujemy struktury danych
        d[i] = MAXINT;
        p[i] = -1;
        A[i] = NULL;
    }

    v1 = n-2;
    v2 = v1+1;
}
