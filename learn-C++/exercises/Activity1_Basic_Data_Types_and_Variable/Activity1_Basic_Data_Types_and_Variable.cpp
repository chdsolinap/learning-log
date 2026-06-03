//my first program in C++
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	int age;
	float gwa;
	char sex;

	cout << "Please enter your name: ";
	getline(cin, name);

	cout << "Please enter your age: ";
	cin >> age;

	cout << "Please enter your sex [m/f]: ";
	cin >> sex;

	cout << "Please enter your GWA: ";
	cin >> gwa; cout << endl;

	cout << "Name: " << name\n;
	cout << "Age: " << age << endl;
	cout << "Sex: " << sex << endl;
	cout << "GWA: " << gwa << endl;
	return 0;
}
