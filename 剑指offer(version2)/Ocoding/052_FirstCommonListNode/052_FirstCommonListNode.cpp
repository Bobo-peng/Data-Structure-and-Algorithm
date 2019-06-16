// 052_FirstCommonListNode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int ListLength(ListNode* head)
{
	int cnt = 0;
	ListNode* cur = head;
	while (cur != nullptr)
	{
		cur = cur->next;
		cnt++;
	}
	return cnt;
}
ListNode* FirstCommonListNode(ListNode* list1, ListNode* list2)
{
	int len1 = ListLength(list1);
	int len2 = ListLength(list2);
	ListNode* longList = list1;
	ListNode* shortList = list2;
	int lenDif = len1 - len2;
	if (len1 < len2)
	{
		longList = list2;
		shortList = list1;
		lenDif = len2 - len1;
	}
	for (int i = 0; i < lenDif; ++i)
	{
		longList = longList->next;
	}
	while (longList != nullptr && shortList != nullptr && longList->val != shortList->val)
	{
		shortList = shortList->next;
		longList = longList->next;
	}
	return longList;
}
void Test()
{
	std::vector<int> arr1{ 1,2,3,6,7 };
	std::vector<int> arr2{ 4,5};
	ListNode* head1 = CreatList(arr1);
	ListNode* head2 = CreatList(arr2);
	head2->next->next = head1->next->next->next;
	ListNode* ret = FirstCommonListNode(head1,head2);
}
int main()
{
    Test(); 
}

