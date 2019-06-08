// 018_DeleteListNode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//==================================================================
// author:pb
// date:2019-06-08
//==================================================================

#include "pch.h"
#include <iostream>
#include<stack>
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
ListNode* DeleteList(ListNode* head, ListNode* del)
{
	if (head == nullptr || del == nullptr)
		return nullptr;
	if (head->next == nullptr)//只有一个节点
		return nullptr;
	if (del == head)//删除头节点
	{
		return head->next;
	}
	else if (del->next == nullptr)//删除尾节点
	{
		ListNode* cur = head;
		while (cur != nullptr)
		{
			if (cur->next == del)
				break;
			cur = cur->next;
		}
		cur->next = cur->next->next;
	}
	else//删除非头节点、非尾节点
	{
		del->val = del->next->val;
		del->next = del->next->next;
	}

	return head;
}
void Test()
{
	std::vector<int> arr1{ 1,2,3,4,5 };
	ListNode* head = CreatList(arr1);
	ListNode* del = head->next->next->next->next;
	ListNode* ret =DeleteList(head, head);
}
int main()
{
	Test();
}



