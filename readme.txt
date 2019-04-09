Miko³aj Kowalczewski 
album: 283681


Specyfikacja problemu:
AAL.11 - Uk³ad œcie¿ek na mikrokontrolerze
Potraktowa³em to, jak problem znajdowania najtañszego maksymalnego przep³ywu w grafie


Dodatkowe parametry:
Sposób wykonania naszego programu kontroluj¹ trzy zmienne:
sw    - ustawiamy czy chcemy zdefiniowaæ wejœcia (false = bez definiowania)
rand  - czy chcemy generowaæ dane losowo (nie trzeba wtedy podawaæ na wejœcie ¿adnych danych)
spec  - pozwala wyœwietliæ specjalistyczne dane informuj¹ce o iloœci krawêdzi, wierzcho³ków
	albo czasu wykonania

Dane wejœciowe:
Parametry wykonania mo¿na uzyskaæ podaj¹c wywo³uj¹c nasz program z: -help 
Tam dowiemy siê ¿e domyœlnie podajemy takie dane jak w poleceniu zadania, a przy opcjach odpowiednio:
-sw   -	dodatkowo iloœæ pinów wejœciowych oraz ich wspó³rzêdne;
-rand -	dodatkowo odpowiednie parametry losowania danych: minimalna szerokoœæ, maksymalna itp.

Dane wyjœciowe:
Domyœlnie na wyjœciu dostaniemy schematycznie narysowany nasz mikrokontroler wraz z utworzonymi
œcie¿kami. Œcie¿ki tworz¹ odpowiednio znaki: <, ^, >, v. Maj¹ one za zadanie imitowaæ strza³ki, które
wskazuj¹ kierunek przep³ywu.

Metoda rozwi¹zania:
Graf przetrzymywany jest jako lista s¹siedztwa. Tworzonych jest (2*x*y + 2) wierzcho³ków. 
Po dwa na ka¿d¹ komórkê powierzchni p³ytki, aby móc wyraziæ przep³yw przez wierzcho³ek 
oraz wierzcho³ki Ÿród³a i ujœcia. ród³o jest po³¹czone albo do wszystkich wierzcho³ków 
na obrze¿ach p³ytki, albo do zdefiniowanych pinów. Ujœcie ³¹czy siê do pinów wyjœciowych.
Ca³y algorytm zak³ada wyznaczenie najkrótszej œcie¿ki powiêkszaj¹cej algorytmem 
Bellmana-Forda ze Ÿród³a do ujœcia. Nastêpnie nale¿y odwróciæ kierunki krawêdzi tworz¹cych 
tê œcie¿kê oraz zamieniæ na przeciwne ich wartoœci. Nastêpnie wyszukujemy kolejne œcie¿ki 
powiêkszaj¹ce do czasu a¿ oka¿e siê, ¿e nie uda³o nam siê osi¹gn¹æ ujœcia. Bêdzie to 
oznacza³o, ¿e znaleŸliœmy ju¿ maksymalny przep³yw o najtañszym koszcie. 

Mierzenie czasu:
Jako i¿ polecenie zak³ada³o aby znaleŸæ odpowiednie u³o¿enie œcie¿ek wiêc czas mierzony zaczyna byæ
tu¿ przed rozpoczêciem i zatrzymywany jest od razu po zakoñczeniu algorytmu. Wszelkie operacje zwi¹zane
z obliczaniem i tworzeniem grafu na bazie podanych danych nie liczy siê w mierzeniu.

struktura programu:
main.cpp   -		funkcja startowa. Zawieraj¹ siê tutaj wszystkie globalnie u¿ywane zmienne 
			które s¹ przekazywane za pomoc¹ referencji;

Implementation.cpp  - 	funkcje zwi¹zane z tworzeniem zmiennych dynamicznych, ich kasowaniem, obliczaniem
			istotnych parametrów takich jak liczba wierzcho³ków, krawêdzi, oraz 
			samo tworzenie grafu na podstawie podanych danych;

minCostFlow.cpp	   -  	Funkcja z w³aœciwym algorytmem projektu. Jako i¿ algorytm Bellmana-Forda
			modyfikuje strukturê grafu uzna³em ¿e samo zapisywanie przebiegu œcie¿ek
			powinno znajdowaæ siê w³aœnie tutaj;

functions.h	-	plik nag³ówkowy;

input.cpp	-	funkcja odpowiedzialna za wprowadzanie danych z konsoli w przypadku
			domyœlnego podawania danych, oraz funkcja obliczaj¹ca parametry grafu
			przy opcji losowania;

output.cpp	-	funkcja wyœwietlaj¹ca odpowiednie informacje.