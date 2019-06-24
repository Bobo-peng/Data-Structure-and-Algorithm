#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
template <typename T>
struct Node {
	T data;
	Node<T> *next;
};
template <typename T>
Node<T> *CreatList(vector<T> &arr)
{
	//Node<T> *head = (Node<T>*)malloc(sizeof(Node<T>));
	Node<T> *head = new Node<T>;
	Node<T> *pre = head;
	Node<T> *p = NULL;
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		//p= (Node<T>*)malloc(sizeof(Node<T>));
		p = new Node<T>;
		pre->next = p;
		p->data = arr[i];
		pre = p;

	}
	p->next = NULL;
	return head->next;
}
template <typename T>
void PrintList(Node<T> *head)
{
	Node<T> *p = new Node<T>;
	p->next = head; //Ϊ�˷������
	while (p->next != NULL)
	{
		p = p->next;
		cout << p->data << "->";
	}
	cout<<"NULL"<< endl;
	
}
template <typename T>
Node<T>* reverseList(Node<T> *head)
{
	Node<T> *pre = NULL, *cur = head, *temp;
	while (cur != NULL)
	{
		temp = cur->next;
		cur->next = pre;//��ת
		pre = cur;
		cur = temp;
		
	}
	
	return pre;
}
//�����n��Ԫ�غ���
template <typename T>
Node<T> * addNode(Node<T> *head, T val, int n)
{
	
	Node<T> *p = head;
	int i = n - 1;
	while (i > 0)
	{
		p = p->next;
		i--;
	}
	Node<T> *q = new Node<T>;//Ҫ�����Ԫ��
	q->data = val;
	q->next = p->next;
	p->next = q;
	return head;
}
//ɾ����n��Ԫ�غ���
template <typename T>
Node<T> * delNode(Node<T> *head, int n)
{
	Node<T> *p = head;
	int i = n - 1;
	while (i > 0)
	{
		
		p = p->next;
		if (p->next == NULL)//���һ��Ԫ�أ�����ɾ��
			return head;
		i--;
	}
	if (p->next->next == NULL)//�����ڶ�����ɾ�����һ����
		p->next = NULL;
	else
	 p->next = p->next->next;
	
	return head;
}
int main()
{
	vector<int> arr(5);
	arr = {1,2,3,4,5};
	Node<int> *head = CreatList(arr);
	PrintList(head);
	/*Node<int> *rhead = reverseList(head);
	PrintList(rhead);*/
	Node<int> *addhead = addNode(head, 8, 3);
	PrintList(addhead);
	delNode(addhead,5);
	PrintList(addhead);
	getchar();
	return 0;
}