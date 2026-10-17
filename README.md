# Laboratorium 01 - Klasy, obiekty i enkapsulacja

**Programowanie obiektowe · 2026/2027**

## Po co ta praca?

Zaprojektujesz zachowanie prostego obiektu `Car` w **C++ i Java**. Nauczysz się odróżniać klasę od obiektu, odczytywać stan i zmieniać go przez metody, które pilnują reguł.

**Enkapsulacja (hermetyzacja)** oznacza ukrycie szczegółów reprezentacji i kontrolowanie dostępu do stanu. Prywatne pola są jednym z narzędzi. Najważniejsze jest to, że obiekt chroni swoje reguły - na przykład przebieg nie może maleć.

**Forma:** indywidualna.  
**Zakres obowiązkowy:** C++ i Java.  
**Czas orientacyjny:** dwa zajęcia po 90 minut, przy działającym środowisku z Lab00.  
**Oddanie:** repozytorium przypisane do zadania w Classroom 50.

Po ukończeniu potrafisz:

- wskazać klasę, obiekt, pole, konstruktor i metodę;
- utworzyć dwa obiekty o niezależnym stanie;
- zastosować `private` i `public`;
- odróżnić getter od operacji zmieniającej stan;
- odrzucić niepoprawną operację bez zmiany obiektu;
- uruchomić gotowe testy i znaleźć przyczynę FAIL;
- pracować przez branch, commit, push i Pull Request.

Nie używamy jeszcze dziedziczenia, polimorfizmu, ręcznej alokacji pamięci ani wzorców projektowych. Konstruktor służy tutaj do prostej inicjalizacji.

## Przygotowanie

Użyj Git, kompilatora C++17 oraz **JDK 17+** skonfigurowanych w Lab00. Testy są gotowe, działają bez Maven, Gradle, JUnit i dodatkowych bibliotek C++.

1. Przyjmij assignment przez link Classroom 50.
2. Otwórz własne repozytorium utworzone dla tego assignmentu.
3. Sklonuj je i utwórz gałąź:

```bash
git clone <HTTPS_URL_TWOJEGO_REPOZYTORIUM>
cd <NAZWA_KATALOGU>
git remote -v
git switch -c lab01-implementation
```

Zastąp wartości `<...>` rzeczywistymi wartościami. `origin` ma wskazywać Twoje repozytorium zadania. Nie twórz dodatkowej kopii przez **Use this template** i nie otwieraj PR do szablonu prowadzącego.

## Pliki

| Plik | Rola | Czy edytujesz? |
|---|---|---|
| `cpp/Car.hpp` | deklaracja klasy i prywatne pola | zachowaj publiczny interfejs; możesz dodać prywatne pomocniki |
| `cpp/Car.cpp` | implementacja C++ | tak |
| `cpp/main.cpp` | demonstracja obiektów | tak |
| `java/Car.java` | klasa Java | tak, zachowaj publiczny interfejs |
| `java/Main.java` | demonstracja obiektów | tak |
| `cpp/tests/car_tests.cpp`, `java/tests/CarTests.java` | gotowe testy zachowania | nie |
| `STUDENT.md` | krótkie odpowiedzi i wyniki | tak |
| `.github/workflows/check.yml` | automatyczna kompilacja i testy | nie |

Szablon zawiera celowo nieukończone metody z `TODO`. **Kompilacja powinna się udać, ale część testów początkowo pokaże FAIL.** To punkt startowy, a nie problem konfiguracji. Po wykonaniu pracy oba zestawy testów mają wypisać `Failed: 0`.

---

## Zadanie 1 - Klasa i dwa obiekty

Przeczytaj deklaracje `Car`. W obu językach obiekt przechowuje:

- markę (`make`);
- model (`model`);
- rok produkcji (`year`);
- przebieg w całych kilometrach (`mileage`).

W C++ nazwy prywatnych pól mają końcowe `_`, aby odróżnić je od parametrów.

Uzupełnij konstruktor i gettery. Konstruktor zapisuje przekazane markę, model i rok, a przebieg ustawia na **0**. Wszystkie pola są prywatne i należą do konkretnego obiektu. Nie zamieniaj ich na `static`.

**Założenie tego ćwiczenia:** dane przekazane do konstruktora są poprawne: marka i model mają co najmniej jeden znak inny niż biały, rok jest z zakresu 1886–2026. Obsługę błędów konstrukcji omówimy później. Nie musisz pisać wyjątków.

W demo są już dwa różne samochody. Po ukończeniu implementacji sprawdź ich początkowy stan.

## Zadanie 2 - Obliczenie bez zmiany stanu

Zaimplementuj `getAge(currentYear)`:

- jeżeli `currentYear >= year`, zwróć `currentYear - year`;
- jeżeli podany rok jest wcześniejszy niż rok produkcji, zwróć **-1**;
- nie zmieniaj pól obiektu.

Przykłady dla auta z 2020 roku:

| Wywołanie | Wynik |
|---|---|
| `getAge(2026)` | 6 |
| `getAge(2020)` | 0 |
| `getAge(2019)` | -1 |

Używamy jawnie podanego roku, a nie zegara systemowego. Wynik testów będzie powtarzalny.

## Zadanie 3 - Enkapsulacja i kontrolowana zmiana

### Zmiana nazwy modelu

Zaimplementuj `renameModel(newModel)`:

- poprawny tekst zawiera co najmniej jeden znak inny niż spacja, tabulator, `\r` lub `\n`;
- poprawna operacja zapisuje dokładnie przekazany tekst i zwraca `true`;
- pusty tekst albo tekst złożony wyłącznie z tych białych znaków jest odrzucany;
- Java dodatkowo odrzuca `null`;
- odrzucona operacja zwraca `false` i pozostawia poprzedni model.

Nie trzeba usuwać spacji z początku lub końca tekstu ani obsługiwać wszystkich białych znaków Unicode.

### Jazda zamiast dowolnego settera

Zaimplementuj `drive(distance)`:

- `distance` jest dodatnią liczbą całkowitą kilometrów;
- po poprawnej operacji przebieg zwiększa się o `distance`, metoda zwraca `true`;
- zero i wartości ujemne są odrzucane;
- w uproszczonym modelu maksymalny przebieg wynosi **1 000 000 km**;
- jeżeli nowy przebieg przekroczyłby limit, odrzuć operację;
- każde odrzucenie zwraca `false` i nie zmienia przebiegu.

Wskazówka: sprawdzaj `distance > 1000000 - mileage` przed dodawaniem. Nie musisz dodawać osobnej obsługi przepełnienia.

Nie dodawaj `setMileage`, `setYear` ani `setMake`. Marka i rok są niezmienne przez publiczny interfejs, a przebieg rośnie wyłącznie w wyniku poprawnej jazdy. **Nie każde prywatne pole powinno mieć setter.**

## Zadanie 4 - Demonstracja i niezależność obiektów

Uzupełnij oba programy demonstracyjne:

1. Utwórz dwa różne obiekty.
2. Zmień model i zwiększ przebieg pierwszego.
3. Wypisz stan obu, pokazując, że drugi się nie zmienił.
4. Spróbuj wykonać `drive(-50)` i wypisz wynik operacji oraz przebieg przed i po próbie.
5. Spróbuj zmienić model na pusty tekst i pokaż, że zachowano poprzednią nazwę.

Oczekiwany fragment dla pierwszego obiektu:

```text
Toyota Corolla Touring | year=2020 | age=6 | mileage=120
Honda Civic | mileage=0
```

Dokładny format dodatkowych komunikatów jest dowolny. Testy sprawdzają zachowanie klasy, a nie tekst demo.

---

## Zadanie 5 - Kompilacja i gotowe testy

Wykonuj polecenia **z katalogu głównego repozytorium**. Po każdej zmianie skompiluj kod ponownie. Jeśli kompilacja się nie udała, nie uruchamiaj starego pliku jako dowodu poprawności nowej wersji.

### Linux / WSL / macOS

```bash
mkdir -p build/cpp build/java
g++ -std=c++17 -Wall -Wextra -Wpedantic cpp/Car.cpp cpp/main.cpp -o build/cpp/demo
g++ -std=c++17 -Wall -Wextra -Wpedantic cpp/Car.cpp cpp/tests/car_tests.cpp -o build/cpp/tests
./build/cpp/demo
./build/cpp/tests
javac -encoding UTF-8 --release 17 -d build/java java/Car.java java/Main.java java/tests/CarTests.java
java -cp build/java Main
java -cp build/java CarTests
```

### Windows PowerShell

```powershell
New-Item -ItemType Directory -Force -Path build/cpp, build/java
g++ -std=c++17 -Wall -Wextra -Wpedantic cpp/Car.cpp cpp/main.cpp -o build/cpp/demo.exe
g++ -std=c++17 -Wall -Wextra -Wpedantic cpp/Car.cpp cpp/tests/car_tests.cpp -o build/cpp/tests.exe
./build/cpp/demo.exe
./build/cpp/tests.exe
javac -encoding UTF-8 --release 17 -d build/java java/Car.java java/Main.java java/tests/CarTests.java
java -cp build/java Main
java -cp build/java CarTests
```

Każdy test wypisuje `PASS` albo `FAIL` i nazwę scenariusza. Na końcu otrzymasz liczbę błędów. Niezerowa liczba oznacza również niezerowy kod zakończenia programu, który GitHub Actions rozpoznaje jako niepowodzenie.

Testy obejmują inicjalizację, wiek, poprawne i odrzucone operacje, zachowanie stanu, limit przebiegu i niezależność obiektów. **Uruchamiasz gotowe testy; nie musisz pisać własnego frameworka ani nowych testów.**

Znajdź jeden FAIL podczas implementacji. Opisz jego przyczynę i poprawkę w `STUDENT.md`. Nie wyłączaj testów i nie zmieniaj ich oczekiwań.

Zielone testy potwierdzają sprawdzone scenariusze. 

## Zadanie 6 - Pull Request, Actions i oddanie

Zapisuj logiczne etapy pracy, np. inicjalizacja, operacje, demo. Nie ma wymaganej liczby commitów.

```bash
git status
git diff
git add cpp/Car.hpp cpp/Car.cpp cpp/main.cpp java/Car.java java/Main.java STUDENT.md
git diff --staged
git commit -m "Implement Car with encapsulated state in C++ and Java"
git push -u origin lab01-implementation
```

Otwórz PR **we własnym repozytorium**:

```text
base: main
compare: lab01-implementation
```

Tytuł: `Lab01: klasy i enkapsulacja`. Uzupełnij opis PR oraz `STUDENT.md` (link do PR możesz dopisać kolejnym commitem).

Otwórz **Actions → Lab01 checks** albo sekcję checks w PR. Workflow ma dwa zadania:

- **C++17 - build and tests**;
- **Java17 - build and tests**.

W każdym znajdziesz osobne kroki kompilacji, demo i testów. Przy FAIL popraw implementację lokalnie, sprawdź ją i wykonaj kolejny commit oraz push. Początkowe czerwone wyniki są oczekiwane dla nieukończonego szablonu; finalny wynik powinien być zielony.

Po poprawnej kontroli scal PR, chyba że prowadzący wymaga przeglądu przed scaleniem. Następnie:

```bash
git switch main
git pull --ff-only origin main
git status
```

Finalna wersja ma znajdować się na `main` Twojego repozytorium assignmentu. Nie wysyłaj osobnego ZIP jako pracy studenckiej. Jeśli Actions są niedostępne z powodu ustawień organizacji - nie zmieniaj workflow, aby ukryć problem.

## Lista kontrolna

- [ ] Pracuję we właściwym repozytorium Classroom 50.
- [ ] Obie implementacje `Car` mają prywatne pola.
- [ ] Konstruktor i gettery działają.
- [ ] `getAge` nie zmienia stanu.
- [ ] Niepoprawna zmiana modelu zachowuje poprzedni model.
- [ ] `drive` chroni przebieg i jego limit.
- [ ] Demo pokazuje niezależność dwóch obiektów i odrzucone operacje.
- [ ] Oba zestawy testów wypisują `Failed: 0`.
- [ ] STUDENT.md jest uzupełniony.
- [ ] Zmiany są wysłane na GitHub; finalny PR jest scalony zgodnie z instrukcją prowadzącego.
- [ ] Finalne Actions są zielone lub problem dostępności uzgodniono z prowadzącym.
- [ ] Pliki z `build/` nie trafiły do Git.

## Kryterium zaliczenia i krótka obrona

Wymagana jest poprawna implementacja w obu językach, wykonane demo, przechodzące dostarczone testy, krótkie odpowiedzi i umiejętność wyjaśnienia kodu. 

Przygotuj się do odpowiedzi:

1. Czym różni się klasa od obiektu?
2. Jaką regułę chroni `drive` i dlaczego `setMileage` byłby ryzykowny?
3. Dlaczego getter nie łamie automatycznie enkapsulacji?
4. Co oznacza `private`, a co `public`?
5. Jak pokażesz, że zmiana jednego obiektu nie zmienia drugiego?
6. Co daje `const` przy getterach C++? Dlaczego w Java nie zapisujemy tego tak samo?

## Zadanie dodatkowe - Parrot

Po ukończeniu części obowiązkowej możesz utworzyć `Parrot` z prywatnym polem `phrase`, konstruktorem, getterem i `changePhrase` odrzucającym pusty tekst. Utwórz dwie papugi i pokaż niezależność ich stanu. Bez losowania, list i dziedziczenia. Zadanie nie jest wymagane do zaliczenia i nie jest sprawdzane przez dostarczone Actions.

## Typowe problemy

| Problem | Co sprawdzić |
|---|---|
| `javac` nie znaleziono | potrzebujesz JDK, nie tylko JRE; sprawdź PATH |
| C++: undefined reference | kompiluj razem `Car.cpp` i plik demo albo testów |
| Java: cannot find symbol Car | kompiluj pliki razem poleceniem powyżej |
| FAIL po zmianie | skompiluj ponownie, przeczytaj nazwę scenariusza i kontrakt metody |
| testy przeszły, demo jest niepełne | demo i odpowiedzi oceniane są również przez prowadzącego |
| Actions nie uruchamiają się | prowadzący sprawdza politykę organizacji i dostępność Actions |

## Dokumentacja

- [Java — klasy i obiekty](https://dev.java/learn/classes-objects/)
- [Java — kontrola dostępu](https://dev.java/learn/classes-objects/more-on-classes/)
- [C++ — klasy](https://en.cppreference.com/w/cpp/language/classes.html)
