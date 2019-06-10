// 036_ConvertBinarySearchTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
template<typename T>
struct TreeNode {
	T val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(T x) :val(x), left(NULL), right(NULL) {};
};
//1.生成二叉树
int index = 0;
template<typename T>
TreeNode<T> *CreatBinaryTree(std::vector<T> &arr)
{
	TreeNode<T> *proot;
	if (arr[index] == '#')
	{
		proot = NULL;
		index++;
	}
	else
	{
		proot = new TreeNode<T>(arr[index++]);
		proot->left = CreatBinaryTree(arr);
		proot->right = CreatBinaryTree(arr);

	}
	return proot;
}
template<typename T>
void _Convert(TreeNode<T> * root, TreeNode<T> ** listNode)
{
	if (root == nullptr)
		return;
	TreeNode<T>* cur = root;
	if (cur->left != nullptr)
		_Convert(cur->left, listNode);
	cur->left = *listNode;
	if (*listNode != nullptr)
		(*listNode)->right = cur;
	*listNode = cur;
	if (cur->right != nullptr)
		_Convert(cur->right, listNode);
}
template<typename T>
TreeNode<T> *Convert(TreeNode<T> * root)
{
	TreeNode<T> * listNode = nullptr;
	_Convert(root, &listNode);
	while (listNode != nullptr && listNode->left != nullptr)
		listNode = listNode->left;
	return listNode;
}
void Test()
{
	std::vector<int> arr = { 10, 6, 4, '#', '#', 8, '#', '#', 14, 12, '#', '#', 16, '#', '#', };	
	TreeNode<int> *root = CreatBinaryTree(arr);
	TreeNode<int>* ret = Convert(root);
}
int main()
{
    Test(); 
}
