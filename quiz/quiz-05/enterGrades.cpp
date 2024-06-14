#include <iostream>
#include <fstream>
#include <cstdlib>

void studentProcess();

int main() {
    studentProcess();

    return 0;
}

void studentProcess() {
    std::ofstream oStudent{"student.txt", std::ios::out};

    if (!oStudent) {
        std::cerr << "student.txt could not be opened." << std::endl;
        std::exit(1);
    }

    const int numberOfStudents{10};

    int studentId;
    int grade1;
    int grade2;
    int grade3;

    for (int i{0}; i < numberOfStudents; ++i) {
        std::cout << '[' << i + 1 << "] Enter Student ID and three grades (each separated by a space): ";
        std::cin >> studentId >> grade1 >> grade2 >> grade3;

        oStudent << studentId << ' ' << grade1 << ' ' << grade2 << ' ' << grade3 << '\n';
    }

    std::cout << "\nStudents and grades have been entered into students.txt" << std::endl;
    oStudent.close();
}
