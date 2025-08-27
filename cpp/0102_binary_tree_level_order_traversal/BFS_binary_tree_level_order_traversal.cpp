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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    題旨：
        前序走訪輸入一二元樹，遇到空值就跳過，同一階層子樹為一組result輸出

    邏輯：
        輸出：
            定義為result

        處理：
            空樹，直接輸出
            if(root==NULL) return {};

            將指標存入結果
            vector<vector<int> result

            目前ptr不是NULL時，存入q以供使用
            queue<TreeNode*> q
            q.push(root)
            while(!q.empty()) {
                int size=q.size()       //階層元素數目
                vector<int> level;      //目前level
                for (int i=0; i<size; ++i) {
                    TreeNode* nowNode=q.front();
                    q.pop();
                    level.push_back(node->val);     //存入ptr所指向的val

                    如往左，則在q新增左點
                    如往右，則在q新增右點
                }
                
            }
            回傳結果

        */
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};

        vector<vector<int>> result;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size=q.size();
            vector<int> level;

            for(int i=0; i<size; ++i) {
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(move(level));
        }
        return result;
    }
};

int main() {
	}

