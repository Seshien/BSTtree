#include "pch.h"

bool compare(std::vector<int>::iterator left, std::vector<int>::iterator right)
{
	if (*right <= *left)
		return true;
	return false;
}

bool compare(std::vector<int>& data, int left, int right)
{
	if (data[right] < data[left])
		return true;
	return false;
}

void mergeSort(std::vector<int>& data)
{
	_mergeSort(data, 0, data.size() - 1);
}

void _mergeSort(std::vector<int>& data, int left, int right)
{
	if (left == right)
		return;

	auto mid = left + (right - left) / 2;
	_mergeSort(data, left, mid);
	_mergeSort(data, mid + 1, right);
	merge(data, left, mid, right);
}

void merge(std::vector<int>& data, int left, int mid, int right)
{
	auto L = left;
	std::vector<int> temp;
	auto lefty = mid + 1;
	while (left < mid + 1 && lefty < right + 1)
	{
		if (compare(data, left, lefty))
		{
			temp.push_back(data[left]);
			left++;
		}
		else
		{
			temp.push_back(data[lefty]);
			lefty++;
		}
	}
	while (left < mid + 1)
	{
		temp.push_back(data[left]);
		left++;
	}
	while (lefty < right + 1)
	{
		temp.push_back(data[lefty]);
		lefty++;
	}
	left = L;
	auto it = temp.begin();
	while (it < temp.end())
	{
		data[left] = *it++;
		left++;
	}
}
void show(const std::vector<int> & d)
{
	std::cout << "Data: " << std::endl;
	for (size_t i = 0; i < d.size() - 1; i++)
	{
		std::cout << d[i] << ", ";
	}
	std::cout << *(d.end() - 1) << std::endl;
}