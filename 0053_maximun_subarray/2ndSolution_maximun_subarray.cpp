/*
	Filename: maximun_subarray.cpp
	Author: yu1
	Date: 2024-11-29 21:56:00 +0800

	Description:
		Given an integer array nums, find the subarray with the largest sum, and return its sum.

 	Example 1:
		Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
		Output: 6
		Explanation: The subarray [4,-1,2,1] has the largest sum 6.

	Example 2:
		Input: nums = [1]
		Output: 1
		Explanation: The subarray [1] has the largest sum 1.

	Example 3:
		Input: nums = [5,4,-1,7,8]
		Output: 23
		Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
	
	Constraints:
		1 <= nums.length <= 105
		-104 <= nums[i] <= 104

	Follow up: 
		If you have figured out the O(n) solution, 
		try coding another solution using the divide and conquer approach, which is more subtle. 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>	//read file
using namespace std;

/*
input:
	vector<int> Ref.

output:
	a integer

logic:
	int saveFlag
	int sum
	sum=num[0]
	saveFlag=num[0]

	i=n:
		saveFlag=max(saveFlag, saveFlag+num[n])
		sum=max(sum, saveflag)

	i=n:
		sum=num

		
		
	*/
int maxSubArray(vector<int>& nums) {
	int saveFlag=nums[0];
	int sum=nums[0];
	for (int i=1; i<nums.size(); ++1) {
		saveFlag=max(nums[i], saveFlag+nums[i]);
		sum=max(sum, saveFlag);
		}
	return sum;
	}

int main() {
	//開啟檔案
	ifstream inputFile("input");

	//如"input"不存在
	if (!inputFile) {
		cerr << "testcase does NOT exist" <<endl;
		return 1;
	}
	
	//將文件內容存入array
	//初始化array
	vector<int> nums;
	int iNumber;
	while (inputFile >> iNumber) {
		nums.push_back(iNumber);
	}
	
	//關閉檔案
	inputFile.close();

	//如檔案為空，回傳錯誤
	if(nums.empty()) {
		cerr << "testcase is EMPTY." << endl;
		return 1;
	}
	cout << maxSubArray(nums) << endl;

	return 0;
}
