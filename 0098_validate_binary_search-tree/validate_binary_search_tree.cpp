/*
Filename: validate_binary_search-tree.cpp
Author: yu1
Date: 2024-12-05 02:14:14 +0800

Description:
	Given the root of a binary tree, determine if it is a valid binary search tree (BST).
	A valid BST is defined as follows:
	The left subtree of a node contains only nodes with keys less than the node's key.
	The right subtree of a node contains only nodes with keys greater than the node's key.
	Both the left and right subtrees must also be binary search trees.
 
	Example 1:
		Input: root = [2,1,3]
		Output: true
		Example 2:

	Example 2:
		Input: root = [5,1,4,null,null,3,6]
		Output: false
		Explanation: The root node's value is 5 but its right child's value is 4.
	*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
/*
    驗證二元搜尋樹
    二元搜尋樹特徵：
    每個節點最多只有兩個子樹
    右子樹必大於左子樹
    中序走訪的情況下，剛好是由小到大
    #空樹也算
            
    logic:
        先將空樹提出：
            if(root==NULL) return 0;
            
        中序走訪(遞迴, 左->中->右, 定義：自己呼叫自己)，如是小->大排列就回傳0, 否就回傳1
            int inOrderTraversal(TreeNode* root, TreeNode*& prev)
            (指向目前節點, 和前一個節點)
            先左走訪：
                !inOrderTraversal(root->left, prev) return -1;
            走訪過程中如出現目前節點值(root->val)大於上一個節點(prev->val)，回傳-1(BST中子樹皆小於根)
                prev != NULL && (prev->val) >= (root->val) return -1;

            遞迴完成, 更新節點值：
                prev=root;

            再回傳root提供右走訪
                return inOrderTraversal(root->right, prev)
                    
    output:
        回傳值給bool isValidBST(TreeNode* root)檢查，如不為0，
        bool value == false
        */
int inOrderTraversal(TreeNode* root, TreeNode*& prev) {
	if(root==NULL) return 0;
	if(!inOrderTraversal(root->left, prev)) return false;
	if(prev!=NULL && prev->val => root->val) return false;
	prev=root;
	return (root->right, prev);
	}
bool vBST(TreeNode* root) {
	TreeNode* prev=NULL;
	return isOrderTraversal(root, prev);
	}

int main() {
	}

