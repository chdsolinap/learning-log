#include <iostream>
using namespace std;

int factorial(int);

int main() {
	int n = 5, f;

	f = factorial(n);
	cout << "Factorial: " << f;
	return 0;
}

int factorial(int x) {
	if (x == 0) return 1;
	else return x * factorial(x - 1);
}
