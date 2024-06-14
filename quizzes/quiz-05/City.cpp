#include "City.h"

City::City(const std::string& newCityName, int newPopulation) {
    setCityName(newCityName);
    setPopulation(newPopulation);
}

void City::setCityName(const std::string& newCityName) {
    std::size_t length{newCityName.length()};
    length =(length < 30 ? length : 29);
    newCityName.copy(cityname, length);
    cityname[length] = '\0';
}

std::string City::getCityName() const {
    return cityname;
}

void City::setPopulation(int newPopulation) {
    population = newPopulation;
}

int City::getPopulation() const {
    return population;
}

void City::printDetails(std::ostream& output) const {
    output << getCityName() << ' ' << getPopulation() << '\n';
}
