// sort.cpp: 定义控制台应用程序的入口点。
//
//#define _CRT_SECURE_NO_WARNINGS
#define INC_03_SELECTION_SORT_DETECT_PERFORMANCE_SORTTESTHELPER_H
#include "stdafx.h"
#include<vector>
#include<string>
#include<iostream>
#include"CRandom.h"
using namespace std;

//基础排序算法
//1.冒泡排序(假)
template<typename T>
vector<T> fbubbleSort(vector<T> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)//从没排好的元素区找最小的值，然后放在i的位置上（和打擂台一样）
			if (arr[i] < arr[j])
				swap(arr[i], arr[j]);
	}
	return arr;
}
//冒泡排序(真)
template<typename T>
vector<T> bubbleSort(vector<T> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size()-1-i; j++)//相邻交换
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
	}
	return arr;
}
//2.插入排序
template<typename T>
vector<T> insertSort(vector<T> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j > 0 && j < arr.size(); j--)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
			}
		}
	}
	return arr;
}
//3.选择排序
template<typename T>
vector<T> selectionSort(vector<T> &arr) {

	for (int i = 0; i < arr.size(); i++) {

		int minIndex = i;
		for (int j = i + 1; j < arr.size(); j++)//找到最小的索引值，只交换一次
			if (arr[j] < arr[minIndex])
				minIndex = j;

		swap(arr[i], arr[minIndex]);
	}
	return arr;
}
//4.归并排序******************************************
template<typename T>
vector<T> mergeSort(vector<T> &arr)
{
	_mergeSort(arr, 0, arr.size() - 1);
	return arr;
}
template<typename T>
void _mergeSort(vector<T> &arr, int start, int end)
{
	if (end - start < 1) return;
	int mid = (end + start) / 2;
	_mergeSort(arr, start, mid);
	_mergeSort(arr, mid+1, end);
	mmerge(arr, start, mid, end);
}
template<typename T>
void mmerge(vector<T> &arr, int start, int mid, int end)
{	
	int i = 0;
	vector<T> temp;//先将数组复制一份
	while (i <= end - start)
	{
		temp.push_back(arr[i + start]);
		i++;
	}
	for (int i = start, j = 0, k = mid + 1 - start; i <= end; i++)
	{
		if (j > mid - start)
		{
			arr[i] = temp[k++];
		}
		else if(k > end - start)
		{
			arr[i] = temp[j++];
		}
		else if (temp[j] <= temp[k])
		{
			arr[i] = temp[j++];
		}
		else
		{
			arr[i] = temp[k++];
		}
	}

}
//5.快速排序******************************************
template<typename T>
vector<T> quickSort(vector<T> &arr)
{
	_quickSort(arr, 0 ,arr.size() - 1);
	return arr;
}
template<typename T>
void _quickSort(vector<T> &arr, int start, int end)
{
	if (end - start < 1) return;
	int p = partion(arr, start, end);
	_quickSort(arr, start, p);
	_quickSort(arr, p + 1, end);
	
}
template<typename T>
int partion(vector<T> &arr, int start, int end)
{
	if (end - start < 1) return start;
	//int temp = arr[start];//取第一个
	//int temp = arr[rand()%(end-start)+start];
	swap(arr[start], arr[rand() % (end - start) + start]);//随机取
	int temp = arr[start];
	int j = start;
	for (int i = start +1; i <= end; i++)
	{
		if (arr[i] < temp)
		{
			j++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[start], arr[j]);
	return j;
}
//打印
template<typename T>
void PrintArr(vector<T> &arr)
{
	int i = 0;
	while (i < arr.size())
	{
		int j;
		for (j = i; j < 16 + i && j < arr.size(); j++)
		{
			cout << arr[j]<<' ';
		}		
		cout << endl;
		i += 16;
	}
	
}
//生成随机数
template<typename T>
vector<T> Random(vector<T> &arr, T n, T L, T R)
{
	srand((unsigned)time(NULL));//种子
	for (int i = 0; i < n; i++)
	{
		arr.push_back(rand() % (R - L) + L);
	}

	return arr;
}
//计算时间
template<typename T>
void testSort(const string &sortName, vector<T>(*sortname)(vector<T> &), vector<T> &arr) {

	clock_t startTime = clock();
	sortname(arr);
	clock_t endTime = clock();
	cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	return;
}

int main()
{
	//随机数测试
	vector<int> arrb(5);
	arrb = { 4,2,8,1,3 };
	bubbleSort(arrb);
	//1.冒泡排序
	cout << "1.冒泡排序" << endl;
	vector<int> arr1;
	Random(arr1, 50, 100, 1000);
	bubbleSort(arr1);
	PrintArr(arr1);
	//2.插入排序
	cout << "2.插入排序" << endl;
	vector<int> arr2;
	Random(arr2, 50, 100, 1000);
	insertSort(arr2);
	PrintArr(arr2);
	//3.选择排序
	cout << "3.选择排序" << endl;
	vector<int> arr3;
	Random(arr3, 50, 100, 1000);
	selectionSort(arr3);
	PrintArr(arr3);
	//4.归并排序
	cout << "4.归并排序" << endl;
	vector<int> arr4;
	Random(arr4, 50, 100, 1000);
	mergeSort(arr4);
	PrintArr(arr4);
	//5.快速排序
	cout << "5.快速排序" << endl;
	vector<int> arr5;
	Random(arr5, 50, 100, 1000);
	quickSort(arr5);
	PrintArr(arr5);

	//测试消耗时间
	//冒泡
	vector<int> arrs1;
	Random(arrs1, 3000, 1, 100000);
	testSort("bubbleSort", bubbleSort, arrs1);
	//插入
	vector<int> arrs2;
	Random(arrs2, 3000, 1, 100000);
	testSort("insertSort", insertSort, arrs2);
	//选择
	vector<int> arrs3;
	Random(arrs3, 3000, 1, 100000);
	testSort("selectionSort", selectionSort, arrs3);
	//归并
	vector<int> arrs4;
	Random(arrs4, 3000, 1, 100000);
	testSort("mergeSort", mergeSort, arrs4);
	//快速
	vector<int> arrs5;
	Random(arrs5, 3000, 1, 100000);
	testSort("quickSort", quickSort, arrs5);
	getchar();
    return 0;
}
