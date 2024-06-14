#ifndef CITY_H
#define CITY_H


#include <string>
#include <iostream>

class City {
public:
    City(const std::string& newCityName = "", int newPopulation = 0);
    void setCityName(const std::string& newCityName);
    std::string getCityName() const;
    void setPopulation(int newPopulation);
    int getPopulation() const;
    void printDetails(std::ostream& output) const;
private:
    char cityname[30];
    int population;
};

#endif // CITY_H
