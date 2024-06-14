// CMPS1232 Principles of Programming 2
// Program Set 1 - Hangman Game
// Date Due: 2024-04-21
// Name: Andres Hung

// main.cpp

// IMPORTANT: there is an issue when compiling using QT Creator and the ahpset1-hangman.pro project file
// on the UB school computers The build process hangs half-way through. To fix that,
// simply make an edit to the ahpset1-hangman.pro file e.g. # remove a comment
// then the build process will work. Afterward, remove the edit and the build should succeed again.

// IMPORTANT: the wordlist.txt file must be located in the project root directory

// NOTES
// 1. Hangman class's alphabetArray data member does NOT need to be ALPHABET_SIZE + 1. It can introduce errors.
// 2. Player class's guessesArray data member uses 0 to indicate no value, but 0 is a valid value in a
//    perfect game of HANGMAN where there were no wrong letter guesses.
// 3. Both Hangman and Player classes redundantly have difficultyLevel and maxAllowedAttempts data members.

#include <iostream>
#include "Hangman.h"

int main() {
    // use a preprocessor directive to clear screen for both Windows and Unix/Linux systems
    // https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
    // https://learn.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=msvc-170
    #if defined(_WIN32)
        std::system("cls"); // for Windows
    #else
        std::system("clear"); // for Unix/Linux
    #endif

    std::cout << "[CMPS1232] HANGMAN GAME by Andres Hung for Program Set 1\n";

    std::cout << "Enter a username (19 character max): ";
    std::string username{};

    // use std::getline for string input, std::ws is used to ignore whitespace
    // https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
    std::getline(std::cin >> std::ws, username);

    Hangman game{"wordlist.txt", username};
    game.startGame();

    return 0;
}
