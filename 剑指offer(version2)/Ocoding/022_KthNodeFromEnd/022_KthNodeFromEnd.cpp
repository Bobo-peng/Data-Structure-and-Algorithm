// 022_KthNodeFromEnd.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//==================================================================
// author:pb
// date:2019-06-08
//==================================================================

#include "pch.h"
#include <iostream>
#include<vector>
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};
//创建链表
ListNode* CreatList(std::vector<int> &arr)
{
	int lsize = arr.size();
	if (lsize <= 0)
		return nullptr;
	ListNode* head = new ListNode(arr[0]);
	ListNode* cur = head;
	for (int i = 1; i < lsize; ++i)
	{
		ListNode* tmp = new ListNode(arr[i]);
		cur->next = tmp;
		cur = cur->next;
	}
	return head;
}
//释放链表
void DestroyList(ListNode* head)
{
	ListNode* cur = head;
	while (nullptr != cur)
	{
		cur = head;
		head = head->next;
		delete cur;
		cur = nullptr;
	}
}
ListNode* FindKthFromTail(ListNode* head, int k)
{
	if (head == nullptr)
		return head;
	if (k == 0)//k=0没有实际意义
		return nullptr;
	ListNode* fast = head, *slow = head;
	for (int i = 0; i < k-1; ++i)
	{
		fast = fast->next;
	}
	while (fast->next != nullptr)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
void Test()
{
	std::vector<int> arr1{ 1,2,3,4,5 };
	ListNode* head = CreatList(arr1);
	ListNode* ret = FindKthFromTail(head, 2);
	 ret = FindKthFromTail(head, 0);
	 ret = FindKthFromTail(head, 1);
	 ret = FindKthFromTail(head, 5);
}
int main()
{
	Test();
}


