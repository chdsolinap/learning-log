//If-else: Days of the week
#include <iostream>
using namespace std;

int main() {
	int n;

	cout << "Enter a number between 1 to 7: ";
	cin >> n;

	if (n <= 0 && n > 7)
		cout << "Error: Out of range.";
	else
		if (n == 1)
			cout << "Sunday";
		else
			if (n == 2)
				cout << "Monday";
			else
				if (n == 3)
					cout << "Tuesday";
				else
					if (n == 4)
						cout << "Wednesday";
					else
						if (n == 5)
							cout << "Thursday";
						else
							if (n == 6)
								cout << "Friday";
							else
								if (n == 7)
									cout << "Saturday";

	return 0;
}
