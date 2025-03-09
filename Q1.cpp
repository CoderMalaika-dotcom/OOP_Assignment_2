//============================================================================
// Name        : Q1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int helper (int arr[], int arr1[], int size , int i=0){
	if(i==size) return 0;
	arr1[i]=arr[i]+arr[i+1];
	return helper(arr,arr1,size,i+1);
}
void sumTriangle(int arr[],int size){
	if(size<1)return;
	int arr1[size-1];
    helper(arr,arr1,size);
	sumTriangle(arr1,size-1);
	cout<<"[";
	for(int i=0;i<size;i++){
		cout<<" "<<arr[i]<<" ";
	}
	cout<<"]"<<endl;
}
int main() {
   int size;
   cout<<"Enter size of triangle";
   cin>>size;
   int arr[size];
   cout<<"Enter the elements";
   for(int i=0;i<size;i++){
	   cin>>arr[i];
	   }
   sumTriangle(arr,size);

}
