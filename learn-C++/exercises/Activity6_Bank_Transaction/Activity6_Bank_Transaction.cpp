//Bank Transaction
#include <iostream>
using namespace std;

int main() {
	char trans;
	int amount, balance(1000);

	cout << "Solinap's Banking System" << endl;
	cout << "[Q]uit" << endl;
	cout << "[W]ithdraw" << endl;
	cout << "[D]eposit" << endl;
	cout << "[C]heck Balance" << endl;
	cout << "Enter transaction type: ";
	cin >> trans;
	cout << endl;

	switch (trans) {
	case 'q':
	case 'Q': cout << "Thanks for banking with us!";
		break;
	case 'w':
	case 'W': cout << "Enter amount to be withdrawn: ";
		cin >> amount;
		if (amount < 0) cout << "Invalid amount.";
		else balance = balance - amount;
		cout << endl << "Current balance: " << balance;
		break;
	case 'd':
	case 'D': cout << "Enter amount to be deposited: ";
		cin >> amount;
		if (amount < 0) cout << "Invalid amount.";
		else balance = balance + amount;
		cout << endl << "Current balance: " << balance;
		break;
	case 'c':
	case 'C': cout << "Current balance: " << balance;
		break;
	default: cout << "Invalid transaction type";
		break;
	}

	return 0;
}
