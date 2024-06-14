#include <iostream>

void replace(char* cptr, const char* replacers) {
    char first{*(replacers)};
    char second{*(replacers + 1)};

    while (*cptr != '\0') {
        if (*cptr == 'a') {
            *cptr = first;
        } else if (*cptr == 'b') {
            *cptr = second;
        }

        ++cptr;
    }

}

int main() {
    char s[10] {"abcde"};
    char t[] {"fg"};

    replace(s, t);

    std::cout << s << '\n';
    return 0;
}
