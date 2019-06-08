// 026_SubInTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
bool _isSubTree(TreeNode* root1, TreeNode* root2)
{
	if (root2 == nullptr)
		return true;
	if (root1 == nullptr)
		return false;
	if (root1->val != root2->val)
		return false;
	return _isSubTree(root1->left, root2->left) && _isSubTree(root1->right, root2->right);
}
bool isSubTree(TreeNode* root1, TreeNode* root2)
{
	bool ret = false;
	if (root1 != nullptr && root2 != nullptr)
	{
		if (root1->val == root2->val)
			ret = _isSubTree(root1, root2);
		if (!ret)
			ret = isSubTree(root1->left, root2);
		if(!ret)
			ret = isSubTree(root1->right, root2);
	}
	return ret;
}
void Test()
{
	std::vector<int> preOrder{ 1, 2, 4, 7, 3, 5, 6, 8 };
	std::vector<int>  inOrder{ 4, 7, 2, 1, 5, 3, 8, 6 };

	std::vector<int> preOrder1{ 3,5,6 };
	std::vector<int>  inOrder1{ 5,3,6};
	TreeNode* root1 = Construct(preOrder, inOrder);
	TreeNode* root2 = Construct(preOrder1, inOrder1);
	bool ret = isSubTree(root1, root1);
}
int main()
{
	Test();
}


