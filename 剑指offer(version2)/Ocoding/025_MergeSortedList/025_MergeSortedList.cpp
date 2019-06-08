// 025_MergeSortedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
ListNode* MergeSortedList(ListNode* head1, ListNode*head2)
{
	ListNode* mergeHead,*cur;
	if (head1 == nullptr)
		return  head2;
	if (head2 == nullptr)
		return  head1;
	if (head1->val > head2->val)
	{
		mergeHead = cur = head2;
		head2 = head2->next;
	}
	else
	{
		mergeHead = cur = head1;
		head1 = head1->next;
	}	
	while (head1 != nullptr && head2 != nullptr)
	{
		if (head1->val > head2->val)
		{
			cur->next = head2;
			head2 = head2->next;
			cur = cur->next;	
		}
		else
		{
			cur->next = head1;
			head1 = head1->next;
			cur = cur->next;
		}	
	}
	if (head1 == nullptr)
		cur->next = head2;
	if (head2 == nullptr)
		cur->next = head1;
	return mergeHead;
}
void Test()
{
	std::vector<int> arr1{ 1,3,5,7 };
	std::vector<int> arr2{ 2,4,6,8 };
	ListNode* head1 = CreatList(arr1);
	ListNode* head2 = CreatList(arr2);
	ListNode* ret = MergeSortedList(head1, head2);

}
int main()
{
	Test();
}
