//============================================================================
// Name        : Q2.cpp
// Author      : Malaika
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

int helper(int choco, int p_wrap, int wrappers = 0) {
    wrappers += choco;
    if (wrappers >= p_wrap) {
        int new_choco=wrappers/p_wrap;
        wrappers%=p_wrap;
        return choco+helper(new_choco, p_wrap, wrappers);
    }

    return choco;
}

int countChocolates(int money, int price, int p_wrap) {
	int choc = money/price;
	return helper(choc, p_wrap);}



int main() {
	int money;
	int price;
	int wrap;
	cout<<"Enter money:";
	cin>>money;
	cout<<"Enter price:";
	cin>>price;
	cout<<"Enter wrap:";
	cin>>wrap;
	cout<<countChocolates(money,price,wrap);
	return 0;}
