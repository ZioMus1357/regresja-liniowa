# Regresja liniowa
Autorzy : Piotr Kumala, Dawid Górka, Dawid Łączek

## Założenia wstępne przyjęta w realizacji projektu
Program powinien mieć możliwość dodania punktów z klawiatury oraz z pliku .txt. Wyświetlenia wyliczonej krzywej regresji na wykresie, zmianę kolorów tła wykresu oraz punktów. Wyświetlenie informacji o regresji tj. jej parametrów oraz błędu w dodatkowym ruchomym oknie.
## Specyfikacja danych wejściowych
Dane wejściowe stanowią punktu o współrzędnych (x,y) podane z klawiatury lub z pliku .txt

## Opis oczekiwanych danych wyjściowych
Dane wyjściowe stanowią:
1. Współczynniki regresji liniowej a,b
2. Błąd regresji liniowej
3. Narysowana krzywa regresji liniowwej

## Zdefiniowane struktury danych
Musieliśmy zdefiniować klase `Container` przechowująca informacje o regresji. Oraz klase `ConfigClass` służącą do configuracji wykresu.
Wykorzystaliśmy napisane przez prowadzącego klasy `Vector` oraz `Matrix` służące do transformacji wykresu.
## Specyfikacja interfejsu Użytkownika
Użytkownik ma możliwośc za pomocą menu:
1. Dodania punktu bezpośrednio z klawiatury
2. Dodania punktów podając plik .txt którego schemat jest przedstawiony w pliku test.txt. 
3. Zapisania wykresu do pliku .jpg
4. Skopiowanie wykresu do schowka

Korzystając z menu po prawej stronie można:
1. Zmienić kolor wykresu, domyślnie jest ustawiony na biały,
2. Zmienieć kolor punktów, domyślnie jest ustawiony kolor oliwkowy
3. Zmienić skale wykresu
4. Zmienić wielkość punktów, domyślnie 1
5. Zmienić styl punktów, do wyboru okrąd oraz prostokąt.
6. Włączenie słupków błędów
7. Zmienienie pozycji ramki z informacjami odnośnie regresji, pierwszy suwak odpowiada za położenie na osi X zaś drugi na osi Y

## Wyodrębnienie i zdefiniowanie zadań
Harmonogram pracy:
1. Szkielet programu
2. Rysowanie osi + skalowanie
3. Implementacja wyboru kolorow
4. Implementacja wyboru wielkości punktów i ich rodzajów
5. Implementacja słupków błędów
6. Implementacja ramki z informacjami oraz jest przesuwanie
7. Implementacja możliwości dodawania danych z klawiatury oraz z pliku tekstowego
8. Implementacja zapisu do pliku oraz kopiowanie do schowka

## Decyzja o wyborze narzędzi programistycznych
Do realizacji projektu wybraliśmy biblioteke wxWidgets, ponieważ jest ona relatywnie łatwa oraz większość funkcji potrzebnych do realizacji projektu została napisana na zajęciach. Do kompilacji zostało użyte Microsoft Visual Studio. Zdecydowaliśmy się głownie na to środowisko ze względu na korzystanie z systemu operacyjnego Windows.
## Podział pracy i analiza czasowa
Większość projektu zrobiliśmy wspólnie, zostawiają testowanie oraz poprawki na późniejszą date.Staraliśmy się postaępować według ustalonego harmonogramu pracy aby nie kompliwować pisania projektu. Ciężko jest określić określić dokładny czas przeznaczony na wykonanie projektu, w przybliżeniu napisanie wszystkiego zajeło nam ponad 24 godziny.
## Opracowanie i opis niezbędnych algorytmów
Algorytm obliczania parametrów regresji liniowej:

Wyznaczenie współczynników regresji liniowej sprowadza się do wyznaczenia śrdniej wartości współrzędnych x oraz y podanych punktów. Następnie w celu wyznacznia współczynnika a obliczamy sumę iloczynu różnic kolejnych wartośći x i średniej wartośći punktów x oraz kolejnych wartośći y i sredniej wartości punktów y, podzielonych przez kwadrat różnicy kolejnych punktów x średniej wartości punktów x.  
![](https://latex.codecogs.com/png.latex?%24%24a%3D%5Cfrac%7B%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%28X_i-%5Coverline%7BX%7D%29%28Y_i-%5Coverline%7BY%7D%29%7D%7B%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%28X_i-%5Coverline%7BX%7D%29%5E2%7D%24%24)  
Współcztnnik b jest różnicą średniej wartośći współrzędnych y oraz iloczynu współcztnnika a i średniej wartości współrzędnych x.  
![](https://latex.codecogs.com/png.latex?%24%24b%3D%5Coverline%7BY%7D-a%5Coverline%7BX%7D%24%24)  

Wzór na błąd standardowy oszacowania w regresji liniowe:

Wyznaczamy wartości kolejnych niestandarzyowanych błędów predykcji w modelu regresji dla każdej pary współrzędnych x i y, obliczając różnice wartości współrzędnej y oraz sumy iloczynu współczynnika b i wartości współrzędnej x oraz współczynnika a.  
![](https://latex.codecogs.com/png.latex?e_i%3Dy-%28bx&plus;a%29)  
Błąd standardowy oszacowania w regresji liniowej jest równy pierwiastowy z sumy wszystkich wartości niestandarzyowanych błędów predykcji, podniesionych do kwadratu oraz podzielony przez ilość punktów zmniejszoną o ilość parametrów czyli 2.  
![](https://latex.codecogs.com/png.latex?%24%24S_%7Be%7D%3D%5Csqrt%7B%5Cfrac%7B%5Csum_%7Bi%3D1%7D%5E%7Bn%7De_%7Bi%7D%5E%7B2%7D%7D%7Bn-2%7D%7D%24%24)  

Algorytm obliczania parametrów regresji nieliniowej:

Obliczamy wartości sum współrzędnych x podniesionych do kolejnych potęg począwszy od 0 do 2m, gdzie m to stopien wielomianu, który chcemy uzyskać.  
![](https://latex.codecogs.com/png.latex?%24%24%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5Ek%24%24), dla k=0, 1, 2, ..., 2m  
Następnie obliczamy sumy iloczynów wpsółrzędnych y oraz x podniesionych do kolejnych potęg od 0 do m.  
![](https://latex.codecogs.com/png.latex?%24%24%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dy_%7Bi%7Dx_%7Bi%7D%5Ek%24%24), dla k=0, 1, 2, ..., m  
Z otrzymanych sum układamy równiania.  
![](https://latex.codecogs.com/png.latex?%24%24a_%7B0%7Dn&plus;a_%7B1%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D&plus;a_%7B2%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E2&plus;...&plus;a_%7Bm%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E%7Bm%7D%3D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dy_%7Bi%7D%24%24%20%5C%5C%20%24%24a_%7B0%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D&plus;a_%7B1%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E2&plus;a_%7B2%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E3&plus;...&plus;a_%7Bm%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E%7Bm&plus;1%7D%3D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7Dy_%7Bi%7D%24%24%20%5C%5C%20%24%24a_%7B0%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E2&plus;a_%7B1%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E3&plus;a_%7B2%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E4&plus;...&plus;a_%7Bm%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E%7Bm&plus;2%7D%3D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E2y_%7Bi%7D%24%24%20%5C%5C%20%5C%5C%20%24%24...%24%24%5C%5C%20%5C%5C%20%24%24a_%7B0%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E%7Bm%7D&plus;a_%7B1%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E%7Bm&plus;1%7D&plus;a_%7B2%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E%7Bm&plus;2%7D&plus;...&plus;a_%7Bm%7D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E%7B2m%7D%3D%5Csum_%7Bi%3D1%7D%5E%7Bn%7Dx_%7Bi%7D%5E%7Bm%7Dy_%7Bi%7D%24%24)  
Mamy m+1 niewiadomych oraz tyle samo równań liniowych. Rozwiązujemy je metodą elimminacji Gaussa otrzumując wartości poszczególnych współczynników wilomianu interpolacyjnego.

## Kodowanie
Zamplimentowaliśmy następujące klasy:
* `MyApp` dziędzicząco po `wxApp` potrzbną do uruchomienia programu
* `MyFrame1` dziedziczącą po `wxFrame` wygenerowaną za pomocą programu wxFormBuilder stanowiąca szkielet całego programu
* `GUIMyFrame1` dziedzicąco po `MyFrame1` implementującą zachowania wszystkich przycisków
* `ChartClass` implementującą wykres , punkty oraz ich właściwości
* `ConfigClass` implementująca właściwości możliwe do zmiany przez użytkownika
* `DataWindow` dziedzicące po `wxFrame` implementujące okno dodawania punktów z klawiatury
* `Container` zawierająca parametry regresji

Dokumentacja dotycząca metod oraz zmiennych znajduję się plikach `.h`.
Wykorzystaliśmy również dostarczoną przez prowadzącego na zajęciach klase `Vector` oraz `Matrix`.
## Testowanie
W związku z tych że duża większość funkcji nie zwracała nic a funkcje które zwracały cokolwiek były zbyt proste aby wykonywać na nich testy jednostkowe, Nie zaimplementowaliśmy tego rodzaju testów. Dokomaliśmy testów UI prosząc kolege ze studiów o przetestowanie naszej aplikacji
Uzyskaną krzywą regresji liniowej porównaliśmy z krzywą uzyskaną za pomocą programu LibreCalc dla takich samych danych wejściowych. Porównawcze zdjęcia znajdują się w repozytorium. Parametry regresji liniowej są sobie.  
<img src="https://github.com/ZioMus1357/gfk/blob/master/wykresy/wykres_libre_office.png" alt="alt text" width="420" height="400">
<img src="https://github.com/ZioMus1357/gfk/blob/master/wykresy/wykres_our.jpg" alt="alt text" width="420" height="400">  
Po lewej stonie znjaduję się prosta regresji wygenerowana za pomocą programu LibreCalc wraz z parametrami, natomiast po prawej prosta wygenerowana przy pomocy naszego programu również z parametrami.
