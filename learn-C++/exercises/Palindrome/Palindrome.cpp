#include <iostream>

using namespace std;

int main() {
	int N, M, D, R;

	cin >> N;
	M = N, R = 0;

	while (N > 0) {
		D = N % 10;
		R = R * 10 + D;
		N = N / 10;
	}
	
	if (M == R) {
		cout << "It is a palindrome.";
	}
	else {
		cout << "It is not a palindrome.";
	}
	return 0;
}