#include <iostream>
using namespace std;

int sum();

int main() {
	int c;

	c = sum();
	cout << "Sum: " << c;
	return 0;
}

int sum() {
	int x = 5, y = 6, z;

	z = x + y;
	return z;
}
