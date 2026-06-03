//Summation of N
//while loop
#include <iostream>
using namespace std;

int main() {
	int sum(0), N, i;

	cout << "Enter a number: ";
	cin >> N;

	i = 1;
	while (i <= N) {
		sum = sum + i;
		i++;
	}

	cout << "The summation is: " << sum;

	return 0;
}
