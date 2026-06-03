#include <iostream>

using namespace std;

int main() {
	int N1, N2, SUM, V, i;
	N1 = 0, N2 = 1, SUM = 0, i = 3;

	cout << "Fibonacci Series" << endl << "Input a number." << endl;
	cin >> V;

	if (V <= 0) {
		cout << "Try positive numbers!";
	}
	else if (V == 1) {
		cout << 0;
	}
	else {
		cout << "0, 1";
		for (i = 3; i <= V; i++) {
			SUM = N1 + N2;
			cout << ", "; cout << SUM;
			N1 = N2;
			N2 = SUM;
		}
	}
	return 0;
}