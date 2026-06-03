#include <iostream>
using namespace std;

const int r = 3;
const int c = 3;

int main() {
	int array[r][c] = { 1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "Element[" << i << "," << j << "]:" << array[i][j] << endl;
		}
	}
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


