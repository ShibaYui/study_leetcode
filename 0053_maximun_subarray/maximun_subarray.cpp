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
#include<fstream>	//讀取外部檔案
using namespace std;

//將testcase存入陣列，以指標指出（指標型別：int）
int maxSubArray(vector<int>& nums) {
	//以DP計算
	//規劃模式：兩項之和（上次結果&下一項），與上次的結果比較，如較大則更新結果
	//從nums[0]開始代入
	//初始化總和
	//初始化紀錄_總和
	int max_sum=nums[0];
	int noted_sum=nums[0];
	for (int i=1; i<nums.size(); ++i) {
		//計算兩項之和，並紀錄於noted_sum
		//得到較大的值，並紀錄於max_sum
		noted_sum=max(nums[i], noted_sum+nums[i]);
		//用max()確保輸出必為最大值
		max_sum=max(max_sum, noted_sum);
	}
	return {max_sum};
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
