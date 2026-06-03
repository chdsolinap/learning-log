#include <iostream>
using namespace std;

void printArray(int[]);
int countOdd(int[]);
const int size = 5;

int main() {
    int numbers[size], odd;

    for (int i = 0; i < size; i++) {
        cout << "Enter Element[" << i + 1 << "]: ";
        cin >> numbers[i];
    }
    printArray(numbers);
    odd = countOdd(numbers);
    cout << "Odd Numbers in the List: " << odd;
    return 0;
}

void printArray(int arr[]) {
    for (int j = 0; j < size; j++) {
        cout << "Element[" << j << "]: " << arr[j] << endl;
    }
}

int countOdd(int num[]) {
    int count = 0;
    for (int x = 0; x < size; x++) {
        if (num[x] % 2 == 1)
            count = count + 1;
    }
    return count;
}


