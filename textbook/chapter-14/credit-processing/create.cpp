#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ClientData.h"

int main() {
    std::ofstream outCredit{"../credit.dat", std::ios::out | std::ios::binary};

    if (!outCredit) {
        std::cerr << "File could not be opened." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    ClientData blankClient;

    for (int i{0}; i < 100; ++i) {
        outCredit.write(reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));
    }

    return 0;
}
