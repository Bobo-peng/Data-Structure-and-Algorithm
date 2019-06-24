#include "stdafx.h"
#include "CRandom.h"
#include<vector>
#include<ctime>

 template<class T>
 CRandom<T>::CRandom()
{
}

 template<class T>
CRandom<T>::~CRandom()
{
}


// template<class T> vector<T> CRandom<T>::Random(vector<T> &arr,T n, T L, T R)
//{
//	// TODO: 在此处添加实现代码.
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		arr.push_back(rand() % (R - L) + L);
//	}
//
//	return arr;
//}
//