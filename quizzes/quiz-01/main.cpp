#include <iostream>

int getGrade(int gradeNumber);
std::size_t getTallyIndex(int grade);
char getTallyLetter(std::size_t tally);
void printTally(int tally[], std::size_t length);

int main() {
    const int gradesCount{10};
    const std::size_t tallyCount{5};
    int tally[tallyCount] {};

    std::cout << "Grade Tally Program [" << gradesCount << " grades]\n";

    for (int i{0}; i < gradesCount; ++i) {
        ++tally[getTallyIndex(getGrade(i + 1))];
    }

    std::cout << "\nGrade Tally Results\n";
    printTally(tally, tallyCount);

    std::cout << std::endl;

    return 0;
}

int getGrade(int gradeNumber) {
    std::cout << '[' << gradeNumber << "] Enter grade: ";
    int grade;
    std::cin >> grade;

    return grade;
}

std::size_t getTallyIndex(int grade) {
    if (grade <= 100 && grade >= 90) {
        return 0;
    } else if (grade < 90 && grade >= 80) {
        return 1;
    } else if (grade < 80 && grade >= 70) {
        return 2;
    } else if (grade < 70 && grade >= 60) {
        return 3;
    } else {
        return 4;
    }
}

char getTallyLetter(std::size_t tallyIndex) {
    switch (tallyIndex) {
        case 0:
            return 'A';
        case 1:
            return 'B';
        case 2:
            return 'C';
        case 3:
            return 'D';
        default:
            return 'F';
    }
}

void printTally(int tally[], std::size_t length) {
    for (std::size_t i{0}; i < length; ++i) {
        std::cout << "The number of " << getTallyLetter(i) << " - " << tally[i] << '\n';
    }
}
