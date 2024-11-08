//
// Created by Javier on 11/6/2024.
//
#include <iostream>
using namespace std;

template <typename T>
void sortArray(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int SIZE = 10;

    // Sorting an array of integers
    int intArray[SIZE] = {34, 7, 23, 32, 5, 62, 32, 5, 18, 29};
    cout << "Original int array: ";
    printArray(intArray, SIZE);
    sortArray(intArray, SIZE);
    cout << "Sorted int array: ";
    printArray(intArray, SIZE);

    // Sorting an array of doubles
    double doubleArray[SIZE] = {34.5, 7.1, 23.9, 32.0, 5.5, 62.4, 32.3, 5.8, 18.1, 29.6};
    cout << "Original double array: ";
    printArray(doubleArray, SIZE);
    sortArray(doubleArray, SIZE);
    cout << "Sorted double array: ";
    printArray(doubleArray, SIZE);

    return 0;
}
