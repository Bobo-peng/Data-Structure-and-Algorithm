// 032_PrintBinaryTreeByLayerOrder.cpp: 定义控制台应用程序的入口点。
//==================================================================
// author:pb
// date:2019-06-08
//==================================================================

#include "stdafx.h"
#include<queue>
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
void PrintBinaryTreeByLayer(TreeNode<int>* root)
{
	std::queue<TreeNode<int>*> q;
	TreeNode<int> * last = root;
	TreeNode<int>* nlast = root;
	q.push(root);
	std::vector<int> ret;
	while (!q.empty())
	{
		
		TreeNode<int>* tmp = q.front();
		//std::cout << tmp->val << ' ';
		q.pop();
		ret.push_back(tmp->val);
		if (tmp->left)
		{
			q.push(tmp->left);
			 nlast = tmp->left;
		}
		if (tmp->right)
		{
			q.push(tmp->right);
			 nlast = tmp->right;
		}
		if (tmp == last)
		{
			for (int i = 0; i < ret.size(); ++i)
				std::cout << ret[i] << " ";
			std::cout << std::endl;
			ret.clear();
			//std::cout << std::endl;
			last = nlast;
		}
	}

}
void Test()
{
	std::vector<char> arr = { 'a', 'b', '#', '#', 'c', '#', '#' };
	std::vector<int> arr1 = { 10, 5, 3, 3, '#', '#', -2, '#', '#', 2, '#', 1, '#', '#', -3, '#', 11, '#', '#', };
	//TreeNode<char> *root = CreatBinaryTree(arr);
	TreeNode<int> *root = CreatBinaryTree(arr1);
	PrintBinaryTreeByLayer(root);
}
int main()
{
	Test();
	getchar();
    return 0;
}

