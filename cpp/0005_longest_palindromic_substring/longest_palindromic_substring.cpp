/*
Filename: 0005_longest_palindromic_substring.cpp
Author: yu1
Date: 2024-12-12 22:03:11 +0800

Description: 
	*/
#include<iostream>
#include<unordered_set>
#include<string>
#include<fstream>
using namespace std;
/*
輸入一字串s，找出最長的回文字串，並輸出長度

logic:
	ex.
		badad
	回文字串定義:
		a[0]==a[n]
		a[1]==a[n-1]
		...
		a[n]==a[0]

	定義邊界 由中心點（或是雙重中心開始）左右擴展
		odd: 邊界為中心左右增加
		even: 邊界為中心*2左右相加
		中心為浮動值

	直到碰到邊界or非回文字符為止

	var:
		maxLength
		left_edge
		right_edge
		s.size()
		
		*/
string longestPalindrome(string s) {
	//if $input==NULL, return "";
	if(s.empty()) return "";
	int center;
	int maxLength=0;

	for (int i=0; i<s.size(); ++i) {
    	//edge defind
		if len_odd=defineEdge(s, i, i);
		if len_even=defineEdge(s, i, i+1);
		
		int len_cache=max(len_odd, len_even);
		
		if (len_catch>maxLength) {
        	maxLength=len_cache;
			center=i-(len_cache-1)/2;
		}
	}
	return s.substr(center, maxLength);

}
private:
	int defineEdge(const string& s, int left, int right) {
    	while(left>=0 && right<s.size() && s[left]==s[right]) {
        	--left;
			++right;
		}
		return right-left-1;
	}

int main() {
	}

