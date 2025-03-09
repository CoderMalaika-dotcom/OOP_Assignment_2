//============================================================================
// Name        : Q3.cpp
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

int sum(int **votes,int row,int column,int &partyAEvenVotes,int &partyBOddVotes, int i=0,int j=0){

 if(i>=row) return 1;

 if(j>=column) return sum(votes,row,column,partyAEvenVotes,partyBOddVotes,i+1,0);

 if(votes[i][j]%2==0)
 partyAEvenVotes+=votes[i][j];

 else
 partyBOddVotes+=votes[i][j];

return sum(votes,row,column,partyAEvenVotes,partyBOddVotes,i,j+1);
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

cout<<"Enter thenumber of rows:";
cin>>row;
cout<<"Enter the number of columns:";
cin>>column;

int **votes;
int partyAEvenVotes=0;
int partyBOddVotes=0;

allocate(votes,row,column);

cout<<"Enter the elements for the votes casted";
initialize(votes,row,column);

sum(votes,row,column,partyAEvenVotes,partyBOddVotes);
cout<<"\n Total votes for party A (Even):   "<<partyAEvenVotes<<"\n Total votes for party B (Odd):   "<<partyBOddVotes;

deallocate(votes,row,column);

}
