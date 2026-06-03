#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int i, j, size, N;

	do {
		cout << "Enter an ODD number: ";
		cin >> size;

		N = size % 2;

		if (N != 0) {
			for (i = 1; i <= size; i++) {
				for (j = 1; j <= size; j++) {
					if (j == i || j == size - i + 1) cout << setw(3) << "*";
					else cout << setw(3) << " ";
				}
				cout << endl;
			}
		}
		else cout << "Enter ODD number only!" << endl;
	}

	while (N == 0);

	return 0;
}
