/*
Filename: ptr_vali.cpp
Author: yu1
Date: 2024-12-11 16:56:56 +0800

Description: 
	*/
#include<iostream>
using namespace std;
int main() {
	int var=20;
	int *ptr;

	ptr= &var;

	cout<<"Value: "<< var << endl;
	cout<<"Pointer: " << ptr << endl;
	}

