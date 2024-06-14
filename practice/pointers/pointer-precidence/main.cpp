#include <iostream>

int main() {
    int blocks[] = {1, 2, 3, 4, 5};

    int* ptr = blocks;
    std::cout << ptr << '\n';

    int temp;

    ptr = blocks + 1;
    std::cout << ptr << '\n';

    temp = *(blocks + 2);
    std::cout << temp << '\n';

    temp = *(ptr + 3);
    std::cout << temp << '\n';

    ptr = blocks + 3;
    std::cout << ptr << '\n';

    temp = *++ptr;
    std::cout << temp << '\n';

    temp = ++*ptr;
    std::cout << temp << '\n';

    temp = *ptr--;
    std::cout << temp << '\n';

    temp = *ptr;
    std::cout << temp << '\n';

    return 0;
}
