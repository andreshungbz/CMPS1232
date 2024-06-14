#include <iostream>
#include <string>

int letterCount(const std::string& word, char letter);

int main () {
    const std::size_t size{6};
    char word[size] {"hello"};

    std::cout << "Enter a letter to search for: ";
    char letter;
    std::cin >> letter;

    int result{letterCount(word, letter)};

    std::cout << "Count of [" << letter << "] in [" << word << "] is " << result << '\n';

    return 0;
}

int letterCount(const std::string& word, char letter) {
    int count{0};

    for (char c : word) {
        if (c == letter)
            ++count;
    }

    return count;
}