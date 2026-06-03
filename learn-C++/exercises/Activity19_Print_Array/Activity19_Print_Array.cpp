#include <iostream>
using namespace std;

const int r = 3;
const int c = 3;

void printArray(int[r][c]);

int main() {

	int array[r][c];
	cout << "Enter a number: ";

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> array[i][j];
		}
	}
	printArray(array);
	return 0;
}

void printArray(int number[r][c]) {
	number[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "Element[" << i << "," << j << "]:" << number[i][j] << endl;

		}
	}

}

