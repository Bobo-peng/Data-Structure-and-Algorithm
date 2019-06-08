// 023_EntryOfRingList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
ListNode* EntryOfRingList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return nullptr;
	ListNode* fast = head->next->next, *slow = head->next;
	while (fast != nullptr && fast->next != nullptr)
	{
		if (fast == slow)
		{
			ListNode* cur = head;
			while (1)
			{
				if (cur == slow)
					return cur;
				cur = cur->next;
				slow = slow->next;
			}
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return nullptr;
}
void Test()
{
	std::vector<int> arr1{ 1,2,3,4,5,6};
	ListNode* head = CreatList(arr1);
	head->next->next->next->next->next->next = head->next->next;
	ListNode* ret = EntryOfRingList(head);

	std::vector<int> arr2{ 1 };
	ListNode* head1 = CreatList(arr2);
	head1->next = head1;
	ret = EntryOfRingList(head1);
}
int main()
{
	Test();
}

