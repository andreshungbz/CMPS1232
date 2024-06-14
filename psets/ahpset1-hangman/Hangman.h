// CMPS1232 Principles of Programming 2
// Program Set 1 - Hangman Game
// Date Due: 2024-04-21
// Name: Andres Hung

// Hangman Class Header

// where appropriate, std::string parameters are made l-value references to const
// to avoid expensive string class copying

// where appropriate, const and static qualifiers are added to member functions

#ifndef AHPSET1_HANGMAN_HANGMAN_H
#define AHPSET1_HANGMAN_HANGMAN_H


#include "Player.h"
#include <vector>

class Hangman {
public:
    // public constants
    const static int ALPHABET_SIZE = 26; // num of rows for alphabet array
    const static int ASCII_ROWS = 7; // for ASCII letter printing
    const static int ASCII_COLS = 8; // for ASCII letter printing

    // constructor that loads the word list and sets username
    Hangman(const std::string& filename, const std::string& username);

    // function that prompts user for difficulty level and sets it
    int selectGameLevel();

    // function that generates a random number based on a range indicated by the difficulty level
    int generateRandomNumber() const;

    // function that returns a word from the word list based on the index
    std::string selectRandomWord(int random_number);

    // function that loads words from a text file to wordVector
    void loadWordList(const std::string& fileName);

    // main driver program that contains the game loop
    void startGame();

    // function that constructs the game box and the text within
    static void printMessage(std::string message, bool printTop = true, bool printBottom = true);

    // function that draws the hangman noose and person
    void drawHangman(int guessCount = 0) const;

    // function that sets alphabetArray to a string of all alphabet capital letters
    void resetAvailableLetters();

    // function that prints a message as a large ASCII array representation
    static void printAsciiMessage(const std::string& message);

    // function that prints a string of letters that are available for guessing
    void printAvailableLetters(std::string taken);

    // function that prints the word to guess and determines whether the player has guessed all the letters
    static bool checkWin(std::string wordToGuess, std::string guessesSoFar);

    // function that prints game final status, stats, and prompts replay
    bool processResults(const std::string& wordToGuess, int guessAttempts, bool hasWon);

    // setter that sets difficulty level and maximum allowed attempts based on such
    void setDifficultyLevel(unsigned diffLevel);

    // getter for difficultyLevel
    unsigned getDifficultyLevel() const;

    // setter for maxAllowedAttempts
    void setMaxAllowedAttempts(unsigned allowedAttempts);

    // getter for maxAllowedAttempts
    unsigned getMaxAllowedAttempts() const;

    // function that returns the number of wrong guesses made so far
    static unsigned attemptsMadeSoFar(const std::string& wordToGuess, std::string guessesSoFar);

private:
    Player player; // game player
    std::vector<std::string> wordVector; // array of all the possible words in the game
    unsigned difficultyLevel; // determines which range of words to pick from
    unsigned maxAllowedAttempts; // is determined by difficultyLewvel
    char alphabetArray[ALPHABET_SIZE + 1]; // array of letters available for guessing

    // ASCII letter definitions are located in Hangman.cpp
    constexpr static char G[ASCII_ROWS][ASCII_COLS] {" ##### ", // Row=0
                                                     " #     ", // Row=1
                                                     " #     ", // Row=2
                                                     " # ### ", // Row=3
                                                     " #   # ", // Row=4
                                                     " #   # ", // Row=5
                                                     " ##### "}; // Row=6

    constexpr static char A[ASCII_ROWS][ASCII_COLS] {" ##### ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " ##### ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # "};

    constexpr static char M[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " ## ## ",
                                                     " # # # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # "};

    constexpr static char E[ASCII_ROWS][ASCII_COLS] {" ##### ",
                                                     " #     ",
                                                     " #     ",
                                                     " ##### ",
                                                     " #     ",
                                                     " #     ",
                                                     " ##### "};

    constexpr static char O[ASCII_ROWS][ASCII_COLS] {" ##### ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " ##### "};

    constexpr static char V[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     "  # #  ",
                                                     "   #   "};

    constexpr static char R[ASCII_ROWS][ASCII_COLS] {" ##### ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " ##### ",
                                                     " # #   ",
                                                     " #  #  ",
                                                     " #   # "};

    constexpr static char Y[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     "  # #  ",
                                                     "   #   ",
                                                     "   #   ",
                                                     "   #   ",
                                                     "   #   ",
                                                     "   #   "};

    constexpr static char U[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " ##### "};

    constexpr static char W[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " # # # ",
                                                     " ## ## ",
                                                     " #   # "};

    constexpr static char N[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " ##  # ",
                                                     " # # # ",
                                                     " #  ## ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # "};

    constexpr static char exclamation[ASCII_ROWS][ASCII_COLS] {"   #   ",
                                                               "   #   ",
                                                               "   #   ",
                                                               "   #   ",
                                                               "       ",
                                                               "   #   ",
                                                               "   #   "};

    constexpr static char space[ASCII_ROWS][ASCII_COLS] {"       ",
                                                         "       ",
                                                         "       ",
                                                         "       ",
                                                         "       ",
                                                         "       ",
                                                         "       "};
};


#endif // AHPSET1_HANGMAN_HANGMAN_H
