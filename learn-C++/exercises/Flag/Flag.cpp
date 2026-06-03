#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int i, j, size, N;

	cout << "Enter a number: ";
	cin >> size;

	//	for (i=1; i<=size; i++) {
	//		for (j=1; j<=size; j++) {
	//			if (j <= size-i) cout << setw(5) << " ";
	//			else cout << setw(5) << "*";
	//		} 
	//		cout << endl;
	//	}

	for (i = 1; i <= size; i++) {
		for (j = 1; j <= size; j++) {
			if (j <= i) cout << setw(5) << "*";
		}
		cout << endl;
	}

	return 0;
}
