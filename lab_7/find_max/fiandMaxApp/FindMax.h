#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
bool FindMax(vector<T> const& arr, T& maxValue)
{
	if (arr.empty())
	{
		return false;
	}

	const T* maxElement = &arr[0];

	for (auto& currentElement : arr)
	{
		if (*maxElement < currentElement)
		{
			maxElement = &currentElement;
		}
	}

	maxValue = *maxElement;
	return true;
}


template <>
bool FindMax<const char*>(vector<const char*> const& arr, const char*& maxValue)
{
	if (arr.empty())
	{
		return false;
	}

	maxValue = arr[0];

	for (size_t i = 0; i < arr.size(); i++)
	{
		if (strcmp(arr[i], maxValue) == 1)
		{
			maxValue = arr[i];
		}
	}

	return true;
};