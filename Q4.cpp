//============================================================================
// Name        : Q4.cpp
// Author      : Malaika
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
void allocate(int **&arr,int row,int column) {

	arr=new int*[row];

	for(int i=0; i<row; i++) {

		arr[i]=new int [column];

	}
}
void initialize(int **arr, int row,int column) {

	for(int i=0; i<row; i++) {

		for(int j=0; j<column; j++) {

			cin>>arr[i][j];
		}
	}
}


int equal(int **artifact1, int **artifact2, int row, int column,int i=0,int j=0) {
	if(i>=row) return 1;

	if(artifact1[i][j]==artifact2[i][j]) {
		if(j<column) {
			return equal(artifact1,artifact2,row,column,i,j+1);
		}
		else
			return equal(artifact1,artifact2,row,column,i+1,0);
	}

	else return 0;

	return 0;
}
void deallocate(int ** arr, int row, int column) {
    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
int main() {

	int row;
	int column;

	cout<<"Enter the number of rows:";
	cin>>row;
	cout<<"Enter the number of columns:";
	cin>>column;

	int **arr1;
	int **arr2;

	allocate(arr1,row,column);
	allocate(arr2,row,column);

	cout<<"Enter the elements for first artifact";
	initialize(arr1,row,column);

	cout<<"Enter the elements for second artifact";
	initialize(arr2,row,column);

	if( equal(arr1,arr2,row,column))
	{
		cout<<"Artifacts Match";
	}

	else
	{
		cout<<"Artifacts Do Not Match";
	}

	deallocate(arr1,row,column);
	deallocate(arr2,row,column);
}
