#include "car.h"
#include <iostream>
#include <fstream>

const int MAX_CARS = 20;

void dodajSamochod(Car cars[], int &count) {
    if (count >= MAX_CARS) {
        std::cout << "Osiagnieto maksymalna liczbe samochodow.\n";
        return;
    }

    Car c;
    std::cout << "Podaj marke: ";
    std::cin >> c.marka;
    std::cout << "Podaj rok produkcji: ";
    std::cin >> c.rokProdukcji;
    std::cout << "Podaj kolor: ";
    std::cin >> c.kolor;
    std::cout << "Podaj numer rejestracyjny: ";
    std::cin >> c.nrRejestracyjny;
    std::cout << "Podaj przebieg: ";
    std::cin >> c.przebieg;

    cars[count++] = c;
}

void wyswietlSamochody(const Car cars[], int count) {
    if (count == 0) {
        std::cout << "Brak samochodow do wyswietlenia.\n";
        return;
    }

    for (int i = 0; i < count; ++i) {
        std::cout << i + 1 << ". " << cars[i].marka << ", "
                  << cars[i].rokProdukcji << ", "
                  << cars[i].kolor << ", "
                  << cars[i].nrRejestracyjny << ", "
                  << cars[i].przebieg << " km\n";
    }
}

void zapiszDoPliku(const Car cars[], int count, const std::string& filename) {
    std::ofstream plik(filename);
    for (int i = 0; i < count; ++i) {
        plik << cars[i].marka << " "
             << cars[i].rokProdukcji << " "
             << cars[i].kolor << " "
             << cars[i].nrRejestracyjny << " "
             << cars[i].przebieg << "\n";
    }
    plik.close();
    std::cout << "Dane zapisane do pliku.\n";
}

void wczytajZPliku(Car cars[], int &count, const std::string& filename) {
    std::ifstream plik(filename);
    count = 0;
    while (plik >> cars[count].marka
                >> cars[count].rokProdukcji
                >> cars[count].kolor
                >> cars[count].nrRejestracyjny
                >> cars[count].przebieg) {
        ++count;
        if (count >= MAX_CARS) break;
    }
    plik.close();
    std::cout << "Dane wczytane z pliku.\n";
}

void usunWszystkieSamochody(int &count) {
    count = 0;
    std::cout << "Wszystkie samochody zostaly usuniete.\n";
}
