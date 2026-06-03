#include <iostream>
using namespace std;

void printArray(int[]);
const int size = 5;

int main() {
    int numbers[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter Element[" << i + 1 << "]: ";
        cin >> numbers[i];
    }
    printArray(numbers);
    return 0;
}

void printArray(int arr[]) {
    for (int j = 0; j < size; j++) {
        cout << "Element[" << j << "]: " << arr[j] << endl;
    }
}

