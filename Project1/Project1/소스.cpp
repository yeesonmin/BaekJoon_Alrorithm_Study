﻿#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//병합배열 복습2

void merge(int *sorted, int *arr, int start, int mid,int end)
{
	int i = start;
	int j = mid + 1;
	int k = start;
	int temp;

	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
		{
			sorted[k] = arr[i];
			i++;
		}
		else
		{
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i > mid)
	{
		for (int l = j; l <= end; l++)
		{
			sorted[k] = arr[l];
			k++;
		}
	}else
	{
		for (int l = i; l <= mid; l++)
		{
			sorted[k] = arr[l];
			k++;
		}
	}


	for (int l = start; l <= end; l++)
	{
		arr[l] = sorted[l];
	}
}

void mergSort(int *sorted, int *arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergSort(sorted, arr, start, mid);
		mergSort(sorted, arr, mid + 1, end);
		merge(sorted, arr, start, mid, end);
	}
}

int main()
{
	int arr[10];
	int sorted[10];

	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	mergSort(sorted, arr, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		cout<< arr[i]<<" ";
	}
}