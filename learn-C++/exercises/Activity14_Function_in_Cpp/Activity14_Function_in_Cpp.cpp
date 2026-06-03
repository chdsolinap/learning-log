#include <iostream>
using namespace std;

const float pi = 3.14;

void circle(); //NO-NO
void square(float); //NO-YES
float triangle(); //YES-NO
int rectangle(int, int); //YES-YES

int main() {
	char ch, ans;
	float s, l, A, w, x;

	do {
		system("CLS");
		cout << "This program compute for the area of " << endl;
		cout << "[C]ircle" << endl;
		cout << "[S]quare" << endl;
		cout << "[T]riangle" << endl;
		cout << "[R]ectangle" << endl;
		cout << "Enter your choice: ";
		cin >> ch; cout << endl;

		switch (toupper(ch)) {
		case 'C': circle(); break;
		case 'S':
			cout << "Enter length: ";
			cin >> s;
			square(s); break;
		case 'T': x = triangle();
			cout << "The area is: " << x << endl; break;
		case 'R':
			cout << "Enter width: ";
			cin >> w;
			cout << "Enter length: ";
			cin >> l;
			A = rectangle(w, l);
			cout << "The area is: " << A << endl; break;
		default: cout << "Invalid choice!" << endl; break;
		}
		cout << "Try again[y/n]: ";
		cin >> ans;
	} while (tolower(ans) == 'y');
	return 0;
}

void circle() {
	float r, A;
	cout << "Enter radius: ";
	cin >> r;
	A = pi * r * r;
	cout << "Area: " << A << endl;
}

void square(float x) {
	float z;
	z = x * x;
	cout << "The area is: " << z << endl;
}

float triangle() {
	float z, b, h;
	cout << "Enter base length: ";
	cin >> b;
	cout << "Enter height: ";
	cin >> h;
	z = (b * h) / 2;
	return z;
}

int rectangle(int x, int y) {
	int z;
	z = x * y;
	return z;
}


