/*
	Filename: two_sum.cpp
	Author: yu1
	Date: 2024-11-29 23:32:50 +0800

	Description:
		Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
		You may assume that each input would have exactly one solution, and you may not use the same element twice.
		You can return the answer in any order.

	Example 1:
		Input: nums = [2,7,11,15], target = 9
		Output: [0,1]
		Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
		
	Example 2:
		Input: nums = [3,2,4], target = 6
		Output: [1,2]

	Example 3:
		Input: nums = [3,3], target = 6
		Output: [0,1]
*/
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	}
	return {};	//如果無解
}


int main() {
	//開啟檔案
	ifstream inputFile("input");

	//如"input"不存在
	if (!inputFile) {
		cerr << "testcase does NOT exist" <<endl;
		return 1;
	}
	
	/*
	使用while-loop將文件內容存入array "nums"
	input格式：
		a1 a2 a3 .. aN
		target
	
	*/
	//初始化array "nums"
	vector<int> nums;
	int target;
	int number;
	while (inputFile >> number) {
		nums.push_back(number);	
	}
	
	//關閉檔案
	inputFile.close();

	//檢查測資
	//至少要有兩行數據
	if (nums.size() < 2) {
		cerr << "TestCase is ERROR" << endl;
		return 1;
	}
	
	//指定最後一行為input_target
	target=nums.back();
	nums.pop_back();

	//輸出結果
	//如無解答則另外輸出訊息
	//if-loop
	vector<int> result=twoSum(nums, target);
	if (!result.empty()) {
		cout << result[0] << " " << result[1] << endl;
	}
	else {
		cout << "No Result" << endl;
	}

	return 0;
}
