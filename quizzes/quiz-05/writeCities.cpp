#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "City.h"

void readCities();
void recordCities();

int main() {
    recordCities();

    return 0;
}

void readCities() {
    std::ifstream iFile{"binfile.txt", std::ios::in | std::ios::binary};

    City city;
    iFile.read(reinterpret_cast<char *>(&city), sizeof(City));
    while (!iFile.eof()) {
        city.printDetails(std::cout);
        iFile.read(reinterpret_cast<char *>(&city), sizeof(City));
    }

    iFile.close();
}

void recordCities() {
    std::fstream file{"binfile.txt", std::ios::out | std::ios::binary};

    if (!file) {
        std::cerr << "binfile.txt could not be opened." << std::endl;
        std::exit(1);
    }

    City city;
    char choice{'n'};

    std::string cityName;
    int cityPopulation;

    do {
        std::cout << "Enter city name: ";
        std::getline(std::cin >> std::ws, cityName);
        std::cout << "Enter " << cityName << "'s population: ";
        std::cin >> cityPopulation;

        city.setCityName(cityName);
        city.setPopulation(cityPopulation);

        file.write(reinterpret_cast<const char*>(&city), sizeof(City));

        std::cout << "\nEnter another city? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    file.close();

    readCities();
}
