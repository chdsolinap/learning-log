//This program calculates the area of a circle
#include <iostream>
using namespace std;

int main()
{
	const float pi = 3.14;
	float rad, area;

	cout << "Please enter the radius of the circle: ";
	cin >> rad;

	area = pi * rad * rad; //formula for the area of a circle

	cout << endl << "The area of the circle is " << area;

	return 0;
}
