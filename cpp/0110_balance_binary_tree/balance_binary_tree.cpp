/*
	Filename: balance_binary_tree.cpp
	Author: yu1
	Date: 2024-12-04 01:50:43 +0800

	Description: 
*/

#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>
using namespace std;
/*判定是否為平衡二元樹
	左右子樹高度差不超過1
	左右子樹本身也必須是平衡二元樹
	*/
    
/*workflow:
	#define input:
		取得tree節點, ex. 3, 9, 20, null, null, 15, 7
			int height(TreeNode *root)
			(指向節點root的指標)
			回傳高度(int, 計算root~現在節點)
	
	#logic
		使用遞迴重複計算
		如節點為NULL，return 0(空樹為平衡)
		if (root=NULL) return 0;

		左子樹高度差：int leftHeight=height(root->left)
		右子樹高度差：int rightHeight=height(root->right)
		左右子樹高度差: abs(leftHeight-rightHeight)

		如果高度差<=1(為平衡樹), 繼續遞迴運算(直到頂部NULL為止)
		如高度差>1, return -1(-1值可同時中止遞迴);

		最後回傳左/右子樹中較大高度(確保在最下層)
		並+1用以提供下一層樹節點繼續遞迴

		題目中的bool isBalanced(TreeNode* root)
		在承接root值，判斷是否為平衡二元樹（bool-value, tree/false）

	#define output: 根據節點差異判定結果
		bool: return ture/false

		如果回傳值為-1, 輸出false "== -1 ? false : true;"
	*/
int height(TreeNode* root) {
	//如果為root本身為空值（到達頂部或為空樹）, return 0
	if (root==NULL) return 0;
	//值為指針間距離

	//遞迴定義：自己呼叫自己
	//如為二元平衡樹，遞迴最終結果必為0
	//反之為-1
	int leftHeight=height(root->left);
	int rightHeight=height(root->right);

	if (leftHeight==-1 || rightHeight==-1 || abs(leftHeight-rightHeight) > 1) {
		return -1;	
		}
	return max(leftHeight, rightHeight);

	}

bool isBalanced(TreeNode* root) {
	height(root) == -1 ? false : true;
	}

int main() {
	}

