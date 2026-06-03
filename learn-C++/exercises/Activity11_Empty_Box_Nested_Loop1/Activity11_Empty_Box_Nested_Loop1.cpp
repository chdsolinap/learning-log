#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int i, j, size;

	cout << "Enter a number: ";
	cin >> size;

	for (i = 1; i <= size; i++) {
		for (j = 1; j <= size; j++) {
			if (j == size || j == 1 || i == size || i == 1) cout << setw(5) << "*";
			else cout << setw(5) << " ";
		}
		cout << endl;
	}

	return 0;
}
