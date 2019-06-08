// 027_MirrorOfBinaryTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};
TreeNode* _Construct(std::vector<int> &preOrder,
	int preStart,
	int preEnd,
	std::vector<int> &inOrder,
	int inStart,
	int inEnd)
{
	TreeNode* root = new TreeNode(preOrder[preStart]);
	if (preStart == preEnd) return root;
	int partion = preStart;
	for (int i = inStart; i <= inEnd; ++i)
	{
		if (inOrder[i] == preOrder[preStart])
		{
			partion = i;
			break;
		}
	}
	std::cout << "preStart=" << preStart << " preEnd=" << preEnd << " inStart=" << inStart << " inEnd=" << inEnd << " partion=" << partion << std::endl;
	int len = partion - inStart;

	if (len > 0)
	{
		root->left = _Construct(preOrder, preStart + 1, preStart + len, inOrder, inStart, partion - 1);
	}
	if (len < preEnd - preStart)
	{
		root->right = _Construct(preOrder, preStart + len + 1, preEnd, inOrder, partion + 1, inEnd);
	}
	return root;
}
TreeNode* Construct(std::vector<int> &preOrder, std::vector<int> &inOrder)
{
	if (preOrder.size() <= 0 || inOrder.size() <= 0)
		return nullptr;

	return _Construct(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1);
}
void MirrorBinaryTree(TreeNode* root)
{
	if (root == nullptr)
		return;
	if (root->left == nullptr && root->right == nullptr)
		return;
	TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	if (root->left)
		MirrorBinaryTree(root->left);
	if (root->right)
		MirrorBinaryTree(root->right);
}
void Test()
{
	std::vector<int> preOrder{ 1, 2, 4, 7, 3, 5, 6, 8 };
	std::vector<int>  inOrder{ 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode* root = Construct(preOrder, inOrder);
	MirrorBinaryTree(root);
}
int main()
{
   Test(); 
}
