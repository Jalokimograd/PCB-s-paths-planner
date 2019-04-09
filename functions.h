//Znajdowanie œcie¿ek na mikrokontrolerze
//Data 18-01-2019
//Autor: Miko³aj Kowalczewski
//___________________________________________________________________________________________________________________

#include <time.h>
// Najwiêksza liczba ca³kowita. Zak³adamy ¿e to nieskoñczonoœæ
const int MAXINT = 2147483647;


//Graf w postaci listy s¹sziedztwa
struct slistEl {
  slistEl * next;
  int v, w=1;
};



void readEdges(int v1, int v2, int x, int y, int z, int z2, slistEl** & A, char* & tab, int* & Ed1, int* & Ed2, bool sw);
void clearAll(int n, slistEl** & A, long long* & d, int* & p, char* & tab, int* & Ed1, int* & Ed2, int & z2, int & flow, int & cost);
void create(int & x, int & y, int & z, int & z2, int & n, int & m, slistEl** & A, long long * & d, int* & p, char* & tab, int & v1, int & v2, int* & Ed1, int* & Ed2, bool sw);

void minCostFlow(int v1, int v2, int n, int x, int y, slistEl** & A, int & flow, int & cost, char* & tab, int* & p, long long* & d, clock_t & timeAlg);

void defaultInput(int & x, int & y, int & z, int & z2, int* & Ed1, int* & Ed2, bool sw, bool ran);
void randomInput(int & x, int & y, int & z, int & z2, int* & Ed1, int* & Ed2, int & minX, int & maxX, int & minY, int & maxY, int & minPo, int & maxPo, int & minPi, int & maxPi, bool sw, bool ran);

void printPCB(int x, int y, char* & tab, int& flow, int& cost, clock_t & timeAlg, int n, int m, bool spec);
