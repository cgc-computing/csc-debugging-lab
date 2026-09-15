// reverse_array.cpp
// Fills an array from user input, reverses it in place using a helper
// function, and prints the array before and after.
#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Reverses the array in place by swapping elements from the two ends
// toward the middle.
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    const int SIZE = 6;
    int values[SIZE];

    cout << "Enter " << SIZE << " integers: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> values[i];
    }

    cout << "Original: ";
    printArray(values, SIZE);

    reverseArray(values, SIZE);

    cout << "Reversed: ";
    printArray(values, SIZE);
    return 0;
}
