#include <iostream>
using namespace std;

const int r = 3;
const int c = 3;

void changedToFive(int[r][c]);


int main() {

	int array[r][c];
	cout << "Enter a number: ";

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> array[i][j];
		}
	}
	changedToFive(array);
	return 0;
}

void changedToFive(int number[r][c]) {
	int x;
	cout << "Enter a number to be changed: ";
	cin >> x;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (number[i][j] == x) number[i][j] = 5;
			cout << "Element[" << i << "," << j << "]:" << number[i][j] << endl;
		}
	}
}

