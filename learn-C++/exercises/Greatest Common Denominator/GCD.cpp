#include <iostream>

using namespace std;

int main() {
	
	int N1, N2, B, S;

	cout << "Enter two numbers." << endl;
	cin >> N1 >> N2;

	if (N1 >= N2) {
		B = N1, S = N2;
	}
	else {
		B = N2, S = N1;
	}
	if (S == 0) {
		cout << "The greatest common divisor is: " << S << endl;
	}
	else if (B % S == 0) {
		cout << "The greatest common divisor is: " << S << endl;
	}
	else {
		int i = 1, gcd = 0;
		while (i <= S) {
			if (B % i == 0 && S % i == 0) {
				gcd = i;
			}
			i = i + 1;
		}
		cout << "The greatest common divisor is: " << gcd <<  endl;
	}
	return 0;
}
