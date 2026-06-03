#include <iostream>
using namespace std;

int sum(int, int);

int main() {
	int a = 5, b = 6, c;

	c = sum(a, b);
	cout << "Sum: " << c;
	return 0;
}

int sum(int x, int y) {
	int z;

	z = x + y;
	return z;
}
