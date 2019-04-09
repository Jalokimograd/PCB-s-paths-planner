Miko�aj Kowalczewski 
album: 283681


Specyfikacja problemu:
AAL.11 - Uk�ad �cie�ek na mikrokontrolerze
Potraktowa�em to, jak problem znajdowania najta�szego maksymalnego przep�ywu w grafie


Dodatkowe parametry:
Spos�b wykonania naszego programu kontroluj� trzy zmienne:
sw    - ustawiamy czy chcemy zdefiniowa� wej�cia (false = bez definiowania)
rand  - czy chcemy generowa� dane losowo (nie trzeba wtedy podawa� na wej�cie �adnych danych)
spec  - pozwala wy�wietli� specjalistyczne dane informuj�ce o ilo�ci kraw�dzi, wierzcho�k�w
	albo czasu wykonania

Dane wej�ciowe:
Parametry wykonania mo�na uzyska� podaj�c wywo�uj�c nasz program z: -help 
Tam dowiemy si� �e domy�lnie podajemy takie dane jak w poleceniu zadania, a przy opcjach odpowiednio:
-sw   -	dodatkowo ilo�� pin�w wej�ciowych oraz ich wsp�rz�dne;
-rand -	dodatkowo odpowiednie parametry losowania danych: minimalna szeroko��, maksymalna itp.

Dane wyj�ciowe:
Domy�lnie na wyj�ciu dostaniemy schematycznie narysowany nasz mikrokontroler wraz z utworzonymi
�cie�kami. �cie�ki tworz� odpowiednio znaki: <, ^, >, v. Maj� one za zadanie imitowa� strza�ki, kt�re
wskazuj� kierunek przep�ywu.

Metoda rozwi�zania:
Graf przetrzymywany jest jako lista s�siedztwa. Tworzonych jest (2*x*y + 2) wierzcho�k�w. 
Po dwa na ka�d� kom�rk� powierzchni p�ytki, aby m�c wyrazi� przep�yw przez wierzcho�ek 
oraz wierzcho�ki �r�d�a i uj�cia. �r�d�o jest po��czone albo do wszystkich wierzcho�k�w 
na obrze�ach p�ytki, albo do zdefiniowanych pin�w. Uj�cie ��czy si� do pin�w wyj�ciowych.
Ca�y algorytm zak�ada wyznaczenie najkr�tszej �cie�ki powi�kszaj�cej algorytmem 
Bellmana-Forda ze �r�d�a do uj�cia. Nast�pnie nale�y odwr�ci� kierunki kraw�dzi tworz�cych 
t� �cie�k� oraz zamieni� na przeciwne ich warto�ci. Nast�pnie wyszukujemy kolejne �cie�ki 
powi�kszaj�ce do czasu a� oka�e si�, �e nie uda�o nam si� osi�gn�� uj�cia. B�dzie to 
oznacza�o, �e znale�li�my ju� maksymalny przep�yw o najta�szym koszcie. 

Mierzenie czasu:
Jako i� polecenie zak�ada�o aby znale�� odpowiednie u�o�enie �cie�ek wi�c czas mierzony zaczyna by�
tu� przed rozpocz�ciem i zatrzymywany jest od razu po zako�czeniu algorytmu. Wszelkie operacje zwi�zane
z obliczaniem i tworzeniem grafu na bazie podanych danych nie liczy si� w mierzeniu.

struktura programu:
main.cpp   -		funkcja startowa. Zawieraj� si� tutaj wszystkie globalnie u�ywane zmienne 
			kt�re s� przekazywane za pomoc� referencji;

Implementation.cpp  - 	funkcje zwi�zane z tworzeniem zmiennych dynamicznych, ich kasowaniem, obliczaniem
			istotnych parametr�w takich jak liczba wierzcho�k�w, kraw�dzi, oraz 
			samo tworzenie grafu na podstawie podanych danych;

minCostFlow.cpp	   -  	Funkcja z w�a�ciwym algorytmem projektu. Jako i� algorytm Bellmana-Forda
			modyfikuje struktur� grafu uzna�em �e samo zapisywanie przebiegu �cie�ek
			powinno znajdowa� si� w�a�nie tutaj;

functions.h	-	plik nag��wkowy;

input.cpp	-	funkcja odpowiedzialna za wprowadzanie danych z konsoli w przypadku
			domy�lnego podawania danych, oraz funkcja obliczaj�ca parametry grafu
			przy opcji losowania;

output.cpp	-	funkcja wy�wietlaj�ca odpowiednie informacje.