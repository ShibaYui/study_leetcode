/*
	Filename: 0141_linked_list_cycle.cpp
	Author: yu1
	Date: 2024-12-01 20:56:19 +0800

	Description:
		Given head, the head of a linked list, 
		determine if the linked list has a cycle in it.

		There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
		Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

		Return true if there is a cycle in the linked list. 
		Otherwise, return false.

	Example 1:
		Input: head = [3,2,0,-4], pos = 1
		Output: true
		Explanation: 
			There is a cycle in the linked list, 
			where the tail connects to the 1st node (0-indexed).

	Example 2:
		Input: head = [1,2], pos = 0
		Output: true
		Explanation: 
			There is a cycle in the linked list, 
			where the tail connects to the 0th node.

	Example 3:
		Input: head = [1], pos = -1
		Output: false
	
	Explanation: There is no cycle in the linked list.
*/
#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool hsaCycle(ListNode *head) {
	//check linklist has cycle or hasn't
	//if head && head->next == NULL, linklist is over or NULL
	//return false
	//init two pointers, slow(1 step) & fast(2 steps)
	//when linklist is NOT over(fast->next && fast all exist)
	//two pointers keepmoving
	//when fast-pointer == slow-pointer (they get same value) 
	//linklist has cycle
	//return false, or return false
	ListNode *fast=head;
	ListNode *slow=head;
	if (head==NULL || head->next==NULL) return false;
	while (fast && fast->next) {
		slow=slow->next;
		fast=fast->next->next;
		if (fast==slow) return true;
		}
	return false;
	}
int main() {
	}

