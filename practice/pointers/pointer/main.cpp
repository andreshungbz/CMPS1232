#include <iostream>

using namespace std;

void doublenumber(int *, int *);
int findMinimum(int *, int );
void printArray(int *, int );
int numberofOdds(int *, int);


int main()
{
    //ask the user to enter two numbers
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int *num1ptr = &num1;
    int *num2ptr = &num2;
    doublenumber(num1ptr, num2ptr);

    cout << "Number 1 has been updated to "  << num1;
    cout << "\nNumber 2 has been updated to "  << num2;

    const int size = 10;
    int array1[size] = {2,3,4,5,6,7};
    printArray(array1, size);

    std::cout << '\n';
    std::cout << "findMinimum: " << findMinimum(array1, size) << '\n';
    std::cout << "numberofOdds: " << numberofOdds(array1, size) << '\n';

    return 0;
}

//This function will double each of the numbers entered
//example user enters 5, 10. The numbers will be changed to 10, 20
void doublenumber(int *var1, int *var2)
{
    *var1 *= 2;
    *var2 *= 2;
}


//this function will find the smallest number in an array and return that number
void printArray(int *aptr, int size)  //put the parameter name
{
    cout << endl;
    for (int i=0 ; i < size; ++i)
        cout << *(aptr +i) << ' ';

}

//This function will print all the smallest number in the array
int findMinimum(int *aptr, int size)
{
    int smallest{*aptr};

    for (int i{1}; i < size; ++i) {
        if (*(aptr + i) < smallest) {
            smallest = *(aptr + i);
        }
    }

    return smallest;
}

//this function will return the number of odd numbers in the array
int numberofOdds(int *aptr, int size)
{
    int oddCount{0};

    for (int i{0}; i < size; ++i) {
        if (*(aptr + i) % 2 == 1) {
            ++oddCount;
        }
    }

    return oddCount;
}

