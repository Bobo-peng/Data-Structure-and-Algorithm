// binaryTree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
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
TreeNode<T> *CreatBinaryTree(vector<T> &arr)
{
	TreeNode<T> *proot;
	if (arr[index] == '#')
	{
		proot = NULL;
		index++;
	}
	else
	{
		proot = new TreeNode<T> (arr[index++]);
		proot->left = CreatBinaryTree(arr);
		proot->right = CreatBinaryTree(arr);
		
	}
	return proot;
}
//2.前序打印
template<typename T>
void prePrint(TreeNode<T> *proot)
{
	if (proot)
	{
		cout << proot->val << " ";
		prePrint(proot->left);
		prePrint(proot->right);
	}
}
//3.非递归前序打印(non-recursion)
template<typename T>
void nonre_prePrint(TreeNode<T> *proot)
{
	stack<TreeNode<T> *> stree;
	TreeNode<T> *p = proot;
	while (p || !stree.empty())
	{
		if(p)
		{
			cout << p->val << ' ';
			stree.push(p);
			p = p->left;
		}
		else
		{
			p = stree.top();
			stree.pop();
			p = p->right;
		}
	}

}
//4.中序打印
template<typename T>
void midPrint(TreeNode<T> *proot)
{
	if (proot)
	{
		
		midPrint(proot->left);
		cout << proot->val << " ";
		midPrint(proot->right);
	}
}
//5.非递归中序打印(non-recursion)
template<typename T>
void nonre_midPrint(TreeNode<T> *proot)
{
	stack<TreeNode<T> *> stree;
	TreeNode<T> *p = proot;
	while (p || !stree.empty())
	{
		if (p)
		{
			stree.push(p);
			p = p->left;
		}
		else
		{
			p = stree.top();
			cout << p->val << ' ';
			stree.pop();
			p = p->right;
		}
	}

}
//6.后序打印
template<typename T>
void postPrint(TreeNode<T> *proot)
{
	if (proot)
	{
		postPrint(proot->left);
		postPrint(proot->right);
		cout << proot->val << " ";
	}
}
//7.非递归后序打印(non-recursion)
template<typename T>
void nonre_postPrint(TreeNode<T> *proot)
{
	stack<TreeNode<T> *> stree;
	TreeNode<T> *p = proot;
	TreeNode<T> *last = NULL;
	while (p || !stree.empty())
	{
		while (p)
		{
			stree.push(p);
			p = p->left;
		}
		p = stree.top();
		if (p->right && p->right != last)
		{
			p = p->right;
		}
		else
		{
			cout << p->val << ' ';
			stree.pop();
			last = p;
			p = NULL;
		}

	}
}
//8.非递归后序打印(non-recursion2);参考：https://www.cnblogs.com/wuiCoding/p/6670620.html
template<typename T>
void nonre_postPrint2(TreeNode<T> *proot)
{
	stack<TreeNode<T> *> stree;
	stack<TreeNode<T> *> spost;
	TreeNode<T> *p = proot;
	stree.push(p);
	while (!stree.empty())
	{
		p = stree.top();
		spost.push(p);
		stree.pop();
		if (p->left)
		{
			stree.push(p->left);
		}
		if (p->right)
		{
			stree.push(p->right);
		}
	}
	while (!spost.empty())
	{
		p = spost.top();
		cout << p->val << ' ';
		spost.pop();
	}
}

//9.按层打印
template<typename T>
void layerPrint(TreeNode<T> *proot)
{
	queue<TreeNode<T> *> qtree;
	qtree.push(proot);
	TreeNode<T> *last = proot;
	TreeNode<T> *nlast = proot;
	while (qtree.size())
	{
		TreeNode<T> *temp = qtree.front();
		cout << temp->val<<' ';
		qtree.pop();
		if (temp->left != NULL)
		{
			qtree.push(temp->left);
			nlast = temp->left;
		}
			
		if (temp->right != NULL)
		{
			qtree.push(temp->right);
			nlast = temp->right;
		}
			
		if (last == temp) {
			cout << endl;
			last = nlast;
		}
	}
}
//10.翻转二叉树（递归）
template<typename T>
TreeNode<T> * Reverse(TreeNode<T> *proot)
{
	if (proot->left || proot->right)
	{
		TreeNode<T> * temp = proot;
		temp = proot->left;
		proot->left = proot->right;
		proot->right = temp;
	}
	if(proot->left)
		Reverse(proot->left);
	if (proot->right)
		Reverse(proot->right);
	return proot;
}
//11.非递归后序打印(Reverse2)：使用队列，按层遍历
template<typename T>
TreeNode<T> * Reverse2(TreeNode<T> *proot)
{
	queue<TreeNode<T> *> qtree;
	qtree.push(proot);
	while (qtree.size())
	{
		TreeNode<T> *p = qtree.front();
		qtree.pop();
		//左右交换
		TreeNode<T> *temp = p->left;
		p->left = p->right;
		p->right = temp;

		if (p->left != NULL)
		{
			qtree.push(p->left);
		}

		if (p->right != NULL)
		{
			qtree.push(p->right);
		}
	}
	return proot;
}
//12.非递归后序打印(Reverse3)：使用栈，按层遍历
template<typename T>
TreeNode<T> * Reverse3(TreeNode<T> *proot)
{
	stack<TreeNode<T> *> stree;
	stree.push(proot);
	while (stree.size())
	{
		TreeNode<T> *p = stree.top();
		stree.pop();
		//左右交换
		TreeNode<T> *temp = p->left;
		p->left = p->right;
		p->right = temp;

		if (p->left != NULL)
		{
			stree.push(p->left);
		}

		if (p->right != NULL)
		{
			stree.push(p->right);
		}
	}
	return proot;
}
//13.二叉树最大深度
template<typename T>
int maxDepth(TreeNode<T> *proot)
{
	if (proot == NULL)
		return 0;
	return 1 + max(maxDepth(proot->left), maxDepth(proot->right));
}
int lengthOfLongestSubstring(string s) 
{
	   int m[256] = { 0 }, res = 0, left = 0;
	   for (int i = 0; i < s.size(); ++i) 
	   {
			if (m[s[i]] == 0 || m[s[i]] < left) 
			{
				res = max(res, i - left + 1);
			}
			else 
			{
				 left = m[s[i]];
			}
			m[s[i]] = i + 1;
		}
	   return res;
}
int lengthOfLongestSubstring1(string s) {
	int m[256];
	int k = 256;
	while (k-- > 0)
		m[k] = -1;
	int j = 0;
	int ret = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (m[s[i]] == -1 || m[s[i]] < j)
		{
			ret = max(ret, i - j + 1);
		}
		else
		{
			j = m[s[i]] + 1;
		}
		m[s[i]] = i;
	}
	return ret;
}
int lengthOfLongestSubstring2(string s) {
	
	vector<int> m(256,-1);
	int j = -1;
	int ret = 0;
	for (int i = 0; i < s.size(); i++)
	{
		j = max(j, m[s[i]]);
		m[s[i]] = i;
		ret = max(ret, i - j);
	}
	return ret;
}
int main()
{
	string s = "abcadef";
	string s1 = "abccbaaaaagfghitpuapnvamvbarytairuakghtmiaaaa";
	string s2 = "tmmzuxt";	
	int r1 = lengthOfLongestSubstring(s2);
	int r2 = lengthOfLongestSubstring1(s2);
	int r3 = lengthOfLongestSubstring2(s2);
	//vector<char> arr(7);
	vector<char> arr = { 'a', 'b', '#', '#', 'c', '#', '#' };
	vector<int> arr1 = { 10, 5, 3, 3, '#', '#', -2, '#', '#', 2, '#', 1, '#', '#', -3, '#', 11, '#', '#', };
	//TreeNode<char> *root = CreatBinaryTree(arr);
	TreeNode<int> *root = CreatBinaryTree(arr1);
	
	cout << "前序："<< endl;
	prePrint(root);
	cout << endl;
	cout << "非递归前序：" << endl;
	nonre_prePrint(root);
	cout << endl;
	cout << "中序：" << endl;
	midPrint(root);
	cout << endl;
	cout << "非递归中序：" << endl;
	nonre_midPrint(root);
	cout << endl;
	cout << "后序：" << endl;
	postPrint(root);
	cout << endl;
	cout << "非递归后序：" << endl;
	nonre_postPrint(root);
	cout << endl;
	cout << "非递归后序2：" << endl;
	nonre_postPrint2(root);
	cout << endl;
	cout << "按层打印：" << endl;
	layerPrint(root);
	cout << endl;
	Reverse(root);
	cout << "按层打印(翻转)：" << endl;
	layerPrint(root);
	cout << endl;
	Reverse2(root);
	cout << "按层打印(翻转使用queue)：" << endl;
	layerPrint(root);
	cout << endl;
	Reverse3(root);
	cout << "按层打印(翻转使用stack)：" << endl;
	layerPrint(root);
	cout << endl;
	int depth = maxDepth(root);
	cout << "最大深度：" << depth << endl;
	getchar();
	return 0;
}

