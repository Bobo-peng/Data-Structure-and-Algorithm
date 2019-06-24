#pragma once
#include<vector>
#include "stdafx.h"
#include "CRandom.h"
#include<ctime>
//#include"CRandom.cpp"
using namespace std;
template<typename T>
class testA
{
public:
	T a;
	
	static T add(T a,T b)
	{
		return a + b;
	}
};
template<typename T>
class  CRandom
{
public:
	CRandom();
	~CRandom();

	//static vector<T> Random(vector<T>&,T, T, T);
	//static vector<int> Random(vector<int>&,int, int, int);
	static vector<T> Random(vector<T> &arr, T n, T L, T R)
		//vector<int> CRandom::Random(vector<int> &arr,int n, int L, int R)
	{
		srand((unsigned)time(NULL));//ÖÖ×Ó
		for (int i = 0; i < n; i++)
		{
			arr.push_back(rand() % (R - L) + L);
		}

		return arr;
	}
};

