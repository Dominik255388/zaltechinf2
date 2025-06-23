#ifndef CAR_H
#define CAR_H

#include <string>

struct Car {
    std::string marka;
    int rokProdukcji;
    std::string kolor;
    std::string nrRejestracyjny;
    int przebieg;
};

void dodajSamochod(Car cars[], int &count);
void wyswietlSamochody(const Car cars[], int count);
void zapiszDoPliku(const Car cars[], int count, const std::string& filename);
void wczytajZPliku(Car cars[], int &count, const std::string& filename);
void usunWszystkieSamochody(int &count);

#endif
