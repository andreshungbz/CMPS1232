// CMPS1232 Principles of Programming 2
// Program Set 1 - Hangman Game
// Date Due: 2024-04-21
// Name: Andres Hung

// Player Class Header

// where appropriate, std::string parameters are made l-value references to const
// to avoid expensive string class copying

#ifndef AHPSET1_HANGMAN_PLAYER_H
#define AHPSET1_HANGMAN_PLAYER_H


#include <string>

class Player {
public:
    // constructor that sets the username and difficultyLevel
    explicit Player(const std::string& username, unsigned int level = 1); // explicit avoids single-argument implicit conversions

    // setter for difficultyLevel that validates range
    void setDifficultyLevel(unsigned int level);

    // getter for difficultyLevel
    int getDifficultyLevel() const;

    // setter for username with character limit validation
    void setUsername(const std::string& name);

    // getter for username
    std::string getUsername();

    // function that adds a game score to guessesArray
    void setGuesses(unsigned int numGuesses);

    // function that returns a string with game scores and average
    std::string generateStatistics();

    // function that sets all values in guessesArray to 0
    void resetGuessesArray();

private:
    int guessesArray[10]; // keeps track of the 10 most recent game scores
    char username[20]; // player's username
    unsigned int difficultyLevel; // chosen game difficulty
    static const unsigned int MAX_DIFFICULTY_LEVEL{3}; // maximum difficulty available
};


#endif //AHPSET1_HANGMAN_PLAYER_H
