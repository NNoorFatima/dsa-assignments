//
// pch.h
//

#pragma once


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Q1 part b
//analysis of the swap and shiftright function 
//for lower values of N the swap and rightShift fucntion take approximately same time even when N is 1000 but for value of N > 10000 the fucntion have a very minute difference where the swap fucntion takes a little less time(in milliseconds) of course this is different from processor to prcessor
//when talking about the crossover point I didnt find any such value of N 
// Q2 par b
//worst case is when there is no value in the array that fulfils the condition,however the loop will regardless run n times and try to find a value fulfilling the condition
//so therefore the worst case is when we have to transverse the whole array however there will be not difference in the code
template <class T>
class ArrayBasics {

public:
	static T findMax(T A[], int i, int j)
	{
		T max = A[i];
		if (i != j)
		{
			for (int k = i; k <= j; k++)
			{
				if (max < A[k])
				{
					max = A[k];
				}
			}
		}
		//cout << max << endl;
		return max;
	}
	//======================
	static int findMaxPos(T A[], int i, int j)
	{
		T max = A[i];
		int pos = i;
		if (i != j)
		{
			for (int k = i; k <= j; k++)
			{
				if (max < A[k])
				{
					max = A[k];
					pos = k;
				}
			}
		}
		//cout << max << endl;
		//cout << pos<<endl;
		return pos;
	}
	static T findMin(T A[], int i, int j)
	{
		T min = A[i];
		if (i != j)
		{
			for (int k = i; k <= j; k++)
			{
				if (min > A[k])
				{
					min = A[k];
				}
			}
		}
		return min;
	}
	static int findMinPos(T A[], int i, int j)
	{
		T min = A[i];
		int pos = i;
		if (i != j)
		{
			for (int k = i; k <= j; k++)
			{
				if (min> A[k])
				{
					min = A[k];
					pos = k;
				}
			}
		}
		return pos;
	}
	//===============================
	static void swap(T A[], int i, int j)
	{
		T temp;
		if (i != j)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	//================================
	static T* createRandomArray(int size, int min, int max)
	{
		T *ar = new T[size];
		srand(time(0));
		for (int i = 0; i < size; i++)
		{
			
			ar[i] = min + (rand() % (max-min+1));
		}
		
		return ar;
	}
	static T** createRandomMatrix(int rows,int cols,int min,int max)
	{
		T** ar = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			ar[i] = new T[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				ar[i][j] = min + (rand() % (max - min + 1));
			}
		}
		return ar;
	}
	static T* copyArray(T A[],int size)
	{
		T* ar = new T[size];
		for(int i=0 ;i<size ;i++)
		{
			ar[i] = A[i];
		}
		return ar;
	}
	//==================================
	static T** copyMatrix(T** A, int rows, int cols)
	{
		T** ar = new T * [rows];
		for(int i=0 ;i<rows ;i++)
		{ 
			ar[i] = new T[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				ar[i][j] = A[i][j];
			}
		}
		return ar;
	}
	//===========================
	static int findInArray(T A[], T q,int size)
	{
		int pos=-1;
		for (int i = 0; i < size; i++)
		{
			if (A[i] == q)
			{
				pos = i;
				return pos;
			}
		}
		return pos;
		
	}
	//=========================
	static int findInSortedArray(T* A, T q, int size)
	{
		int pos = -1;
		for (int i = 0; i < size; i++)
		{
			if (A[i] == q)
			{
				pos = i;
				return pos;
			}
		}
		return pos;
	}
	//=========================
	static int findFirstInSortedArray(T* A, T q, int size)
	{
		int pos = -1;
		for (int i = 0; i < size; i++)
		{
			if (A[i] == q)
			{
				pos = i;
				return pos;
			}
		}
		return pos;
	}
	//========================
	static void shiftLeft(T A[], int i, int j)
	{
		T temp;
		T temp_2 = A[j];

		for (int k = i + 1; k <= j + 1; k++)
		{

			A[k - 1] = A[k];

		}
		A[j] = temp_2;
	}
	static void shiftRight(T A[], int i, int j)
	{
		
		T temp = A[j];
		for (int k = i; k > i; k--)
			A[k] = A[k - 1];
		A[i] = temp;
		
		cout << endl;
	}
};
template <class T>
class ArrayUtility 
{
public:
	static void maxSortWithSwap(T A[], int size)
	{
		for (int i = 0; i <size; i++)
		{
			int M_index = ArrayBasics<T>::findMaxPos(A, i, size);
			ArrayBasics<T>::swap(A, M_index, i);
		}
	}
	static void maxSortWithShiftRight(T A[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			int M_index= ArrayBasics<T>::findMaxPos(A, i, size);
			ArrayBasics<T>::shiftRight(A, i, M_index);
		}
	}
};

template <typename T>
//q3
T maximizeProfit(int m, int n, int a[], T p[], T s)
{
	T temp;
	int temp_2;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (p[i] < p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
				temp_2 = a[i];
				a[i] = a[j];
				a[j] = temp_2;
			}

		}
	}
	
	T profit=0;
	int total = 0;
	int max = m;
	int left;
	int i = 0;
	while (m > 0 && i < n)
	{
		m -= a[i];
		total += a[i];
		if (max > total)
		{
			profit += p[i];
			
		}
		else
		{
			
			m += a[i];
			total -= a[i];
			left = max - total;
			
			if (a[i] != left)
			{
				i++; continue;
			}
			else if (a[i] == left)
			{
				profit += p[i];
			}
			
		}
		i++;
	}
	if (s != 0 && i >= n)
	{
		int s_cost = (max - total) * s;
		profit -= s_cost;
	}
	return profit;
}

//q2
template <class T>
class WarehouseAlgorithm
{
public:
	static bool hasClosePair(T B[], int n, T r)
	{
		int j = 0;
		for (int i = 0, j = i + 1; i < n; j++)
		{
			if (B[i] + B[j] == r && i!=j)
			{
				if (abs(i - j) < n / 10)
				{
					return 1;
				}
			}
			else if (j == n - 1)
			{
				i++;
				j = 0;
			}
		}
		return 0;
	
	}
};
