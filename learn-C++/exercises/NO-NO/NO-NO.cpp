#include <iostream>
using namespace std;

void sum();

int main() {
	sum();
	return 0;
}

void sum() {
	int x = 5, y = 6, z;

	z = x + y;
	cout << "Sum: " << z;
}
