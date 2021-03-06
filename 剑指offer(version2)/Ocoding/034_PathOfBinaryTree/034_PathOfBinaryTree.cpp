// 034_PathOfBinaryTree.cpp: 定义控制台应用程序的入口点。
//==================================================================
// author:pb
// date:2019-06-08
//==================================================================

#include "stdafx.h"
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

void _FindPath
(
	TreeNode<int>*   root,
	int               Sum,
	std::vector<int>& path,
	int&              curSum
)
{
	curSum += root->val;
	path.push_back(root->val);

	// 如果是叶结点，并且路径上结点的和等于输入的值
	// 打印出这条路径
	bool isLeaf = root->left == nullptr && root->right == nullptr;
	if (curSum == Sum && isLeaf)
	{
		std::cout << "A path is found: ";
		std::vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter)
		std::cout << *iter << " ";
		std::cout << std::endl;
		
	}

	// 如果不是叶结点，则遍历它的子结点
	if (root->left != nullptr)
		_FindPath(root->left, Sum, path, curSum);
	if (root->right != nullptr)
		_FindPath(root->right, Sum, path, curSum);

	// 在返回到父结点之前，在路径上删除当前结点，
	// 并在currentSum中减去当前结点的值
	curSum -= root->val;
	path.pop_back();
}

void FindPath(TreeNode<int>* root, int Sum)
{
	if (root == nullptr)
		return;

	std::vector<int> path;
	int curSum = 0;
	_FindPath(root, Sum, path, curSum);
}


void Test()
{
	std::vector<int> arr = { 10, 5, 4, '#','#', 7, '#','#', 12, '#','#' };
	TreeNode<int> *root = CreatBinaryTree(arr);
	FindPath(root,22);
}
int main()
{
	Test();
	getchar();
    return 0;
}

