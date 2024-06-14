#include <iostream>

char* my_strcpy(char* s1, const char* s2);
char* my_strncpy(char* s1, const char* s2, std::size_t n);
char* my_strcat(char *s1, const char *s2);
char* my_strncat(char *s1, const char *s2, std::size_t n);
int my_strcmp(const char* s1, const char* s2);
int my_strncmp(const char* s1, const char* s2, std::size_t n);
std::size_t my_strlen(const char* s);
char* my_strtok(char* s1, const char* s2);

int main() {
    // strcpy
    char s1[13];
    char s2[] {"Hello world!"};

    my_strcpy(s1, s2);
    std::cout << "[s2] " << s1 << " strcpy [s1]: " << s2 << '\n';

    // strcpy
    char s3[6];

    my_strncpy(s3, s2, 5);
    std::cout << "[s2] " << s2 << "strncpy [s3] with len 5: " << s3 << '\n';

    // strcat
    char s4[16] {"Happy "};
    char s5[] {"New Year!"};

    my_strcat(s4, s5);
    std::cout << "[s4] " << s4 << " strcat [s5] " << s5 << ": " << s4 << '\n';

    // strncat
    char s6[10] {"Happy "};

    my_strncat(s6, s5, 3);
    std::cout << "[s6] " << s6 << " strncat [s5] with len 3: " << s6 << '\n';

    // strcmp
    char s7[] {"Happy New Year"};
    char s8[] {"Happy New Year"};
    char s9[] {"Happy Holidays"};

    std::cout << s7 << " strcmp " << s8 << ": " << my_strcmp(s7, s8) << '\n';
    std::cout << s7 << " strcmp " << s9 << ": " << my_strcmp(s7, s9) << '\n';
    std::cout << s9 << " strcmp " << s7 << ": " << my_strcmp(s9, s7) << '\n';

    // strncmp
    std::cout << s7 << " strncmp " << s9 << ": " << my_strncmp(s7, s9, 6) << '\n';
    std::cout << s7 << " strncmp " << s9 << ": " << my_strncmp(s7, s9, 7) << '\n';
    std::cout << s9 << " strncmp " << s7 << ": " << my_strncmp(s9, s7, 7) << '\n';

    // strlen
    std::cout << "[s2] " << s2 << " strlen: " << my_strlen(s2) << '\n';

    //strtok
    char sentence[] {"This is a sentence with 7 tokens"};
    char* tokenPtr;

    std::cout << "\nThe string to be tokenized is:\n" << sentence
        << "\n\nThe tokens are:\n\n";

    tokenPtr = my_strtok(sentence, " ");

    while (tokenPtr) {
        std::cout << tokenPtr << '\n';
        tokenPtr = my_strtok(nullptr, " ");
    }

    std::cout << "\nAfter strtok, sentence = " << sentence << '\n';

    return 0;
}

char* my_strcpy(char* s1, const char* s2) {
    while (*s2 != '\0')
        *s1++ = *s2++;

    *s1 = '\0';

    return s1;
}

char* my_strncpy(char* s1, const char* s2, std::size_t n) {
    while (*s2 != '\0' && n--)
        *s1++ = *s2++;

    *s1 = '\0';

    return s1;
}

char* my_strcat(char *s1, const char *s2) {
    // move s1 pointer to end
    while (*s1 != '\0')
        ++s1;

    while (*s2 != '\0')
        *s1++ = *s2++;

    *s1 = '\0';

    return s1;
}

char* my_strncat(char *s1, const char *s2, std::size_t n) {
    // move s1 pointer to end
    while (*s1 != '\0')
        ++s1;

    while (*s2 != '\0' && n--)
        *s1++ = *s2++;

    *s1 = '\0';

    return s1;
}

int my_strcmp(const char* s1, const char* s2) {
    int comparison{0};

    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 != *s2) {
            comparison = *s1 - *s2;
            break;
        }

        ++s1;
        ++s2;
    }

    return comparison;
}

int my_strncmp(const char* s1, const char* s2, std::size_t n) {
    int comparison{0};

    while ((*s1 != '\0' || *s2 != '\0') && n--) {
        if (*s1 != *s2) {
            comparison = *s1 - *s2;
            break;
        }

        ++s1;
        ++s2;
    }

    return comparison;
}

std::size_t my_strlen(const char* s) {
    std::size_t counter{0};

    while (*s++ != '\0')
        ++counter;

    return counter;
}

char* my_strtok(char* s1, const char* s2) {
    // keep pointer throughout program
    static char* token{};

    // if s1 is not nullptr, then assign initial string, else reuse token
    if (s1) token = s1;

    if (token == nullptr) {
        return nullptr;
    }

    char* startPtr{token};
    for (char* c{startPtr}; *c != '\0'; ++c) {
        if (*c == *s2) {
            *c = '\0';
            token = c + 1;
            return startPtr;
        }
    }

    token = nullptr;
    return startPtr;
}