/*
	Filename: invert_binary_tree.cpp
	Author: yu1
	Date: 2024-11-30 21:59:31 +0800

	Description:
		Given the root of a binary tree, invert the tree, and return its root.

		Example 1:
			Input: root = [4,2,7,1,3,6,9]
			Output: [4,7,2,9,6,3,1]

		Example 2:
			Input: root = [2,1,3]
			Output: [2,3,1]

		Example 3:
			Input: root = []
			Output: []
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
TreeNode* invertTree(TreeNote* root) {
	//遞迴處理，前序走訪
	//子樹由上到下左右交換
	//依序中>左>走訪/交換（前序）
	if (root==NULL) {
		//如input為空值，直接回傳
		//空節點不需反轉
		return root;
		}
	swap(root->left, root->right);
	invertTree(root->left);
	invertTree(root->right);}


int main() {
	//透過ifstream讀取testcase"input", #include<fstream>
	//判斷是否存在，如不存在return 1;
	/*使用while-loop逐行讀取字串"while(getline(input, line))"
		ex.input:
			i am a dog
		*/
	//關閉檔案
	}

