/*
	Filename: 5_factorial_recursion.cpp
	Author: yu1
	Date: 2024-11-30 22:26:53 +0800

	Description:
		5! recursion
*/
#include<iostream>
using namespace std;
int factorial (int n) {
	//階乘定義：
		//1*2*3...n
	//import n=5
	if (n<=1) {
		return n;
		}
	//遞迴規則：n*(n-1)
	return n * factorial(n-1);
	}
int main() {
	int n=5;
	cout << factorial(n) << endl;
	}

