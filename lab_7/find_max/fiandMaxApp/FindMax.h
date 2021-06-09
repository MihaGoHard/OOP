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
