/*
Filename: lonhest_substring_without_repeating_characters.cpp
Author: yu1
Date: 2024-12-11 22:26:19 +0800

Description: 
	Given a string s, find the length of the longest substring 
	without repeating characters.

	Example 1:
		Input: s = "abcabcbb"
		Output: 3
		Explanation: The answer is "abc", with the length of 3.

	Example 2:
		Input: s= "bbbbb"
		Output: 1
		Explanation: The answer is "b", with the length of 1.

	Example 3:
		Input: s = "pwwkew"
		Output: 3
		Explanation: The answer is "wke", with the length of 3.
			Notice that the answer must be a substring, 
			"pwke" is a subsequence and not a substring.
		*/
#include<iostream>
#include<fstream>
#include<unordered_set>
#include<string>
using namespace std;
/*
一組字串 找出最常的不重複組合，並輸出長度

不重複組合 組合長度
	int maxLength
	save string

	input:
		string s

	output:
		a number

	將字符存入hashtable 使用邊界操作
	double vector設置邊界(from left to right)
	當左邊界跟右邊界重複
		縮小邊界(++left)

	沒有重複字元的情況下
		擴大邊界(right=0 ++right)
		
	*/
int longthOfLongestSubstring(string s) {
    //save testcase(string) as hash map
	unordered_set<char> seen;
	int maxLength;
	int left=0;

	for (int right=0; right<s.size(); ++right) {
		//seen.end() == left edge
		while(seen.find(s[right])!=seen.end()) {
			seen.erase(s[left]);
			++left;
			}
		seen.insert(s[right]);

		//+1
		//because from 0~end-1
		maxLength=max(maxLength, right-left+1);
		}
		return maxLength;
	}

int main() {
	}

