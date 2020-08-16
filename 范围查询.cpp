#include<iostream>
using namespace std;

int binarysearch(int* sorted_arr, int left, int right, int target);
void quick_sort(int* arr, int begin, int end);
int get_pivot(int* arr, int begin, int end);
void shellsort(int* arr, int size);
int main()
{
	int size, example_nums;
	cin>>size>>example_nums;
	int* sset = new int[size];
	for (int i = 0; i < size; i++)
		cin >> sset[i];
	//quick_sort(sset, 0, size - 1);
	shellsort(sset, size);
	for (int i = 0; i < example_nums; i++)
	{
		int begin, end, left_rank, right_rank, result;
		cin >> begin >> end;
		left_rank = binarysearch(sset, 0, size, begin);  // 注意， left_rank 可能取值为-1；
		right_rank = binarysearch(sset, 0, size, end);
		result= right_rank - left_rank;
		if (left_rank >= 0 && sset[left_rank] == begin)
			result++;
		//result= sset[left_rank] == begin ? right_rank - left_rank + 1 : right_rank - left_rank;
		cout<<result<<endl;
	}
	delete[] sset;
}

int binarysearch(int* sorted_arr, int left, int right, int target)
{
	int lo = left, hi = right;
	while (lo < hi)
	{
		int mid = (lo + hi) >> 1;
		if (sorted_arr[mid] > target)
			hi = mid;
		else
			lo = mid + 1;
	}
	return  --lo;
}


int get_pivot(int* arr, int begin, int end)
{
	int pivot = arr[begin];
	while (begin < end)
	{
		while (begin < end && arr[end] >= pivot)
			end--;
		arr[begin] = arr[end];
		while (begin < end && arr[begin] <= pivot)
			begin++;
		arr[end] = arr[begin];
	}
	arr[begin] = pivot;
	return begin;
}


void quick_sort(int* arr, int begin, int end)
{
	if (begin >= end) return;
	int pivot = get_pivot(arr, begin, end);
	quick_sort(arr, begin, pivot - 1);
	quick_sort(arr, pivot + 1, end);
}

void shellsort(int* arr, int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; i++)
		{
			for (int j = i; j >= gap && arr[j] < arr[j - gap]; j -= gap)
				swap(arr[j], arr[j - gap]);
		}
	}
}





