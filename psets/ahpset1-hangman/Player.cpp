// CMPS1232 Principles of Programming 2
// Program Set 1 - Hangman Game
// Date Due: 2024-04-21
// Name: Andres Hung

// Player Class Implementation

#include "Player.h"
#include <iomanip> // std::fixed, std::setprecision
#include <sstream> // std::ostringstream

Player::Player(const std::string& username, unsigned int level) { // NOLINT(*-pro-type-member-init)
    setUsername(username);
    setDifficultyLevel(level);
    resetGuessesArray();
}

void Player::setDifficultyLevel(unsigned int level) {
    // ensure level is in valid range
    difficultyLevel = (level >= 1 && level <= MAX_DIFFICULTY_LEVEL) ? level : 1;
}

int Player::getDifficultyLevel() const {
    return static_cast<int>(difficultyLevel);
}

void Player::setUsername(const std::string& name) {
    std::size_t length{name.length()};

    // truncate name if it exceeds username's 19-character limit
    // one space in the char username[20] must be '\0'
    if (length > 19) {
        length = 19;
    }

    for (std::size_t i{0}; i < length; ++i) {
        username[i] = name[i];
    }

    // append the null terminating character
    username[length] = '\0';
}

std::string Player::getUsername() {
    return username;
}

void Player::setGuesses(unsigned int numGuesses) {
    for (std::size_t i{0}; i < 10; ++i) {
        // if there is an available space in the array, assign score and return
        if (guessesArray[i] == 0) {
            guessesArray[i] = static_cast<int>(numGuesses);
            return;
        }
    }

    // if there is no available space, reset array and assign first score
    resetGuessesArray();
    guessesArray[0] = static_cast<int>(numGuesses);
}

std::string Player::generateStatistics() {
    // initial string for appending scores and average
    std::string statString{"Guesses:"};

    // keep track of total and count in order to calculate average
    int count{0};
    double total{0};

    // appends each score to the string while keeping track of count and total
    for (std::size_t i{0}; guessesArray[i] != 0 && i < 10; ++i) {
        statString += ' ' + std::to_string(guessesArray[i]);
        total += guessesArray[i];
        ++count;
    }

    // also check if count is 0
    double average{count ? (total / count) : 0};

    // use ostringstream to set the precision of average in string concatenation
    // https://www.learncpp.com/cpp-tutorial/stdstring-construction-and-destruction/
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(1) << average;

    statString += "\n\nAverage Guesses: ";
    statString += stream.str();

    return statString;
}

void Player::resetGuessesArray() {
    for (std::size_t i{0}; i < 10; ++i) {
        guessesArray[i] = 0;
    }
}