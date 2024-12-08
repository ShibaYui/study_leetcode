/*
Filename: binary_tree_level_order_traversal.cpp
Author: yu1
Date: 2024-12-08 13:40:39 +0800

Description: 
	Given the root of a binary tree, 
	return the level order traversal of its nodes' values. 
	(i.e., from left to right, level by level).

	Example 1:
		Input: root = [3,9,20,null,null,15,7]
		Output: [[3],[9,20],[15,7]]

	Example 2:
		Input: root = [1]
		Output: [[1]]

	Example 3:
		Input: root = []
		Output: []

	*/
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
/*
    輸入:
        root指向

    輸出:
        得到root指向之後，帶入遍歷function，產生result

    邏輯:
        遞迴遍歷tree(需要節點指向， 深度值(初始為0), 以及vector<vector<int>>& result)
        result的結構:
        result={
            {1},        //level 0 (depth)
            {2,3},      //level 1
            {4,5,6}     //level 2
        }
        NULL即回傳
        將深度值存入depth, 並跟指向result的size比較:
            result空間必須>深度，才能容納節點
            如果depth>=result.size(), 將result.size增加1 (新增指向)
        將node->val填入目前result[]中的深度
        分別遍歷左邊子樹(記得深度+1)
        再遍歷右邊子樹(記得深度+1)
        最後call遍歷func (完成遞迴)
        中止條件: 下一個指向為空值（沒有子樹或本身就是空樹）
    */
    //不須回傳值，使用void
void dfs(TreeNode* node, int depth, vector<vector<int>>& result) {
	if(!node) return;
	if(depth=>result.size()) result.push_back({});
	result[depth].push_back(node->val);
	dfs(node->left, depth+1, result);
	dfs(node->left, depth+1, result);
	}

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> result;
	dfs(root, 0, result);
	return result;
	}

int main() {
	}

