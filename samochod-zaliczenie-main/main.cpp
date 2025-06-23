#include <iostream>
#include "car.h"

const std::string PLIK = "samochody.txt";

int main() {
    Car cars[20];
    int count = 0;
    int wybor;

    do {
        std::cout << "\nMENU:\n";
        std::cout << "1. Dodaj samochod\n";
        std::cout << "2. Wyswietl samochody\n";
        std::cout << "3. Zapisz do pliku\n";
        std::cout << "4. Wczytaj z pliku\n";
        std::cout << "5. Usun wszystkie samochody\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                dodajSamochod(cars, count);
                break;
            case 2:
                wyswietlSamochody(cars, count);
                break;
            case 3:
                zapiszDoPliku(cars, count, PLIK);
                break;
            case 4:
                wczytajZPliku(cars, count, PLIK);
                break;
            case 5:
                usunWszystkieSamochody(count);
                break;
            case 0:
                std::cout << "Zamykanie programu.\n";
                break;
            default:
                std::cout << "Nieprawidlowy wybor!\n";
        }

    } while (wybor != 0);

    return 0;
}
