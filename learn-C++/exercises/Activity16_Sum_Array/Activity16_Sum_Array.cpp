#include <iostream>
using namespace std;

int sumArray(int[]);
void printArray(int[]);
const int size = 5;

int main() {
    int numbers[size], sum = 0;

    for (int i = 0; i < size; i++) {
        cout << "Enter Element[" << i + 1 << "]: ";
        cin >> numbers[i];
    }
    printArray(numbers);
    sum = sumArray(numbers);
    cout << "Sum: " << sum;
    return 0;
}

void printArray(int arr[]) {
    for (int j = 0; j < size; j++) {
        cout << "Element[" << j << "]: " << arr[j] << endl;
    }
}

int sumArray(int num[]) {
    int k = 0;
    for (int n = 0; n < size; n++) {
        k = k + num[n];
    }
    return k;
}

