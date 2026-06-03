//math calculator
//do while loop
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;

int main() {
	double num1, num2, r;
	char operation;
	bool solve(1);

	do {
		system("CLS");

		cout << "Enter the first number: ";
		cin >> num1;

		cout << "Enter the second number: ";
		cin >> num2;

		cout << "Enter the mathematical operation to be performed (+, -, *, /): ";
		cin >> operation;

		switch (operation) {
		case '+': {
			r = num1 + num2;
			cout << "The answer is: " << r;
			getch(); break;
		}
		case '-': {
			r = num1 - num2;
			cout << "The answer is: " << r;
			getch(); break;
		}
		case '*': {
			r = num1 * num2;
			cout << "The answer is: " << r;
			getch(); break;
		}
		case '/': {
			r = num1 / num2;
			cout << "The answer is: " << fixed << setprecision(2) << r;
			getch(); break;
		}
		default: cout << "Invalid operator."; getch(); break;
		}
		cout << endl << endl;
	} while (solve);

	return 0;
}

