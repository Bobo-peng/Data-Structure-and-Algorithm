// 055_TreeDepth.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include<vector>
#include<iostream>
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
int TreeDepth(TreeNode<int>* root)
{
	if (root == nullptr)
		return 0;
	return TreeDepth(root->left) > TreeDepth(root->right) ? TreeDepth(root->left) + 1 : TreeDepth(root->right) + 1;
}
void Test()
{
	std::vector<int> arr1 = { 10, 5, 3, 3, '#', '#', -2, '#', '#', 2, '#', 1, '#', '#', -3, '#', 11, '#', '#', };
	TreeNode<int> *root = CreatBinaryTree(arr1);
	int ret = TreeDepth(root);
}
int main()
{
	Test();
	getchar();
	return 0;
}