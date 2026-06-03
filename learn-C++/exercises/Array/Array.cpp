#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int numbers[size], sum = 0;

    for (int i = 0; i < size; i++) {
        cout << "Enter Element[" << i + 1 << "]: ";
        cin >> numbers[i];
    }
    for (int j = 0; j < size; j++) {
        cout << "Element[" << j << "]: " << numbers[j] << endl;
    }
    for (int k = 0; k < size; k++) {
        sum = sum + numbers[k];
    }
    cout << "Sum: " << sum;
    return 0;
}

