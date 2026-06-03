//Summation of N
//for loop
#include <iostream>
using namespace std;

int main() {
	int sum(0), N, i;

	cout << "Enter a number: ";
	cin >> N;

	for (i = 0; i <= N; i++)
		sum = sum + i;

	cout << "The summation is: " << sum;

	return 0;
}
