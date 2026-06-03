#include <iostream>
using namespace std;

const int r = 3;
const int c = 3;

void printArray(int[r][c]);

void changedToFive(int[r][c]);

void sumOfOdd(int[r][c]);

int main() {
	//	int array[r][c]={1,2,3,4,5,6,7,8,9};
	//	
	//	for(int i=0; i<r; i++){
	//		for(int j=0; j<c; j++){
	//			cout<<"Element["<<i<<","<<j<<"]:"<<array[i][j]<<endl;
	//		}
	//	}
	//	--------------------------------------------------------------------
	//	int array[r][c];
	//	cout<<"Enter a number: ";
	//
	//	for(int i=0; i<r; i++){
	//		for(int j=0; j<c; j++){
	//			cin>>array[i][j];
	//			cout<<"Element["<<i<<","<<j<<"]:"<<array[i][j]<<endl;
	//			
	//		}
	//	}
	// 	----------------------------------------------------------------------
	int array[r][c];
	cout << "Enter a number: ";

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> array[i][j];
		}
	}
	//	printArray(array);
	changedToFive(array);
	return 0;
}

void printArray(int number[r][c]) {
	number[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "Element[" << i << "," << j << "]:" << number[i][j] << endl;

		}
	}

}

void changedToFive(int number[r][c]) {
	int x;
	cout << "Enter a number to be changed: ";
	cin >> x;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (number[i][j] == x) number[i][j] = 5;
			cout << "Element[" << i << "," << j << "]:" << number[i][j] << endl;
		}
	}
	sumOfOdd(number);
}

void sumOfOdd(int number[r][c]) {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (number[i][j] % 2 == 1) {
				sum = sum + number[i][j];
			}
		}
	}
	cout << "The sum of all odd numbers is: " << sum;
}
