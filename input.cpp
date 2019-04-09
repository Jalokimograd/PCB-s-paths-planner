//Znajdowanie œcie¿ek na mikrokontrolerze
//Data 18-01-2019
//Autor: Miko³aj Kowalczewski


#include "functions.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>


using namespace std;


void defaultInput(int & x, int & y, int & z, int & z2, int* & Ed1, int* & Ed2, bool sw, bool ran) {

    cout<<"wymiary: ";
    cin>>x>>y;
    if(x<3 || y<3) {cout<<"za mala plytka. Liczenie nie ma sensu"; exit;}
    cout<<"ilosc pinow: ";
    cin>>z;
    if(sw==true){
        cout<<"ilosc pinow wejsciowych: ";
        cin>>z2;
    }

    Ed1 = new int[z+z2];
    Ed2 = new int[z+z2];

    cout<<"Piny wyjsciowe: "<<endl;
    for(int i=0; i<z; i++) {
        cin>>Ed1[i]>>Ed2[i];                  //Czytamy wspó³rzêdne pinu x y
    }

    //przypadek zdefiniowanych pinów
    if(sw==true){
        cout<<"Piny wejsciowe: "<<endl;
        for(int i=z; i<z+z2; i++) {
            cin>>Ed1[i]>>Ed2[i];                  //Czytamy wspó³rzêdne pinu x y
        }
    }
}

void randomInput(int & x, int & y, int & z, int & z2, int* & Ed1, int* & Ed2, int & minX, int & maxX, int & minY, int & maxY, int & minPo, int & maxPo, int & minPi, int & maxPi, bool sw, bool ran) {


    x = rand()% (maxX-minX+1) + minX;
    y = rand()% (maxY-minY+1) + minY;
    z = rand()% (x*y*(maxPo-minPo)/100) + minPo;
    if(sw==true){
        z2 = rand() % (x*y*(maxPi-minPi+1)/100) + minPi;
    }

    Ed1 = new int[z+z2];
    Ed2 = new int[z+z2];

    for(int i=0; i<z; i++) {
        Ed1[i] = rand() % x+1;
        Ed2[i] = rand() % y+1;                  //Losujemy wspó³rzêdne pinu x y
    }

    //przypadek zdefiniowanych pinów
    if(sw==true){
        int los;
        for(int i=z; i<z+z2; i++) {
            los = rand()%4;
            switch(los) {
            case 0:
                Ed1[i] = 1;
                Ed2[i] = rand() % y+1;
                break;
            case 1:
                Ed1[i] = x;
                Ed2[i] = rand() % y+1;
                break;
            case 2:
                Ed1[i] = rand() % x+1;
                Ed2[i] = 1;
                break;
            default:
                Ed1[i] = rand() % x+1;
                Ed2[i] = y;
                break;
            }
        }
    }
}
