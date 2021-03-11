#include "TransformVector.h"

bool TransformVector(std::vector<double> &numVector)
{
	if (numVector.size() == 0)
	{
		std::cout << "empty vector\n";
		return false;
	}
	double maxElem = *std::max_element(numVector.begin(), numVector.end());
	double devideIndex = maxElem / 2;
	
	std::for_each(numVector.begin(), numVector.end(), [&](double& vectorElem) { vectorElem /= devideIndex; });
	
	return true;
}

bool SortVector(std::vector<double>& numVector)
{
	if (numVector.size() == 0)
	{
		std::cout << "empty vector\n";
		return false;
	}
	std::sort(numVector.begin(), numVector.end());
	return true;
}