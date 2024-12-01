/*
	Filename: binary_search.cpp
	Author: yu1
	Date: 2024-12-01 11:41:32 +0800

	Description:
		Given an array of integers nums which is sorted in ascending order
		, and an integer target, write a function to search target in nums. 
		If target exists, then return its index. Otherwise, return -1.

		You must write an algorithm with O(log n) runtime complexity.

		Example 1:
			Input: nums = [-1,0,3,5,9,12], target = 9
			Output: 4
			Explanation: 9 exists in nums and its index is 4
		
		Example 2:
			Input: nums = [-1,0,3,5,9,12], target = 2
			Output: -1
		Explanation: 2 does not exist in nums so return -1
*/
#include<iostream>
using namespace std;
int binary_search(vector<int>& nums, target) {
	//二元搜尋
	//算法：
	//左邊界nums[0], 右邊界nums[tails], 以及中間值nums[middle]
	//如target>nums[middle],則偏右邊界
	//反則偏左
	int left=0;
	int right=nums.size()-1;
	while (left<=right) {
		int middle=(left+right)/2;
		if (target>nums[middle]) {
			//重定義range
			//range右偏
			left=middle+1;
			}
		else if (target<nums[middle]) {
			//range左偏
			right=middle-1;
			}
		else {
			return middle;
			}
		}
	return -1;
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

