//This program identifies if a number is an odd or even number./
#include <iostream>
using namespace std;

int main() {
	int n, rem;

	cout << "Input a number: ";
	cin >> n;

	rem = n % 2; //check if there is a remainder

	if (rem == 0) cout << "This is an EVEN NUMBER.";
	if (rem == 1) cout << "This is an ODD NUMBER.";

	return 0;
}
