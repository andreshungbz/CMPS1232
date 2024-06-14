#include <iostream>
using namespace std;

//Write the function numOccur prototype.
int numOccur(const char word[], char letter, int size);

int main()
{
    const int arraysize=6;
    char a[arraysize] = "hello";
    char letter;
    cout << "Enter a letter to search for \n";
    cin >> letter;

//Call the function to check the number of occurrences of the letter
    int count{numOccur(a, letter, arraysize)};

//Print out the result
    cout << "Number of occurrences of letter [" << letter << "] in word ["
         << a << "] is " << count << '\n';

    return 0;
}

//Write the function numOccur.
int numOccur(const char word[], char letter, int size) {
    int count{0};

    for (std::size_t i{0}; i < size; ++i) {
        if (word[i] == letter) {
            ++count;
        }
    }

    return count;
}