/*
	Filename: valid_palindrome.cpp
	Author: yu1
	Date: 2024-11-30 13:32:59 +0800

	Description:
		A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
		it reads the same forward and backward. Alphanumeric characters include letters and numbers.
		Given a string s, return true if it is a palindrome, or false otherwise.
		判斷是否為"回文串"（正向/反向讀取意義相同）

		Example 1:
			Input: s = "A man, a plan, a canal: Panama"
			Output: true
			Explanation: "amanaplanacanalpanama" is a palindrome.
	
		Example 2:
			Input: s = "race a car"
			Output: false
			Explanation: "raceacar" is not a palindrome.

		Example 3:
			Input: s = " "
			Output: true

		Explanation: 
			s is an empty string "" after removing non-alphanumeric characters.
			Since an empty string reads the same forward and backward, it is a palindrome.
		
*/
#include<iostream>
#include<fstream>
#include<string>
//for "isalnum" & "tolower"
#include<cctype>
using namespace std;
bool isPalindrome(string s) {
	//double pointer
	//read left-pointer & right-pointer
		//check is or isn't a character or number (using "isalnum")
	//compare them (using "tolower")
	//if left != right, return false, loop stop
	//if s[left] == s[right], return true, move pointer to next site

	//初始化左右指針
	int left=0;
	int right=s.size()-1;
	
	//left-pointer has to be smaller than right-pointer
	while (left<right) {
		//if s[left] is NOT a number of character
		//jump to s[left+1]
		while (left<right && !isalnum(s[left])) {
			++left;
			}
		//if s[right] is NOT a number or character
		//jump to s[right-1]
		while (left<right && !isalnum(s[right])) {
			--right;
			}
		
		if (tolower(s[left]) != tolower(s[right])) {
			return false;
			}
		++left;
		--right;
		}
	return true;
	}

int main() {
	//透過ifstream讀取testcase"input", #include<fstream>
	//判斷是否存在，如不存在return 1;
	/*使用while-loop逐行讀取字串"while(getline(input, line))"
		ex.input:
			i am a dog
		*/
	//關閉檔案
	//回傳結果，如為空值，return 1;
	ifstream input("input");
	if (!input) {
		cerr << "File is NOT exist" << endl;
		return 1;
		}
	//初始化逐行讀取
	string content, line;
	while (getline(input, line)) {
		//將內容接續
		content += line;
		}
	input.close();
	if (content.empty()) {
		cerr << "testcase is EMPTY" << endl;
		return 1;
		}
	cout << (isPalindrome(content) ? "true" : "false")  << endl;
	return 0;
	}
