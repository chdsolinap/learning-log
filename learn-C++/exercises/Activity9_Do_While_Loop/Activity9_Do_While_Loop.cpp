//Summation of N
//do-while loop
#include <iostream>
using namespace std;

int main() {
	int sum(0), N, i(1);

	cout << "Enter a number: ";
	cin >> N;

	do {
		sum = sum + i;
		i++;
	} while (i <= N);

	cout << "The summation is: " << sum;

	return 0;
}
