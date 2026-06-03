//#include <iostream>
//using namespace std;
//
//const int r=3;
//const int c=3;
//
//void changedToFive(int [r][c]);
//
//int sumOfOdd(int [r][c]);
//int sum=0;
//
//int main(){
//	
//	int array[r][c];
//	cout<<"Enter a number: ";
//
//	for(int i=0; i<r; i++){
//		for(int j=0; j<c; j++){
//			cin>>array[i][j];
//		}
//	}
//	
//	changedToFive(array);
//	cout<<"The sum of all the odd numbers is: "<<sum;
//	return 0;
//}
//
//void changedToFive(int number[r][c]){
//	int x;
//	cout<<"Enter a number to be changed: ";
//	cin>>x;
//	for(int i=0; i<r; i++){
//		for(int j=0; j<c; j++){
//			if(number[i][j] == x) number[i][j]=5;
//			cout<<"Element["<<i<<","<<j<<"]:"<<number[i][j]<<endl;
//		}
//	}
//	sumOfOdd(number);
//}
//
//int sumOfOdd(int number[r][c]){
//	for(int i=0; i<r; i++){
//		for(int j=0; j<c; j++){
//			if(number[i][j] % 2 == 1){
//				sum = sum + number[i][j];
//			}
//		}
//	}
//	return sum;
//}
