#include <iostream>

template <typename T>
void print1DArray(const T* array, std::size_t size);

template <typename T>
void selectionSort(T* array, std::size_t size);

template <typename T>
void bubbleSort(T* array, std::size_t size);

template <typename T>
void insertionSort(T* array, std::size_t size);

// https://www.programiz.com/dsa/merge-sort

template <typename T>
void merge(T* array, int p, int q, int r);

template <typename T>
void mergeSort(T* array, int l, int r);

template <typename T>
int partition(T* array, int start, int end);

template <typename T>
void quickSort(T* array, int start, int end);

int main() {
    const std::size_t size{10};
    int array[size] {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};

    std::cout << "Initial Array: ";
    print1DArray(array, size);

    quickSort(array, 0, size - 1);
    std::cout << "\nSorted Array: ";
    print1DArray(array, size);

    return 0;
}

template <typename T>
void print1DArray(const T* array, std::size_t size) {
    bool first{true};

    for (std::size_t i{0}; i < size; ++i) {
        if (first) {
            first = false;
        } else {
            std::cout << ' ';
        }

        std::cout << *(array + i);
    }
}

template <typename T>
void selectionSort(T* array, std::size_t size) {
    for (std::size_t i{0}; i < size; ++i) {
        std::size_t smallestIndex{i};

        for (std::size_t j{i}; j < size; ++j) {
            if (*(array + j) < *(array + smallestIndex)) {
                smallestIndex = j;
            }
        }

        T temp{*(array + i)};
        *(array + i) = *(array + smallestIndex);
        *(array + smallestIndex) = temp;
    }
}

template <typename T>
void bubbleSort(T* array, std::size_t size) {
    for (std::size_t i{0}; i < size - 1; ++i) {
        for (std::size_t j{0}; j < size - 1; ++j) {
            if (*(array + j + 1) < *(array + j)) {
                T temp{*(array + j)};
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }
}

template <typename T>
void insertionSort(T* array, std::size_t size) {
    for (std::size_t i{0}; i < size - 1; ++i) {
        if (*(array + i + 1) < *(array + i)) {
            int j{static_cast<int>(i)};

            while (*(array + j + 1) < *(array + j)) {
                T temp{*(array + j)};
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;

                --j;
            }
        }
    }
}

template <typename T>
void merge(T* array, int p, int q, int r) {
    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = array[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i{0};
    int j{0};
    int k{p};

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            array[k] = L[i++];
        } else {
            array[k] = M[j++];
        }

        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        array[k++] = L[i++];
    }

    while (j < n2) {
        array[k++] = M[j++];
    }
}

template <typename T>
void mergeSort(T* array, int l, int r) {
    if (l < r) {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        // Merge the sorted subarrays
        merge(array, l, m, r);
    }
}

template <typename T>
int partition(T* array, int start, int end) {
    if (start == end) {
        return -1;
    }

    T* startPtr {array + start};
    T* endPtr {array + end};

    while (*endPtr > *startPtr) {
        --endPtr;
    }

    if (startPtr == endPtr) {
        return startPtr - array;
    }

    T temp {*startPtr};
    *startPtr = *endPtr;
    *endPtr = temp;

    ++startPtr;

    while (*startPtr < *endPtr) {
        ++startPtr;
    }

    temp = *startPtr;
    *startPtr = *endPtr;
    *endPtr = temp;

    if (startPtr == endPtr) {
        return startPtr - array;
    }

    int index {partition(array, startPtr - array, (endPtr - 1) - array)};

    return index;
}

template <typename T>
void quickSort(T* array, int start, int end) {
    if (start >= end) return;

    int index{partition(array, start, end)};

    // partition left side
    quickSort(array, start, index - 1);
    // partition right side
    quickSort(array, index + 1, end);
}