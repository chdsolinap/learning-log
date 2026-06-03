//Take Home Assignment 1, creating a source code from a given output
//Solutions for minor user input errors were applied
#include <iostream>
#include <string> //for getline()
#include <iomanip> //for fixed and setprecision()
using namespace std;

int main() {
	string name;
	char gender, color;
	double weight, feet, inches, totalInches, meters, BMI; //assuming user only inputs correct values
	bool diabetic;

	cout << "Enter your Full Name: ";
	getline(cin, name);

	cout << "Enter Gender[M/F]: ";
	cin >> gender;

	cout << "Enter weight[Kg]: ";
	cin >> weight;

	cout << "Enter height[feet and inches]: ";
	cin >> feet >> inches;

	cout << "What is you favorite color[B]lue,[G]reen,[O]range, Gol[d] : ";
	cin >> color;

	cout << "Are you diabetic[0-NO/1-YES]?: ";
	cin >> diabetic; cout << endl;

	//this is for the Name with a title, an output
	switch (gender) {
	case 'm':
	case 'M': cout << "Name: Mr. " + name << endl; break;
	case 'f':
	case 'F': cout << "Name: Ms. " + name << endl; break;
	default: cout << "Error: Invalid Gender." << endl; break;
	}

	//this is for the conversion of height to meters, an output
	totalInches = (feet * 12) + inches;
	meters = totalInches * 0.0254;
	cout << "Converted height to meter: " << fixed << setprecision(2) << meters << endl;

	//this is for the computation of BMI, an output
	BMI = weight / (meters * meters);
	cout << "BMI(Kg/m*m): " << fixed << setprecision(2) << BMI << endl;

	//this is for the BMI classification, an output
	if (BMI < 18.5) cout << "Classification: Underweight";
	else if (BMI >= 18.5 and BMI <= 24.9) cout << "Classification: Normal Weight";
	else if (BMI >= 25.0 and BMI <= 29.9) cout << "Classification: Overweight";
	else if (BMI >= 30.0 and BMI <= 34.9) cout << "Classification: Obese class I";
	else if (BMI >= 35.0 and BMI <= 39.9) cout << "Classification: Obese class II";
	else if (BMI >= 40) cout << "Classification: Obese class III";
	cout << endl;

	//this is for the color meaning, an output
	switch (color) {
	case 'b':
	case 'B': cout << "You are a DIRECTOR."; break;
	case 'g':
	case 'G': cout << "You are a SOCIALIZER."; break;
	case 'o':
	case 'O': cout << "You are a SUPPORTER."; break;
	case 'd':
	case 'D': cout << "You are a THINKER."; break;
	default: cout << "Error: Invalid color input."; break;
	}
	cout << endl;

	//this is for the diabetic's reminder, an output
	if (diabetic) cout << "Please monitor your sugar level.";
	else cout << "Do not forget to exercise.";
	cout << endl;

	return 0;
}