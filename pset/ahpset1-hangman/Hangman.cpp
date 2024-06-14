// CMPS1232 Principles of Programming 2
// Program Set 1 - Hangman Game
// Date Due: 2024-04-21
// Name: Andres Hung

// Hangman Class Implementation

// in CLION, use CMakeLists.txt as the project file
// in QT CREATOR, use ahpset1-hangman.pro as the project file

#include "Hangman.h"
#include <cassert> // assert
#include <cctype> // std::tolower, std::tohigher, std::isalpha
#include <chrono> // std::chrono::steady_clock
#include <cstdlib> // std::system, std::exit, [OPTIONAL] std::rand, [OPTIONAL] std::srand
// #include <ctime> // std::time
#include <fstream> // std::ifstream
#include <iostream>
#include <limits> // std::numeric_limits
#include <random> // std::random_device, std::seed_seq, std::mt19937, std::uniform_int_distribution

// defining static data members in Hangman.cpp helps to avoid the One Definition Rule
// as it keeps it the single source of definition here.
// https://www.learncpp.com/cpp-tutorial/static-member-variables/
constexpr char Hangman::G[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::A[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::M[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::E[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::O[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::V[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::R[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::Y[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::U[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::W[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::N[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::exclamation[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::space[ASCII_ROWS][ASCII_COLS];

Hangman::Hangman(const std::string& filename, const std::string& username) : player(username) { // NOLINT(*-pro-type-member-init)
    // construct pathname to word list for debug configurations
    std::string path{".."};

    // create relative path for Windows and Unix/Linux
    #if defined(_WIN32)
        path += '\\';
    #else
        path +='/';
    #endif

    // append word list file
    path += filename;

    loadWordList(path);

    player.setDifficultyLevel(selectGameLevel()); // set difficultyLevel in Hangman's Player object
}

int Hangman::selectGameLevel() {
    while (true) {
        #if defined(_WIN32)
            std::system("cls"); // for Windows
        #else
            std::system("clear"); // for Unix/Linux
        #endif

        std::cout << "[CMPS1232] HANGMAN GAME by Andres Hung for Program Set 1\n";

        std::cout << "Choose a difficulty level number [1 = Easy] [2 = Medium] [3 = Hard]: ";
        int difficultyNumber{};
        std::cin >> difficultyNumber;

        // account for failed extraction
        // https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
        if (!std::cin) {
            std::cin.clear(); // return to normal mode
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        // ensure input is within valid range
        if (difficultyNumber < 1 || difficultyNumber > 3) {
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove extra input

        setDifficultyLevel(difficultyNumber); // set difficultyLevel in Hangman object

        return difficultyNumber;
    }
}

int Hangman::generateRandomNumber() const {
    // use the Mersenne Twister PRNG using random devices and system clock for seeding
    // https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/
    static std::random_device rd{};

    // non-static means the seed sequence is reseeded on every call with different time
    std::seed_seq ss{static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
                     rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt{ss};

    // make sure word list has at least 486 words
    // https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/
    assert(wordVector.size() >= 486 && "too few words in word list");

    // word list difficulty thresholds
    const unsigned easyThreshold{63};
    const unsigned mediumThreshold{351};
    const unsigned hardThreshold{485};

    // create number generator based on difficulty level
    unsigned level{getDifficultyLevel()};

    int min{};
    int max{};

    if (level == 1) {
        min = 0;
        max = easyThreshold;
    } else if (level == 2) {
        min = easyThreshold + 1; // 64
        max = mediumThreshold;
    } else if (level == 3) {
        min = mediumThreshold + 1; // 352
        max = hardThreshold;
    }

    std::uniform_int_distribution<int> numberGenerator{min, max};

    // alternative using std::rand
    // return min + std::rand() % (max - min + 1);

    return numberGenerator(mt);
}

std::string Hangman::selectRandomWord(int random_number) {
    return wordVector[random_number];
}

void Hangman::loadWordList(const std::string& fileName) {
    std::string word;

    std::ifstream infile; // creates a file inputstream object used to connect to a text file
    infile.open (fileName); // use the inputstream object to open file

    if (infile.is_open()) { // check if the file was successfully opened
        while(!infile.eof()) { // while not at the end of file eof()
            getline(infile, word); // read a line from the file and store it in the string variable, word
            wordVector.push_back(word); // insert string word into the vector
        } // repeat until the end of file is reached

        infile.close(); // close the file once it has been processed
    } else { // if you are here, it is because there was a problem opening the file
        std::cout << "Unable to open file, " << fileName << std::endl; // notify the user that a problem has occurred
        std::cout << "Hangman game will now terminate." << std::endl;

        std::exit(-1); // terminate the program since no words could be loaded, making the game impossible
    }
}

void Hangman::startGame() {
    std::string guessedSoFar; // letters player has guessed so far
    std::string wordToGuess; // random word chosen to guess
    int totalGuesses; // number of guesses so far
    bool hasWon; // whether the player has won the game
    bool playAgain; // whether the player wants to play again
    char guess{}; // current guessed letter

    // NOTE: in place of using std::srand, the Hangmann::generateRandomNumber member function
    // has its seed sequence reseeded on every call with the updated time, even though technically
    // not necessary if made static. The same effect is achieved of randomness per number generated.
    // below is the statement for seeding std::srand for use with std::rand.

    // std::srand(static_cast<unsigned>(std::time(nullptr)));

    // game loop
    do {
        // reset variables
        guessedSoFar = "";
        wordToGuess = "";
        totalGuesses = 0;

        // generate new word
        int randomNumber{generateRandomNumber()};
        wordToGuess = selectRandomWord(randomNumber);

        resetAvailableLetters();

        // guess loop
        do {
            #if defined(_WIN32)
                std::system("cls"); // for Windows
            #else
                std::system("clear"); // for Unix/Linux
            #endif

            printMessage("HANGMAN", true, true);
            drawHangman(totalGuesses);
            printAvailableLetters(guessedSoFar);
            printMessage("Guess the word", true, true);
            hasWon = checkWin(wordToGuess, guessedSoFar);

            if (hasWon) {
                break;
            }

            std::cout << "\nEnter guess: ";
            std::cin >> guess;

            // account for failed extraction
            // https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
            if (!std::cin) {
                std::cin.clear(); // return to normal mode
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                continue;
            }

            // don't accept non-alphabetical characters
            // https://en.cppreference.com/w/cpp/string/byte/isalpha
            if (!(std::isalpha(guess))) {
                continue;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove extra input

            // convert guess letter to uppercase
            guess = static_cast<char>(std::toupper(guess));

            // if guess letter is unique, append it to guessedSoFar
            if (guessedSoFar.find(guess) == std::string::npos) {
                guessedSoFar += guess;
            } else {
                // this skips redundantly running the update to totalGuesses below
                continue;
            }

            // update totalGuesses
            totalGuesses = static_cast<int>(attemptsMadeSoFar(wordToGuess, guessedSoFar));
        } while (totalGuesses < static_cast<int>(getMaxAllowedAttempts()));

        playAgain = processResults(wordToGuess, totalGuesses, hasWon);
    } while (playAgain);

    #if defined(_WIN32)
        std::system("cls"); // for Windows
    #else
        std::system("clear"); // for Unix/Linux
    #endif

    std::cout << "[CMPS1232] HANGMAN GAME by Andres Hung for Program Set 1\n";
    std::cout << "Thank you for playing!\n";

    #if defined(_WIN32)
        std::system("pause"); // for Windows
    #else
        std::cout << "Press any key to exit . . .";
    #endif

    std::getchar();
}

void Hangman::printMessage(std::string message, bool printTop, bool printBottom) {
    const std::size_t dashesCount{33}; // width of the game box

    // prints the top of the box
    if (printTop) {
        std::cout << '+';
        for (std::size_t i{0}; i < dashesCount; ++i) {
            std::cout << '-';
        }
        std::cout << '+';

        std::cout << '\n';
    }

    std::cout << '|';

    // ensure the message is printed in the center
    std::size_t messageLength{message.size()};
    std::size_t difference{dashesCount - messageLength};
    bool leftPosition{true};

    while (difference--) {
        if (leftPosition) {
            // using string methods insert and begin to append the space at the beginning
            // https://en.cppreference.com/w/cpp/string/basic_string/insert
            message.insert(message.begin(), ' ');
        } else {
            message += ' ';
        }

        // alternate spaces
        leftPosition = !leftPosition;
    }

    std::cout << message;

    std::cout << '|';

    // prints the bottom of the box
    if (printBottom) {
        std::cout << '\n';

        std::cout << '+';
        for (std::size_t i{0}; i < dashesCount; ++i) {
            std::cout << '-';
        }
        std::cout << '+';
    }

    std::cout << '\n';
}

void Hangman::drawHangman(int guessCount) const {
    // noose size depends on maxAllowedAttempts
    const std::size_t personRows{4};
    const std::size_t personCounter{8};
    const std::size_t nooseCounter{getMaxAllowedAttempts() - personCounter};

    // draw the noose
    for (std::size_t i{0}; i < nooseCounter; ++i) {
        if (guessCount == 0) {
            printMessage("", false, false);
        } else {
            printMessage("|", false, false);
            --guessCount;
        }
    }

    int drawCounter{1};

    // draw the person
    for (std::size_t i{0}; i < personRows; ++i) {
        if (drawCounter <= guessCount) {
            if (drawCounter == 1) {
                printMessage("O", false, false);

                if (guessCount == 1 || guessCount == 2) {
                    ++drawCounter;
                } else if (guessCount == 3) {
                    drawCounter += 2;
                } else if (guessCount > 3) {
                    drawCounter += 3;
                }

                continue;
            }

            if (drawCounter == 2 || drawCounter == 6) {
                printMessage("/  ", false, false);
                ++drawCounter;
                continue;
            }

            if (drawCounter == 3) {
                printMessage("/| ", false, false);
                ++drawCounter;
                continue;
            }

            if (drawCounter == 4) {
                printMessage("/|\\", false, false);
                ++drawCounter;
                continue;
            }

            if (drawCounter == 5) {
                printMessage(" | ", false, false);

                if (guessCount == 5 || guessCount == 6) {
                    ++drawCounter;
                } else if (guessCount == 7) {
                    drawCounter += 2;
                }

                continue;
            }

            if (drawCounter == 7) {
                printMessage("/ \\", false, false);
                ++drawCounter;
                continue;
            }
        } else {
            // print the rest as empty space
            printMessage("", false, false);
        }
    }
}

void Hangman::resetAvailableLetters() {
    for (int i{0}; i < ALPHABET_SIZE; ++i) {
        alphabetArray[i] = static_cast<char>('A' + i);
    }

    // add a space to the extra location in alphabetArray
    alphabetArray[ALPHABET_SIZE] = ' ';
}

void Hangman::printAsciiMessage(const std::string& message) {
    std::cout << '\n';

    for (int i{0}; i < ASCII_ROWS; ++i) {
        // print the top part of each ASCII representation
        for (const char c : message) {
            switch (c) {
                case 'G':
                    std::cout << G[i];
                    break;
                case 'A':
                    std::cout << A[i];
                    break;
                case 'M':
                    std::cout << M[i];
                    break;
                case 'E':
                    std::cout << E[i];
                    break;
                case 'O':
                    std::cout << O[i];
                    break;
                case 'V':
                    std::cout << V[i];
                    break;
                case 'R':
                    std::cout << R[i];
                    break;
                case 'Y':
                    std::cout << Y[i];
                    break;
                case 'U':
                    std::cout << U[i];
                    break;
                case 'W':
                    std::cout << W[i];
                    break;
                case 'N':
                    std::cout << N[i];
                    break;
                case '!':
                    std::cout << exclamation[i];
                    break;
                case ' ':
                    std::cout << space[i];
                    break;
                default:
                    break;
            }
        }

        std::cout << '\n';
    }

    std::cout << '\n';
}

void Hangman::printAvailableLetters(std::string taken) {
    printMessage("Available Letters", true, false);

    std::size_t takenLength{taken.length()};

    for (std::size_t i{0}; i < takenLength; ++i) {
        // check if character guessed is available in alphabetArray, and if so, replace with space
        for (int j{0}; j < ALPHABET_SIZE; ++j) {
            // use std::toupper from <cctype> for extra validation
            // https://en.cppreference.com/w/cpp/string/byte/toupper
            if (static_cast<char>(std::toupper(taken[i])) == alphabetArray[j]) {
                alphabetArray[j] = ' ';
                break;
            }
        }
    }

    // construct string from available letters from alphabetArray
    std::string availableLetters{};
    for (const char c : alphabetArray) {
        availableLetters += c;
    }

    printMessage(availableLetters, true, false);
}

bool Hangman::checkWin(std::string wordToGuess, std::string guessesSoFar) {
    std::size_t wordToGuessLength{wordToGuess.length()};

    // convert wordToGuess to uppercase
    for (std::size_t i{0}; i < wordToGuessLength; ++i) {
        wordToGuess[i] = static_cast<char>(std::toupper(wordToGuess[i]));
    }

    // convert guessesSoFar to uppercase just in case
    for (std::size_t i{0}; i < guessesSoFar.length(); ++i) {
        guessesSoFar[i] = static_cast<char>(std::toupper(guessesSoFar[i]));
    }

    std::string wordField{};
    std::size_t lettersGuessed{0};

    // first variable is used to not append a leading space
    bool first{true};
    for (std::size_t i{0}; i < wordToGuessLength; ++i) {
        if (first) {
            first = false;
        } else {
            wordField += ' ';
        }

        // if character in guessed letters is in word, append letter to show
        if (guessesSoFar.find(wordToGuess[i]) != std::string::npos) {
            wordField += wordToGuess[i];
            ++lettersGuessed;
        } else {
            // characters not guess yet are shown as an underscore
            wordField += '_';
        }
    }

    printMessage(wordField, true, true);

    // if the count of lettersGuessed is equal to the word length, then all letters have been guessed
    // and player has won
    return wordToGuessLength == lettersGuessed;
}

bool Hangman::processResults(const std::string& wordToGuess, int guessAttempts, bool hasWon) {
    player.setGuesses(guessAttempts);

    if (hasWon) {
        printAsciiMessage("YOU WON!");
    } else {
        printAsciiMessage("GAME OVER!");
    }

    std::cout << "The correct word was: " << wordToGuess << "\n\n";

    std::cout << "-- " << player.getUsername() << "'s Current Stats (scores reset every 10 games)\n";
    std::cout << "-- Lower values are better! Perfect games don't count!\n\n";

    std::cout << player.generateStatistics() << "\n\n";

    while (true) {
        std::cout << "-- Would you like to play again? [Y] [N]: ";
        char response{};
        std::cin >> response;

        // account for failed extraction
        // https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
        if (!std::cin) {
            std::cin.clear(); // return to normal mode
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove extra input

        if (response == 'Y' || response == 'y') {
            player.setDifficultyLevel(selectGameLevel());

            return true;
        } else {
            return false;
        }
    }
}

void Hangman::setDifficultyLevel(unsigned int diffLevel) {
    difficultyLevel = (diffLevel >= 1 && diffLevel <= 3) ? diffLevel : 1;

    if (difficultyLevel == 1 || difficultyLevel == 3) {
        setMaxAllowedAttempts(10);
    } else {
        // if difficulty level is 2
        setMaxAllowedAttempts(13);
    }
}

unsigned Hangman::getDifficultyLevel() const {
    return difficultyLevel;
}

void Hangman::setMaxAllowedAttempts(unsigned int allowedAttempts) {
    maxAllowedAttempts = allowedAttempts;
}

unsigned Hangman::getMaxAllowedAttempts() const {
    return maxAllowedAttempts;
}

unsigned Hangman::attemptsMadeSoFar(const std::string& wordToGuess, std::string guessesSoFar) {
    std::size_t guessesLength{guessesSoFar.length()};
    unsigned notInWordCounter{0};

    for (std::size_t i{0}; i < guessesLength; ++i) {
        // use std::string find member function and std::tolower function from <cctype> to compare characters
        // https://en.cppreference.com/w/cpp/string/byte/tolower
        // https://en.cppreference.com/w/cpp/string/basic_string/find
        if (wordToGuess.find(static_cast<char>(std::tolower(guessesSoFar[i]))) == std::string::npos) {
            ++notInWordCounter;
        }
    }

    return notInWordCounter;
}
