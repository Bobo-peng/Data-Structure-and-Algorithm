// sort.cpp: 定义控制台应用程序的入口点。
//
//#define _CRT_SECURE_NO_WARNINGS
#define INC_03_SELECTION_SORT_DETECT_PERFORMANCE_SORTTESTHELPER_H
#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>
#include<io.h>
#include<fcntl.h>
#include<string>
#include"CRandom.h"
using namespace std;

//基础排序算法
//1.选择排序
template<typename T>
vector<T> selectionSort(vector<T> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[minIndex] > arr[j])//条件成立就交换()
			{
				swap(arr[minIndex], arr[j]);
			}
		}
	}
	return arr;
}
template<typename T>
vector<T> selectionSort1(vector<T> &arr) {

	for (int i = 0; i < arr.size(); i++) {

		int minIndex = i;
		for (int j = i + 1; j < arr.size(); j++)//找到最小的索引值，只交换一次
			if (arr[j] < arr[minIndex])
				minIndex = j;

		swap(arr[i], arr[minIndex]);
	}
	return arr;
}
//2.冒泡排序
template<typename T>
vector<T> bubbleSort(vector<T> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
	}
	return arr;
}
//插入排序
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
//归并排序******************************************
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
//快速排序******************************************
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
//*************************************************
 //Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

 static bool cmp(Interval a, Interval b) {
	 return a.start < b.start;
 }
 
vector<Interval> merge1(vector<Interval>& intervals) {
	sort(intervals.begin(), intervals.end(), cmp);
	
	if (intervals.size() == 1)
		return intervals;
	vector<Interval> res;
	int i = 0;
	while (i < intervals.size()) {
		int start = intervals[i].start, end = intervals[i].end;
		int j = i + 1;
		while (j < intervals.size() && intervals[j].start <= end) {
			if (end < intervals[j].end)
				end = intervals[j].end;
			j++;
		}
		struct Interval merge = { start, end };
		res.push_back(merge);
		i = j;
	}
	return res;
}
	
vector<Interval> merge(vector<Interval>& intervals) {
	if (intervals.size() <= 1) return intervals;
	vector<Interval> res;
	sort(intervals.begin(), intervals.end(), cmp);
	int i = 0;
	Interval temp = { intervals[0].start, intervals[0].end };
	while (i < intervals.size())
	{
		temp.start = intervals[i].start;
		temp.end = intervals[i].end;
		while (i < intervals.size())
		{
			if (i < intervals.size()-1 && temp.end >= intervals[i + 1].start)
			{
				if (temp.end < intervals[i + 1].end)
				{
					temp.end = intervals[i + 1].end;
				}

				i++;
			}
			else
			{
				i++;
				break;
			}

		}
		res.push_back(temp);
	}

	return res;

}
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> res;
	return res;
}
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
template<typename T>
void testSort(const string &sortName, vector<T>(*sort)(vector<T> &), vector<T> &arr) {

	clock_t startTime = clock();
	sort(arr);
	clock_t endTime = clock();

	//assert(isSorted(arr, n));
	cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

	return;
}
template<class T, typename G>
G add(T a, G b)
{
	return a + b;
}
template<typename T, typename G>
G minus(T a, G b)
{
	return a + b;
}

void RecordAxisDataMach(int filenum)
{

	int i;
	FILE *fp = NULL;
	//char path[256] = {0};
	//strcat(path, "C:\\CAXA\\CAXADNC2018\\CAXADNCMonitor\\datatemp\\");
	//strcat(path, filenum)
	char s0[32] = { 0 };
	sprintf(s0, "%d",  filenum);
	string str(s0);
    string path = "C:\\CAXA\\CAXADNC2018\\CAXADNCMonitor\\datatemp\\" + str + ".txt";//datatemp路径
	fp = fopen(path.c_str(), "w+");
	if (NULL != fp)
	{
		for (i = 0; i < 15; i++)
		{
			char s[32] = { 0 };
			sprintf(s, "%f", (double)(i + rand() % 100));
			strcat(s, "\r\n");
			//s += "\r\n";
			fwrite(s, strlen(s), 1, fp);
		}
	}
	fclose(fp);

}
int main()
{
	int i = 1;
	while (1)
	{
		
		RecordAxisDataMach(i++);
		if (i > 20) i = 1;

	}
	

	testA<int> ::add(1, 2);
	
	add(1, 2);
	add(1, 2.0);
	//FILE *fp = NULL;
	//char file[256] = {"E:\\caxan\\send\\34.txt"};
	//int handle = _open(file, _O_RDWR);
	//fp = fopen(file, "r");
	vector<int> testInt = {5,6,7,9,1,2,3,0,4};
	vector<char> testChar = { 'A','c','m','T','O','a','p','R','E' };
	vector<string> testString = { "D", "d", "A", "B", "C", "c" };
	//selectionSort(testInt);
	selectionSort(testChar);
	selectionSort(testString);
	string c[4] = { "D","C","B","A" };
	//selectionSort1(c, 4);
	bubbleSort(testInt);
	//-----------------------2018.10.25-----------
	//随机数测试，选择排序
	cout << "选择排序" << endl;
	vector<int> arr;
	CRandom<int>::Random(arr,50, 100, 1000);
	selectionSort(arr);
	PrintArr(arr);
	//---------------------------------------------
	//插入排序
	cout << "插入排序" << endl;
	vector<int> arr1;
	CRandom<int>::Random(arr1, 50, 100, 1000);
	insertSort(arr1);
	PrintArr(arr1);
	//归并排序
	cout << "归并排序" << endl;
	vector<int> arr3;
	CRandom<int>::Random(arr3, 50, 100, 1000);
	mergeSort(arr3);
	PrintArr(arr3);
	//快速排序
	cout << "快速排序" << endl;
	vector<int> arr4;
	CRandom<int>::Random(arr4, 50, 100, 1000);
	quickSort(arr3);
	PrintArr(arr3);
	//-------------比较时间--------------------------------
	/*vector<int> arrs;
	for (int i = 0; i < 3000; i++)
	{
		arrs.push_back(i);
	}
	*/
	//选择（冒泡）
	vector<int> arrs1;
	CRandom<int>::Random(arrs1, 3000, 1, 100000);
	testSort("selectionSort", selectionSort, arrs1);
	//冒泡
	vector<int> arrs2;
	CRandom<int>::Random(arrs2, 3000, 1, 100000);
	testSort("bubbleSort", bubbleSort, arrs2);
	//插入
	vector<int> arrs3;
	CRandom<int>::Random(arrs3, 3000, 1, 100000);
	testSort("insertSort", insertSort, arrs3);
	//选择
	vector<int> arrs4;
	CRandom<int>::Random(arrs4, 3000, 1, 100000);
	testSort("selectionSort1", selectionSort1, arrs4);
	//归并
	vector<int> arrs5;
	CRandom<int>::Random(arrs5, 3000, 1, 100000);
	testSort("mergeSort", mergeSort, arrs5);
	//快速
	vector<int> arrs6;
	CRandom<int>::Random(arrs6, 3000, 1, 100000);
	testSort("quickSort", quickSort, arrs6);

	
	//--------------------------------------------
	Interval inter1(5, 5);
	Interval inter2(1, 2);
	Interval inter3(2, 4);
	Interval inter4(2, 3);
	Interval inter5(4, 4);
	Interval inter6(5, 5);
	Interval inter7(2, 3);
	Interval inter8(5, 6);
	Interval inter9(0, 0);
	Interval inter10(5, 6);
	vector<Interval> v = { inter1, inter2, inter3, inter4, inter5,inter6, inter7, inter8, inter9, inter10 };
	merge1(v);

	
	getchar();
    return 0;
}

